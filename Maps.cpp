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

	mapData.obstacleTriangle.push_back(GameObject(Vector2f(240, 170.2), obstacleTriangleTexture));
	mapData.obstacleTriangle.push_back(GameObject(Vector2f(270, 170.2), obstacleTriangleTexture));
	mapData.obstacleTriangle.push_back(GameObject(Vector2f(360, 110.2), obstacleTriangleTexture));
	mapData.obstacleTriangle.push_back(GameObject(Vector2f(450, 140.2), obstacleTriangleTexture));
	mapData.obstacleTriangle.push_back(GameObject(Vector2f(480, 140.2 - 0.4), obstacleTriangleTexture));

	mapData.stars.push_back(GameObject(Vector2f(180, 140), starTexture));
	mapData.stars.push_back(GameObject(Vector2f(680, 140), starTexture));
	mapData.stars.push_back(GameObject(Vector2f(1230, 80), starTexture));

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