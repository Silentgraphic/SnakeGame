#include "Header.h"
#include <iostream>
#include <string>

using namespace Map;
using namespace std;

class HorizontalLines
{
	protected:
		string generateHorizontalLines(int width) {
			string horizontalLine;
			for (int i = 0; i < width; i++)
			{
				horizontalLine.append("#");
			}
			horizontalLine.append("\n");
			return horizontalLine;
		}
};

class VerticalLines
{
	protected:
		string generateVerticalLine(int hieght, int width) {
			string verticalLines;
			for (int i = 0; i < hieght; i++)
			{
				for (int j = 0; j < width; j++)
				{
					if (j == 0 || j == (width - 1)) {
						verticalLines.append("#");
					}
					else
					{
						verticalLines.append(" ");
					}
				}
				verticalLines.append("\n");
			}
			return verticalLines;
		}
};

class Shape 
{
	public:
		virtual void makeShape(int height,int width, CompletedMap *map) = 0;
};

class MakeMapSquare:public Shape,private HorizontalLines,private VerticalLines
{
	public:
		void makeShape(int height,int width, CompletedMap *map) {
			makeSquare(height, width,map);
		};
	private:
		void makeSquare(int height, int width, CompletedMap *map) {
			map->finishedMap.append(generateHorizontalLines(width));
			map->finishedMap.append(generateVerticalLine(height,width));
			map->finishedMap.append(generateHorizontalLines(width));
		};
};

void MapGenerator::makemap(CompletedMap *map) {
	MakeMapSquare squareMap;
	squareMap.makeShape(map->mapHeight, map->mapLength,map);
};