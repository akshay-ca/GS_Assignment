#include <iostream>

using namespace std;

int FindMin(int a[], size_t size)
{
	if (size == 0) return -1;

	size_t Left = 0;
	size_t Right = size - 1;

	if ((size == 1) || (a[Right] > a[Left])) return a[0];
	if (size == 2) {
		if (a[Right] < a[Left]) return a[1];
		else return a[0];
	}

	while (Left < Right) {
		size_t Pivot = Left + (Right - Left) / 2;

		if ((Pivot > 0) && (a[Pivot] < a[Pivot - 1])) {
			return a[Pivot];
		}
		else if ((a[Pivot] > a[Left]) && (a[Pivot] > a[Right])){
			Left = Pivot + 1;
		}
		else {
			Right = Pivot - 1;
		}
	}

	return a[Left];
}

bool doTestsPass()
{
	bool result = true;
	size_t int_size = sizeof(int);

	int x[] = { 3,4,5,6,1,2 };
	result = result && (FindMin(x, sizeof(x) / int_size) == 1);
	int y[] = { 2,1 };
	result = result && (FindMin(y, sizeof(y) / int_size) == 1);
	int z[] = { 1 };
	result = result && (FindMin(z, sizeof(z) / int_size) == 1);
	return result;
}

int main()
{
	if (doTestsPass())
	{
		cout << "All tests Pass" << endl;
	}
	else
	{
		cout << "there are test failures" << endl;
	}
	return 0;
}