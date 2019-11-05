#include "Header.h"
#include <iostream>
#include <string>

using namespace Map;
using namespace std;
using namespace Snake;

int main()
{
	int x,y; 
	std:cin >> x >> y;
	MapGenerator testing;
	SnakeGenerator testing2;
	CompletedMap maybeMap = testing.makemap(x,y);
	SnakeComplete makeMeASnake = testing2.makeSnake();
	std::cout << maybeMap.finishedMap << std::endl << makeMeASnake.finsishedSnake << std::endl;
}
