#pragma once
#include "Coordinate.h"
#include <string>

class MoveValidator
{
public:
	MoveValidator(const std::string& _Id);
	~MoveValidator();

public:
	virtual bool validate_move(const Coordinate& _sour, const Coordinate& _dest) const = 0;
	const std::string & identifier() const;

private:
	std::string id;
};

