//	Kathryn Shea
//	December 14, 2015
//	Assessed Exercise #3, C++
//	chess: ChessMain.cpp

#include <iostream>
#include <string>
#include "ChessBoard.h"
#include "Pieces.h"

using namespace std;

int main() {

	// create board
	
    cout << "============================" << endl;
    cout << "  Testing the Chess Engine  " << endl;
    cout << "============================" << endl;
    cout << endl;

    ChessBoard cb;
    cout << endl;

    cb.submitMove("D7", "D6"); // it's not black's turn to move
    cout << endl;

    cb.submitMove("D4", "H6"); // there is no piece at D4
    cout << endl;

    cb.submitMove("D2", "D4"); // legal move for white's pawn
    cout << endl;

    cb.submitMove("F8", "B4"); // Black's Bishop can't jump
    cout << endl;
    
    /* some additional tests */
    
    cb.submitMove("G8", "H6"); // Successful Black knight move
    cout << endl;
    
    cb.submitMove("G1", "C3"); // Invalid White knight move
    cout << endl;
    
    cb.submitMove("H2", "H3"); // Move a white pawn
    cout << endl;
    
	cb.submitMove("H8", "G8"); // Successful move
    cout << endl;
    
    cb.submitMove("H3", "H4"); // Successful move
    cout << endl;

	cb.submitMove("G8", "H4"); // Rooks only move in their ranks/files!
    cout << endl;
    
    cb.submitMove("G8", "G4"); // Black Rook can't jump (rank)
    cout << endl;
    
    cout << "===========================" << endl;
    cout << " Alekhine vs. Vasic (1931) " << endl;
    cout << "===========================" << endl;
    cout << endl;

    cb.resetBoard();
    cout << endl;

    cb.submitMove("E2", "E4");
    cb.submitMove("E7", "E6");
    cout << endl;

    cb.submitMove("D2", "D4");
    cb.submitMove("D7", "D5");
    cout << endl;

    cb.submitMove("B1", "C3");
    cb.submitMove("F8", "B4");
    cout << endl;

    cb.submitMove("F1", "D3");
    cb.submitMove("B4", "C3");
    cout << endl;

    cb.submitMove("B2", "C3");
    cb.submitMove("H7", "H6");
    cout << endl;

    cb.submitMove("C1", "A3");
    cb.submitMove("B8", "D7");
    cout << endl;

    cb.submitMove("D1", "E2");
    cb.submitMove("D5", "E4");
    cout << endl;

    cb.submitMove("D3", "E4");
    cb.submitMove("G8", "F6");
    cout << endl;

    cb.submitMove("E4", "D3");
    cb.submitMove("B7", "B6");
    cout << endl;

    cb.submitMove("E2", "E6");
    cb.submitMove("F7", "E6");
    cout << endl;

    cb.submitMove("D3", "G6");
    cout << endl;

    return 0;
}
