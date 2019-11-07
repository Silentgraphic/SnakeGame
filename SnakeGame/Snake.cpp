#include "Header.h"
#include "SnakeGraphics.h"
#include <iostream>
#include <string>

using namespace Snake;
using namespace std;

class SnakeBody
{
	protected:
		void snakeBodyGenerator(SnakeComplete *snakePointer) {
			for (int i = 0; i < snakePointer->snakeLength; i++)
			{
				snakePointer->finsishedSnake.append("o");
			}
		};
};


class SnakeHead
{
protected:
	void snakeHeadGenerator(SnakeComplete* snakePointer) {
		snakePointer->finsishedSnake.append("0");
	};
};

class SnakeMaker: private SnakeBody, private SnakeHead
{
	public:
		void generateFinishedSnake(SnakeComplete *snakePointer) {
			snakeBodyGenerator(snakePointer);
			snakeHeadGenerator(snakePointer);
		};
};

void SnakeGraphics::SnakeGenerator::makeSnake(SnakeComplete *finishedSnake) {
	SnakeMaker snake;
	snake.generateFinishedSnake(finishedSnake);
};