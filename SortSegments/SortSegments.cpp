#include <iostream>
#include <set>
#include <vector>
#include <list>

using namespace std;

bool AddToEndOrBeg(list<pair<int, int>> & ActualOutput, const pair<int, int> & Insert)
{
	bool RetVal = true;
	if (Insert.second == ActualOutput.front().first) {
		ActualOutput.emplace_front(Insert);
	}
	else if (Insert.first == ActualOutput.back().second) {
		ActualOutput.emplace_back(Insert);
	}
	else {
		RetVal = false;
	}
	return RetVal;
}

vector<pair<int, int> > sortSegments(const vector<pair<int, int> >& segments) {

	list<pair<int, int>> ActualOutput;
	set<pair<int, int>> ToBeInserted;
	ActualOutput.emplace_back(segments[0]);

	for (size_t i = 1; i < segments.size(); ++i){
		for (auto & EachSetElement : ToBeInserted) {
			AddToEndOrBeg(ActualOutput, EachSetElement);
		}

		if (!AddToEndOrBeg(ActualOutput, segments[i])) {
			ToBeInserted.insert(segments[i]);
		}
	}

	vector<pair<int, int> > ActualOutputVector;
	ActualOutputVector.reserve(segments.size());
	for (auto & ListElement : ActualOutput) {
		ActualOutputVector.emplace_back(ListElement);
	}

	return ActualOutputVector;
}

bool testBasicSort() {
	bool RetVal = true;
	vector<pair<int, int> >jumbled_segments = { { 4,5} , {9,4}, {5,1}, {11,9} };
	auto actual_continous_path = sortSegments(jumbled_segments);
	vector<pair<int, int> >excepted_continous_path = { { 11,9} , {9,4}, {4,5}, {5,1} };

	RetVal = RetVal && excepted_continous_path == actual_continous_path;

	jumbled_segments = { { 0,5} , {-2,0}, {5,1}, {11,-2}, {1, 6} };
	excepted_continous_path = { { 11,-2} , {-2,0}, {0,5}, {5,1}, {1, 6}};
	actual_continous_path = sortSegments(jumbled_segments);
	RetVal = RetVal && excepted_continous_path == actual_continous_path;
	return (RetVal);
}

bool doTestsPass() {
	auto all_pass = true;
	all_pass = all_pass && testBasicSort();

	return all_pass;
}

int main() 
{
	if (doTestsPass()) {
		cout << "All tests pass" << endl;
	}
	else {
		cout << "some tests fail" << endl;
	}
	return 0;
}