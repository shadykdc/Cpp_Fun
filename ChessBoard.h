// chess: ChessBoard.h
#ifndef CHESSBOARD_H
#define CHESSBOARD_H

#include <iostream>
#include <string>
#include <map>

class Piece;

class ChessBoard
{
private:
	std::string turn;
	std::string opponent;
	std::map <std::/*const*/string, Piece *> board;
public:
	ChessBoard();
	/*	initializer */
	
	void resetBoard();
	/*	resets the chess board to the start of a game */
	
	bool submitMove(std::string source_square, std::string destination_square);
	/*	attempts to move a piece on the board:
			checks if the position is already filled by that player's piece
			checks if the correct player is making a move
			checks if the other player is now in a stalemate 
			checks if the other player is now in check
			checks if the other player is now checkmated */
		
	void change_turn();
	/*	changes whose turn it is */
		
	std::string get_turn();
	/*	returns the color of the person whose turn it is */
};

#endif
