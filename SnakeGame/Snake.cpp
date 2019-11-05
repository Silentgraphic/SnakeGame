#include "Header.h"
#include <iostream>
#include <string>

using namespace Snake;
using namespace std;

class SnakeBody
{
	protected:
		string snakeBodyGenerator() {
			string snakeBody;
			for (int i = 0; i < 5; i++)
			{
				snakeBody.append("o");
			}
			return snakeBody;
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
		string finishedSnake;
	public:
		void generateFinishedSnake() {
			finishedSnake.append(snakeBodyGenerator());
			finishedSnake.append(getSnakeHead());
		};
		string getFinishedSnake() {
			return finishedSnake;
		};
};

string SnakeGenerator::makeSnake() {
	SnakeMaker snake;
	snake.generateFinishedSnake();
	return snake.getFinishedSnake();
};