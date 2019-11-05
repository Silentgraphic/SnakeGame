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
		virtual void makeShape(int height,int width) = 0;
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
		void makeShape(int height,int width) {
			makeSquare(height, width);
		};
		string finishedSquareMap;
	private:
		void makeSquare(int height, int width) {
			finishedSquareMap.append(makeTopAndBottomOfMap(width));
			finishedSquareMap.append(makeSidesOfMap(height,width));
			finishedSquareMap.append(makeTopAndBottomOfMap(width));
		};
};

string MapGenerator::makemap(int heightInput, int widthInput) {
	MakeMapSquare squareMap;
	squareMap.setHeightAndWidth(heightInput, widthInput);
	squareMap.makeShape(heightInput,widthInput);
	return squareMap.finishedSquareMap;
};