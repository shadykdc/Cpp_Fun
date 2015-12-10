// chess: Knight.h
#ifndef KNIGHT_H
#define KNIGHT_H
#include "Piece.h"
#include <string>

using namespace std;

class Knight: public Piece
{
public:
	Knight(char _color);
	~Knight();
	
	bool move(string source_square, string destination_square, ChessBoard *cb,
	bool msg);
	/*	returns true if the knight at source can move to destination
		returns false if:
			there is a piece of the same color in the destination square
			moving the knight would result in putting the king in check
			that position is not an L away from the knight's position
		if msg is true then it will output an error message if applicable
	*/
};
#endif
