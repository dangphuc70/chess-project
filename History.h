#pragma once
#include "Move.h"
#include <vector>
#include <iostream>

using namespace std;
class History
{
	friend ostream& operator<<(ostream& o, const History& h);
	friend istream& operator>>(istream& i, History& h);
public:
	History();
	~History();

	void clear();
	const Move& LastMove() const;
	void Add(const Move& m);

private:
	vector<Move> history_;
};

