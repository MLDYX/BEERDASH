#define SDL_MAIN_HANDLED
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>
#include <vector>
#include <iostream>
#include <sstream>
#include <iomanip>

// Pliki nag³ówkowe
#include "WindowManager.h"
#include "GameObject.h"
#include "Maps.h"
#include "Stars.h"

/////// NAJWA¯NIEJSZE ELEMENTY KODU ///////
/////// NAJWA¯NIEJSZE ELEMENTY KODU ///////
/////// NAJWA¯NIEJSZE ELEMENTY KODU ///////
// Detekcja kolizji
bool checkCollision(SDL_Rect a, SDL_Rect b)
{
	//Boki kwadratów
	int leftA, leftB;
	int rightA, rightB;
	int topA, topB;
	int bottomA, bottomB;

	//Obliczanie boków kwadratu A
	leftA = a.x;
	rightA = a.x + a.w;
	topA = a.y;
	bottomA = a.y + a.h;

	//obliczanie boków kwadratu B
	leftB = b.x;
	rightB = b.x + b.w;
	topB = b.y;
	bottomB = b.y + b.h;

	//Jeœ³i któryœ z boków kwadratu A jest poza bokami kwadratu B
	if (bottomA <= topB)
	{
		return false;
	}

	if (topA >= bottomB)
	{
		return false;
	}

	if (rightA <= leftB)
	{
		return false;
	}

	if (leftA >= rightB)
	{
		return false;
	}

	//Jeœli ¿aden z powy¿szych warunków nie jest spe³niony, kwadraty nachodz¹ na siebie
	return true;
}

void renderText(SDL_Renderer* renderer, TTF_Font* congratsFont, const std::string& message, SDL_Color color, int x, int y)
{
	SDL_Surface* textSurface = TTF_RenderText_Solid(congratsFont, message.c_str(), color);
	SDL_Texture* textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
	SDL_Rect textRect = { x, y, textSurface->w, textSurface->h };
	SDL_FreeSurface(textSurface);
	SDL_RenderCopy(renderer, textTexture, nullptr, &textRect);
	SDL_DestroyTexture(textTexture);
}

SDL_Texture* createTextTexture(SDL_Renderer* renderer, TTF_Font* font, const std::string& text, SDL_Color color)
{
	SDL_Surface* textSurface = TTF_RenderText_Solid(font, text.c_str(), color);
	SDL_Texture* textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
	SDL_FreeSurface(textSurface);
	return textTexture;
}

