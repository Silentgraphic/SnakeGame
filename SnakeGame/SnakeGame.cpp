#include "Header.h"
#include "SnakeGraphics.h"
#include <iostream>
#include <string>

using namespace Map;
using namespace std;
using namespace Snake;

int main()
{ 
	CompletedMap maybeMap; 
	SnakeComplete maybeSnake;
	maybeSnake.snakeLength = 5;
	std:cin >> maybeMap.mapHeight >> maybeMap.mapLength;
	MapGraphics::MapGenerator testing;
	SnakeGraphics::SnakeGenerator testing2;
	testing.makemap(&maybeMap);
	testing2.makeSnake(&maybeSnake);
	std::cout << maybeMap.finishedMap << std::endl << maybeSnake.finsishedSnake << std::endl;
}
