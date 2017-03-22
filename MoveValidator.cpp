#include "MoveValidator.h"



MoveValidator::MoveValidator(const std::string & _Id) : id(_Id)
{
}

MoveValidator::~MoveValidator()
{
}

const std::string & MoveValidator::identifier() const
{
	return id;
}