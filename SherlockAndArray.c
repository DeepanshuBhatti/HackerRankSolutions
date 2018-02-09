/*
Watson gives an array A1,A2...AN to Sherlock. Then he asks him to find if there exists an element in the array, such that, the sum of elements on its left is equal to the sum of elements on its right. If there are no elements to left/right, then sum is considered to be zero.
Formally, find an i, such that, A1+A2...Ai-1 = Ai+1+Ai+2...AN.

Input Format 
The first line contains T, the number of test cases. For each test case, the first line contains N, the number of elements in the array A. The second line for each testcase contains N space separated integers, denoting the array A.

Output Format 
For each test case, print YES if there exists an element in the array, such that, the sum of elements on its left is equal to the sum of elements on its right, else print NO.

Constraints 
1 = T = 10 
1 = N = 105 
1 = Ai = 2*10^4 for 1 = i = N

Sample Input
2
3
1 2 3
4
1 2 3 3

Sample Output
NO

YES
Explanation 
For test case 1, no such index exists. 
For test case 2, A[1]+A[2]=A[4], therefore index 3 satisfies.
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{
	int t,i,j,n,a[100000],L,R,k;
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
		L = 0;
		R = 0;
		k = 0;
		scanf("%d",&n);
		for(j=0;j<n;j++)
		{
			scanf("%d",&a[j]);
			R = R + a[j];
		}
		for(j=0;j<n;j++)
		{
			R = R - a[j];
			if(R==L)
			{
				k++;
				continue;
			}
			L = L + a[j];
		}
		if(k>0)
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	
	}
    return 0;
}

