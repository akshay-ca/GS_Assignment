#include <iostream>
#include <unordered_map>

using namespace std;

int NumPairs(int a[], const size_t size, int sum)
{
	unordered_map<int, size_t> ComplementArray;
	size_t count = 0;

	ComplementArray[sum - a[0]]++;

	for (int i = 1; i < size; ++i)
	{
		if (ComplementArray.find(a[i]) != ComplementArray.end()) {
			count += ComplementArray[a[i]];
		}
		ComplementArray[sum - a[i]]++;
	}

	return count;
}

int doTestsPass()
{
	//todo: implement more tests, please
	//feel free to make testing more elegant

	int a[1] = {};
	int b[3] = { 1, 2, -4 };
	int c[3] = { 1,1,1 };
	int d[5] = { -10,7,0,10,3 };
	int e[9] = { 10,3,5,3,9,2,0,1,5 };
	int result = 1;
	int int_size = sizeof(int);

	if ((NumPairs(a, sizeof(a) / sizeof(int), 10) != 0) ||
	(NumPairs(e, sizeof(e) / sizeof(int), 10) != 3) ||
	(NumPairs(b, sizeof(b) / sizeof(int), -2) != 1) ||
	(NumPairs(d, sizeof(d) / sizeof(int), 10) != 2) ||
	(NumPairs(c, sizeof(c) / sizeof(int), 2) != 3))	{
		result = 0;
	}
	return result;
};

int main()
{
	if (doTestsPass())
	{
	cout << " All the tests pass " << endl;
	}
	else
	{
		cout << " There are test failures" << endl;
	}
	return 0;
}