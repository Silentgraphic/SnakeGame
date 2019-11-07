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

	class MapGenerator
	{
	public:
		void makemap(CompletedMap *map);
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

	//class used to build snake elements
	class SnakeGenerator
	{
	public:
		void makeSnake(SnakeComplete *finishedSnake);
	};
}