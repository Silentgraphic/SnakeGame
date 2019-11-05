#include "Header.h"
#include <iostream>
#include <string>

using namespace Map;
using namespace std;

int main()
{
	MapGenerator testing;
	Snake::SnakeGenerator testing2;
	int x,y; 
	std:cin >> x >> y;
	string maybeMap = testing.makemap(x,y);
	string maybeSnake = testing2.makeSnake();
	std::cout << maybeMap << std::endl << maybeSnake << std::endl;
}
