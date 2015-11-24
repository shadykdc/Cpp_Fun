// chess: ChessBoard.cpp
#include <iostream>
#include <map>
#include <string>
#include "Pieces.h"
#include "ChessBoard.h"

using namespace std;

class ChessBoard()
{
	// do nothing?
}

void ChessBoard::resetBoard()
{
	/* insert the white pieces to their starting positions */
	board.insert(make_pair("A1", Rook('w')));
	board.insert(make_pair("B1", Knight('w')));
	board.insert(make_pair("C1", Bishop('w')));
	board.insert(make_pair("D1", Queen('w')));
	board.insert(make_pair("E1", King('w')));
	board.insert(make_pair("F1", Bishop('w')));
	board.insert(make_pair("G1", Knight('w')));
	board.insert(make_pair("H1", Rook('w')));
	board.insert(make_pair("A2", Pawn('w')));
	board.insert(make_pair("B2", Pawn('w')));
	board.insert(make_pair("C2", Pawn('w')));
	board.insert(make_pair("D2", Pawn('w')));
	board.insert(make_pair("E2", Pawn('w')));
	board.insert(make_pair("F2", Pawn('w')));
	board.insert(make_pair("G2", Pawn('w')));
	board.insert(make_pair("H2", Pawn('w')));
	
	/* insert the black pieces to their starting positions */
	board.insert(make_pair("A8", Rook('b')));
	board.insert(make_pair("B8", Knight('b')));
	board.insert(make_pair("C8", Bishop('b')));
	board.insert(make_pair("D8", Queen('b')));
	board.insert(make_pair("E8", King('b')));
	board.insert(make_pair("F8", Bishop('b')));
	board.insert(make_pair("G8", Knight('b')));
	board.insert(make_pair("H8", Rook('b')));
	board.insert(make_pair("A7", Pawn('b')));
	board.insert(make_pair("B7", Pawn('b')));
	board.insert(make_pair("C7", Pawn('b')));
	board.insert(make_pair("D7", Pawn('b')));
	board.insert(make_pair("E7", Pawn('b')));
	board.insert(make_pair("F7", Pawn('b')));
	board.insert(make_pair("G7", Pawn('b')));
	board.insert(make_pair("H7", Pawn('b')));
	
	/* set the rest of the board to null/empty */
	board.insert(make_pair("A6", NULL));
	board.insert(make_pair("B6", NULL));
	board.insert(make_pair("C6", NULL));
	board.insert(make_pair("D6", NULL));
	board.insert(make_pair("E6", NULL));
	board.insert(make_pair("F6", NULL));
	board.insert(make_pair("G6", NULL));
	board.insert(make_pair("H6", NULL));
	board.insert(make_pair("A5", NULL));
	board.insert(make_pair("B5", NULL));
	board.insert(make_pair("C5", NULL));
	board.insert(make_pair("D5", NULL));
	board.insert(make_pair("E5", NULL));
	board.insert(make_pair("F5", NULL));
	board.insert(make_pair("G5", NULL));
	board.insert(make_pair("H5", NULL));
	board.insert(make_pair("A4", NULL));
	board.insert(make_pair("B4", NULL));
	board.insert(make_pair("C4", NULL));
	board.insert(make_pair("D4", NULL));
	board.insert(make_pair("E4", NULL));
	board.insert(make_pair("F4", NULL));
	board.insert(make_pair("G4", NULL));
	board.insert(make_pair("H4", NULL));
	board.insert(make_pair("A3", NULL));
	board.insert(make_pair("B3", NULL));
	board.insert(make_pair("C3", NULL));
	board.insert(make_pair("D3", NULL));
	board.insert(make_pair("E3", NULL));
	board.insert(make_pair("F3", NULL));
	board.insert(make_pair("G3", NULL));
	board.insert(make_pair("H3", NULL));
}
	
bool ChessBoard::submitMove(string source_square, string destination_square)
{
	if(board.find(source_square) == NULL){
		cout << "There is no piece at position " << source_square << "!";
		cout << endl << endl;
		return false;
	}
	Piece current_piece = board.find(source_square);
	return true;
}

bool ChessBoard::empty(std::string position)
{
	return true;
}
		
char ChessBoard::change_turn()
{
	if(turn == 'w') {
		turn = 'b';
		return turn;
	}
	else {
		turn = 'w';	
		return turn;
	}
}

void ChessBoard::remove(std::string position)
{

}
