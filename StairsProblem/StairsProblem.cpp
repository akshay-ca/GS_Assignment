#include <iostream>

using namespace std;

int countStepsRec(int n, bool RetainRecRetVal = false)
{
	static int i = 0;

	if (false == RetainRecRetVal) {
		i = 0;
	}

	if (0 == n)
		return ++i;

	if (n >= 3) {
		countStepsRec(n - 3, true);
	}
	if (n >= 2) {
		countStepsRec(n - 2, true);
	}
	if (n >= 1) {
		countStepsRec(n - 1, true);
	}

	return i;
}

int countSteps(int n)
{
	if (n <= 0) return 0;
	return countStepsRec(n);
}

bool doTestsPass()
{
	//todo: implement more tests, if you'd like 
	return countSteps(3) == 4
		&& countSteps(4) == 7
		&& countSteps(1) == 1
		&& countSteps(2) == 2
		&& countSteps(0) == 0
		&& countSteps(-5) == 0
		&& countSteps(10) == 274
		&& countSteps(36) == 2082876103; // will cause naive solutions to time out
}

int main()
{
	//Run the tests
	if (doTestsPass())
	{
	cout << " All the tests pass " << endl;
	}
	else
	{
		cout << " There are test failures" << endl;
	}
	//Try some examples
	for (int n = -5; n <= 10; n++)
	{
		cout << n << "steps" << countSteps(n) << endl;
	}

	return 0;
}