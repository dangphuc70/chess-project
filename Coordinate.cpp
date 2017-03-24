#include "Coordinate.h"
#include <sstream>
#include <iostream>

using namespace std;



Coordinate::Coordinate(int x0, int y0) : x(x0), y(y0)
{
}

Coordinate::~Coordinate()
{
}

string Coordinate::toCommonCoordinate() const
{
	// this assumes 1 <= x,y <= 7
	char a[3] = {'a'+x , '0' + 8 - y, 0};

	return string(a);
}

bool Coordinate::operator==(const Coordinate & _Second) const
{
	return !(*this != _Second);
}

bool Coordinate::operator!=(const Coordinate & _Second) const
{
	return (x != _Second.x) || (y != _Second.y);;
}

ostream & operator<<(ostream & o, const Coordinate & m)
{
	o << m.x;
	o << ' ';
	o << m.y;
	return o;
}

istream & operator >> (istream & i, Coordinate & m)
{
	i >> m.x;
	i >> m.y;
	return i;
}
