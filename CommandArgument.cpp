#include "CommandArgument.h"
#include <sstream>
#include <ctype.h>

using namespace std;

CommandArgument::CommandArgument(const string & command, const char delim)
{
	string chunk;
	string chunk1, chunk2;
	istringstream comm(command);

	

	getline(comm, chunk, delim);
	if (chunk == "move") {
		type_ = move;
		getline(comm, chunk1, delim);
		getline(comm, chunk2, delim);
		if (chunk1.length() != 2 || chunk2.length() != 2)
			type_ = epsilon;
		else if (!isalpha(chunk1[0]) || !isalpha(chunk2[0])) {
			type_ = epsilon;
		}
		else if (!isdigit(chunk1[1]) || !isdigit(chunk2[1])) {
			type_ = epsilon;
		}
		else if (chunk1[0] < 'a' || chunk1[0] > 'h' || chunk2[0] < 'a' || chunk2[0] > 'h') {
			type_ = epsilon;
		}
		else if (chunk1[1] < '1' || chunk1[1] > '8' || chunk2[1] < '1' || chunk2[1] > '8') {
			type_ = epsilon;
		}
		else {
			from_ = Coordinate(chunk1[0] - 'a', 8 - (chunk1[1] - '0'));
			to_ = Coordinate(chunk2[0] - 'a', 8 - (chunk2[1] - '0'));
		}
		
	}
	else if (chunk == "show") {
		type_ = show;
		
	}
	else if (chunk == "new") {
		type_ = newgame;
	}
	else if (chunk == "save") {
		type_ = save;
		getline(comm, chunk1, delim);
		filename_ = chunk1;
	}
	else if (chunk == "load") {
		type_ = load;
		getline(comm, chunk1, delim);
		filename_ = chunk1;
	}
	else if (chunk == "help") {
		type_ = help;
	}
	else if (chunk == "quit") {
		type_ = quit;
	}
	else if (chunk.length() == 2) { // suspected shorthand move command : b2 b7
		type_ = move;
			getline(comm, chunk2, delim);

			if (chunk2.length() != 2)
				type_ = epsilon;
			else if (!isalpha(chunk[0]) || !isalpha(chunk2[0])) {
				type_ = epsilon;
			}
			else if (!isdigit(chunk[1]) || !isdigit(chunk2[1])) {
				type_ = epsilon;
			}
			else if (chunk[0] < 'a' || chunk[0] > 'h' || chunk2[0] < 'a' || chunk2[0] > 'h') {
				type_ = epsilon;
			}
			else if (chunk[1] < '1' || chunk[1] > '8' || chunk2[1] < '1' || chunk2[1] > '8') {
				type_ = epsilon;
			}
			else {
				from_ = Coordinate(chunk[0] - 'a', 8 - (chunk[1] - '0'));
				to_ = Coordinate(chunk2[0] - 'a', 8 - (chunk2[1] - '0'));
			}
	}
	else {
		type_ = epsilon;
	}
}


CommandArgument::~CommandArgument()
{
}

bool CommandArgument::available()
{
	return (type_ == epsilon) ? false : true;
}

CommandArgument::Type CommandArgument::type()
{
	return type_;
}

const string & CommandArgument::filename()
{
	if (type_ == save || type_ == load)
		return filename_;
	else return empty;
}

const Coordinate & CommandArgument::from()
{
	if (type_ == move)
		return from_;
	else
		return none;
}

const Coordinate & CommandArgument::to()
{
	if (type_ == move)
		return to_;
	else
		return none;
}
