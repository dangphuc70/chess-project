#pragma once

#include "MoveValidator.h"
#include <map>

class Rules
{
public:
	Rules();
	~Rules();

	const MoveValidator * find(const std::string &key) const;
private:
	std::map<std::string, MoveValidator*> validators;
};

