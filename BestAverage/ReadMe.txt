* Instructions to the candidates

1) Given a list of student test scores, find the best average grade. Each student may have more than one test score in the lists.
2) Complete the bestaverageGrade function in the editor below.
	It has one parameter, scores, which is an array of student test scores.
	Each element in the array is a two-element array of the form [student name, test score]	e.g. [ "Bobby","87" ].
	Test scores may be positive or negative integers.

Example:

Input:
[ [ "Bobby", "87" ]
  [ "Charles", "100" ],
  [ "Eric", "64" ],
  [ "Charles", "22"] ].

Expected output: 87
Explanation: the average scores are 87, 61, and 64 for Bobby, Charles, and Eric respectively. 87 is the highest.

* Pseudo Code

#include<iostream>
#include<vector>
#include<unordered_map>
#include<float.h>
#include<math.h>
using namespace std;


// Find the best average grade.

int bestAverageGrade(vector<vector<string>> scores)
{
	//Check for empty list
	if(scores.size() == 0){
		return 0;
	}
	//Build hasmap of students to list of scores
	unordered_map<string, vector<int>> studentsToScores;
	for(auto scoreRow : Scores){
		//Check for well formed input
		if(scores.size() != 2)
		{
			return 0;
		};
		string student = scoreRow[0];
		int score      = stoi(scoreRow[1]);

		// Find student in list
		unordered_map<string, vector<int>>::iterator iter = studentstoScores.find(student);
		if(iter == studentsToScores.end())
		{
			vector<int> currentScores;
			currentScores.push_back(score);
			studentToScores.insert(make_pair(student, currentScores));
		}
		else
		{
			// append score to list
			iter->second.push_back(score);
		}
	}
	//get average and max
	double max = -DBL_MAX;
	for(auto mapElen : studentsToScores ){
		int sum = 0;
		for(int i : mapElen.second)
		{
			sum += i;
		}
		double average = sum / (double)mapElen.second.size();
		max = std::max(max, average);
	}
	return static_cast<int>(floor(max));
}

// Returns true if the tests pass. Otherwise, returns false;

bool doTestsPass()
{
      //TODO: implement more test cases
      vector<pair<vector<vector<string>>, int>> testCases =
	{

	make_pair(vector<vector<string>>({
			{ "Bobby", "87"},
			{ "Charles", "100"},
			{ "Eric", "64"},
			{ "Charles", "22" }}) ,87),
	make_pair(vector<vector<string>>({}),0),
	make_pair(vector<vector<string>>({
			{ "Sarah", "91"},
			{ "Goldie", "92"},
			{ "Elaine", "93"},
			{ "Elaine", "95"},
			{ "Goldie", "94"},
			{ "Sarah", "93"}}), 94),
	make_pair(vector<vector<string>>({
			{ "Janie", "-66"},
			{ "Janie", "0"},
			{ "Gina", "-88"},
			{ "Bobby", "0"},
			{ "Gina", "44"},
			{ "Bobby", "0"},
			{ "Bobby", "-6"}}), -2),
	make_pair(vector<vector<string>>({
			{ "Alpha", "99"},
			{ "Bravo", "99"},
			{ "Charlie", "99"},
			{ "Delta", "99"},
			{ "Echo", "99"},
			{ "Foxtrot", "99"},
			{ "Foxtrot", "99"}}), 99),
	 make_pair(vector<vector<string>>({
			{ "Gerald", "91"},
			{ "Gerald", "92"}}), 91),
	 make_pair(vector<vector<string>>({
			{ "Barry", "-66"},
			{ "Barry", "-65"},
			{ "Alfred", "-122"}}), -66)
	};
	bool passed=true;
	for(unsigned int ii=0;ii<testCases.size();ii++){
		int actual=bestAverageGrade(testCases[ii].first);
		if(actual!=testCases[ii].second) {
			passed=false;
			cout<<"failed for case"<<ii<<,"expected"<<testCases[ii].second<<",actual"<<actual<<endl;
		}
	}
	return passed;
}

int main()
{
	if(doTestsPass()) {
		cout<<"All tests pass"<<endl;
	} else {
		cout<<"All tests pass"<<endl;
	}
	return 0;
}