* Instructions to the candidate
1) Run this code in the REPL to observe its behavior. The execution entry point is main().
2). Find the Median of Two sorted arrays.

* Pseudo Code

#include<iostream>
#include<stdio.h>
#include<climits>
using namespace std;

double getkth(int a[],int m, int aStart, int b[], int n, int bStart,int k) {
	if(aStart > m-1) return b[bStart + k - 1];
	if(aStart > n-1) return a[aStart + k - 1];
	if(k == 1) return min(a[aStart], b[bStart]);
	int aMid = INT_MAX;
	int bMid = INT_MAX;

	if(aStart + k / 2 - 1 < m) aMid = a[aStart + k / 2 - 1];
	if(bStart + k / 2 - 1 < m) bMid = b[bStart + k / 2 - 1];

	if (aMid < bMid)
		return getkth(a,m,aStart + k / 2,b,n,bStart,k - k / 2; //Check: aRight + bLeft
	else
		return getkth(a,m,bStart + k / 2,b,n,bStart,k - k / 2; //Check: bRight + aLeft
}

double findMedianSortedArraya(int a[], int a1,int b[], int b1)
{
	int l = (a1 + b1 + 1) / 2;
	int r = (a1 + b1 + 2) / 2;
	return (getkth(a,a1,0,b,b1,0,l) + getkth(a,a1,b,b1,0,r)) / 2.0;
}


/** int doTestsPass()
* Returns 1 if all  tests pass. Otherwise, returns 0 */

int doTestsPass(){
	//todo: implement more tests, please
	//feel free to make testing more elegant
	int result = 1;
	int a[] = {1,3};
	int b[] = {2,4};

	int c[] = {1,3};
	int d[] = {2};
	 
	int a1 = sizeof(a) / sizeof(*a);
	int b1 = sizeof(b) / sizeof(*b);
	int c1 = sizeof(c) / sizeof(*c);
	int d1 = sizeof(d) / sizeof(*d);
	result &= findMedianSortedArrays(a,a1,b,b1) == 2.5;
	result &= findMedianSortedArrays(c,c1,d,d1) == 2.0;
	return result;
}

int main()
{
	if(doTestsPass)()) {
		cout<<" All the tests pass "<< endl;
	} else {
		cout<<" There are test failures"<< endl;
	}
	return 0;
}