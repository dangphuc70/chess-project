#include "BlackRook.h"

BlackRook::BlackRook() : text_name("Black Rook"), symbol(" b-r ")
{
}

BlackRook::~BlackRook()
{
}

PieceOut::Color BlackRook::color()
{
	return PieceOut::black;
}

const std::string & BlackRook::name()
{
	return text_name;
}

const std::string & BlackRook::Symbol()
{
	return symbol;
}

size_t BlackRook::SymbolLength()
{
	return Symbol().length();
}
