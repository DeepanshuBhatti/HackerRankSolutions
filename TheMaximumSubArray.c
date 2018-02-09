/*
Given an array A={a1,a2,…,aN} of N elements, find the maximum possible sum of a

Contiguous subarray
Non-contiguous (not necessarily contiguous) subarray.
Empty subarrays/subsequences should not be considered.

This Youtube video by Ben Wright might be useful to understand the Kadane algorithm for the maximum subarray in a 1-D sequence.


Input Format

First line of the input has an integer T. T cases follow. 
Each test case begins with an integer N. In the next line, N integers follow representing the elements of array A.

Constraints:

1<=T<=10
1<=N<=10^5
-10^4<=ai<=10^4
The subarray and subsequences you consider should have at least one element.

Output Format

Two, space separated, integers denoting the maximum contiguous and non-contiguous subarray. At least one integer should be selected and put into the subarrays (this may be required in cases where all elements are negative).

Sample Input

2 
4 
1 2 3 4
6
2 -1 2 3 4 -5
Sample Output

10 10
10 11
Explanation

In the first case: 
The max sum for both contiguous and non-contiguous elements is the sum of ALL the elements (as they are all positive).

In the second case: 
[2 -1 2 3 4] --> This forms the contiguous sub-array with the maximum sum. 
For the max sum of a not-necessarily-contiguous group of elements, simply add all the positive elements.

*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{
	int t,i,n,j;
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
		scanf("%d",&n);
		int a[n],ncsum=0,csum=0,sum=0,val,neg=0,max=-100000;
		for(j=0;j<n;j++)
		{
			scanf("%d",&a[j]);
			if(a[j]>0)
			{
				ncsum = ncsum + a[j];
			}
			else
			{
				neg++;
			}
			if(a[j]>max)
			{
				max = a[j];
			}
		}
		for(j=0;j<n;j++)
		{
			val = sum + a[j];
			if(val>0)
			{
				sum = val;
			}
			else
			{
				sum = 0;
			}
			if(sum>csum)
			{
				csum = sum;
			}
		}
		if(neg == n)
		{
			ncsum = max;
			csum = max;
		}
		printf("%d %d\n",csum,ncsum);
	}
    return 0;
}