int main()
{

	if (SDL_Init(SDL_INIT_VIDEO) > 0)
		std::cout << "SDL failed to load" << SDL_GetError() << std::endl;

	if(!(IMG_Init(IMG_INIT_PNG)))
		std::cout<< "SDL image PNG failed to load" << SDL_GetError() << std::endl;

	if (SDL_Init(SDL_INIT_AUDIO) < 0)
	{
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
		return 1;
	}

	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
		std::cout << "SDL_mixer failed to initialize: " << Mix_GetError() << std::endl;

	if (TTF_Init() == -1)
	{
		std::cout << "SDL_ttf could not initialize! SDL_ttf Error: " << TTF_GetError() << std::endl;
		return 1;
	}

	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1");
	SDL_GL_SetSwapInterval(1);
	
	// Tworzenie okna
	RenderWindow window("BEERDASH", 1920, 1080);


	// Wczytywanie tekstur
	SDL_Texture* menuTextureLato = window.loadTexture("Resources/wybor_mapy_lato.png");
	SDL_Texture* menuTextureJesien = window.loadTexture("Resources/wybor_mapy_jesien.png");
	SDL_Texture* menuTextureZima = window.loadTexture("Resources/wybor_mapy_zima.png");
	SDL_Texture* playerTexture         = window.loadTexture("Resources/piwo.png");

	// Wczytywanie dzwiêków
	Mix_Chunk* backgroundMusic = Mix_LoadWAV("Resources/Bossfight - Milky Ways.wav");
	Mix_Chunk* laughSound = Mix_LoadWAV("Resources/laughing.wav");
	Mix_Chunk* clapSound = Mix_LoadWAV("Resources/clap.wav");
	Mix_Chunk* starSound = Mix_LoadWAV("Resources/smb_coin.wav");

	
	// G³ówne flagi odpowiadaj¹ce za dzia³anie programu.
	bool isGameRunning = false;
	bool menuRunning = true;
	bool isProgramRunning = true;
	
	Stars stars;
	SDL_Event event;

	int mapFlag = 0;
	std::vector<SDL_Texture*> menuTextures = { menuTextureLato, menuTextureJesien, menuTextureZima };

	/////// NAJWA¯NIEJSZE ELEMENTY KODU ///////
	/////// NAJWA¯NIEJSZE ELEMENTY KODU ///////
	/////// NAJWA¯NIEJSZE ELEMENTY KODU ///////

	while (isProgramRunning) {
		// Pêtla sprawiaj¹ca ¿e menu dzia³a
		while (menuRunning)
		{
			window.renderBackground(menuTextures[mapFlag]);
			while (SDL_PollEvent(&event))
			{
				if (event.type == SDL_QUIT)
				{
					isGameRunning = false;
					menuRunning = false;
					isProgramRunning = false;
				}
				else if (event.type == SDL_KEYDOWN)
				{
					if (event.key.keysym.sym == SDLK_RIGHT)
					{
						mapFlag = (mapFlag + 1) % menuTextures.size();
					}
					else if (event.key.keysym.sym == SDLK_RETURN)
					{
						menuRunning = false;
						SDL_Delay(100);
						isGameRunning = true;
					}
				}
			}
			window.display();
		}

		/////// NAJWA¯NIEJSZE ELEMENTY KODU ///////
		/////// NAJWA¯NIEJSZE ELEMENTY KODU ///////
		// Wybór mapy i jej wczytywanie
		MapData mapa;
		std::string mapName;
		if (mapFlag == 0) {
			mapa = loadMapaLato(window);
			mapName = "lato";
		}
		else if (mapFlag == 1) {
			mapa = loadMapaJesien(window);
			mapName = "jesien";
		}
		else if (mapFlag == 2) {
			mapa = loadMapaZima(window);
			mapName = "zima";
		}

		//Wczytywanie czcionek
		TTF_Font* font = TTF_OpenFont("Resources/NokiaKokia.ttf", 24);
		if (font == nullptr) {
			std::cout << "Failed to load font! SDL_ttf Error: " << TTF_GetError() << std::endl;
			return 1;
		}
		TTF_Font* congratsFont = TTF_OpenFont("Resources/NokiaKokia.ttf", 64);
		if (congratsFont == nullptr) {
			std::cout << "Failed to load font! SDL_ttf Error: " << TTF_GetError() << std::endl;
			return 1;
		}
		SDL_Color textColor = { 255, 255, 255, 255 };


		// Granie muzyki
		int musicChannel = Mix_PlayChannel(-1, backgroundMusic, -1);

		// Pocz¹tkowa pozycja gracza
		GameObject player(Vector2f(20, 90), playerTexture);

		Uint32 lastTime = SDL_GetTicks();

		//Zmienne poruszania siê gracza
		float jumpVelocity = -280.0f;
		float speed = 115.0f;
		float gravity = 600.0f;
		float groundLevel = 170.0f;
		float velocityY = 0.0f;

		if (mapName == "zima") {
			speed = 132.5f;
		}

		if (mapName == "jesien") {
			speed = 105.0f;
		}

		bool isJumping = false;
		bool isOnGround = true;

		// Zmienne obrotu gracza
		float targetRotation = 0.0f;
		float rotationProgress = 0.0f;
		float rotationDuration = 0.75f;

		// Flagi kolizji
		bool collisionDetected = false;
		bool isDead = false;
		bool isWon = false;

		// Zbieranie gwiazdek
		int star1Collected = 0;
		int star2Collected = 2;
		int star3Collected = 4;

		// Zmienne kamerki
		float cameraX = 0.0f;
		float cameraSpeed;
		cameraSpeed = speed;
		SDL_Texture* congratsTexture = nullptr;

		/////// NAJWA¯NIEJSZE ELEMENTY KODU ///////
		/////// NAJWA¯NIEJSZE ELEMENTY KODU ///////
		/////// NAJWA¯NIEJSZE ELEMENTY KODU ///////
		// Pêtla gry
		while (isGameRunning && !menuRunning)
		{
			Uint32 currentTime = SDL_GetTicks();
			float deltaTime = (currentTime - lastTime) / 1000.0f;
			lastTime = currentTime;


			// Rotacja Gracza
			if (isJumping)
			{
				rotationProgress += deltaTime / rotationDuration;
				if (rotationProgress > 1.0f) rotationProgress = 1.0f;
				float currentRotation = player.getRotation() + (targetRotation - player.getRotation()) * rotationProgress;
				player.setRotation(currentRotation);

				if (rotationProgress >= 1.0f)
				{
					isJumping = false;
					rotationProgress = 0.0f;
				}
			}

			// Obs³ugiwanie inputu z klawiatury
			while (SDL_PollEvent(&event))
			{
				if (event.type == SDL_QUIT)
				{
					isGameRunning = false;
					isProgramRunning = false;
				}
				else if (event.type == SDL_KEYDOWN)
				{
					if (event.key.keysym.sym == SDLK_SPACE && !isJumping && isOnGround)
					{
						velocityY = jumpVelocity;
						isJumping = true;
						targetRotation = player.getRotation() + 360.0f;
						isOnGround = false;
					}
					if ((isDead || isWon) && event.key.keysym.sym == SDLK_RETURN) {
						isDead = false;
						player.getPos().x = 20;
						player.getPos().y = 90;
						isGameRunning = false;
						menuRunning = true;
					}
				}
			}


			/////// NAJWA¯NIEJSZE ELEMENTY KODU ///////
			/////// NAJWA¯NIEJSZE ELEMENTY KODU ///////
			// /////// NAJWA¯NIEJSZE ELEMENTY KODU ///////
			// Logika skakania
			velocityY += gravity * deltaTime;
			player.getPos().x += speed * deltaTime;
			player.getPos().y += velocityY * deltaTime;
			if (player.getPos().y >= groundLevel)
			{
				player.getPos().y = groundLevel;
				isOnGround = true;
				velocityY = 0;
				isJumping = false;
			}

			// If sprawiaj¹cy ¿e kamera porusza siê dopiero po pewnym momencie
			if (player.getPos().x > 120)
			{
				cameraX += cameraSpeed * deltaTime;
			}

			// Czyszczenie okna
			window.clear();

			// Renderowanie t³a
			window.renderBackground(mapa.backgroundTexture);

			// Renderowanie pod³ogi
			for (GameObject& gt : mapa.groundTiles)
			{
				window.render(gt, cameraX);
			}

			// Renderowania gracza
			SDL_Rect playerRect = window.render(player, cameraX);

			/////// NAJWA¯NIEJSZE ELEMENTY KODU ///////
			/////// NAJWA¯NIEJSZE ELEMENTY KODU ///////
			/////// NAJWA¯NIEJSZE ELEMENTY KODU ///////

			// Renderowanie kwadratowych przeszkód
			for (GameObject& os : mapa.obstacleSquare)
			{

				SDL_Rect obstacleRect = window.render(os, cameraX);
				if (checkCollision(playerRect, obstacleRect))
				{
					// Gdy gracz zderzy siê z przeszkod¹ pionowo od góry
					if (player.getPos().y + player.getObjectSize().h > os.getPos().y &&
						player.getPos().y < os.getPos().y)
					{
						velocityY = 0;
						isJumping = false;
						// Poziom 0 - ground
						if (player.getPos().y >= 160)
						{
							player.getPos().y = 170;
							isOnGround = true;
						}
						// Poziom 1
						else if (player.getPos().y <= 150 && player.getPos().y >= 130)
						{
							player.getPos().y = 140;
							isOnGround = true;
						}
						// Poziom 2
						else if (player.getPos().y >= 100 && player.getPos().y <= 120)
						{
							player.getPos().y = 110;
							isOnGround = true;
						}
						// Poziom 3
						else if (player.getPos().y >= 70 && player.getPos().y <= 90)
						{
							player.getPos().y = 80;
							isOnGround = true;
						}
						// Gdy gracz zderzy siê z przeszkod¹ pinowo od do³u
						else
						{
							isOnGround = false;
							speed = 0.0f;
							cameraSpeed = 0.0f;
							velocityY = 0;
							gravity = 0;
							targetRotation = 180.0f;
							player.setRotation(180.0f);
							isDead = true;
						}
					}

					// Gdy gracz zderzy siê z przeszkod¹ poziomo

					else if (player.getPos().x + player.getObjectSize().w > os.getPos().x &&
						player.getPos().x < os.getPos().x + os.getObjectSize().w)
					{
						speed = 0.0f;
						cameraSpeed = 0.0f;
						velocityY = 0;
						gravity = 0;
						targetRotation = 180.0f;
						player.setRotation(180.0f);
						isDead = true;
					}
				}

				collisionDetected = true;
			}

			/////// NAJWA¯NIEJSZE ELEMENTY KODU ///////
			/////// NAJWA¯NIEJSZE ELEMENTY KODU ///////
			/////// NAJWA¯NIEJSZE ELEMENTY KODU ///////

			// Wczytywanie trójk¹tnych przeszkód
			for (GameObject& ott : mapa.obstacleTriangle)
			{
				SDL_Rect obstacleTriangleRect = window.render(ott, cameraX);
				if (checkCollision(playerRect, obstacleTriangleRect))
				{

					// Gdy gracz zderzy siê z przeszkod¹ pionowo
					if (player.getPos().y + player.getObjectSize().h > ott.getPos().y &&
						player.getPos().y < ott.getPos().y + (ott.getObjectSize().h))
					{
						speed = 0.0f;
						cameraSpeed = 0.0f;
						velocityY = 0;
						gravity = 0;
						targetRotation = 180.0f;
						player.setRotation(180.0f);
					}

					// Gdy gracz zderzy siê z przeszkod¹ poziomo
					if (player.getPos().x + player.getObjectSize().w > ott.getPos().x &&
						player.getPos().x < ott.getPos().x + (ott.getObjectSize().w))
					{
						speed = 0.0f;
						cameraSpeed = 0.0f;
						velocityY = 0;
						gravity = 0;
						targetRotation = 180.0f;
						player.setRotation(180.0f);
					}
					collisionDetected = true;
					isDead = true;
				}
			}

			//Logika zbierania gwiazdek

			SDL_Rect starRect1 = window.render(mapa.stars[0], cameraX);

			if (checkCollision(playerRect, starRect1) && star1Collected == 0 /*&& !stars.isStarCollected(mapName, 1)*/)
			{
				stars.collectStar1(mapName);
				star1Collected = 1;
				int starChannel = Mix_PlayChannel(-1, starSound, 0);
				mapa.stars.push_back(mapa.stars[0]);
				if (!mapa.stars.empty()) {
					mapa.stars.erase(mapa.stars.begin());
				}
			}

			SDL_Rect starRect2 = window.render(mapa.stars[0], cameraX);

			if (checkCollision(playerRect, starRect2) && star2Collected == 2 /*&& !stars.isStarCollected(mapName, 2)*/)
			{
				stars.collectStar2(mapName);
				star2Collected = 3;
				mapa.stars.push_back(mapa.stars[0]);
				int starChannel = Mix_PlayChannel(-1, starSound, 0);
				if (!mapa.stars.empty()) {
					mapa.stars.erase(mapa.stars.begin());
				}
			}

			SDL_Rect starRect3 = window.render(mapa.stars[0], cameraX);

			if (checkCollision(playerRect, starRect3) && star3Collected == 4 /*&& !stars.isStarCollected(mapName, 3)*/)
			{
				stars.collectStar3(mapName);
				star3Collected = 4;
				int starChannel = Mix_PlayChannel(-1, starSound, 0);
				mapa.stars.push_back(mapa.stars[0]);
				if (!mapa.stars.empty()) {
					mapa.stars.erase(mapa.stars.begin());
				}
			}

			std::ostringstream oss;
			if (mapName == "lato") {
				oss << std::fixed << std::setprecision(1) << stars.getLatoStarCount();
			}
			if (mapName == "jesien") {
				oss << std::fixed << std::setprecision(1) << stars.getJesienStarCount();
			}
			if (mapName == "zima") {
				oss << std::fixed << std::setprecision(1) << stars.getZimaStarCount();
			}
			
			renderText(window.getRenderer(), font, "OCENA " + oss.str(), textColor, 1710, 10);

			// Renderownie znaku finish
			for (GameObject& fin : mapa.finish)
			{
				window.render(fin, cameraX);
			}

			//Tekst wyœwietlany po œmierci
			if (isDead && congratsTexture == nullptr)
			{
				std::string message = "PIWO SIE WYLALO";
				congratsTexture = createTextTexture(window.getRenderer(), congratsFont, message, textColor);
			}

			if (congratsTexture != nullptr)
			{
				int screenWidth = 1920;
				int screenHeight = 1080;
				int textWidth = 0;
				int textHeight = 0;
				SDL_QueryTexture(congratsTexture, nullptr, nullptr, &textWidth, &textHeight);
				int x = (screenWidth - textWidth) / 2;
				int y = (screenHeight - textHeight) / 2;
				SDL_Rect textRect = { x, y, textWidth, textHeight };
				SDL_RenderCopy(window.getRenderer(), congratsTexture, nullptr, &textRect);
			}

			// Jeœli gracz dojdzie do mety
			if (player.getPos().x >= 2115)
			{
				speed = 0.0f;
				cameraSpeed = 0.0f;
				int clapChannel = Mix_PlayChannel(-1, clapSound, 0);
				Mix_HaltChannel(musicChannel);
			}

			// Jeœli gracz zginie
			if (speed == 0.0f)
			{
				if (player.getPos().x < 2115)
				{
					int laughChannel = Mix_PlayChannel(-1, laughSound, 0);
					Mix_HaltChannel(musicChannel);
				}
				isJumping = true;
			}

			// Licznik postêpu
			float percentage = (player.getPos().x / 2115.0f) * 100.0f;
			std::string percentageText = "PROGRESS " + std::to_string(static_cast<int>(percentage)) + "%";

			std::string congratsText = "GRATULACJE";

			SDL_Texture* textTexture = createTextTexture(window.getRenderer(), font, percentageText, textColor);

			if (textTexture != nullptr)
			{
				int textWidth = 0, textHeight = 0;
				SDL_QueryTexture(textTexture, nullptr, nullptr, &textWidth, &textHeight);
				SDL_Rect textRect = { 10, 10, textWidth, textHeight };
				SDL_RenderCopy(window.getRenderer(), textTexture, nullptr, &textRect);
				SDL_DestroyTexture(textTexture);
			}

			if (percentage >= 100.0f && congratsTexture == nullptr)
			{
				isWon = true;
				std::string message = "GRATULACJE";
				congratsTexture = createTextTexture(window.getRenderer(), congratsFont, message, textColor);
			}

			if (congratsTexture != nullptr)
			{
				int screenWidth = 1920;
				int screenHeight = 1080;
				int textWidth = 0;
				int textHeight = 0;
				SDL_QueryTexture(congratsTexture, nullptr, nullptr, &textWidth, &textHeight);
				int x = (screenWidth - textWidth) / 2;
				int y = (screenHeight - textHeight) / 2;
				SDL_Rect textRect = { x, y, textWidth, textHeight };
				SDL_RenderCopy(window.getRenderer(), congratsTexture, nullptr, &textRect);
			}

			// Pokazanie wyrenderowanych rzeczy
			window.display();

		}
		TTF_CloseFont(font);
		TTF_CloseFont(congratsFont);
		SDL_DestroyTexture(congratsTexture);
		Mix_HaltChannel(musicChannel);
		
	}
	// Czyszczenie pamieci i usuwanie
	SDL_DestroyTexture(menuTextureLato);
	SDL_DestroyTexture(playerTexture);
	
	Mix_FreeChunk(backgroundMusic);
	Mix_FreeChunk(laughSound);
	Mix_FreeChunk(clapSound);
	
	window.cleanUp();
	Mix_CloseAudio();
	IMG_Quit();
	Mix_Quit();
	SDL_Quit();


	return 0;
}