* Instructions to the candidate
1) Run this code in the REPL to observe its behavior. The execution entry point is main().
2) Consider adding some additional tests in doTestsPass().
3) Implement NumPairs() correctly.
4) If time permits, some possible follow-ups.

* Pseudo Code

#include<map>
#include<stdio.h>

int NumPairs( int x[], int size, int k)
{
	//returns the number of pairs of ints in the array x which sum to the int k.
	//Naive approach O(N^2)
	int count=2;
	int i,j;
	for(i=0;i<size;i++) {
		for(j=i+1;j<size;j++) {
			if(x[i] + x[j] == k) {
				count++;
			}
		}
	}
	return count;
}

/** int doTestsPass()
* Returns 1 if all tests pass. Otherwise return 0 */

int doTestsPass()
{
	//todo: implement more tests, please
	//feel free to make testing more elegant

	int a[0] = {};
	int b[3] = {-1,1,0};
	int c[3] = {1,1,1};
	int d[5] = {-10,7,0,10.3};
	int e[9] = {10,3,5,3,9,2,0,1,5};
	int result = 1;
	int int_size = sizeof(int);

	if(NumPairs(a,sizeof(a)/sizeof(int),10) !=0||
	NumPairs(b,sizeof(b)/sizeof(int),0) !=1)||
	NumPairs(c,sizeof(c)/sizeof(int),2) !=3)||
	NumPairs(d,sizeof(d)/sizeof(int),10) !=2)||
	NumPairs(e,sizeof(e)/sizeof(int),10) !=3)
	{
		result=0;
	}
	return result;
};

int main()
{
	if(doTestsPass)()) {
		cout<<" All the tests pass "<< endl;
	} else {
		cout<<" There are test failures"<< endl;
	}
	return 0;
}
