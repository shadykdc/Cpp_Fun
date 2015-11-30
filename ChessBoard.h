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
	std::map <std::string, Piece *> board;
public:
	ChessBoard();
	/*	initializer */
	
	void resetBoard();
	/*	resets the chess board to the start of a game */
	
	bool submitMove(std::string source_square, std::string destination_square);
	/*	attempts to move a piece on the board:
		returns false if:
			destination is already filled by that player's piece
			the correct player is making a move
			the current player is now in check */
		
	void change_turn();
	/*	changes whose turn it is */
		
	std::string get_turn();
	/*	returns the color of the person whose turn it is */
	
	std::map <std::string, Piece *> get_board();
	/* 	returns the board */
	
	bool check_stalemate(std::string player);
	/*	returns true if the player ("Black" or "White") is in stalemate */
	
	bool check_check(std::string player);
	/*	returns true if the player ("Black" or "White") is in check */
	
	bool check_checkmate(std::string player);
	/*	returns true if the player ("Black" or "White") is in checkmate */
};

#endif
