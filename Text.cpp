#include "Text.h"



Text::Text(std::string _Symbol) : symbol(_Symbol)
{
}


Text::~Text()
{
}

const std::string & Text::Symbol() const
{
	return symbol;
}

size_t Text::length() const
{
	return symbol.length();
}
