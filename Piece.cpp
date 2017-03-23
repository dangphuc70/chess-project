#include "Piece.h"



Piece::Piece(const std::string& _Symbol, PieceOut::Color _Color) : symbol(_Symbol), colr(_Color)
{
}


Piece::~Piece()
{
}

PieceOut::Color Piece::color()
{
	return colr;
}

const std::string & Piece::Symbol()
{
	return symbol;
}

size_t Piece::SymbolLength()
{
	return symbol.length();
}
