* Instructions to the candidate.
1) Run this code in the REPL to observe its behavior. The execution entry point is main().
2) Consider adding some additional tests in doTestPass().
3) Implement MyhashMap correctly.
4) If time permits, some possible follow-ups.

*Pseudo Code

 #include <iostream>
 #include <vector>
 #include <list>

 using namespace std;

/**
* class MyHashMap
*
* Associates a key-value pair in memory such that lookups
* and inserts can be performed in 0(1) time for a reasonable
* small set of data, and scales linearly (at worst) for larger
* sets of key-value pairs.
*
*
* Each unique key is associated with one single value.
*/

template<typename K,typename V>
class MyHashMap
{
public:
	MyHashMap()
	{
	}

	~MyHashMap()
	{
	}

	V& operator[](const K& key)
	{
	//todo : implement
	}
};

void doTestsPass()
{
	const list<pair<int, int>> testCases = { {1,2}, {3,4}, {5,6}, {1,7}, {1,8} };
	const list<pair<string, string>> stringTestCases = { {"one", "two"}, {"three", "four"}, {"one", "five"} };

	MyHashMap<int, int> map;
	MyHashMap<string, string> stringMap;
	bool passed = true;

	for (const auto test: testCases)
	{
		int key = test.first;
		int value = test.second;

		map[key] = value;

		if (value != map[key])
		{
			passed = false;

			cout << "Test case failed [" << key << ',' << value << ']' << endl;
		}
	}

	for (const auto test : stringTestCases)
	{

		string key = test.first;
		string value = test.second;

		stringMap[key] = value;

		if (value != stringMap[key])
		{
			passed = false;
			cout << "Test case failed [" << key << ',' << value << ']' << endl;
		}
	}

	if (passed)
	{
		cout << "All tests passed." << endl;
	}
}

int main() {
	doTestsPass();
	return 0;
}