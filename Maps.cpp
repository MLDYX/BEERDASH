#include "Maps.h"

MapData loadMapaLato(RenderWindow& window)
{
	MapData mapData;

	SDL_Texture* groundTexture = window.loadTexture("Resources/trawa.png");
	SDL_Texture* obstacleSquareTexture = window.loadTexture("Resources/obstacle.png");
	SDL_Texture* obstacleTriangleTexture = window.loadTexture("Resources/killers.png");
	SDL_Texture* starTexture = window.loadTexture("Resources/gwiazdka.png");
	SDL_Texture* finFinish = window.loadTexture("Resources/fin.png");
	SDL_Texture* ishFinish = window.loadTexture("Resources/ish.png");
	mapData.backgroundTexture = window.loadTexture("Resources/tlo_lato.png");

	float groundTileWidth = 30.0f;
	int numGroundTiles = 85;

	for (int i = 0; i < numGroundTiles; ++i)
	{
		float xPos = i * groundTileWidth;
		mapData.groundTiles.push_back(GameObject(Vector2f(xPos, 200), groundTexture));
	}

	mapData.obstacleSquare.push_back(GameObject(Vector2f(180, 170), obstacleSquareTexture));
	mapData.obstacleSquare.push_back(GameObject(Vector2f(300, 140), obstacleSquareTexture));
	mapData.obstacleSquare.push_back(GameObject(Vector2f(300, 170), obstacleSquareTexture));
	mapData.obstacleSquare.push_back(GameObject(Vector2f(390, 110), obstacleSquareTexture));
	mapData.obstacleSquare.push_back(GameObject(Vector2f(390, 140), obstacleSquareTexture));
	mapData.obstacleSquare.push_back(GameObject(Vector2f(450, 170), obstacleSquareTexture));
	mapData.obstacleSquare.push_back(GameObject(Vector2f(510, 110), obstacleSquareTexture));
	mapData.obstacleSquare.push_back(GameObject(Vector2f(600, 110), obstacleSquareTexture));
	mapData.obstacleSquare.push_back(GameObject(Vector2f(630, 110), obstacleSquareTexture));
	mapData.obstacleSquare.push_back(GameObject(Vector2f(930, 140), obstacleSquareTexture));
	mapData.obstacleSquare.push_back(GameObject(Vector2f(1050, 170), obstacleSquareTexture));
	mapData.obstacleSquare.push_back(GameObject(Vector2f(1140, 140), obstacleSquareTexture));
	mapData.obstacleSquare.push_back(GameObject(Vector2f(1230, 110), obstacleSquareTexture));
	mapData.obstacleSquare.push_back(GameObject(Vector2f(1260, 110), obstacleSquareTexture));
	mapData.obstacleSquare.push_back(GameObject(Vector2f(1380, 170), obstacleSquareTexture));
	mapData.obstacleSquare.push_back(GameObject(Vector2f(1500, 140), obstacleSquareTexture));
	mapData.obstacleSquare.push_back(GameObject(Vector2f(1590, 110), obstacleSquareTexture));
	mapData.obstacleSquare.push_back(GameObject(Vector2f(1620, 170), obstacleSquareTexture));
	mapData.obstacleSquare.push_back(GameObject(Vector2f(1620, 140), obstacleSquareTexture));
	mapData.obstacleSquare.push_back(GameObject(Vector2f(1680, 110), obstacleSquareTexture));
	mapData.obstacleSquare.push_back(GameObject(Vector2f(1770, 140), obstacleSquareTexture));
	mapData.obstacleSquare.push_back(GameObject(Vector2f(1770, 170), obstacleSquareTexture));
	mapData.obstacleSquare.push_back(GameObject(Vector2f(1800, 110), obstacleSquareTexture));

	mapData.obstacleTriangle.push_back(GameObject(Vector2f(240, 170.2), obstacleTriangleTexture));
	mapData.obstacleTriangle.push_back(GameObject(Vector2f(270, 170.2), obstacleTriangleTexture));
	mapData.obstacleTriangle.push_back(GameObject(Vector2f(360, 110.2), obstacleTriangleTexture));
	mapData.obstacleTriangle.push_back(GameObject(Vector2f(450, 140.2), obstacleTriangleTexture));
	mapData.obstacleTriangle.push_back(GameObject(Vector2f(480, 140.2 - 0.4), obstacleTriangleTexture));
	mapData.obstacleTriangle.push_back(GameObject(Vector2f(780, 170.2), obstacleTriangleTexture));
	mapData.obstacleTriangle.push_back(GameObject(Vector2f(900, 140.2), obstacleTriangleTexture));
	mapData.obstacleTriangle.push_back(GameObject(Vector2f(1110, 140.2), obstacleTriangleTexture));
	mapData.obstacleTriangle.push_back(GameObject(Vector2f(1200, 110.2), obstacleTriangleTexture));
	mapData.obstacleTriangle.push_back(GameObject(Vector2f(1290, 110.2), obstacleTriangleTexture));
	mapData.obstacleTriangle.push_back(GameObject(Vector2f(1620, 110.2), obstacleTriangleTexture));
	mapData.obstacleTriangle.push_back(GameObject(Vector2f(1650, 110.2), obstacleTriangleTexture));
	mapData.obstacleTriangle.push_back(GameObject(Vector2f(1770, 110.2), obstacleTriangleTexture));

	mapData.stars.push_back(GameObject(Vector2f(180, 140), starTexture));
	mapData.stars.push_back(GameObject(Vector2f(680, 140), starTexture));
	mapData.stars.push_back(GameObject(Vector2f(1230, 80), starTexture));

	mapData.finish.push_back(GameObject(Vector2f(2100, 80), finFinish));
	mapData.finish.push_back(GameObject(Vector2f(2130, 80), ishFinish));

	return mapData;
}

