#include<array>
#include<iostream>

constexpr size_t NO_OF_COORDINATES = 2;

using namespace std;

typedef array<int, NO_OF_COORDINATES> Position;

Position walk(std::string path)
{
	Position result{0,0};

	for (const char & ch : path){
		switch (ch){
		case 'U':{
			++result[1];
			break;
		}
		case 'D':{
			--result[1];
			break;
		}
		case 'L':{
			--result[0];
			break;
		}
		case 'R':{
			++result[0];
			break;
		}
		default:
			break;
		}
	}

	return result;
}

bool doTestsPass()
{
	bool result;
	result = walk("UUU") == Position{0,3};
	result = result && walk("ULDR") == Position{0,0};
	result = result && walk("ULLLDUDUUURLRLR") == Position{-2,3};
	result = result && walk("UP LEFT 2xDOWN DOWN RIGHT RIGHT UP UP") == Position{1,1};
	
	return result;
}

int main()
{
	if (doTestsPass()){
		cout << "All tests Pass" << endl;
	}
	else{
		cout << "There are test failures" << endl;
	}
	return 0;
}