#include "Header.h"
#include <iostream>
#include <string>

using namespace Map;
using namespace std;

class HorizontalLines
{
	public:
		string horizontalLineSymbol = "#";
	protected:
		void generateHorizontalLines(int width, CompletedMap *map) {
			for (int i = 0; i < width; i++)
			{
				map->finishedMap.append(horizontalLineSymbol);
			}
			map->finishedMap.append("\n");
		}
};

class VerticalLines
{
	public:
		string verticalLinesSymbol = "#";
		string whiteSpace = " ";
	protected:
		void generateVerticalLine(int hieght, int width,CompletedMap *map) {
			for (int i = 0; i < hieght; i++)
			{
				for (int j = 0; j < width; j++)
				{
					if (j == 0 || j == (width - 1)) {
						map->finishedMap.append(verticalLinesSymbol);
					}
					else
					{
						map->finishedMap.append(whiteSpace);
					}
				}
				map->finishedMap.append("\n");
			}
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
			generateHorizontalLines(width,map);
			generateVerticalLine(height,width,map);
			generateHorizontalLines(width,map);
		};
};

void MapGenerator::makemap(CompletedMap *map) {
	MakeMapSquare squareMap;
	squareMap.makeShape(map->mapHeight, map->mapLength,map);
};