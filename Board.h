#pragma once
#include <memory>
#include "Piece.h"

#include "Interfaces.h"

class Board : public BoardOut
{
public:
	static const int chess_board_size_first = 8;
	static const int chess_board_size_second = 8;
private:
	std::unique_ptr<Piece> board[chess_board_size_first][chess_board_size_second];

public:
	Board();
	~Board();

public:
	std::unique_ptr<Piece> & operator[](const Coordinate& at);

	//BoardOut
	bool validate_move(const Coordinate& _sour, const Coordinate& _dest);

	bool valid_coordinate(const Coordinate& coor);
	
};

