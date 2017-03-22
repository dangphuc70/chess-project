#pragma once
class Coordinate
{
public:
	Coordinate(size_t x0=0, size_t y0=0);
	~Coordinate();

	size_t x;
	size_t y;

	bool operator==(const Coordinate& _Second) const;
	bool operator!=(const Coordinate& _Second) const;
};

