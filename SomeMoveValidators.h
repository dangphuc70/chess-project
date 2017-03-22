#pragma once

#include "MoveValidator.h"

class RookValidator : public MoveValidator
{
public:
	RookValidator();
	~RookValidator();
	//MoveValidator
	bool validate_move(const Coordinate& _sour, const Coordinate& _dest) const;
private:

};

class KnightValidator : public MoveValidator
{
public:
	KnightValidator();
	~KnightValidator();
	//MoveValidator
	bool validate_move(const Coordinate& _sour, const Coordinate& _dest) const;

private:

};

class BishopValidator : public MoveValidator
{
public:
	BishopValidator();
	~BishopValidator();
	//MoveValidator
	bool validate_move(const Coordinate& _sour, const Coordinate& _dest) const;

private:

};

class QueenValidator : public MoveValidator
{
public:
	QueenValidator();
	~QueenValidator();
	//MoveValidator
	bool validate_move(const Coordinate& _sour, const Coordinate& _dest) const;

private:

};

class KingValidator : public MoveValidator
{
public:
	KingValidator();
	~KingValidator();
	//MoveValidator
	bool validate_move(const Coordinate& _sour, const Coordinate& _dest) const;

private:

};

class PawnValidator : public MoveValidator
{
public:
	PawnValidator();
	~PawnValidator();
	//MoveValidator
	bool validate_move(const Coordinate& _sour, const Coordinate& _dest) const;

private:

};