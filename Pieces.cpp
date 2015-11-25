// chess: Pieces.cpp
#include "Pieces.h"
#include "ChessBoard.h"
#include <string>
#include <cmath>

using namespace std;

King::King(char _color)
{
	color = _color;
	name = "King";
}


Queen::Queen(char _color)
{
	color = _color;
	name = "Queen";
}


Rook::Rook(char _color)
{
	color = _color;
	name = "Rook";
}


Knight::Knight(char _color)
{
	color = _color;
	name = "Knight";
}

Bishop::Bishop(char _color)
{
	color = _color;
	name = "Bishop";
}

Pawn::Pawn(char _color)
{
	color = _color;
	name = "Pawn";
}

bool Piece::move(int rank_src, int file_src, int rank_dest, int file_dest,
	std::map<string, Piece *> &board)
{
	return true;
}

bool King::move(int rank_src, int file_src, int rank_dest, int file_dest,
	std::map<string, Piece *> &board)
{
	/* return false if the king is moving more than one space */
	if ((rank_src - rank_dest > 1) || (file_src - file_dest > 1) ||
	(rank_dest - rank_src > 1) || (file_dest - file_src > 1)) {
		cout << "The King can only move one space at a time." << endl;
		return false;
	}

	/* return false if the king is putting itself in check */
	
	return true;
}

bool Queen::move(int rank_src, int file_src, int rank_dest, int file_dest,
	std::map<string, Piece *> &board)
{
	return true;
}

bool Rook::move(int rank_src, int file_src, int rank_dest, int file_dest,
	std::map<string, Piece *> &board)
{

	
	/* return false if there is a piece between the source and destination */
	
	/* if the two squares share the same file, check the spaces between */
	if (rank_src == rank_dest) {
		int lesser_file = min(file_src, file_dest)+1;
		int greater_file = max(file_src, file_dest);
		while (lesser_file < greater_file){
			string square = "00";
			square[0] = lesser_file+64;
			square[1] = rank_src+48; // or rank_dest, they're the same
			if (board[square] != NULL) {
				cout << "There is a " << board[square]->get_name()<< " at ";
				cout << square << " and the Rook cannot hop over it." << endl;
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
				cout << "There is a " << board[square]->get_name()<< " at ";
				cout << square << " and the Rook cannot hop over it." << endl;
				return false;
			}
			lesser_rank++;
		}
	}
	/* return false if the destination is not in the same rank or file */
	else {
		cout << "Rooks can only move within their own rank or file." << endl;
		return false;
	}
	
	return true;
}

bool Knight::move(int rank_src, int file_src, int rank_dest, int file_dest,
	std::map<string, Piece *> &board)
{
	/* return false if the knight does not move in an L */
	int sum = (abs(rank_src-rank_dest)+abs(file_src-file_dest));
	if (sum != 3) {
		cout << "That is not how knights move." << endl;
		return false;
	}
	return true;
}

bool Bishop::move(int rank_src, int file_src, int rank_dest, int file_dest,
	std::map<string, Piece *> &board)
{
	/* return false if the move is not on the Bishop's diagonal */
	if (abs(rank_src - rank_dest) != abs(file_src - file_dest)) {
		cout << "That is not a valid move for a Bishop." << endl;
		return false;
	}
	
	/* return false if there is a piece between the source and destination */
	int lesser_rank = min(rank_src, rank_dest)+1;
	int greater_rank = max(rank_src, rank_dest);
	int lesser_file = min(file_src, file_dest)+1;
	int greater_file = max(file_src, file_dest);
	while (lesser_rank < greater_rank) {
		while (lesser_file < greater_file) {
			string square = "00";
			square[0] = lesser_file+64;
			square[1] = lesser_rank+48;
			if (board[square] != NULL) {
				cout << "There is a " << board[square]->get_name()<< " at ";
				cout << square << " and the Bishop cannot hop over it." << endl;
				return false;
			}
			lesser_rank++;
			lesser_file++;
		}
	}
	return true;
}

bool Pawn::move(int rank_src, int file_src, int rank_dest, int file_dest,
	std::map<string, Piece *> &board)
{
	return true;
}

char Piece::get_color()
{
	return color;
}

string Piece::get_name()
{
	return name;
}
