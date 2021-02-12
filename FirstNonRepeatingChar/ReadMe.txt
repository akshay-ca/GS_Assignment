* Instructions to the candidate.
1) Run this code in REPL to observe its behavior. The execution entry point is main().
2) Consider adding some additional tests in doTestsPass().
3) Implement findFirst() correctly.
4) If time permits, some possible follow-ups.

*Pseudo Code

#include<iostream>
#include<limits.h>
#include<string>

using namespace std;

/** char findFirst(const char* input)
  * Finds the first character that does not repeat anywhere in the input string
  * Given "apple", the answer is "a"
  * Given "racecars", the answer is "e"
  * Given "ababdc", the answer is "d" */

char findFirst(const string input)
{
	//TODO: implement the solution here
	return 0;
}

bool doTestsPass()
{
	//todo:implement more tests , please 
	//feel free to make testing more elegant
	bool result = true;
	result &= findFirst("apple") == 'a';
	result &= findFirst("racecars") == 'e';
	result &= findFirst("ababdc") == 'd';
	retrun result;
}

int main()
{
    if (dotestsPass()){
         cout<<"All test pass "<<endl;
	} else {
       cout<<"There are test failures"<<endl;
	}

    return 0;
}