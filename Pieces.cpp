// chess: Pieces.cpp
#include "Pieces.h"
#include <string>

using namespace std;

King::King(char _color)
{
	color = _color;
	name = "King";
}


Queen::Queen(char _color)
{
	color = _color;
	name = "Queen";
}


Rook::Rook(char _color)
{
	color = _color;
	name = "Rook";
}


Knight::Knight(char _color)
{
	color = _color;
	name = "Knight";
}

Bishop::Bishop(char _color)
{
	color = _color;
	name = "Bishop";
}

Pawn::Pawn(char _color)
{
	color = _color;
	name = "Pawn";
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

char Piece::get_color()
{
	return color;
}


string Piece::get_name()
{
	return name;
}
