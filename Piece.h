// chess: Piece.h
#ifndef PIECE_H
#define PIECE_H
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
	ChessBoard *cb, bool msg)=0;
	/* 	pure virtual function;
		subclass versions return true if the move is valid */
	
	std::string get_name();
	/*	returns the name of the piece (Bishop, Rook, etc.) */
	
	char get_color();
	/*	returns the color of the piece; 'w' = white, 'b' = black */
};
#endif
