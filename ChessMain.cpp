//	Kathryn Shea
//	December 14, 2015
//	Assessed Exercise #3, C++
//	chess: ChessMain.cpp

#include <iostream>
#include <string>
#include "ChessBoard.h"
#include "Pieces.h"

using namespace std;

/* Questions:
I'm creating a new board in every move file... maybe consider having a pointer to the board in each Piece.
	
How do I delete one piece?
Is my clear deleting my pieces? No.
Deconstructors?
	
Is Piece an abstract class? I don't think so...
	
Should be able to declare a move function for Piece that can create variables (soruce and destination square) either in the attributes or in the function, I'm still not sure, and then that function will call the special functions for the individual pieces.  Then we don't have to pass a ton of stuff into 6 different functions.

Can I have a flag to turn off cout when checking for check in my move() func?
	
	To Do:
	--destructors
	--make sure we can't move a piece to where it already is
*/

int main() {

	cout << "============================" << endl;
    cout << "  Testing the Chess Engine  " << endl;
    cout << "============================" << endl;
    cout << endl;

    ChessBoard cb;
    cout << endl;

    cb.submitMove("D7", "D6");
    cout << endl;

    cb.submitMove("D4", "H6");
    cout << endl;

    cb.submitMove("D2", "D4");
    cout << endl;

    cb.submitMove("F8", "B4");
    cout << endl;
   
   	cout << "============================" << endl;
    cout << "        Katie's Tests       " << endl;
    cout << "============================" << endl;
    cout << endl;

    cb.resetBoard();
    cout << endl;
	
    cb.submitMove("A1", "A4"); // can w rook jump?
    cout << endl;

    cb.submitMove("A1", "B1"); // can w rook take a piece of it's own color?
    cout << endl;

    cb.submitMove("B2", "B4"); // move w pawn two spaces
    cout << endl;
    
    cb.submitMove("D8", "D6"); // can b queen jump a pawn?
    cout << endl;

    cb.submitMove("E8", "E7"); // can b king take a piece of it's own color?
    cout << endl;
    
    cb.submitMove("D8", "C8"); // can b queen take a piece of it's own color?
    cout << endl;

    cb.submitMove("B8", "C6"); // move b knight
    cout << endl;

    cb.submitMove("A1", "C3"); // can w rook move diagonally?
    cout << endl;
    
    cb.submitMove("C1", "E3"); // can w bishop jump the pawn?
    cout << endl;

    cb.submitMove("C1", "D2"); // can w bishop take a piece of it's own color?
    cout << endl;

    cb.submitMove("C1", "A3"); // move w bishop 2 spaces
    cout << endl;
    
    cb.submitMove("E7", "E5"); // move b pawn two spaces
    cout << endl;

    cb.submitMove("B1", "C3"); // move w knight
    cout << endl;

    cb.submitMove("D8", "F6"); // move b queen diagonally
    cout << endl;
    
    cb.submitMove("A1", "B1"); // move w rook horizontally /problem****
    cout << endl;

    cb.submitMove("F6", "D6"); // move b queen horizontally
    cout << endl;

    cb.submitMove("B1", "B2"); // move w rook vertically
    cout << endl;
    
    cb.submitMove("D6", "D2");	// take a w piece with the b queen
    cout << endl;				// CHECK!!! (but not checkmate)
    
    cb.submitMove("E1", "D2"); // capture b queen with w king diagonally
    cout << endl;
    
    cb.submitMove("E5", "E3"); // try to move b pawn two spaces when it can't
    cout << endl;
    
    cb.submitMove("E5", "E6"); // try to move b pawn backwards
    cout << endl;
    
    cb.submitMove("E5", "F4"); // try to "capture" nothing with b pawn
    cout << endl;
    
    cb.submitMove("E5", "E4"); // move b pawn one space
    cout << endl;
    
    cb.submitMove("F2", "F3"); // move w pawn one space
    cout << endl;
    
    cb.submitMove("E4", "F3"); // b pawn capture w pawn
    cout << endl;
    
    cb.submitMove("F8", "B4"); // capture w pawn with b bishop
    cout << endl;
    
    cb.submitMove("C3", "D5"); // attempt to move knight, putting king in check
    cout << endl;
    
    cb.submitMove("B2", "B5"); // check if w rook can jump b bishop
    cout << endl;
    
    cb.submitMove("B2", "B4"); // take bishop with w rook
    cout << endl;
    
    // http://lichess.org/editor/r1b1k1nr/pppp1ppp/2n5/8/1R6/B1N2p2/P1PKP1PP/3Q1BNR_w_KQkq_-
   
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
