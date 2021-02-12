#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

char findFirst(const string input)
{
	unordered_map<char, size_t> CharCountMap;
	for (const char & ch : input) {
		CharCountMap[ch]++;
	}

	char SingleOccuranceChar;

	for (const char & ch : input) {
		if (1 == CharCountMap[ch]){
			SingleOccuranceChar = ch;
			break;
		}
	}
	return SingleOccuranceChar;
}

bool doTestsPass()
{
	bool result = true;
	result &= findFirst("apple") == 'a';
	result &= findFirst("racecars") == 'e';
	result &= findFirst("ababdc") == 'd';
	return result;
}

int main()
{
	if (doTestsPass()){
		cout << "All test pass " << endl;
	}
	else{
		cout << "There are test failures" << endl;
	}

	return 0;
}