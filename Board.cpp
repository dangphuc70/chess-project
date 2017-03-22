#include "Board.h"



Board::Board()
{
}


Board::~Board()
{
}

std::unique_ptr<Piece>& Board::operator[](const Coordinate & at) // unchecked invalid Coordinate
{
	return board[at.x][at.y];
}

bool Board::validate_move(const Coordinate & s, const Coordinate & d)
{
	Board &b = *this;
	if (!valid_coordinate(s) || !valid_coordinate(d)) {
		return false;
	}
	else if (b[s] == nullptr) {
		return false;
	}
	else if (s == d) {
		return false;
	}
	else if (b[d] == nullptr) {
		return true;
	}
	else if (b[d]->color() == b[s]->color()) {
		return false;
	}
	
	return true;
}

bool Board::valid_coordinate(const Coordinate & coor)
{
	return (coor.x >= 0 && coor.x < chess_board_size_first)
		&& (coor.y >= 0 && coor.y < chess_board_size_second);
}
