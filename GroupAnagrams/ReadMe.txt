Instructions to the candidate.
1) Given a list of words , group them by anagrams
	Input:List of "cat" , "dog" , 'god"
    Output : A set of grouping of sets of anagrams: {{'cat'},{'dog','god'}}

2) Run this code in the REPL to observe its behavior. The execution entry point is main().
3) Consider adding some additional tests in doTestsPass().
4) Implement the groupByanagram() function correctly.
5) If time permits, try to improve your implementation.

* Pseudo Code

#include<algorithm>
#include<iostream>
#include<string>
#include<unordered_set>
#include<vector>
using namespace std;
 
vector<unordered_set<string>> groupByAnagramsconst vector<string> &words) {
      return vector<unordered_set<string>>();
}
        
bool doTestsPass() {
	cout<< " Start test...." << endl;
    vector<string>words = {"cat","dog",'god","cat"};
    vector<unordered_set,string>>groups=groupByAnagram(words);
	//Excepted sets
	unordered_set<string> set1({"cat"});
	unordered_set<string> set2({"dog","god"});
	bool result=true;
	result = result && (groups.size() == (unsigned int)2);
	result = result && (find(groups.begin(), groups.end(),set1) != groups.end());
	result = result && (find(groups.begin(), groups.end(),set2) != groups.end());
	retrun result;
}

int main()
{
	if (dotestsPass()) {
		cout<<"All tests passes."<< endl;
	} else {
		cout<< "Test failed." <<endl;
	}

    cin.get();
    return 0;
}