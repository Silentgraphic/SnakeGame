#include "Header.h"
#include <iostream>
#include <string>

using namespace Map;
using namespace std;

int main()
{
	MapGenerator testing;
	int x,y; 
	std:cin >> x >> y;
	string maybeMap = testing.makemap(x,y);
	std::cout << maybeMap << std::endl;
}
