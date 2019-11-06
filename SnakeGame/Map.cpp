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
		virtual CompletedMap makeShape(int height,int width) = 0;
};

class MakeMapSquare:public Shape,private HorizontalLines,private VerticalLines
{
	public:
		CompletedMap map;
		CompletedMap makeShape(int height,int width) {
			makeSquare(height, width);
			return map;
		};
	private:
		void makeSquare(int height, int width) {
			map.finishedMap.append(generateHorizontalLines(width));
			map.finishedMap.append(generateVerticalLine(height,width));
			map.finishedMap.append(generateHorizontalLines(width));
		};
};

CompletedMap MapGenerator::makemap(int heightInput, int widthInput) {
	MakeMapSquare squareMap;
	CompletedMap generatedMap;
	generatedMap = squareMap.makeShape(heightInput,widthInput);
	return generatedMap;
};