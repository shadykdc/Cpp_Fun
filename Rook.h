// chess: Rook.h
#ifndef ROOK_H
#define ROOK_H
#include "Piece.h"
#include <string>

using namespace std;

class Rook: public Piece
{
public:
	Rook(char _color);
	~Rook();
	
	bool move(string source_square, string destination_square, ChessBoard *cb,
	bool msg);
	/*	returns true if the rook at source can move to destination
		returns false if:
			there is a piece of the same color in the destination square
			moving the rook would result in putting the king in check
			that position is not along the rook's vertical or horizontal
			there is another piece between the rook and the position 
		if msg is true then it will output an error message if applicable
	*/
};
#endif
