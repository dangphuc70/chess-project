#pragma once
#include "Board.h"
#include "Piece.h"

class Game
{
public:
	Game(size_t c_h=3, size_t c_w=5);
	~Game();

private:
	Board board;


public:
	bool place(const Coordinate& destination, Piece * piece);
	bool validate_move(const Coordinate& source, const Coordinate& destination);
	bool move(const Coordinate& source, const Coordinate& destination);
	void draw();

private:
	size_t cell_height; // for text render
	size_t cell_width; // for text render
	bool black_cell(const Coordinate& coor);
};

