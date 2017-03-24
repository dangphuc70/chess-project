#include "History.h"
#include <sstream>


History::History()
{
}


History::~History()
{
}

void History::clear()
{
	history_.clear();
}

const Move & History::LastMove() const
{
	return *history_.rbegin();
}

void History::Add(const Move & m)
{
	history_.push_back(m);
}

ostream & operator<<(ostream & o, const History & h)
{
	for (auto i = h.history_.begin(); i != h.history_.end(); ++i) {
		o << *i << ' ';
	}
	o << endl;
	return o;
}

istream & operator >> (istream & i, History & h)
{
	// TODO: insert return statement here
	istringstream b;
	string l;
	getline(i, l);
	b.str(l);
	Move m;
	while (b) {
		b >> m;
		h.Add(m);
	}

	return i;

}
