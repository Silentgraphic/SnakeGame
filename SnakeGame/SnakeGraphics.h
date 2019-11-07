#pragma once
#include <string>
#include "Header.h"
namespace MapGraphics {
	class MapGenerator
	{
	public:
		void makemap(Map::CompletedMap* map);
	};
	class PrintMapToConsole
	{
	public:
		void printToConsole(Map::CompletedMap* map);
	};
}

namespace SnakeGraphics {
	class SnakeGenerator
	{
	public:
		void makeSnake(Snake::SnakeComplete* finishedSnake);
	};

	class PrintSnakeToConsole
	{
	public:
		void printToConsole(Snake::SnakeComplete* finishedSnake);
	};
}