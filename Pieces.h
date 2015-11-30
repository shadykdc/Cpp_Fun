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
	string name;
public:
	Piece(char _color);
	/*	constructor	*/
	
	virtual ~Piece();
	/*	destructor	*/
	
	virtual bool move(string source_square, string destination_square,
	ChessBoard *cb, bool msg);
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
	~King();
	
	bool move(string source_square, string destination_square, ChessBoard *cb,
	bool msg);
	/*	returns true if the king can move to position
		returns false if:
			there is a piece of the same color in the destination square
			that position is not adjacent to the king's current position
			
		if msg is true then it will output an error message if applicable
	*/
};

class Queen: public Piece
{
public:
	Queen(char _color);
	~Queen();
	
	bool move(string source_square, string destination_square, ChessBoard *cb,
	bool msg);
	/*	returns true if the queen can move to position
		returns false if:
			there is a piece of the same color in the destination square
			that position is not along the queen's diagonals, vert, or horiz
			there is another piece between the queen and the position
			
		if msg is true then it will output an error message if applicable
	*/
};

class Rook: public Piece
{
public:
	Rook(char _color);
	~Rook();
	
	bool move(string source_square, string destination_square, ChessBoard *cb,
	bool msg);
	/*	returns true if the rook can move to position
		returns false if:
			there is a piece of the same color in the destination square
			moving the rook would result in putting the king in check
			that position is not along the rook's vertical or horizontal
			there is another piece between the rook and the position 
		if msg is true then it will output an error message if applicable
	*/
};

class Knight: public Piece
{
public:
	Knight(char _color);
	~Knight();
	
	bool move(string source_square, string destination_square, ChessBoard *cb,
	bool msg);
	/*	returns true if the knight can move to position
		returns false if:
			there is a piece of the same color in the destination square
			moving the knight would result in putting the king in check
			that position is not an L away from the knight's position
		if msg is true then it will output an error message if applicable
	*/
};

class Bishop: public Piece
{
public:
	Bishop(char _color);
	~Bishop();
	
	bool move(string source_square, string destination_square, ChessBoard *cb,
	bool msg);
	/*	returns true if the bishop can move to position
		returns false if:
			there is a piece of the same color in the destination square
			moving the bishop would result in putting the king in check
			that position is not along the bishop's diagonals
			there is another piece between the bishop and the position
		if msg is true then it will output an error message if applicable
	*/
};

class Pawn: public Piece
{
private:
	int moves;
public:
	Pawn(char _color);
	~Pawn();
	
	bool move(string source_square, string destination_square, ChessBoard *cb,
	bool msg);
	/*	returns true if the pawn can move to position
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
