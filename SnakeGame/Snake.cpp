#include "Header.h"
#include <iostream>
#include <string>

using namespace Snake;
using namespace std;

class SnakeBody
{
	private:
		string snakeBody;
		int snakeLength = 3;
	protected:
		void snakeBodyGenerator() {
			for (int i = 0; i < snakeLength; i++)
			{
				snakeBody.append("o");
			}
		};
		string getSnakeBody() {
			return snakeBody;
		};
		void setSnakeLength(int length) {
			snakeLength = length;
		};
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