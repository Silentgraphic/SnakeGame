#pragma once
#include <string>
namespace Map
{
	class CompletedMap 
	{
	public:
		int mapHeight;
		int mapLength;
		std::string *finishedMap;
		std::string mapShape;
	};
}
namespace Snake
{
	class SnakeComplete 
	{
	public:
		int posX;
		int posY;
		int snakeLength;
		std::string finsishedSnake;
	};
}