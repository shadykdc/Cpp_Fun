// chess: Bishop.h
#ifndef BISHOP_H
#define BISHOP_H
#include "Piece.h"
#include <string>
#include <cmath>

class Bishop: public Piece
{
public:
	Bishop(char _color);
	~Bishop();
	
	bool move(string source_square, string destination_square, ChessBoard *cb,
	bool msg);
	/*	returns true if the bishop at source can move to destination
		returns false if:
			there is a piece of the same color in the destination square
			moving the bishop would result in putting the king in check
			that position is not along the bishop's diagonals
			there is another piece between the bishop and the position
		if msg is true then it will output an error message if applicable
	*/
};
#endif
