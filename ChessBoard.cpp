// chess: ChessBoard.cpp
#include <iostream>
#include <map>
#include <string>
#include "King.h"
#include "Queen.h"
#include "Rook.h"
#include "Bishop.h"
#include "Knight.h"
#include "Pawn.h"
#include "Piece.h"
#include "ChessBoard.h"

using namespace std;

ChessBoard::ChessBoard()
{
	createBoard();
}

ChessBoard::~ChessBoard()
{
	/* delete all of the pieces on the current board */
	map<string,Piece *>::iterator i;
	for (i = board.begin(); i != board.end(); i++) {
		if (i->second != NULL) {
			delete i->second;
		}
		board.erase(i->first);
	}
}

void ChessBoard::createBoard()
{
	cout  << "A new chess game is started!" << endl;
	turn = "White";
	opponent = "Black";
	
	/* insert the white pieces to their starting positions */
	board["A1"] = new Rook('w');
	board["B1"] = new Knight('w');
	board["C1"] = new Bishop('w');
	board["D1"] = new Queen('w');
	board["E1"] = new King('w');
	board["F1"] = new Bishop('w');
	board["G1"] = new Knight('w');
	board["H1"] = new Rook('w');
	board["A2"] = new Pawn('w');
	board["B2"] = new Pawn('w');
	board["C2"] = new Pawn('w');
	board["D2"] = new Pawn('w');
	board["E2"] = new Pawn('w');
	board["F2"] = new Pawn('w');
	board["G2"] = new Pawn('w');
	board["H2"] = new Pawn('w');

	/* insert the black pieces to their starting positions */
	board["A8"] = new Rook('b');
	board["B8"] = new Knight('b');
	board["C8"] = new Bishop('b');
	board["D8"] = new Queen('b');
	board["E8"] = new King('b');
	board["F8"] = new Bishop('b');
	board["G8"] = new Knight('b');
	board["H8"] = new Rook('b');
	board["A7"] = new Pawn('b');
	board["B7"] = new Pawn('b');
	board["C7"] = new Pawn('b');
	board["D7"] = new Pawn('b');
	board["E7"] = new Pawn('b');
	board["F7"] = new Pawn('b');
	board["G7"] = new Pawn('b');
	board["H7"] = new Pawn('b');
	
	/* set the rest of the board to null/zero */
	board["A3"] = NULL;
	board["B3"] = NULL;
	board["C3"] = NULL;
	board["D3"] = NULL;
	board["E3"] = NULL;
	board["F3"] = NULL;
	board["G3"] = NULL;
	board["H3"] = NULL;
	board["A4"] = NULL;
	board["B4"] = NULL;
	board["C4"] = NULL;
	board["D4"] = NULL;
	board["E4"] = NULL;
	board["F4"] = NULL;
	board["G4"] = NULL;
	board["H4"] = NULL;
	board["A5"] = NULL;
	board["B5"] = NULL;
	board["C5"] = NULL;
	board["D5"] = NULL;
	board["E5"] = NULL;
	board["F5"] = NULL;
	board["G5"] = NULL;
	board["H5"] = NULL;
	board["A6"] = NULL;
	board["B6"] = NULL;
	board["C6"] = NULL;
	board["D6"] = NULL;
	board["E6"] = NULL;
	board["F6"] = NULL;
	board["G6"] = NULL;
	board["H6"] = NULL;
}

void ChessBoard::resetBoard()
{
	/* delete all of the pieces on the current board */
	map<string,Piece *>::iterator i;
	for (i = board.begin(); i != board.end(); i++) {
		if (i->second != NULL) {
			delete i->second;
		}
	}
	
	/* re-initialize the board */
	createBoard();
}

bool ChessBoard::submitMove(string source_square, string destination_square)
{
	/*	check if source_square and destination_square are on the board */
	if (board.find(source_square) == board.end() ||
	board.find(destination_square) == board.end()) {
		cout << "Out of bounds!" << endl;
		return false;
	}
	
	/*	check if there is a piece at source_square */
	if (board[source_square] == NULL) {
		cout << "There is no piece at position " << source_square <<"!"<< endl;
		return false;
	}

	/*	check if the correct player is making a move */
	if (board[source_square]->get_color() == 'w' && turn == "Black") {
		cout << "It is not White's turn to move!" << endl;
		return false;
	}
	if (board[source_square]->get_color() == 'b' && turn == "White"){
		cout << "It is not Black's turn to move!" << endl;
		return false;
	}
	
	/*	if move is valid, move piece to destination (and maybe capture) */
	if (board[source_square]->move(source_square,destination_square,this,true)){
		/* move the piece and set the source_square to be empty */
		Piece *piecePtr = board[destination_square]; //saving ptr just in case
		board[destination_square] = board[source_square];
		board[source_square] = NULL;
		
		/* make sure the current player has not left themselves in check */
		if (check_check(turn)) {
			/* undo our move with the pointer we saved and print error */
			board[source_square] = board[destination_square];
			board[destination_square] = piecePtr;
			cout << turn << "'s ";
			cout << board[source_square]->get_name() << " cannot move";
			cout << " to " << destination_square << "!" << endl;
			return false;
		}
		else {
			/* if they're not in check then we can delete that piecePtr */
			cout << turn << "'s " << board[destination_square]->get_name();
			cout << " moves from " << source_square << " to ";
			cout << destination_square;
			if (piecePtr != NULL) {
				cout << " taking " << opponent << "'s ";
				cout << piecePtr->get_name();
				delete piecePtr;
			}
			cout << endl;
		}
	}
	/*	if the move was not valid, return false */
	else {
		/*	move() should, in this case, return an error in cout */
		return false;
	}
	
	/* check if the opponent is in stalemate */
	if (check_stalemate(opponent)) {
		cout << opponent << " is in stalemate" << endl;
	}
	
	/* check if the opponent is in checkmate */
	else if (check_checkmate(opponent)) {
		cout << opponent << " is in checkmate" << endl;
	}
	
	/* check if the opponent is in check */
	else if (check_check(opponent)) {
		cout << opponent << " is in check" << endl;
	}
	
	change_turn();
	return true;
}
		
