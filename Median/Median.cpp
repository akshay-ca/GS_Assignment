#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

double findMedianSortedArrays(int a[], int a1, int b[], int b1)
{
	vector<int> Result(a1+b1);
	merge(a, a+a1, b, b+b1, Result.begin());
	
	double dResult;
	if (Result.size() % 2)
		dResult = Result[(Result.size() / 2)];
	else
		dResult = (Result[(Result.size() / 2)] + Result[(Result.size() / 2) - 1]) / 2.0;

	return dResult;
}

int doTestsPass() {
	//todo: implement more tests, please
	//feel free to make testing more elegant
	int result = 1;
	int a[] = { 1,3 };
	int b[] = { 2,4 };

	int c[] = { 1,3 };
	int d[] = { 2 };


	int a1 = sizeof(a) / sizeof(*a);

	int b1 = sizeof(b) / sizeof(*b);

	int c1 = sizeof(c) / sizeof(*c);

	int d1 = sizeof(d) / sizeof(*d);

	result &= findMedianSortedArrays(a, a1, b, b1) == 2.5;
	result &= findMedianSortedArrays(c, c1, d, d1) == 2.0;

	return result;
}

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