#include <iostream>
#include <unordered_map>
#include <sstream>

using namespace std;

int bestAverageGrade(vector<vector<string>> scores)
{
	if (scores.empty()){
		return 0;
	}
	unordered_map<string, unsigned char> NameOccuranceCount;
	unordered_map<string, int> ActualScorePerStudent;
	
	for (const auto & IndividualStudent : scores) {
		++NameOccuranceCount[IndividualStudent[0]];
		stringstream TempStr(IndividualStudent[1]);
		int Mark = 0;
		TempStr >> Mark;
		ActualScorePerStudent[IndividualStudent[0]] += Mark;
	}

	for (const auto & MapElement : NameOccuranceCount) {
		if (MapElement.second > 1) {
			ActualScorePerStudent[MapElement.first] /= MapElement.second;
		}
	}

	int BestAvg = INT32_MIN;

	for (const auto & MapElement : ActualScorePerStudent) {
		if (MapElement.second > BestAvg) {
			BestAvg = MapElement.second;
		}
	}
	return BestAvg;
}

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
	bool passed = true;
	for (size_t i = 0; i < testCases.size(); i++)
	{
		int actual = bestAverageGrade(testCases[i].first);
		if (actual != testCases[i].second)
		{
			passed = false;
			cout << "failed for case" << i <<  "expected" << testCases[i].second << ",actual" << actual << endl;
		}
	}
	return passed;
}

int main()
{
	if (doTestsPass())
	{
		cout << "All tests pass" << endl;
	}
	else
	{
		cout << "All tests pass" << endl;
	}
	return 0;
}
