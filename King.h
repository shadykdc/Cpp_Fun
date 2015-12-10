// chess: King.h
#ifndef KING_H
#define KING_H
#include "Piece.h"
#include <string>

using namespace std;

class King: public Piece
{
public:
	King(char _color);
	~King();
	
	bool move(string source_square, string destination_square, ChessBoard *cb,
	bool msg);
	/*	returns true if the king at source can move to destination
		returns false if:
			there is a piece of the same color in the destination square
			that position is not adjacent to the king's current position
			
		if msg is true then it will output an error message if applicable
	*/
};
#endif
