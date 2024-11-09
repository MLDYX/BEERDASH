#define SDL_MAIN_HANDLED
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>
#include <vector>
#include <iostream>
#include <sstream>

// Project headers
#include "WindowManager.h"
#include "GameObject.h"


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
	if (bottomA < topB)
	{
		return false;
	}

	if (topA > bottomB)
	{
		return false;
	}

	if (rightA < leftB)
	{
		return false;
	}

	if (leftA > rightB)
	{
		return false;
	}

	//If none of the sides from A are outside B
	return true;
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
	SDL_Texture* menuTexture           = window.loadTexture("Resources/wybor_mapy_lato.png");
	SDL_Texture* backgroundTexture     = window.loadTexture("Resources/tlo_lato.png");
	SDL_Texture* playerTexture         = window.loadTexture("Resources/piwo.png");
	SDL_Texture* groundTexture         = window.loadTexture("Resources/trawa.png");
	SDL_Texture* obstacleSquareTexture = window.loadTexture("Resources/obstacle.png");
	SDL_Texture* obstacleTriangleTexture = window.loadTexture("Resources/killers.png");

	// Load Sound
	Mix_Chunk* backgroundMusic = Mix_LoadWAV("Resources/Bossfight - Milky Ways.wav");
	Mix_Chunk* laughSound = Mix_LoadWAV("Resources/laughing.wav");
	Mix_Chunk* clapSound = Mix_LoadWAV("Resources/clap.wav");

	//Load Font
	TTF_Font* font = TTF_OpenFont("Resources/NokiaKokia.ttf", 24);
	if (font == nullptr) {
		std::cout << "Failed to load font! SDL_ttf Error: " << TTF_GetError() << std::endl;
		return 1;
	}
	SDL_Color textColor = { 255, 255, 255, 255 }; 


	// Play Music
	int musicChannel = Mix_PlayChannel(-1, backgroundMusic, -1);

	// Player initial position
	GameObject player(Vector2f(20, 90), playerTexture);

	// Ground tiles position
	std::vector<GameObject> groundTiles;

	float groundTileWidth = 30.0f;
	int numGroundTiles = 140;

	for (int i = 0; i < numGroundTiles; ++i)
	{
		float xPos = i * groundTileWidth;
		groundTiles.push_back(GameObject(Vector2f(xPos, 200), groundTexture));
	}

	// Square obstacle position
	std::vector<GameObject> obstacleSquare = {
	GameObject(Vector2f(180, 170), obstacleSquareTexture),
	GameObject(Vector2f(300, 140), obstacleSquareTexture),
	GameObject(Vector2f(360, 110), obstacleSquareTexture),
	GameObject(Vector2f(390, 110), obstacleSquareTexture),
	GameObject(Vector2f(420, 140), obstacleSquareTexture),
	GameObject(Vector2f(420, 170), obstacleSquareTexture),
	GameObject(Vector2f(450, 110), obstacleSquareTexture),
	GameObject(Vector2f(480, 110), obstacleSquareTexture),
	GameObject(Vector2f(480, 110), obstacleSquareTexture),
	GameObject(Vector2f(600, 110), obstacleSquareTexture),
	GameObject(Vector2f(630, 110), obstacleSquareTexture),
	GameObject(Vector2f(660, 110), obstacleSquareTexture),
	GameObject(Vector2f(180 + 600, 170), obstacleSquareTexture),
	GameObject(Vector2f(300 + 600, 140), obstacleSquareTexture),
	GameObject(Vector2f(360 + 600, 110), obstacleSquareTexture),
	GameObject(Vector2f(390 + 600, 110), obstacleSquareTexture),
	GameObject(Vector2f(420 + 600, 140), obstacleSquareTexture),
	GameObject(Vector2f(420 + 600, 170), obstacleSquareTexture),
	GameObject(Vector2f(450 + 600, 110), obstacleSquareTexture),
	GameObject(Vector2f(480 + 600, 110), obstacleSquareTexture),
	GameObject(Vector2f(480 + 600, 110), obstacleSquareTexture),
	GameObject(Vector2f(600 + 600, 110), obstacleSquareTexture),
	GameObject(Vector2f(630 + 600, 110), obstacleSquareTexture),
	GameObject(Vector2f(660 + 600, 110), obstacleSquareTexture),
	GameObject(Vector2f(180 + 600 + 600, 170), obstacleSquareTexture),
	GameObject(Vector2f(300 + 600 + 600, 140), obstacleSquareTexture),
	GameObject(Vector2f(360 + 600 + 600, 110), obstacleSquareTexture),
	GameObject(Vector2f(390 + 600 + 600, 110), obstacleSquareTexture),
	GameObject(Vector2f(420 + 600 + 600, 140), obstacleSquareTexture),
	GameObject(Vector2f(420 + 600 + 600, 170), obstacleSquareTexture),
	GameObject(Vector2f(450 + 600 + 600, 110), obstacleSquareTexture),
	GameObject(Vector2f(480 + 600 + 600, 110), obstacleSquareTexture),
	GameObject(Vector2f(480 + 600 + 600, 110), obstacleSquareTexture),
	GameObject(Vector2f(600 + 600 + 600, 110), obstacleSquareTexture),
	GameObject(Vector2f(630 + 600 + 600, 110), obstacleSquareTexture)
	};

	// Triangle obstacle position
	std::vector<GameObject> obstacleTriangle = {
	GameObject(Vector2f(240, 170.2), obstacleTriangleTexture),
	GameObject(Vector2f(270, 170.2), obstacleTriangleTexture),
	GameObject(Vector2f(420, 110.2), obstacleTriangleTexture),
	GameObject(Vector2f(840, 170.2), obstacleTriangleTexture),
	GameObject(Vector2f(870, 170.2), obstacleTriangleTexture),
	GameObject(Vector2f(1020, 110.2), obstacleTriangleTexture)
	};

	// GameLoop variables
	bool isGameRunning = true;
	bool menuRunning = true;
	bool upsideDown = false;
	Uint32 lastTime = SDL_GetTicks();
	SDL_Event event;

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

	//Camera variables
	float cameraX = 0.0f;
	float cameraSpeed;
	cameraSpeed = speed;

	/*while (menuRunning)
	{
		window.renderBackground(menuTexture);
		while (SDL_PollEvent(&event))
		{
			if (event.type = SDL_QUIT)
			{
				isGameRunning = false;
			}
			else if (event.type = SDL_KEYDOWN)
			{
				if (event.key.keysym.sym == SDLK_KP_ENTER)
				{
					menuRunning = false;
				}
			}
		}
	}*/

	// GameLoop
	while (isGameRunning)
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
		window.renderBackground(backgroundTexture);

		// Render floor tiles
		for (GameObject& gt : groundTiles)
		{
			window.render(gt, cameraX);
		}

		// Render player square
		SDL_Rect playerRect = window.render(player, cameraX);

		// Render square obstacles
		for (GameObject& os : obstacleSquare)
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
				if (player.getPos().y >= 150)
				{
					player.getPos().y = 170; 
					isOnGround = true; 
				}
				else if (player.getPos().y <= 145 && player.getPos().y >= 135)
				{
					player.getPos().y = 140;
					isOnGround = true;
				}
				else if ((player.getPos().y >= 100 && player.getPos().y <= 125))
				{
					player.getPos().y = 110;
					isOnGround = true;
				}
				else if ((player.getPos().y >= 65 && player.getPos().y <= 90))
				{
					player.getPos().y = 80;
					isOnGround = true;
				}
				else
				{
					isOnGround = false;
				}
			}

			// When the player collides horizontally

			else if (player.getPos().x + player.getObjectSize().w > os.getPos().x &&
				player.getPos().x < os.getPos().x + (os.getObjectSize().w))
			{
				speed = 0.0f;
				cameraSpeed = 0.0f;
			}
		}

		collisionDetected = true;
	}

		// Render triangle Obstacles
		for (GameObject& ott : obstacleTriangle)
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

				}

				// When the player collides horizontally
				if (player.getPos().x + player.getObjectSize().w> ott.getPos().x  &&
					player.getPos().x < ott.getPos().x + (ott.getObjectSize().w ))
				{

					speed = 0.0f;
					cameraSpeed = 0.0f;


				}

				collisionDetected = true;
			}
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

		//std::cout << percentageText << std::endl;

		// Font rendering
		SDL_Texture* textTexture = createTextTexture(window.getRenderer(), font, percentageText, textColor);

		if (textTexture != nullptr) {
			int textWidth = 0, textHeight = 0;
			SDL_QueryTexture(textTexture, nullptr, nullptr, &textWidth, &textHeight);
			SDL_Rect textRect = { 10, 10, textWidth, textHeight };
			SDL_RenderCopy(window.getRenderer(), textTexture, nullptr, &textRect);
			SDL_DestroyTexture(textTexture);
		}

		// Display Render
		window.display();

	}
	// Clean and delete
	window.cleanUp();
	Mix_FreeChunk(backgroundMusic);
	Mix_FreeChunk(laughSound);
	Mix_FreeChunk(clapSound);
	IMG_Quit();
	Mix_Quit();
	SDL_Quit();


	return 0;
}