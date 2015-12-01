// chess: Pieces.cpp
#include "Pieces.h"
#include "ChessBoard.h"
#include <string>
#include <cmath>

using namespace std;

Piece::Piece(char _color) : color(_color){ }

Piece::~Piece() { }

char Piece::get_color() {
	return color;
}

string Piece::get_name() {
	return name;
}

King::King(char _color) : Piece(_color) {
	name = "King";
}

King::~King() { }

Queen::Queen(char _color) : Piece(_color) {
	name = "Queen";
}

Queen::~Queen() { }

Rook::Rook(char _color) : Piece(_color) {
	name = "Rook";
}

Rook::~Rook() { }

Knight::Knight(char _color) : Piece(_color) {
	name = "Knight";
}

Knight::~Knight() { }

Bishop::Bishop(char _color) : Piece(_color) {
	name = "Bishop";
}

Bishop::~Bishop() { }

Pawn::Pawn(char _color) : Piece(_color) {
	name = "Pawn";
}

Pawn::~Pawn() { }

bool King::move(string source_square,string destination_square,ChessBoard *cb, bool msg)
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

bool Queen::move(string source_square,string destination_square,ChessBoard *cb, bool msg)
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
	
	/* return false if the dest is not in the same rank, file, or diagonal */
	/* if the two squares share the same file, check the spaces between */
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
	/* if the two squares share the same diagonal, check the spaces between */
	else if (abs(rank_src - rank_dest) == abs(file_src - file_dest)) {
		int lesser_rank = min(rank_src, rank_dest)+1;
		int greater_rank = max(rank_src, rank_dest)-1;
		int lesser_file = min(file_src, file_dest)+1;
		int greater_file = max(file_src, file_dest)-1;
		/* moving along a SW-NE (/) line */
		while (lesser_rank <= greater_rank && lesser_file <= greater_file &&
		((rank_src < rank_dest && file_src < file_dest) ||
		(rank_src > rank_dest && file_src > file_dest))) {
			string square = "00";
			square[0] = lesser_file+64;
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
			lesser_file++;
		}
		/* moving along a NW-SE (\) line */
		while (lesser_rank <= greater_rank && lesser_file <= greater_file &&
		((rank_src < rank_dest && file_src > file_dest) ||
		(rank_src > rank_dest && file_src < file_dest))) {
			string square = "00";
			square[0] = greater_file+64;
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
			greater_file--;
		}
	}
	/* the destination must not be on the same diagonal, rank, or file */
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

bool Rook::move(string source_square,string destination_square,ChessBoard *cb, bool msg)
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

bool Knight::move(string source_square,string destination_square,ChessBoard *cb, bool msg)
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
	
	/* return false if the knight does not move in an L */
	int sum = (abs(rank_src-rank_dest)+abs(file_src-file_dest));
	if (sum != 3 || abs(rank_src-rank_dest)==3 || abs(file_src-file_dest)==3) {
		if (msg == true) {
			cout << cb->get_turn() << "'s ";
			cout << board[source_square]->get_name() << " cannot move to ";
			cout << destination_square << "!" << endl;
		}
		return false;
	}
	return true;
}

bool Bishop::move(string source_square,string destination_square,ChessBoard *cb, bool msg)
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
		
	/* return false if the move is not on the Bishop's diagonal */
	if (abs(rank_src - rank_dest) != abs(file_src - file_dest)) {
		if(msg == true) {
			cout << cb->get_turn() << "'s ";
			cout << board[source_square]->get_name() << " cannot move to ";
			cout << destination_square << "!" << endl;
		}
		return false;
	}
	
	/* return false if there is a piece between the source and destination */
	int lesser_rank = min(rank_src, rank_dest)+1;
	int greater_rank = max(rank_src, rank_dest)-1;
	int lesser_file = min(file_src, file_dest)+1;
	int greater_file = max(file_src, file_dest)-1;
	/* moving along a SW-NE (/) line */
	while (lesser_rank <= greater_rank && lesser_file <= greater_file &&
	((rank_src < rank_dest && file_src < file_dest) ||
	(rank_src > rank_dest && file_src > file_dest))) {
		string square = "00";
		square[0] = lesser_file+64;
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
		lesser_file++;
	}
	/* moving along a NW-SE (\) line */
	while (lesser_rank <= greater_rank && lesser_file <= greater_file &&
	((rank_src < rank_dest && file_src > file_dest) ||
	(rank_src > rank_dest && file_src < file_dest))) {
		string square = "00";
		square[0] = greater_file+64;
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
		greater_file--;
	}
	return true;
}

bool Pawn::move(string source_square, string destination_square, ChessBoard *cb, bool msg)
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