MapData loadMapaJesien(RenderWindow& window)
{
	MapData mapData;

	SDL_Texture* groundTexture = window.loadTexture("Resources/liscie.png");
	SDL_Texture* obstacleSquareTexture = window.loadTexture("Resources/obstacle.png");
	SDL_Texture* obstacleTriangleTexture = window.loadTexture("Resources/killers.png");
	SDL_Texture* starTexture = window.loadTexture("Resources/gwiazdka.png");
	SDL_Texture* finFinish = window.loadTexture("Resources/fin.png");
	SDL_Texture* ishFinish = window.loadTexture("Resources/ish.png");
	mapData.backgroundTexture = window.loadTexture("Resources/tlo_jesien.png");

	float groundTileWidth = 30.0f;
	int numGroundTiles = 85;

	for (int i = 0; i < numGroundTiles; ++i)
	{
		float xPos = i * groundTileWidth;
		mapData.groundTiles.push_back(GameObject(Vector2f(xPos, 200), groundTexture));
	}

	mapData.obstacleSquare.push_back(GameObject(Vector2f(180, 170), obstacleSquareTexture));
	mapData.obstacleSquare.push_back(GameObject(Vector2f(300, 140), obstacleSquareTexture));
	mapData.obstacleSquare.push_back(GameObject(Vector2f(300, 170), obstacleSquareTexture));
	mapData.obstacleSquare.push_back(GameObject(Vector2f(390, 110), obstacleSquareTexture));
	mapData.obstacleSquare.push_back(GameObject(Vector2f(390, 140), obstacleSquareTexture));
	mapData.obstacleSquare.push_back(GameObject(Vector2f(450, 170), obstacleSquareTexture));
	mapData.obstacleSquare.push_back(GameObject(Vector2f(510, 110), obstacleSquareTexture));
	mapData.obstacleSquare.push_back(GameObject(Vector2f(600, 110), obstacleSquareTexture));
	mapData.obstacleSquare.push_back(GameObject(Vector2f(630, 110), obstacleSquareTexture));
	mapData.obstacleSquare.push_back(GameObject(Vector2f(780, 170), obstacleSquareTexture));
	mapData.obstacleSquare.push_back(GameObject(Vector2f(870, 140), obstacleSquareTexture));
	mapData.obstacleSquare.push_back(GameObject(Vector2f(990, 170), obstacleSquareTexture));
	mapData.obstacleSquare.push_back(GameObject(Vector2f(1020, 170), obstacleSquareTexture));
	mapData.obstacleSquare.push_back(GameObject(Vector2f(1110, 140), obstacleSquareTexture));
	mapData.obstacleSquare.push_back(GameObject(Vector2f(1170, 170), obstacleSquareTexture));
	mapData.obstacleSquare.push_back(GameObject(Vector2f(1230, 140), obstacleSquareTexture));
	mapData.obstacleSquare.push_back(GameObject(Vector2f(1230, 170), obstacleSquareTexture));
	mapData.obstacleSquare.push_back(GameObject(Vector2f(1260, 140), obstacleSquareTexture));
	mapData.obstacleSquare.push_back(GameObject(Vector2f(1290, 140), obstacleSquareTexture));
	mapData.obstacleSquare.push_back(GameObject(Vector2f(1290, 170), obstacleSquareTexture));
	mapData.obstacleSquare.push_back(GameObject(Vector2f(1290, 50), obstacleSquareTexture));
	mapData.obstacleSquare.push_back(GameObject(Vector2f(1320, 50), obstacleSquareTexture));
	mapData.obstacleSquare.push_back(GameObject(Vector2f(1350, 50), obstacleSquareTexture));
	mapData.obstacleSquare.push_back(GameObject(Vector2f(1380, 50), obstacleSquareTexture));
	mapData.obstacleSquare.push_back(GameObject(Vector2f(1380, 80), obstacleSquareTexture));
	mapData.obstacleSquare.push_back(GameObject(Vector2f(1410, 80), obstacleSquareTexture));
	mapData.obstacleSquare.push_back(GameObject(Vector2f(1410, 110), obstacleSquareTexture));
	mapData.obstacleSquare.push_back(GameObject(Vector2f(1410, 140), obstacleSquareTexture));
	mapData.obstacleSquare.push_back(GameObject(Vector2f(1530, 170), obstacleSquareTexture));
	mapData.obstacleSquare.push_back(GameObject(Vector2f(1620, 140), obstacleSquareTexture));
	mapData.obstacleSquare.push_back(GameObject(Vector2f(1650, 170), obstacleSquareTexture));
	mapData.obstacleSquare.push_back(GameObject(Vector2f(1650, 140), obstacleSquareTexture));
	mapData.obstacleSquare.push_back(GameObject(Vector2f(1710, 140), obstacleSquareTexture));
	mapData.obstacleSquare.push_back(GameObject(Vector2f(1710, 170), obstacleSquareTexture));
	mapData.obstacleSquare.push_back(GameObject(Vector2f(1740, 140), obstacleSquareTexture));
	mapData.obstacleSquare.push_back(GameObject(Vector2f(1800, 140), obstacleSquareTexture));
	mapData.obstacleSquare.push_back(GameObject(Vector2f(1830, 110), obstacleSquareTexture));

	

	mapData.obstacleTriangle.push_back(GameObject(Vector2f(240, 170.2), obstacleTriangleTexture));
	mapData.obstacleTriangle.push_back(GameObject(Vector2f(270, 170.2), obstacleTriangleTexture));
	mapData.obstacleTriangle.push_back(GameObject(Vector2f(360, 110.2), obstacleTriangleTexture));
	mapData.obstacleTriangle.push_back(GameObject(Vector2f(450, 140.2), obstacleTriangleTexture));
	mapData.obstacleTriangle.push_back(GameObject(Vector2f(480, 140.2 - 0.4), obstacleTriangleTexture));
	mapData.obstacleTriangle.push_back(GameObject(Vector2f(660, 170.2), obstacleTriangleTexture));
	mapData.obstacleTriangle.push_back(GameObject(Vector2f(960, 170.2), obstacleTriangleTexture));
	/*mapData.obstacleTriangle.push_back(GameObject(Vector2f(1050, 170.2), obstacleTriangleTexture));*/
	mapData.obstacleTriangle.push_back(GameObject(Vector2f(1080, 170.2), obstacleTriangleTexture));
	mapData.obstacleTriangle.push_back(GameObject(Vector2f(1170, 140.2), obstacleTriangleTexture));
	mapData.obstacleTriangle.push_back(GameObject(Vector2f(1140, 170.2), obstacleTriangleTexture));
	mapData.obstacleTriangle.push_back(GameObject(Vector2f(1200, 170.2), obstacleTriangleTexture));
	mapData.obstacleTriangle.push_back(GameObject(Vector2f(1320, 170.2), obstacleTriangleTexture));
	mapData.obstacleTriangle.push_back(GameObject(Vector2f(1680, 140.2), obstacleTriangleTexture));
	mapData.obstacleTriangle.push_back(GameObject(Vector2f(1800, 110.2), obstacleTriangleTexture));

	mapData.stars.push_back(GameObject(Vector2f(680, 140), starTexture));
	mapData.stars.push_back(GameObject(Vector2f(1230, 80), starTexture));
	mapData.stars.push_back(GameObject(Vector2f(1830, 80), starTexture));

	mapData.finish.push_back(GameObject(Vector2f(2100, 80), finFinish));
	mapData.finish.push_back(GameObject(Vector2f(2130, 80), ishFinish));

	return mapData;
}

