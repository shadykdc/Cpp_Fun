// chess: Queen.h
#ifndef QUEEN_H
#define QUEEN_H
#include "Piece.h"
#include <string>

using namespace std;

class Queen: public Piece
{
public:
	Queen(char _color);
	~Queen();
	
	bool move(string source_square, string destination_square, ChessBoard *cb,
	bool msg);
	/*	returns true if the queen at source can move to destination
		returns false if:
			there is a piece of the same color in the destination square
			that position is not along the queen's diagonals, vert, or horiz
			there is another piece between the queen and the position
			
		if msg is true then it will output an error message if applicable
	*/
};
#endif
