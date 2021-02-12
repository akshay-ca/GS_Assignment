#include <iostream>
#include <set>
#include <cmath>

using namespace std;

set <pair<char, char>> AllPossiblePositions;

void CalculatePositions()
{
	static set <pair<char, char>> PossibleMoves{ { -2, -1 }, { -2, 1 }, { 2, -1 }, { 2, 1 }, { -1, -2 }, { -1, 2 }, { 1, -1 }, { 1, 2 } };
	set <pair<char, char>> NextAllPossiblePositions;

	for (auto & PairElement : PossibleMoves) {
		for (auto & EachPossiblePosition : AllPossiblePositions) {
			pair<char, char> EachMove(PairElement.first + EachPossiblePosition.first, PairElement.second + EachPossiblePosition.second);
			if ((0 <= EachMove.first) && (EachMove.first <= 7) && (0 <= EachMove.second) && (EachMove.second <= 7)) {
				NextAllPossiblePositions.insert(EachMove);
			}
		}
	}
	AllPossiblePositions = NextAllPossiblePositions;
}

double Probability(int x, int y, int n)
{
	if (0 == n) {
		return 1;
	}
	AllPossiblePositions.clear();
	AllPossiblePositions.insert({ x, y });

	for (int i = 0; i < n; i++) {
		CalculatePositions();
	}

	int TotalEndPosition = AllPossiblePositions.size();

	double Probability = pow(0.125, n) * (TotalEndPosition);
	return Probability;
};

int doTestsPass() {
	// todo: implement more tests, please
	// feel free to make testing elegant
	int result = 1;
	//Start in a corner, no moves
	result &= Probability(0, 0, 0) == 1.0;
	//Start in the middle, one move
	result &= Probability(3, 3, 1) == 1.0;
	//Start in a corner, one move
	result &= Probability(0, 0, 1) == 0.25;

	return result;
};

int main() {
	if (doTestsPass())
	{
		cout << "All Tests pass\n" << endl;
	}
	else
	{
		cout << "There are test failures\n" << endl;
	}
	return 0;
}