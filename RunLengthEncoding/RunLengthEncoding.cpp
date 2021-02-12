#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

string rle(string testString)
{
	if (testString.empty()) return "";

	string str;
	unordered_map<char, size_t> CharCount;

	for (const char & ch : testString) {
		++CharCount[ch];
	}

	for (const auto MapElement : CharCount){
		str.push_back(MapElement.first);
		str.append(to_string(MapElement.second));
	}
	return str;
}

bool doTestsPass()
{
	bool result;
	result = rle(string("aaa")) == string("a3");
	result = result && rle(string("aabbc")) == string("a2b2c1");
	return result;
}

int main()
{
	if (doTestsPass()){
		cout << "All tests Pass" << endl;
	}
	else{
		cout << "there are test failures" << endl;
	}
	return 0;
}