MapData loadMapaZima(RenderWindow& window)
{
	MapData mapData;

	SDL_Texture* groundTexture = window.loadTexture("Resources/snieg.png");
	SDL_Texture* obstacleSquareTexture = window.loadTexture("Resources/obstacle.png");
	SDL_Texture* obstacleTriangleTexture = window.loadTexture("Resources/killers.png");
	SDL_Texture* starTexture = window.loadTexture("Resources/gwiazdka.png");
	SDL_Texture* finFinish = window.loadTexture("Resources/fin.png");
	SDL_Texture* ishFinish = window.loadTexture("Resources/ish.png");
	mapData.backgroundTexture = window.loadTexture("Resources/tlo_zima.png");

	float groundTileWidth = 30.0f;
	int numGroundTiles = 85;

	for (int i = 0; i < numGroundTiles; ++i)
	{
		float xPos = i * groundTileWidth;
		mapData.groundTiles.push_back(GameObject(Vector2f(xPos, 200), groundTexture));
	}

	mapData.obstacleSquare.push_back(GameObject(Vector2f(210, 170), obstacleSquareTexture));
	mapData.obstacleSquare.push_back(GameObject(Vector2f(300, 170), obstacleSquareTexture));
	mapData.obstacleSquare.push_back(GameObject(Vector2f(330, 140), obstacleSquareTexture));
	mapData.obstacleSquare.push_back(GameObject(Vector2f(420, 140), obstacleSquareTexture));
	mapData.obstacleSquare.push_back(GameObject(Vector2f(420, 170), obstacleSquareTexture));
	mapData.obstacleSquare.push_back(GameObject(Vector2f(450, 110), obstacleSquareTexture));
	mapData.obstacleSquare.push_back(GameObject(Vector2f(540, 140), obstacleSquareTexture));
	mapData.obstacleSquare.push_back(GameObject(Vector2f(660, 170), obstacleSquareTexture));
	mapData.obstacleSquare.push_back(GameObject(Vector2f(780, 140), obstacleSquareTexture));
	mapData.obstacleSquare.push_back(GameObject(Vector2f(810, 140), obstacleSquareTexture));
	mapData.obstacleSquare.push_back(GameObject(Vector2f(840, 140), obstacleSquareTexture));
	mapData.obstacleSquare.push_back(GameObject(Vector2f(960, 170), obstacleSquareTexture));
	mapData.obstacleSquare.push_back(GameObject(Vector2f(1020, 170), obstacleSquareTexture));
	mapData.obstacleSquare.push_back(GameObject(Vector2f(1080, 170), obstacleSquareTexture));
	mapData.obstacleSquare.push_back(GameObject(Vector2f(1110, 140), obstacleSquareTexture));
	mapData.obstacleSquare.push_back(GameObject(Vector2f(1140, 170), obstacleSquareTexture));
	mapData.obstacleSquare.push_back(GameObject(Vector2f(1140, 140), obstacleSquareTexture));
	mapData.obstacleSquare.push_back(GameObject(Vector2f(1230, 110), obstacleSquareTexture));
	mapData.obstacleSquare.push_back(GameObject(Vector2f(1260, 110), obstacleSquareTexture));
	mapData.obstacleSquare.push_back(GameObject(Vector2f(1410, 50), obstacleSquareTexture));
	mapData.obstacleSquare.push_back(GameObject(Vector2f(1410, 140), obstacleSquareTexture));
	mapData.obstacleSquare.push_back(GameObject(Vector2f(1440, 50), obstacleSquareTexture));
	mapData.obstacleSquare.push_back(GameObject(Vector2f(1440, 140), obstacleSquareTexture));
	mapData.obstacleSquare.push_back(GameObject(Vector2f(1440, 170), obstacleSquareTexture));
	mapData.obstacleSquare.push_back(GameObject(Vector2f(1470, 50), obstacleSquareTexture));
	mapData.obstacleSquare.push_back(GameObject(Vector2f(1500, 80), obstacleSquareTexture));
	mapData.obstacleSquare.push_back(GameObject(Vector2f(1530, 80), obstacleSquareTexture));
	mapData.obstacleSquare.push_back(GameObject(Vector2f(1560, 110), obstacleSquareTexture));
	mapData.obstacleSquare.push_back(GameObject(Vector2f(1560 + 180, 170), obstacleSquareTexture));
	mapData.obstacleSquare.push_back(GameObject(Vector2f(1560 + 360, 170), obstacleSquareTexture));
	mapData.obstacleSquare.push_back(GameObject(Vector2f(1560 + 360, 140), obstacleSquareTexture));
	mapData.obstacleSquare.push_back(GameObject(Vector2f(1560 + 300, 140), obstacleSquareTexture));
	mapData.obstacleSquare.push_back(GameObject(Vector2f(1560 + 300, 170), obstacleSquareTexture));
	mapData.obstacleSquare.push_back(GameObject(Vector2f(1590 + 360, 110), obstacleSquareTexture));
	mapData.obstacleSquare.push_back(GameObject(Vector2f(1590 + 390, 110), obstacleSquareTexture));
	mapData.obstacleSquare.push_back(GameObject(Vector2f(1590 + 390, 140), obstacleSquareTexture));
	mapData.obstacleSquare.push_back(GameObject(Vector2f(1560 + 450, 170), obstacleSquareTexture));

	

	mapData.obstacleTriangle.push_back(GameObject(Vector2f(300, 140.2), obstacleTriangleTexture));
	mapData.obstacleTriangle.push_back(GameObject(Vector2f(420, 110.2), obstacleTriangleTexture));
	mapData.obstacleTriangle.push_back(GameObject(Vector2f(570, 140.2), obstacleTriangleTexture));
	mapData.obstacleTriangle.push_back(GameObject(Vector2f(630, 170.2), obstacleTriangleTexture));
	mapData.obstacleTriangle.push_back(GameObject(Vector2f(780, 110.2), obstacleTriangleTexture));
	mapData.obstacleTriangle.push_back(GameObject(Vector2f(810, 110.2), obstacleTriangleTexture));
	mapData.obstacleTriangle.push_back(GameObject(Vector2f(840, 110.2), obstacleTriangleTexture));
	mapData.obstacleTriangle.push_back(GameObject(Vector2f(960, 155.2), obstacleTriangleTexture));
	mapData.obstacleTriangle.push_back(GameObject(Vector2f(1050, 170.2), obstacleTriangleTexture));
	mapData.obstacleTriangle.push_back(GameObject(Vector2f(1080, 140.2), obstacleTriangleTexture));
	mapData.obstacleTriangle.push_back(GameObject(Vector2f(1200, 110.2), obstacleTriangleTexture));
	mapData.obstacleTriangle.push_back(GameObject(Vector2f(1290, 110.2), obstacleTriangleTexture));
	mapData.obstacleTriangle.push_back(GameObject(Vector2f(1320, 110.2), obstacleTriangleTexture));
	mapData.obstacleTriangle.push_back(GameObject(Vector2f(1470, 170.2), obstacleTriangleTexture));
	mapData.obstacleTriangle.push_back(GameObject(Vector2f(1560 + 240, 170.2), obstacleTriangleTexture));
	mapData.obstacleTriangle.push_back(GameObject(Vector2f(1560 + 270, 170.2), obstacleTriangleTexture));
	mapData.obstacleTriangle.push_back(GameObject(Vector2f(1560 + 360, 110.2), obstacleTriangleTexture));
	mapData.obstacleTriangle.push_back(GameObject(Vector2f(1560 + 450, 140.2), obstacleTriangleTexture));

	mapData.stars.push_back(GameObject(Vector2f(450, 80), starTexture));
	mapData.stars.push_back(GameObject(Vector2f(660, 140), starTexture));
	mapData.stars.push_back(GameObject(Vector2f(1230, 80), starTexture));

	mapData.finish.push_back(GameObject(Vector2f(2100, 80), finFinish));
	mapData.finish.push_back(GameObject(Vector2f(2130, 80), ishFinish));

	return mapData;
}