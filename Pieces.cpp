// chess: Pieces.cpp
#include "ChessBoard.h"
#include "Pieces.h"
#include <string>

using namespace std;

King::King(char _color)
{
	color = _color;
//	position = _position;
}


Queen::Queen(char _color)
{
	color = _color;
//	position = _position;
}


Rook::Rook(char _color)
{
	color = _color;
//	position = _position;
}


Knight::Knight(char _color)
{
	color = _color;
//	position = _position;
}

Bishop::Bishop(char _color)
{
	color = _color;
//	position = _position;
}

Pawn::Pawn(char _color)
{
	color = _color;
//	position = _position;
}

bool Piece::move()
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
