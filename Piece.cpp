#include "Piece.h"
#include <sstream>
#include <string>


Piece::Piece()
{
}



Piece::~Piece()
{
}

std::string Piece::toString()
{
	std::ostringstream save;
	save << color_code << default_delim
		<< validator_ptr->identifier() << default_delim
		<< symbol0 << default_delim
		<< name << default_delim;
	return save.str();
}

bool Piece::validate_move(const Coordinate & _sour, const Coordinate & _dest) const
{
	return validator_ptr->validate_move(_sour, _dest);
}

PieceOut::Color Piece::color()
{
	return color_code;
}

const std::string & Piece::name()
{
	return name0;
}

const std::string & Piece::Symbol()
{
	return symbol0;
}

size_t Piece::SymbolLength()
{
	return symbol0.length();
}
