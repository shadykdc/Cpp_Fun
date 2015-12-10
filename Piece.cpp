// chess: Piece.cpp
#include "Piece.h"
#include <string>
#include <cmath>

using namespace std;

Piece::Piece(char _color) : color(_color){ }

Piece::~Piece() { }

char Piece::get_color() {
	return color;
}

string Piece::get_name() {
	return name;
}
