#pragma once
#include <string>
#include <vector>
#include "Coordinate.h"
using namespace std;

class CommandArgument
{
public:
	CommandArgument(const string & command, const char delim = ' ');
	~CommandArgument();

	enum Type { epsilon, move, show, newgame, save, load, help, quit };
	
	bool available();

	Type type();
	const string & filename();
	const Coordinate& from();
	const Coordinate& to();

	const string empty = "";
	const Coordinate none = { -1, -1 };

private:
	Type type_;
	string filename_;
	Coordinate from_;
	Coordinate to_;
	
};

