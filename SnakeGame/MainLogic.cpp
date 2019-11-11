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

class LoacateSnakeOnMap
{
	public:
		void loacateSnakeOnMap(Snake::SnakeComplete* snake,Map::CompletedMap* map, Frame* frame) {
			frame->frame = map->finishedMap;
			for (int i = 0, pos = 0; i < (snake->snakeLength) + 1; i++)
			{
				pos = snake->posX + (snake->posY * map->mapLength +1);
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
			snakeData.posX = 1;
			snakeData.posY = 1;
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
	GetSnakeData snakeData;
	GetMapData mapData;
	GenerateGraphics graphics;
	graphics.generateGraphics(&snakeData.snakeData, &mapData.mapData);
	Frame frame1;
	LoacateSnakeOnMap snakeLocation;
	for (int i = 0; i < 9; i++)
	{
		snakeLocation.loacateSnakeOnMap(&snakeData.snakeData, &mapData.mapData, &frame1);
		cout << frame1.frame << endl;
		snakeData.snakeData.posX += 1;
	}
};
