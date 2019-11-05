#include "Header.h"
#include <iostream>
#include <string>

using namespace Snake;
using namespace std;

class SnakeBody
{
	private:
		string snakeBody;
	protected:
		string snakeBodyGenerator() {
			string snakeBody;
			for (int i = 0; i < 5; i++)
			{
				snakeBody.append("o");
			}
			return snakeBody;
		};
		string getSnakeBody() {
			return snakeBody;
		}
};

class SnakeHead
{
	private:
		string snakeHead;
	protected:
		void snakeHeadGenerator() {
			snakeHead.append("0");
		};
		string getSnakeHead() {
			return snakeHead;
		};
};

class SnakeMaker: private SnakeBody, private SnakeHead
{
	private:
		string finishedSnake;
		SnakeComplete makeMeASnake;
	public:
		SnakeComplete generateFinishedSnake() {
			snakeBodyGenerator();
			snakeHeadGenerator();
			makeMeASnake.finsishedSnake.append(getSnakeBody());
			makeMeASnake.finsishedSnake.append(getSnakeHead());
			return makeMeASnake;
		};
};

SnakeComplete SnakeGenerator::makeSnake() {
	SnakeMaker snake;
	SnakeComplete completeSnake;
	completeSnake = snake.generateFinishedSnake();
	return completeSnake;
};