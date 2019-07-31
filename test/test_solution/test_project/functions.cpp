#include "pch.h"
#include "functions.h"

template <typename T>
std::string ToString(T tX)
{
	std::ostringstream oStream;
	oStream << tX;
	return oStream.str();
}

template std::string ToString<int>(int);

void something(std::array<int, 3> &in)
{
	


}
