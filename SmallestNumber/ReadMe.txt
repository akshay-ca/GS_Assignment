* Instructions to the candidate
1) The execution entry point is main().
2) Consider adding some additional test in doTestspass().
3) Implement FindMin(int a[]) correctly.
4) If time permits, discuss the solution in case there are duplicates in the array.

*Pseudo Code

#include<iostream>

/** int Findmin(int a[])
  * Returns the smallest number in array that has been rotated
  * For example - Array {3,4,5,6,1,2} returns 1
  * Input array was originally sorted in incresing orders
  * Findmin must have 0 (logn 0 runtime
  * Assume that the array does not have any duplicates. **/

int FindMin(int a[]) , int size)
{
      //TODO:Implement solution here
      return 0;
}

/** int doTestsPass()
  *Returns true if all tests pass . Otherwise returns false. **/

int doTestsPass()
{
	int result=true;
	int int_size=sizeof(int);

	int x[]={3,4,5,6,1,2};
	result=result && (FindMin(x, sizeof(x)/int_size)==1);
	int y[]={2,1};
	result=result && (FindMin(y, sizeof(y)/int_size)==1);
	int z[]={1};
	result=result && (FindMin(z, sizeof(z)/int_size)==1);
	return result;
}

int main()
{
	if(doTestsPass()) {
		cout<<"All tests Pass"<<endl;
	} else {
		cout<<"there are test failures"<<endl;
	}
	return 0;
}