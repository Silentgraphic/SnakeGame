#pragma once
#include <string>
namespace Map
{
	class MapGenerator
	{
	public:
		std::string makemap(int height, int width);
	};
}
namespace Snake
{
	class SnakeGenerator
	{
	public:
		std::string makeSnake();
	};
}