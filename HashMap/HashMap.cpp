#include <iostream>
#include <list>
#include <string>

using namespace std;

template<typename K, typename V>
class MyHashMap
{
	static const size_t NO_OF_LISTS = 11;
	list<pair<K, V>> HashList[NO_OF_LISTS];

	size_t HashFunction(int key);
	size_t HashFunction(string key);
	V& InsertThisKey(const K & key);
public:
	MyHashMap()
	{
	}

	~MyHashMap()
	{
	}

	V& operator[](const K& key)
	{
		list<pair<K, V>> & PossibleTargetList = HashList[HashFunction(key)];
		for (auto & EachItemInList : PossibleTargetList) {
			if (EachItemInList.first == key) {
				return EachItemInList.second;
			}
		}

		return InsertThisKey(key);
	}

};

template <typename K, typename V>
size_t MyHashMap<K, V>::HashFunction(int key)
{
	return key % 11;
}

template <typename K, typename V>
size_t MyHashMap<K, V>::HashFunction(string key)
{
	size_t hashValue = 0;
	size_t PositionVal = key.size();
	for (char ch : key) {
		hashValue += ch * PositionVal--;
	}
	return hashValue % 11;
}

template <typename K, typename V>
V& MyHashMap<K, V>::InsertThisKey(const K & key)
{
	size_t hashValue = HashFunction(key);
	pair<K, V> NewElement;
	NewElement.first = key;
	HashList[hashValue].emplace_back(NewElement);
	return HashList[hashValue].back().second;
}

void doTestsPass()
{
	const list<pair<int, int>> testCases = { {1,2}, {3,4}, {5,6}, {1,7}, {1,8} };
	const list<pair<string, string>> stringTestCases = { {"one", "two"}, {"three", "four"}, {"one", "five"} };

	MyHashMap<int, int> map;
	MyHashMap<string, string> stringMap;
	bool passed = true;

	for (const auto test : testCases)
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