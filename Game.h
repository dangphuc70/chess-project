#pragma once
#include "Board.h"
#include "Piece.h"
#include "PieceBox.h"
#include <vector>
#include "Move.h"

class Game
{
public:
	Game(int c_h=3, int c_w=7);
	~Game();

public:
	int numberOfTurn();
	const string & Turn();
	const Move& LastMove() const;

public:
	bool save(const string filename);
	bool load(const string filename);

private:
	bool turn; // true : black, false : white
	int nturn;
	PieceBox box;
	Board board;
	std::unique_ptr<std::string> b_map[Board::chess_board_size_first][Board::chess_board_size_second];

	std::vector<Move> history;

public:
	bool place(const Coordinate& destination, std::unique_ptr<Piece>& _Piece, std::unique_ptr<std::string>& _CommonName);
	bool place(const Coordinate& destination, const std::string & _CommonName);
	bool validate_move(const Coordinate& source, const Coordinate& destination);
	bool move(const Coordinate& source, const Coordinate& destination);
	void draw();
	void clear();
	Coordinate to_coordinate(char letter, int number);

private:
	int cell_height; // for text render
	int cell_width; // for text render
	bool black_cell(const Coordinate& coor);

private:
	const string turnBlack = "black";
	const string turnWhite = "white";
	bool PieceOnStraightPath(const Coordinate& start, const Coordinate& end);
	bool PieceOnDiagonalPath(const Coordinate& start, const Coordinate& end);
};

