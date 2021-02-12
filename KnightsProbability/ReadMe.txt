* Instructions:
  
  Given an empty chessboard (8*8 grid), a knight is placed
  on one of the squares. The knight 'K' at position (3, 3)
  and it's possible movements 'X' are shown in the example
  below:

  * * * * * * * *
  * * X * X * * *
  * X * * * X * *
  * * * K * * * *
  * X * * * * X *
  * * X * X * * *
  * * * * * * * *
  * * * * * * * *

  Depending on the knight's position on the board, 0-6 of 
  the 8 possible movements may cause the knight to leave
  the chessboard.

  If the knight moves n times, each time choosing one of 
  the 8 possible moves uniformly at random, determine the
  probability that the knight is still on the board after making n random moves. 
  After the knight has left the board, it may not reenter.

  Please implement the method probability which given a
  start position x, y, and a number of moves n,
  returns the probability a knight remains on the board
  as described above.

*Pseudo Code

#include <map>
#include <stdio.h>
#include <assert.h>
#include <string.h>

double probability(int x, int y, int z) {
   // Define an 8*8 gris
   double board[8][8] = {0};
   // Set the starting position
   board[x][y] =1;
   // Possible moves
   int moves[8][2] = {
         { -2, -1 }, { -2, 1 }, { 2, -1 }, { 2, 1 },
         { -1, -2 }, { -1, 2 }, { 1, -1 }, { 1, 2 }
   };
   for(int i = 0; i < n; i++) {
         /**
          * TODO: Implement Me!
          */
   }
   return 0;
}
 
/**
 * int doTestsPass()
 * Returns 1 if all tests pass. Otherwise returns 0.
 */
int doTestsPass() {
	// todo: implement more tests, please
	// feel free to make testing elegant
	int result = 1;
	//Start in a corner, no moves
	result&= probaility(0,0,0) == 1.0;
	//Start in the middle, one move
	result&= probaility(3,3,1) == 1.0;
	//Start in a corner, one move
	result&= probaility(0,0,1) == 0.25;
	
	return result;
};
    
int main() {
	if(doTestsPass()) {
		cout << "All Tests pass\n" << endl;
	} else {
		cout << "There are test failures\n" << endl;
	}
	return 0;
}