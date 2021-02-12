* Instructions to the candidate.
1) Run this code in the REPL to observe its behavior. The execution entry point is main().
2) Consider adding some additional tests in doTestPass().
3) Implement sortSegments correctly.
4) If time permits, some possible follow-ups.

*Pseudo Code

#include <iostream>
#include <deque>
#include <algorithm>
#include<iterator>
#include<numeric>
#include<random>
#include<unordered_map>

using namespace std;

/*
 Given a jumbled collection of segments, each of which is represented as
 a std::pair(start_point , end_point), this function sorts the segments to
 make a continuous path.
 
 A few assumptions you can make:
 1. each particular segment goes in one direction only, i.e., if you
 see(1,2), you will not see(2,1).
 2. each starting point only have one way to the endpoint,i.e. if you
 see(6,5), you will not see(6,10), (6,3),etc.
 
 For example, if you're passed a list containing the following int arrays:
    [(4,5),(9,4),(5,1),(11,9)]
 Then your implementation should sort it such:
  [(11,0),(9,4),(4,5),(5,1)]

 param: segments collection of segments, each represented by a pair(start_point, end_point).
 return: The sorted segments such that they form a continuous path.
 throws; invalid-argument if there is no way to create one continuous path from all the segments passed into this function. feel free to change the exception type as you think appropriate.

  */

vector<pair<int,int> > sortSegments (const vector<pair<int,int> >& segments) {
	return vector<pair<int,int> >();
}

bool testBasicSort() {
	vector<pair<int , int> >jumbled_segments = { { 4,5} , {9,4}, {5,1}, {11,9} };
	auto actual_continous_path = sortSegments(jumbled_segments);
	vector<pair<int , int> >excepted_continous_path = { { 11,9} , {9,4}, {4,5}, {5,1} };
	return (excepted_continous_path == actual_continous_path);
}

bool doTestsPass() {
	auto all_pass = true;
	all_pass = all_pass && testBasicSort();
	return all_pass;
}

int main() {
	if (doTestsPass()) {
	    cout<<"All tests pass"<<endl;
	} else {
	  cout<<"some tests fail"<<endl;
	}
	return 0;
}