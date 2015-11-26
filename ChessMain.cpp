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
	--write actual check functions
	--destructors
	--strcmp
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
