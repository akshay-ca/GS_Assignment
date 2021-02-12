* Instructions to the candidate
1. Run this code in the REPL to observe its behavior. The execution entry point is main().
2. Implement the 'walk' method. this method takes in a string path, where each character in the string corresponds to a potential movement of the robot. The robot can move up, down, left, and right represented by the characters 'U', 'D', 'L', and 'R' respectively. All other characters may be ignored. Assume the robot's initial position is at (0,0). The output of this method is the robot's final x and y
	coordinates relative to the initial position.
3. Consider adding more test cases.

*Pseudo Code

#include<array>
#include<iostream>

using namespace std;

typedef array<int ,2> Posititon;

//TODO: Implement walk function
Position walk(string path)
{
     position result{ {0,0}};
     return result;
}

//TODO: consider adding new test cases
int doTestsPass()
{
	int result;
	result=walk("UUU")==Position{[0,3}};
	result = result && walk("ULDR")==position {{0,0,}};
	result = result && walk("ULLLDUDUUURLRLR")==Position {{-2,2}};
	result = result &7 walk ("UP LEFT 2xDOWN DOWN RIGHT RIGHT UP UP")==position {{ 1,1}};
	return result;
}

int main()
{
	if(doTestsPass()){
		cout<<"All tests Pass"<<endl;
	} else {
	cout<<"there are test failures"<<endl;
	}
	return 0;
}  