void ChessBoard::change_turn()
{
	if(turn == "White") {
		turn = "Black";
		opponent = "White";
	}
	else {
		turn = "White";
		opponent = "Black";
	}
}

string ChessBoard::get_turn()
{
	return turn;
}

map <std::string, Piece *> &ChessBoard::get_board()
{
	return board;
}

bool ChessBoard::check_stalemate(string player)
{
	/* check input */
	if (player.compare("White")) {
		if (player.compare("Black")) {
			cout << "Something went wrong in check_stalemate().";
			cout << "Argument was neither Black nor White." << endl;
		}
	}

	/* if player is in check, return false */
	if (check_check(player)) {
		return false;
	}
	
	/* color of opponent */
	char opponent_piece;
	if (player.compare("White")) {
		opponent_piece = 'w';}
	else {
		opponent_piece = 'b';}

	/* if any player move results in !check, return false */
	map<string,Piece *>::iterator i; // i is the piece
	map<string,Piece *>::iterator j; // j is the potential move
	
	for (i = board.begin(); i != board.end(); i++) {
		for (j = board.begin(); j != board.end(); j++) {
			/* if player's piece can move somewhere... */
			if ((i->first).compare(j->first) &&
			(i->second) != NULL &&
			(i->second)->get_color() != opponent_piece &&
			(i->second)->move(i->first, j->first, this, false)) {
				/* ...try the move; if it results in check, undo */
				Piece *piecePtr = j->second;
				board[j->first] = i->second;
				board[i->first] = NULL;
				if (check_check(player)) {
					board[i->first] = board[j->first];
					board[j->first] = piecePtr;
				}
				/* if it results in not check, still undo but return false */
				else {
					board[i->first] = board[j->first];
					board[j->first] = piecePtr;
					return false;
				}
			}
		}
	}
	/* we've tried the whole board so the player must be in stalemate */
	return true;
}

bool ChessBoard::check_check(string player)
{
	/* check input */
	if (player.compare("White")) {
		if (player.compare("Black")) {
			cout << "Something went wrong in check_stalemate().";
			cout << "Argument was neither Black nor White." << endl;
		}
	}
	
	/* color of opponent */
	char opponent_piece;
	if (player.compare("White")) {
		opponent_piece = 'w';}
	else {
		opponent_piece = 'b';}
	
	/* an iterator */
	map<string,Piece *>::iterator i;
	
	/* find the player's king */
	string king_square;
	for (i = board.begin(); i != board.end(); i++)
	{
		if ((i->second) != NULL &&
		!(i->second)->get_name().compare("King") &&
		(i->second)->get_color() != opponent_piece) {
			king_square = i->first;
		}
	}

	/* check to see if player's king is under attack */
	for (i = board.begin(); i != board.end(); i++) {
		if ((i->second) != NULL &&
		(i->second)->get_color() == opponent_piece &&
		(i->second)->move(i->first, king_square, this, false)) {
			return true;
		}
	}
	return false;
}

bool ChessBoard::check_checkmate(string player)
{
	/* check input */
	if (player.compare("White")) {
		if (player.compare("Black")) {
			cout << "Something went wrong in check_stalemate().";
			cout << "Argument was neither Black nor White." << endl;
		}
	}
	
	/* if the king is not in check, return false */
	if (!check_check(player)) {
		return false;
	}
	
	/* color of opponent */
	char opponent_piece;
	if (player.compare("White")) {
		opponent_piece = 'w';}
	else {
		opponent_piece = 'b';}

	/* if any player move results in !check, return false */
	map<string,Piece *>::iterator i; // i is the piece
	map<string,Piece *>::iterator j; // j is the potential move
	
	for (i = board.begin(); i != board.end(); i++) {
		for (j = board.begin(); j != board.end(); j++) {
			/* if player's piece can move somewhere... */
			if ((i->first).compare(j->first) &&
			(i->second) != NULL &&
			(i->second)->get_color() != opponent_piece &&
			(i->second)->move(i->first, j->first, this, false)) {
				/* ...try the move; if it results in check, undo */
				Piece *piecePtr = j->second;
				board[j->first] = i->second;
				board[i->first] = NULL;
				if (check_check(player)) {
					board[i->first] = board[j->first];
					board[j->first] = piecePtr;
				}
				/* if it results in not check, still undo but return false */
				else {
					board[i->first] = board[j->first];
					board[j->first] = piecePtr;
					return false;
				}
			}
		}
	}
	/* we've tried the whole board so the player must be in checkmate */
	return true;
}
