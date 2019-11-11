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
		void makeFrame(Map::CompletedMap* map) {
			for (int i = 0; i < map->mapHeight; i++)
			{
			}
		};
};

class LoacateSnakeOnMap
{
	public:
		void loacateSnakeOnMap(Snake::SnakeComplete* snake,Map::CompletedMap* map, Frame* frame) {
			
		};
};

class GetMapData
{
	public:
		Map::CompletedMap mapData;
		GetMapData() {
			mapData.mapHeight = 10;
			mapData.mapLength = 10;
			mapData.finishedMap = new std::string[mapData.mapHeight+1];
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
	Frame frame1;
	graphics.generateGraphics(&snakeData.snakeData, &mapData.mapData);
	LoacateSnakeOnMap snakeLocation;
};
