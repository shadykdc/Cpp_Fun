// chess: Pawn.cpp
#include "Pawn.h"
#include <string>
#include <cmath>

using namespace std;

Pawn::Pawn(char _color) : Piece(_color) {
	name = "Pawn";
}

Pawn::~Pawn() { }

bool Pawn::move(string source_square, string destination_square, ChessBoard *cb,
bool msg)
{
	map<string, Piece *> &board = cb->get_board();
	
	/*	check if there is a piece of the same color at destination_square */
	if (board[destination_square] != NULL &&
	board[source_square]->get_color() == 
	board[destination_square]->get_color()) {
		if (msg == true) {
			cout << cb->get_turn() << "'s ";
			cout << board[source_square]->get_name() << " cannot move";
			cout << " to " << destination_square << "!" << endl;
		}
		return false;
	}
	
	/* convert the source_square and destination_square to ranks and files */
	int rank_src = source_square[1] - 48;
	int file_src = source_square[0] - 64;
	int rank_dest = destination_square[1] - 48;
	int file_dest = destination_square[0] - 64;
	
	/* return false if the pawn is at the end of the board */
	if (rank_src == 8 || rank_src == 1){
		if (msg == true) {
			cout << cb->get_turn() << "'s ";
			cout << board[source_square]->get_name() << " cannot move to ";
			cout << destination_square << "!" << endl;
		}
		return false;
	}
	
	/* get the infront_square */
	string infront_square = "00"; // pawn in front of the source square
	if (board[source_square]->get_color() == 'w') {	// WHITE
		infront_square[1] = rank_src+49;
	}
	else {
		infront_square[1] = rank_src+47;			// BLACK
	}
	infront_square[0] = file_dest+64;
	
	/* return true if destination is directly in front of source and empty */
	if (board[destination_square] == NULL &&		// WHITE
	((rank_src+1) == rank_dest) &&
	file_src == file_dest &&
	board[source_square]->get_color() == 'w') {
		return true;
	}
	
	if (board[destination_square] == NULL &&		// BLACK
	((rank_src-1) == rank_dest) &&
	file_src == file_dest &&
	board[source_square]->get_color() == 'b') {
		return true;
	}
	
	/* return true if destination is two ahead, the next one is unoccupied, the
	pawn hasn't moved, and the destination is also not occupied. */
	if ((rank_src+2) == rank_dest &&				// WHITE
	file_src == file_dest &&
	board[infront_square] == NULL &&
	rank_src == 2 &&
	board[destination_square] == NULL &&
	board[source_square]->get_color() == 'w') {
		return true;
	}
	
	if ((rank_src-2) == rank_dest &&				// BLACK
	file_src == file_dest &&
	board[infront_square] == NULL &&
	rank_src == 7 &&
	board[destination_square] == NULL &&
	board[source_square]->get_color() == 'b') {
		return true;
	}
	
	/* return true if dest is diagonally forward and has an opponent piece */
	if (rank_dest - rank_src == 1 &&				// WHITE
	abs(file_dest - file_src) == 1 &&
	board[destination_square] != NULL &&
	board[source_square]->get_color() == 'w' &&
	board[destination_square]->get_color() == 'b') {
		return true;
	}
	
	if (rank_src - rank_dest == 1 &&				// BLACK
	abs(file_dest - file_src) == 1 &&
	board[destination_square] != NULL &&
	board[source_square]->get_color() == 'b' &&
	board[destination_square]->get_color() == 'w') {
		return true;
	}
	if (msg == true) {
		cout << cb->get_turn() << "'s " << board[source_square]->get_name();
		cout << " cannot move to " << destination_square << "!" << endl;
	}
	return false;
}
