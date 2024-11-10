#pragma once
#include <vector>
#include "GameObject.h"
#include "WindowManager.h"

struct MapData {
	SDL_Texture* backgroundTexture;
	std::vector<GameObject> obstacleSquare;
	std::vector<GameObject> obstacleTriangle;
	std::vector<GameObject> groundTiles;
	std::vector<GameObject> finish;
};

MapData loadMapaLato(RenderWindow& window);
MapData loadMapaZima(RenderWindow& window);
MapData loadMapaJesien(RenderWindow& window);