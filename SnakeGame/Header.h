#pragma once
#include <string>
namespace Map
{
	class CompletedMap 
	{
	public:
		std::string finishedMap;
		int mapHeight;
		int mapLength;
		std::string mapShape;
	};
}
namespace Snake
{
	//Finished snake class
	class SnakeComplete 
	{
	public:
		int snakeLength;
		std::string finsishedSnake;
	};
}