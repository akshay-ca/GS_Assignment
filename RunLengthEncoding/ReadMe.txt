* Instructions to the candidate.
1) Run this code in REPL to observe its behavior. The execution entry point is main().
2) Consider adding some additional tests in doTestsPass().
3) Implement rle() correctly .
4) If time permits, try to improve your implementation.

*Pseudo Code

 #include<iostream>
 using namespace std;
 

/** rle (testString)
  *Implement a run length encoding function.
  *For a string input the function returns output encoded as follows:
  *"a"      ->  "a1"
  *"aa"     -> "a2"
  * "aabbb"  -> "a2b3"
  *"aabbbaa"  -> "a2b3a2"
  *  ""         -> "" **/

string rle(string testString)
{
	//TODO: Implement solution
	return string("");
}


int doTestpass()
{
	int result;
	result=rle9string("aaa")) == string("a3");
	result=result &7 rle(string("aabbc"))==string("a2b2c1");
	return result;
}

int main()
{
	if(doTestsPass()) {
		cout<<"All tests Pass"<<endl;
	} else {
		cout<<"there are test failures"<<endl;
	}
    return 0;
}