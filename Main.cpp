#define SDL_MAIN_HANDLED
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>
#include <vector>
#include <iostream>
#include <sstream>
#include <iomanip>

// Project headers
#include "WindowManager.h"
#include "GameObject.h"
#include "Maps.h"
#include "Stars.h"


// Collision Detection
bool checkCollision(SDL_Rect a, SDL_Rect b)
{
	//The sides of the rectangles
	int leftA, leftB;
	int rightA, rightB;
	int topA, topB;
	int bottomA, bottomB;

	//Calculate the sides of rect A
	leftA = a.x;
	rightA = a.x + a.w;
	topA = a.y;
	bottomA = a.y + a.h;

	//Calculate the sides of rect B
	leftB = b.x;
	rightB = b.x + b.w;
	topB = b.y;
	bottomB = b.y + b.h;

	//If any of the sides from A are outside of B
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

	//If none of the sides from A are outside B
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

// Font Texture font
SDL_Texture* createTextTexture(SDL_Renderer* renderer, TTF_Font* font, const std::string& text, SDL_Color color)
{
	SDL_Surface* textSurface = TTF_RenderText_Solid(font, text.c_str(), color);
	SDL_Texture* textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
	SDL_FreeSurface(textSurface);
	return textTexture;
}

int main()
{

	// Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) > 0)
		std::cout << "SDL failed to load" << SDL_GetError() << std::endl;

	// Initialize SDL image library
	if(!(IMG_Init(IMG_INIT_PNG)))
		std::cout<< "SDL image PNG failed to load" << SDL_GetError() << std::endl;

	// Initialize SDL audio mixer
	if (SDL_Init(SDL_INIT_AUDIO) < 0)
	{
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
		return 1;
	}

	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
		std::cout << "SDL_mixer failed to initialize: " << Mix_GetError() << std::endl;

	// Initialize SDL font
	if (TTF_Init() == -1)
	{
		std::cout << "SDL_ttf could not initialize! SDL_ttf Error: " << TTF_GetError() << std::endl;
		return 1;
	}
	
	// Window Manager
	RenderWindow window("BEERDASH", 1920, 1080);


	// Load textures
	SDL_Texture* menuTextureLato = window.loadTexture("Resources/wybor_mapy_lato.png");
	SDL_Texture* menuTextureJesien = window.loadTexture("Resources/wybor_mapy_jesien.png");
	SDL_Texture* menuTextureZima = window.loadTexture("Resources/wybor_mapy_zima.png");
	SDL_Texture* playerTexture         = window.loadTexture("Resources/piwo.png");

	// Load Sound
	Mix_Chunk* backgroundMusic = Mix_LoadWAV("Resources/Bossfight - Milky Ways.wav");
	Mix_Chunk* laughSound = Mix_LoadWAV("Resources/laughing.wav");
	Mix_Chunk* clapSound = Mix_LoadWAV("Resources/clap.wav");

	bool isGameRunning = false;
	bool menuRunning = true;
	
	Stars stars;
	SDL_Event event;

	int mapFlag = 0;
	std::vector<SDL_Texture*> menuTextures = { menuTextureLato/*, menuTextureJesien, menuTextureZima */ };

	while (menuRunning)
	{
		window.renderBackground(menuTextures[mapFlag]);
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
			{
				isGameRunning = false;
				menuRunning = false;
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

	MapData mapa;
	if (mapFlag == 0) {
		mapa = loadMapaLato(window);
	}
	//else if (mapFlag == 1) {
	//	mapa = loadMapaJesien(window);
	//}
	//else if (mapFlag == 2) {
	//	mapa = loadMapaZima(window);
	//}

	//Load Font
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


	// Play Music
	int musicChannel = Mix_PlayChannel(-1, backgroundMusic, -1);

	// Player initial position
	GameObject player(Vector2f(20, 90), playerTexture);

	// GameLoop variables
	bool upsideDown = false;
	Uint32 lastTime = SDL_GetTicks();

	//Player movement variables
	float jumpVelocity = -280.0f;
	float speed = 115.0f;
	float gravity = 600.0f;
	float groundLevel = 170.0f;
	float velocityY = 0.0f;

	if (upsideDown) {
		float jumpVelocity = 280.0f;
		float speed = 115.0f;
		float gravity = -600.0f;
		float groundLevel = -170.0f;
		float velocityY = 0.0f;
	}

	bool isJumping = false;
	bool isOnGround = true;

	// player rotation variables
	float targetRotation = 0.0f;
	float rotationProgress = 0.0f;
	float rotationDuration = 0.75f;

	// Collision Detection
	bool collisionDetected = false;
	bool isDead = false;

	//Camera variables
	float cameraX = 0.0f;
	float cameraSpeed;
	cameraSpeed = speed;
	SDL_Texture* congratsTexture = nullptr;

	while (isGameRunning && !menuRunning)
	{
		//DOROBIÆ KOLEJNY WHILE LOOP Z FLAG¥ isMenuRunning i dopóki user nie wciœnie enter pokazywaæ menu
		Uint32 currentTime = SDL_GetTicks();
		float deltaTime = (currentTime - lastTime) / 1000.0f;
		lastTime = currentTime;
		

		// Player rotation 
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

		// Input handling
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
			{
				isGameRunning = false;
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
			}
		}

		// Jumping Logic
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

		// Camera starts moving afer a certain destination
		if (player.getPos().x > 100)
		{
			cameraX += cameraSpeed * deltaTime;
		}

		// Clear screen
		window.clear();

		// Render background
		window.renderBackground(mapa.backgroundTexture);

		// Render floor tiles
		for (GameObject& gt : mapa.groundTiles)
		{
			window.render(gt, cameraX);
		}

		// Render player square
		SDL_Rect playerRect = window.render(player, cameraX);

		// Render square obstacles
		for (GameObject& os : mapa.obstacleSquare)
		{

			SDL_Rect obstacleRect = window.render(os, cameraX);
		    if (checkCollision(playerRect, obstacleRect))
			{
				// When the player collides vertically
				if (player.getPos().y + player.getObjectSize().h > os.getPos().y &&
					player.getPos().y < os.getPos().y)
				{
					velocityY = 0; 
					isJumping = false;
					if (player.getPos().y >= 160)
					{
						player.getPos().y = 170; 
						isOnGround = true; 
					}
					else if (player.getPos().y <= 145 && player.getPos().y >= 135)
					{
						player.getPos().y = 140;
						isOnGround = true;
					}
					else if (player.getPos().y >= 105 && player.getPos().y <= 115)
					{
						player.getPos().y = 110;
						isOnGround = true;
					}
					else if (player.getPos().y >= 75 && player.getPos().y <= 85)
					{
						player.getPos().y = 80;
						isOnGround = true;
					}
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

				// When the player collides horizontally

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

		// Render triangle Obstacles
		for (GameObject& ott : mapa.obstacleTriangle)
		{
			SDL_Rect obstacleTriangleRect = window.render(ott, cameraX);
			if (checkCollision(playerRect, obstacleTriangleRect))
			{

				// When the player collides vertically
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

				// When the player collides horizontally
				if (player.getPos().x + player.getObjectSize().w > ott.getPos().x  &&
					player.getPos().x < ott.getPos().x + (ott.getObjectSize().w ))
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
		int counterForStars = 0;
		int star1Collected = 0;
		int star2Collected = 2;
		int star3Collected = 4;

		SDL_Rect starRect1 = window.render(mapa.stars[0], cameraX);

		if (checkCollision(playerRect, starRect1))
		{	
			stars.collectStar(star1Collected);
			star1Collected = 1;
		}

		/*SDL_Rect starRect2 = window.render(mapa.stars[0], cameraX);

		if (checkCollision(playerRect, starRect1))
		{
			stars.collectStar();
		}

		SDL_Rect starRect3 = window.render(mapa.stars[0], cameraX);

		if (checkCollision(playerRect, starRect1))
		{
			stars.collectStar();
		}*/

		std::ostringstream oss;
		oss << std::fixed << std::setprecision(1) << stars.getStarCount();
		renderText(window.getRenderer(), font, "OCENA " + oss.str(), textColor, 1710, 10);

			//std::string percentageText = "PROGRESS " + std::to_string(static_cast<int>(percentage)) + "%";

			//std::string congratsText = "GRATULACJE";

			//// Font rendering
			//SDL_Texture* textTexture = createTextTexture(window.getRenderer(), font, percentageText, textColor);

			//collisionDetected = true;

		for (GameObject& fin : mapa.finish) 
		{
			window.render(fin, cameraX);
		}

		if (isDead && congratsTexture == nullptr)
		{
			std::string message = "PIWO SIE WYLALO";
			congratsTexture = createTextTexture(window.getRenderer(), congratsFont, message, textColor);
		}

		// Render the congrats message if the texture is created
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

		// When the player arrives at the end
		if (player.getPos().x >= 4250)
		{
			speed = 0.0f;
			cameraSpeed = 0.0f;
			int clapChannel = Mix_PlayChannel(-1, clapSound, 0);
			Mix_HaltChannel(musicChannel);
		}

		// When the player loses/end level
		if (speed == 0.0f)
		{
			if (player.getPos().x < 4250)
			{
				int laughChannel = Mix_PlayChannel(-1, laughSound, 0);
				Mix_HaltChannel(musicChannel);
			}
			isJumping = true;
		}

		// Process count
		float percentage = (player.getPos().x / 4250.0f) * 100.0f;
		std::string percentageText = "PROGRESS " + std::to_string(static_cast<int>(percentage)) + "%";
		
		std::string congratsText = "GRATULACJE";

		// Font rendering
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
			std::string message = "GRATULACJE";
			congratsTexture = createTextTexture(window.getRenderer(), congratsFont, message, textColor);
		}

		// Render the congrats message if the texture is created
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

		// Display Render
		window.display();

	}
	// Clean and delete
	SDL_DestroyTexture(menuTextureLato);
	SDL_DestroyTexture(playerTexture);
	SDL_DestroyTexture(congratsTexture);
	Mix_FreeChunk(backgroundMusic);
	Mix_FreeChunk(laughSound);
	Mix_FreeChunk(clapSound);
	TTF_CloseFont(font);
	TTF_CloseFont(congratsFont);
	window.cleanUp();
	Mix_CloseAudio();
	IMG_Quit();
	Mix_Quit();
	SDL_Quit();


	return 0;
}