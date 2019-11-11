#include "Header.h"
#include "SnakeGraphics.h"
#include <iostream>
#include <string>


using namespace Map;
using namespace std;

class HorizontalLines
{
	public:
		string horizontalLineSymbol = "#";
	protected:
		void generateHorizontalLines(int width, CompletedMap *map,int height) {
			for (int i = 0; i < width; i++)
			{
				map->finishedMap[i].append(horizontalLineSymbol);
			}
			map->finishedMap[width].append("\n");
		}
};

class VerticalLines
{
	public:
		string verticalLinesSymbol = "#";
		string whiteSpace = " ";
	protected:
		void generateVerticalLine(int width,CompletedMap *map,int height) {
			for (int j = 0; j < width; j++)
			{
				if (j == 0 || j == (width - 1)) {
					map->finishedMap[j].append(verticalLinesSymbol);
				}
				else
				{
					map->finishedMap[j].append(whiteSpace);
				}
			}
			map->finishedMap[width].append("\n");
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
			for (int i = 0; i <= height; i++)
			{
				if (i == 0|| i == height) {
					generateHorizontalLines(width, map,i);
				}
				else {
					generateVerticalLine(width, map,i);
				}
			}
		};
};

void MapGraphics::MapGenerator::makemap(CompletedMap *map) {
	MakeMapSquare squareMap;
	squareMap.makeShape(map->mapHeight, map->mapLength,map);
};

void MapGraphics::PrintMapToConsole::printToConsole(CompletedMap* map) {
	cout << map->finishedMap << endl;
};