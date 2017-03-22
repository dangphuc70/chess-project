#include "SomeMoveValidators.h"

bool RookValidator::validate_move(const Coordinate& s, const Coordinate& d) const
{
	return false;
}

bool KnightValidator::validate_move(const Coordinate& s, const Coordinate& d) const
{
	return false;
}

bool BishopValidator::validate_move(const Coordinate& s, const Coordinate& d) const
{
	return false;
}

bool QueenValidator::validate_move(const Coordinate& s, const Coordinate& d) const
{
	return false;
}

bool KingValidator::validate_move(const Coordinate& s, const Coordinate& d) const
{
	return false;
}

bool PawnValidator::validate_move(const Coordinate& s, const Coordinate& d) const
{
	return false;
}

RookValidator::RookValidator() : MoveValidator("rook")
{
}

RookValidator::~RookValidator()
{
}

KnightValidator::KnightValidator() : MoveValidator("knight")
{
}

KnightValidator::~KnightValidator()
{
}

BishopValidator::BishopValidator() : MoveValidator("bishop")
{
}

BishopValidator::~BishopValidator()
{
}

QueenValidator::QueenValidator() : MoveValidator("queen")
{
}

QueenValidator::~QueenValidator()
{
}

KingValidator::KingValidator() : MoveValidator("king")
{
}

KingValidator::~KingValidator()
{
}

PawnValidator::PawnValidator() : MoveValidator("pawn")
{
}

PawnValidator::~PawnValidator()
{
}
