#pragma once
#include "Board.h"
#include "Piece.h"

class Game
{
public:
	Game(size_t c_h=3, size_t c_w=5);
	~Game();

public:
	void save(const char * filename);
	//void load(const string& filename);

private:
	Board board;
	std::unique_ptr<std::string> b_map[Board::chess_board_size_first][Board::chess_board_size_second];
public:
	bool place(const Coordinate& destination, std::unique_ptr<Piece>& _Piece, std::unique_ptr<std::string>& _CommonLanguage);
	bool validate_move(const Coordinate& source, const Coordinate& destination);
	bool move(const Coordinate& source, const Coordinate& destination);
	void draw();

private:
	size_t cell_height; // for text render
	size_t cell_width; // for text render
	bool black_cell(const Coordinate& coor);
};

