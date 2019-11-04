#include "Header.h"
#include <iostream>
#include <string>

using namespace Map;
using namespace std;

int main()
{
	mapGenerator testing;
	int x; 
	std:cin >> x;
	string maybeMap = testing.makemap(x);
	std::cout << maybeMap << std::endl;
}
