// chess: Rook.cpp
#include "Rook.h"
#include <string>
#include <cmath>

Rook::Rook(char _color) : Piece(_color) {
	name = "Rook";
}

Rook::~Rook() { }

bool Rook::move(string source_square,string destination_square,ChessBoard *cb,
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
	
	/* if the two squares share the same rank, check the spaces between */
	if (rank_src == rank_dest) {
		int lesser_file = min(file_src, file_dest)+1;
		int greater_file = max(file_src, file_dest);
		while (lesser_file < greater_file){
			string square = "00";
			square[0] = lesser_file+64;
			square[1] = rank_src+48; // or rank_dest, they're the same
			map<string, Piece *> board = cb->get_board();
			if (board[square] != NULL) {
				if (msg == true) {
					cout << cb->get_turn() << "'s ";
					cout << board[source_square]->get_name() << " cannot move";
					cout << " to " << destination_square << "!" << endl;
				}
				return false;
			}
			lesser_file++;
		}
	}
	
	/* if the two squares share the same file, check the spaces between */
	else if (file_src == file_dest) {
		int lesser_rank = min(rank_src, rank_dest)+1;
		int greater_rank = max(rank_src, rank_dest);
		while (lesser_rank < greater_rank){
			string square = "00";
			square[0] = file_src+64; // or file_dest, they're the same
			square[1] = lesser_rank+48;
			if (board[square] != NULL) {
				if (msg == true) {
					cout << cb->get_turn() << "'s ";
					cout << board[source_square]->get_name() << " cannot move";
					cout << " to " << destination_square << "!" << endl;
				}
				return false;
			}
			lesser_rank++;
		}
	}
	
	/* return false if the destination is not in the same rank or file */
	else {
		if (msg == true) {
			cout << cb->get_turn() << "'s ";
			cout << board[source_square]->get_name() << " cannot move";
			cout << " to " << destination_square << "!" << endl;
		}
		return false;
	}
	return true;
}
