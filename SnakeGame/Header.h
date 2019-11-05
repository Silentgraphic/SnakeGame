#pragma once
#include <string>
namespace Map
{
	class CompletedMap 
	{
	public:
		std::string finishedMap;
	};

	class MapGenerator
	{
	public:
		CompletedMap makemap(int height, int width);
	};
}
namespace Snake
{
	//Finished snake class
	class SnakeComplete 
	{
	public:
		std::string finsishedSnake;
	};

	//class used to build snake elements
	class SnakeGenerator
	{
	public:
		SnakeComplete makeSnake();
	};
}