#include "Header.h"
#include <iostream>
#include <string>

using namespace Map;
using namespace std;

class HorizontalLines
{
	protected:
		string makeTopAndBottomOfMap(int topAndBottomWidth) {
			string topAndBottom;
			for (int i = 0; i < topAndBottomWidth; i++)
			{
				topAndBottom.append("#");
			}
			topAndBottom.append("\n");
			return topAndBottom;
		}
};

class VerticalLines
{
	protected:
		string makeSidesOfMap(int hieghtOfSides, int widthOfWhiteSpace) {
			string sides;
			for (int i = 0; i < hieghtOfSides; i++)
			{
				for (int j = 0; j < widthOfWhiteSpace; j++)
				{
					if (j == 0 || j == (widthOfWhiteSpace - 1)) {
						sides.append("#");
					}
					else
					{
						sides.append(" ");
					}
				}
				sides.append("\n");
			}
			return sides;
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
			map.finishedMap.append(makeTopAndBottomOfMap(width));
			map.finishedMap.append(makeSidesOfMap(height,width));
			map.finishedMap.append(makeTopAndBottomOfMap(width));
		};
};

CompletedMap MapGenerator::makemap(int heightInput, int widthInput) {
	MakeMapSquare squareMap;
	CompletedMap generatedMap;
	generatedMap = squareMap.makeShape(heightInput,widthInput);
	return generatedMap;
};