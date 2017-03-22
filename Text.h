#pragma once
#include <string>

class Text
{
public:
	Text(std::string _Symbol="");
	~Text();
public:
	const std::string & Symbol() const;
	size_t length() const;
	virtual void dummie() = 0;
private:
	std::string symbol;
};
