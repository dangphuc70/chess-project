#pragma once
#include <iostream>
#include <string>
using namespace std;
class Coordinate
{
	friend ostream& operator<<(ostream& o, const Coordinate& m);
	friend istream& operator>>(istream& i, Coordinate& m);
public:
	Coordinate(int x0=0, int y0=0);
	~Coordinate();

	string toCommonCoordinate() const;

	int x;
	int y;

	bool operator==(const Coordinate& _Second) const;
	bool operator!=(const Coordinate& _Second) const;
};

