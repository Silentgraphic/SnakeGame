#include "Header.h"
#include <iostream>
#include <string>

using namespace Map;
using namespace std;

class HorizontalLines
{
	public:
		string topAndBottom(int topAndBottomWidth) {
			string getTopAndBottom = makeTopAndBottomOfMap(topAndBottomWidth);
			return getTopAndBottom;
		};
	private:
		string makeTopAndBottomOfMap(int topAndBottomWidth) {
			string topAndBottom;
			for (int i = 0; i < topAndBottomWidth; i++)
			{
				topAndBottom.append("-");
			}
			topAndBottom.append("\n");
			return topAndBottom;
		}
};

class VerticalLines
{
	public:
		string sides(int hieghtOfSides, int widthOfWhiteSpace) {
			string getSides = makeSidesOfMap(hieghtOfSides, widthOfWhiteSpace);
			return getSides;
		};
	private:
		string makeSidesOfMap(int hieghtOfSides, int widthOfWhiteSpace) {
			string sides;
			for (int i = 0; i < hieghtOfSides; i++)
			{
				for (int j = 0; j < widthOfWhiteSpace; j++)
				{
					if (j == 0 || j == (widthOfWhiteSpace - 1)) {
						sides.append("|");
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
		virtual string makeShape(int height,int width) = 0;
		void setHeightAndWidth(int setHeight, int setWidth) {
			int height = setHeight;
			int width = setWidth;
		};
	protected:
		int height;
		int width;
};

class MakeMapSquare:public Shape,private HorizontalLines,private VerticalLines
{
	public:
		string makeShape(int height,int width) {
			makeSquare(height, width);
			return squareMap;
		};
	private:
		string squareMap;
		void makeSquare(int height, int width) {
			squareMap.append(topAndBottom(width));
			squareMap.append(sides(height,width));
			squareMap.append(topAndBottom(width));
		};
};

string mapGenerator::makemap(int heightInput, int widthInput) {
	string finishedMap;
	MakeMapSquare squareMap;
	squareMap.setHeightAndWidth(heightInput, widthInput);
	finishedMap = squareMap.makeShape(heightInput,widthInput);
	return finishedMap;
};