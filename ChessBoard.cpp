// chess: ChessBoard.cpp
#include <iostream>
#include <map>
#include <string>
#include "Pieces.h"
#include "ChessBoard.h"

using namespace std;

ChessBoard::ChessBoard()
{
	cout  << endl << "A new chess game is started!" << endl;
	turn = "White";
	
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
	board.clear();
	
	cout  << endl << "A new chess game is started!" << endl;
	turn = "White";
	
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

	/*	move the piece into that space (if the move is valid) */
	if (board[source_square]->move()) {
		if (board[destination_square] == NULL) {
			board[destination_square] = board[source_square];
			cout << turn << "'s " << board[source_square]->get_name();
			cout << " moves from " << source_square << " to ";
			cout << destination_square << endl;
		}
	}
	
	change_turn();
	
	return true;
}

bool ChessBoard::empty(std::string position)
{
	return true;
}
		
void ChessBoard::change_turn()
{
	if(turn == "White") {
		turn = "Black";
	}
	else {
		turn = "White";
	}
}

string ChessBoard::get_turn()
{
	return turn;
}

void ChessBoard::remove(std::string position)
{

}
