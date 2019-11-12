#include "Header.h"
#include "SnakeGraphics.h"
#include "GameLogic.h"
#include <iostream>
#include <string>

using namespace std;



class GetMapData
{
	public:
		Map::CompletedMap mapData;
		GetMapData() {
			mapData.mapHeight = 10;
			mapData.mapLength = 10;
			mapData.finishedMap = new string[mapData.mapHeight+1];
		};
};

class GetSnakeData
{
	public:
		Snake::SnakeComplete snakeData;
		GetSnakeData() {
			snakeData.posX = 1;
			snakeData.posY = 1;
			snakeData.snakeLength = 3;
		};
};

class GenerateGraphics:public MapGraphics::MapGenerator, SnakeGraphics::SnakeGenerator
{
	public:
		GenerateGraphics(Snake::SnakeComplete* snake,Map::CompletedMap* map) {
			makemap(map);
			makeSnake(snake);
		};
};

class LoacateSnakeOnMap
{
	public:
		void loacateSnakeOnMap(Snake::SnakeComplete* snake,Map::CompletedMap* map) {
			for (int i = 0; i < snake->snakeLength+1; i++)
			{
				map->finishedMap[snake->posY][snake->posX] = snake->finsishedSnake[i];
				snake->posX++;
			}
		};
};

class PrintFrame:public LoacateSnakeOnMap
{
	public:
		PrintFrame(Snake::SnakeComplete* snake, Map::CompletedMap* map) {
			loacateSnakeOnMap(snake, map);
			for(int i = 0; i < map->mapHeight; i++)
			{
				cout << map->finishedMap[i] << endl;
			}
		};
};

void MainLoop::StartGame::run() {
	GetSnakeData snakeData;
	GetMapData mapData;
	GenerateGraphics(&snakeData.snakeData, &mapData.mapData);
	PrintFrame(&snakeData.snakeData,&mapData.mapData);
};
