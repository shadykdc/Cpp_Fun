// chess: Pieces.h
#ifndef PIECES_H
#define PIECES_H

#include "ChessBoard.h"
#include <string>

using namespace std;

class Piece
{
protected:
	char color;
	string position;
	string name;
public:
	virtual bool move(string source_square, string destination_square,
	ChessBoard *cb);
	/* 	attempts to move a piece to a position */
	
	std::string get_name();
	/*	returns the name of the piece (Bishop, Rook, etc.) */
	
	char get_color();
	/*	returns the color of the piece; 'w' = white, 'b' = black */
};

class King: public Piece
{
public:
	King(char _color);
	
	bool move(string source_square, string destination_square, ChessBoard *cb);
	/*	returns true if the king can move to position
		returns false if:
			that position is not adjacent to the king's current position */
};

class Queen: public Piece
{
public:
	Queen(char _color);
	
	bool move(string source_square, string destination_square, ChessBoard *cb);
	/*	returns true if the queen can move to position
		returns false if:
			that position is not along the queen's diagonals, vert, or horiz
			there is another piece between the queen and the position */
};

class Rook: public Piece
{
public:
	Rook(char _color);
	
	bool move(string source_square, string destination_square, ChessBoard *cb);
	/*	returns true if the rook can move to position
		returns false if:
			moving the rook would result in putting the king in check
			that position is not along the rook's vertical or horizontal
			there is another piece between the rook and the position */
};

class Knight: public Piece
{
public:
	Knight(char _color);
	
	bool move(string source_square, string destination_square, ChessBoard *cb);
	/*	returns true if the knight can move to position
		returns false if:
			moving the knight would result in putting the king in check
			that position is not an L away from the knight's position */
};

class Bishop: public Piece
{
public:
	Bishop(char _color);
	
	bool move(string source_square, string destination_square, ChessBoard *cb);
	/*	returns true if the bishop can move to position
		returns false if:
			moving the bishop would result in putting the king in check
			that position is not along the bishop's diagonals
			there is another piece between the bishop and the position */
};

class Pawn: public Piece
{
private:
	int moves;
public:
	Pawn(char _color);
	
	bool move(string source_square, string destination_square, ChessBoard *cb);
	/*	returns true if the pawn can move to position
		returns false if:
			moving the pawn would result in putting the king in check
			that position is infront of the pawn and occupied
			that position is to the front left/right and occupied by same color
			that position is 2 spaces forward and the pawn has moved
			that position is 2 spaces forward and occupied */
	
	/* special capture rules */
};

#endif
