/* Instructions to the candidates
1) There is a staircase with 'n' number of steps. A child walks by and wants to climb up the stairs, starting at the bottom step and ascending to the top.
2) Of course, the child wants to have fun, too, so instead of taking 1 step at a time, she will vary between taking either 1,2, or 3 steps at a time.
3) Please complete the 'countSteps' method below so that given 'n' number of steps it will return the number of unique combinations the child could traverse.

An example would be countsteps(3)=4;
1 1 1 
2 1
1 2 
3

*Pseudo Code

#include<iostream>
#include<vector>
using namespace std;

/** Given n steps returns the number of possible permutations to climb the staircase
	*returns 0 when the input n <=0 */

int countStepsRec(int n)
{
}

bool doTestsPass()
{
	//todo: implement more tests, if you'd like 
	return countSteps(3) == 4
		&& countSteps(4) == 7
		&& countSteps(1) == 1
		&& countSteps(2) == 2
		&& countSteps(0) == 0
		&& countSteps(-5) == 0
		&& countSteps(10) == 274
		&& countSteps(36) == 2082876103; // will cause naive solutions to time out
}

int main()
{
	if(doTestsPass)()) {
		cout<<" All the tests pass "<< endl;
	} else {
		cout<<" There are test failures"<< endl;
	}
	//Try some examples
	for(int n = 1;n <=5; n++) {
		cout<<n<<"steps"<<countSteps(n)<<endl;
	}
	return 0;
}