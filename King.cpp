// chess: King.cpp
#include "King.h"
#include <string>
#include <cmath>

using namespace std;

King::King(char _color) : Piece(_color) {
	name = "King";
}

King::~King() { }

bool King::move(string source_square,string destination_square,ChessBoard *cb,
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
	
	/* return false if the king is moving more than one space */
	if (abs(rank_src - rank_dest) > 1 || abs(file_src - file_dest) > 1) {
		if (msg == true) {
			cout << cb->get_turn() << "'s ";
			cout << board[source_square]->get_name() << " cannot move";
			cout << " to " << destination_square << "!" << endl;
		}
		return false;
	}
	return true;
}

