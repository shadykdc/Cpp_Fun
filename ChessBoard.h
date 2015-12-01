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
	
	~ChessBoard();
	/*	deconstructor that deletes the chess pieces on the heap */
	
	void createBoard();
	/*	initializes the chessboard */
	
	void resetBoard();
	/*	resets the chess board to the start of a game */
	
	bool submitMove(std::string source_square, std::string destination_square);
	/*	attempts to move a piece on the board:
		returns false if:
			source or destination are not on the board
			there is no piece at source
			the correct player is making a move
			destination is already filled by that player's piece
			the current player is putting themselves in check
			the move is invalid according to Piece::move()
		runs check_stalemate(), check_checkmate(), and check_check() at the
		end of every turn and runs change_turn to change whose turn it
		is after a successful move */
		
	void change_turn();
	/*	changes whose turn it is */
		
	std::string get_turn();
	/*	returns the color of the person whose turn it is */
	
	std::map <std::string, Piece *> &get_board();
	/* 	returns a reference to the board */
	
	bool check_stalemate(std::string player);
	/*	returns true if the player ("Black" or "White") is in stalemate */
	
	bool check_check(std::string player);
	/*	returns true if the player ("Black" or "White") is in check */
	
	bool check_checkmate(std::string player);
	/*	returns true if the player ("Black" or "White") is in checkmate */
};

#endif
