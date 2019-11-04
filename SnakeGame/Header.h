#pragma once
#include <string>
namespace Map
{
	class mapGenerator
	{
	public:
		int sizeOfMap;
		std::string makemap(int perimeter);
	};
}