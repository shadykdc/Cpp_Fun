// chess: Pieces.cpp
#include "ChessBoard.h"
#include "Pieces.h"
#include <string>

using namespace std;

Piece::Piece()
{
	//initialize?
}

King::King()
{
	//initialize?
}


Queen::Queen()
{
	//initialize?
}


Rook::Rook()
{
	//initialize?
}


Knight::Knight()
{
	//initialize?
}

Bishop::Bishop()
{
	//initialize?
}

Pawn::Pawn()
{
	//initialize?
}

virtual bool Piece::move()
{
	return true;
}

bool King::in_check()
{
	return true;
}
	
bool King::mate()
{
	return true;
}

bool King::move(string position)
{
	return true;
}

bool Queen::move(string position)
{
	return true;
}

bool Rook::move(string position)
{
	return true;
}

bool Knight::move(string position)
{
	return true;
}

bool Bishop::move(string position)
{
	return true;
}

bool Pawn::move(string position)
{
	return true;
}
