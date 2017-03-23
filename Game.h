#pragma once
#include "Board.h"
#include "Piece.h"
#include "PieceBox.h"

class Game
{
public:
	Game(size_t c_h=3, size_t c_w=7);
	~Game();

public:
	int numberOfTurn();
	const string & Turn();

public:
	void save(const string filename);
	void load(const string filename);

private:
	bool turn; // true : black, false : white
	int nturn;
	PieceBox box;
	Board board;
	std::unique_ptr<std::string> b_map[Board::chess_board_size_first][Board::chess_board_size_second];
public:
	bool place(const Coordinate& destination, std::unique_ptr<Piece>& _Piece, std::unique_ptr<std::string>& _CommonName);
	bool place(const Coordinate& destination, const std::string & _CommonName);
	bool validate_move(const Coordinate& source, const Coordinate& destination);
	bool move(const Coordinate& source, const Coordinate& destination);
	void draw();
	void clear();
	Coordinate to_coordinate(char letter, size_t number);
private:
	size_t cell_height; // for text render
	size_t cell_width; // for text render
	bool black_cell(const Coordinate& coor);
	
};

