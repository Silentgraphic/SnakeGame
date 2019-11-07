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
};

class snakePos 
{
	public:
		void findSnakePosY(Snake::SnakeComplete* snake, Map::CompletedMap* map) {
			snake->posY *= map->mapLength+1;
		};
};

class LoacateSnakeOnMap:public Frame, public snakePos 
{
	public:
	void snakeLocator(Snake::SnakeComplete* snake, Map::CompletedMap* map) {
		frame = map->finishedMap;
		findSnakePosY(snake, map);
		for (int i = 0; i < (snake->snakeLength)+1; i++)
		{ 
			frame[(snake->posX+snake->posY)+i] = snake->finsishedSnake[i];
		}
		cout << frame << endl;
	};
};

void MainLoop::StartGame::run() {
	Map::CompletedMap mapObject;
	Snake::SnakeComplete snakeObject;
	snakeObject.posX = 1;
	snakeObject.posY = 1;
	snakeObject.snakeLength = 3;
	mapObject.mapHeight = 10;
	mapObject.mapLength = 10;
	MapGraphics::MapGenerator mapGenerator;
	SnakeGraphics::SnakeGenerator snakeGenerator;
	mapGenerator.makemap(&mapObject);
	snakeGenerator.makeSnake(&snakeObject);
	LoacateSnakeOnMap findPos;
	findPos.snakeLocator(&snakeObject, &mapObject);
};
