#include "Header.h"
#include "SnakeGraphics.h"
#include "GameLogic.h"
#include <iostream>
#include <string>

void MainLoop::StartGame::run() {
	Map::CompletedMap mapObject;
	Snake::SnakeComplete snakeObject;
	snakeObject.snakeLength = 5;
	mapObject.mapHeight = 100;
	mapObject.mapLength = 100;
	MapGraphics::MapGenerator mapGenerator;
	SnakeGraphics::SnakeGenerator snakeGenerator;
	MapGraphics::PrintMapToConsole printMap;
	SnakeGraphics::PrintSnakeToConsole printSnake;
	mapGenerator.makemap(&mapObject);
	snakeGenerator.makeSnake(&snakeObject);
	printMap.printToConsole(&mapObject);
	printSnake.printToConsole(&snakeObject);
};
