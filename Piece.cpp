#include "Piece.h"
#include <sstream>
#include <string>


Piece::Piece(PieceOut::Color _Color, const MoveValidator * _Validator, const std::string& _OnBoardSymbol)
	: color_code(_Color), validator_ptr(_Validator), onboardsymbol(_OnBoardSymbol)
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
		<< onboardsymbol << default_delim;
	return save.str();
}

const std::string & Piece::OnBoardSymbol()
{
	return onboardsymbol;
}

bool Piece::validate_move(const Coordinate & _sour, const Coordinate & _dest)
{
	if (validator_ptr == nullptr) return false;
	else return validator_ptr->validate_move(_sour, _dest);
}

PieceOut::Color Piece::color()
{
	return color_code;
}
