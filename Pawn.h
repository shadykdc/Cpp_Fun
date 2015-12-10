// chess: Pawn.h
#ifndef PAWN_H
#define PAWN_H
#include "Piece.h"
#include <string>

using namespace std;

class Pawn: public Piece
{
private:
	int moves;
public:
	Pawn(char _color);
	~Pawn();
	
	bool move(string source_square, string destination_square, ChessBoard *cb,
	bool msg);
	/*	returns true if the pawn at source can move to destination
		returns false if:
			there is a piece of the same color in the destination square
			moving the pawn would result in putting the king in check
			that position is infront of the pawn and occupied
			that position is to the front left/right and occupied by same color
			that position is 2 spaces forward and the pawn has moved
			that position is 2 spaces forward and occupied
		if msg is true then it will output an error message if applicable
	*/
};
#endif
