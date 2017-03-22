#include "Coordinate.h"



Coordinate::Coordinate(size_t x0, size_t y0) : x(x0), y(y0)
{
}

Coordinate::~Coordinate()
{
}

bool Coordinate::operator==(const Coordinate & _Second) const
{
	return !(*this != _Second);
}

bool Coordinate::operator!=(const Coordinate & _Second) const
{
	return (x != _Second.x) || (y != _Second.y);;
}
