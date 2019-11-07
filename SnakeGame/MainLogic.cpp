#include "Header.h"
#include "SnakeGraphics.h"
#include "GameLogic.h"
#include <iostream>
#include <string>

class StartGame 
{
	public:
		void run() {
			Map::CompletedMap mapObject;
			Snake::SnakeComplete snakeObject;
			snakeObject.snakeLength = 5;
			mapObject.mapHeight = 100;
			mapObject.mapLength = 100;
			MapGraphics::MapGenerator mapGenerator;
			SnakeGraphics::SnakeGenerator snakeGenerator;
			mapGenerator.makemap(&mapObject);
			snakeGenerator.makeSnake(&snakeObject);
		};
};