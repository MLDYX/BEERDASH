#include "Maps.h"

MapData loadMapaLato(RenderWindow& window)
{
	MapData mapData;

	SDL_Texture* groundTexture = window.loadTexture("Resources/trawa.png");
	SDL_Texture* obstacleSquareTexture = window.loadTexture("Resources/obstacle.png");
	SDL_Texture* obstacleTriangleTexture = window.loadTexture("Resources/killers.png");
	SDL_Texture* finFinish = window.loadTexture("Resources/fin.png");
	SDL_Texture* ishFinish = window.loadTexture("Resources/ish.png");
	mapData.backgroundTexture = window.loadTexture("Resources/tlo_lato.png");

	float groundTileWidth = 30.0f;
	int numGroundTiles = 160;

	for (int i = 0; i < numGroundTiles; ++i)
	{
		float xPos = i * groundTileWidth;
		mapData.groundTiles.push_back(GameObject(Vector2f(xPos, 200), groundTexture));
	}

	mapData.obstacleSquare.push_back(GameObject(Vector2f(180, 170), obstacleSquareTexture));
	mapData.obstacleSquare.push_back(GameObject(Vector2f(300, 140), obstacleSquareTexture));
	mapData.obstacleSquare.push_back(GameObject(Vector2f(360, 110), obstacleSquareTexture));
	mapData.obstacleSquare.push_back(GameObject(Vector2f(390, 110), obstacleSquareTexture));
	mapData.obstacleSquare.push_back(GameObject(Vector2f(420, 140), obstacleSquareTexture));
	mapData.obstacleSquare.push_back(GameObject(Vector2f(420, 170), obstacleSquareTexture));
	mapData.obstacleSquare.push_back(GameObject(Vector2f(450, 110), obstacleSquareTexture));
	mapData.obstacleSquare.push_back(GameObject(Vector2f(480, 110), obstacleSquareTexture));
	mapData.obstacleSquare.push_back(GameObject(Vector2f(480, 110), obstacleSquareTexture));
	mapData.obstacleSquare.push_back(GameObject(Vector2f(600, 110), obstacleSquareTexture));
	mapData.obstacleSquare.push_back(GameObject(Vector2f(630, 110), obstacleSquareTexture));
	mapData.obstacleSquare.push_back(GameObject(Vector2f(660, 110), obstacleSquareTexture));
	mapData.obstacleSquare.push_back(GameObject(Vector2f(180 + 600, 170), obstacleSquareTexture));
	mapData.obstacleSquare.push_back(GameObject(Vector2f(300 + 600, 140), obstacleSquareTexture));
	mapData.obstacleSquare.push_back(GameObject(Vector2f(360 + 600, 110), obstacleSquareTexture));
	mapData.obstacleSquare.push_back(GameObject(Vector2f(390 + 600, 110), obstacleSquareTexture));
	mapData.obstacleSquare.push_back(GameObject(Vector2f(420 + 600, 140), obstacleSquareTexture));
	mapData.obstacleSquare.push_back(GameObject(Vector2f(420 + 600, 170), obstacleSquareTexture));
	mapData.obstacleSquare.push_back(GameObject(Vector2f(450 + 600, 110), obstacleSquareTexture));
	mapData.obstacleSquare.push_back(GameObject(Vector2f(480 + 600, 110), obstacleSquareTexture));
	mapData.obstacleSquare.push_back(GameObject(Vector2f(480 + 600, 110), obstacleSquareTexture));
	mapData.obstacleSquare.push_back(GameObject(Vector2f(600 + 600, 110), obstacleSquareTexture));
	mapData.obstacleSquare.push_back(GameObject(Vector2f(630 + 600, 110), obstacleSquareTexture));
	mapData.obstacleSquare.push_back(GameObject(Vector2f(660 + 600, 110), obstacleSquareTexture));
	mapData.obstacleSquare.push_back(GameObject(Vector2f(180 + 600 + 600, 170), obstacleSquareTexture));
	mapData.obstacleSquare.push_back(GameObject(Vector2f(300 + 600 + 600, 140), obstacleSquareTexture));
	mapData.obstacleSquare.push_back(GameObject(Vector2f(360 + 600 + 600, 110), obstacleSquareTexture));
	mapData.obstacleSquare.push_back(GameObject(Vector2f(390 + 600 + 600, 110), obstacleSquareTexture));
	mapData.obstacleSquare.push_back(GameObject(Vector2f(420 + 600 + 600, 140), obstacleSquareTexture));
	mapData.obstacleSquare.push_back(GameObject(Vector2f(420 + 600 + 600, 170), obstacleSquareTexture));
	mapData.obstacleSquare.push_back(GameObject(Vector2f(450 + 600 + 600, 110), obstacleSquareTexture));
	mapData.obstacleSquare.push_back(GameObject(Vector2f(480 + 600 + 600, 110), obstacleSquareTexture));
	mapData.obstacleSquare.push_back(GameObject(Vector2f(480 + 600 + 600, 110), obstacleSquareTexture));
	mapData.obstacleSquare.push_back(GameObject(Vector2f(600 + 600 + 600, 110), obstacleSquareTexture));
	mapData.obstacleSquare.push_back(GameObject(Vector2f(630 + 600 + 600, 110), obstacleSquareTexture));

	mapData.obstacleTriangle.push_back(GameObject(Vector2f(240, 170.2), obstacleTriangleTexture));
	mapData.obstacleTriangle.push_back(GameObject(Vector2f(270, 170.2), obstacleTriangleTexture));

	mapData.finish.push_back(GameObject(Vector2f(4220, 80), finFinish));
	mapData.finish.push_back(GameObject(Vector2f(4250, 80), ishFinish));

	return mapData;
}