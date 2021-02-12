#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <map>
#include <algorithm>

using namespace std;

vector<unordered_set<string>> groupByAnagrams(const vector<string> & words)
{
	vector<string> SortedVectOfStrs;
	for (const string & str : words) {
		string Tempstr = str;
		std::sort(Tempstr.begin(), Tempstr.end());
		SortedVectOfStrs.push_back(Tempstr);
	}

	unordered_map<string, size_t> StrCount;
	vector<unordered_set<string>> Result;
	for (const string & str : SortedVectOfStrs) {
		++StrCount[str];
	}

	for (const auto & MapElement : StrCount) {
		unordered_set<string> TempResults;
		if (MapElement.second > 1) {
			TempResults.clear();
			for (size_t i = 0; i < SortedVectOfStrs.size(); ++i) {
				if (SortedVectOfStrs[i] == MapElement.first)
				{
					TempResults.insert(words[i]);
				}
			}
			Result.push_back(TempResults);
		}
	}

	return Result;
}

bool doTestsPass()
{
	cout << " Start test...." << endl;

	vector<string>words = { "cat","dog","god","cat" };
	vector<unordered_set<string>> groups = groupByAnagrams(words);

	//Excepted sets
	unordered_set<string> set1({ "cat" });
	unordered_set<string> set2({ "dog","god" });

	bool result = true;
	result = result && (groups.size() == (unsigned int)2);
	result = result && (find(groups.begin(), groups.end(), set1) != groups.end());
	result = result && (find(groups.begin(), groups.end(), set2) != groups.end());
	return result;
}

int main()
{
	if (doTestsPass()) {
		cout << "All tests passes." << endl;
	}
	else {
		cout << "Test failed." << endl;
	}
	cin.get();
	return 0;
}