#include "Header.h"
#include <iostream>
#include <string>

using namespace Map;
using namespace std;

class MakeTopAndBottomOfMap
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

class MakeSidesOfMap
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

class MakeMapSquare:private MakeTopAndBottomOfMap,private MakeSidesOfMap 
{
	private:
		string squareMap;
		void make(int perimeter) {
			squareMap.append(topAndBottom(perimeter));
			squareMap.append(sides(perimeter, perimeter));
			squareMap.append(topAndBottom(perimeter));
		};
	public:
		string makeMapSquare(int perimeter) {
			make(perimeter);
			return squareMap;
		};
};

string mapGenerator::makemap(int perimeter) {
	string finishedMap;
	MakeMapSquare squareMap;
	finishedMap = squareMap.makeMapSquare(perimeter);
	return finishedMap;
};