#include "Header.h"
#include "SnakeGraphics.h"
#include "GameLogic.h"
#include <iostream>
#include <string>

using namespace std;

class Frame
{
	public:
		string frame;
		int snakePosx;
		int snakePosY;
};

class snakePos 
{
	public:
		void findSnakePosY(Snake::SnakeComplete* snake, Map::CompletedMap* map) {
			snake->posY *= map->mapLength+1;
		};
		void findSnakePosX(Snake::SnakeComplete* snake, Map::CompletedMap* map) {
			snake->posX = map->mapLength+1;
		};
};

class LoacateSnakeOnMap:public snakePos
{
	public:
		void snakeLocator(Snake::SnakeComplete* snake,Map::CompletedMap* map, Frame* frame) {
			findSnakePosY(snake, map);
			findSnakePosX(snake, map);
			for (int i = 0, pos = 0; i < (snake->snakeLength) + 1; i++)
			{
				pos = snake->posX + snake->posY;
				frame->frame[pos + i] = snake->finsishedSnake[i];
			}
		};
};

class GetMapData
{
	public:
		Map::CompletedMap mapData;
		GetMapData() {
			mapData.mapHeight = 10;
			mapData.mapLength = 10;
		};
};

class GetSnakeData
{
	public:
		Snake::SnakeComplete snakeData;
		GetSnakeData() {;
			snakeData.posX = 10;
			snakeData.posY = 10;
			snakeData.snakeLength = 3;
		};
};

class GenerateGraphics
{
	private:
		MapGraphics::MapGenerator mapMaker;
		SnakeGraphics::SnakeGenerator snakeMaker;
	public:
		void generateGraphics(Snake::SnakeComplete* snake,Map::CompletedMap* map) {
			mapMaker.makemap(map);
			snakeMaker.makeSnake(snake);
		};
};

void MainLoop::StartGame::run() {
	GenerateGraphics graphics;
	GetSnakeData snakeData;
	GetMapData mapData;
	graphics.generateGraphics(&snakeData.snakeData, &mapData.mapData);
};
