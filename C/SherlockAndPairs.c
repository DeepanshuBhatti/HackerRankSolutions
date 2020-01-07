/*
Sherlock is given an array of N integers (A0, A1 ... AN-1 by Watson. Now Watson asks Sherlock how many different pairs of indices i and j exist such that i is not equal to j but Ai is equal to Aj.

That is, Sherlock has to count the total number of pairs of indices (i,j) where Ai =Aj AND i?j.

Input Format 
The first line contains T, the number of test cases. T test cases follow. 
Each test case consists of two lines; the first line contains an integer N, the size of array, while the next line contains N space separated integers.

Output Format 
For each test case, print the required answer on a different line.

Constraints 
1<=T<=10 
1<=N<=10^5 
1<=A[i]<=10^6

Sample input
2
3
1 2 3
3
1 1 2

Sample output
0
2

Explanation 
In the first test case, no two pair of indices exist which satisfy the given condition. 
In the second test case as A[0] = A[1] = 1, the pairs of indices (0,1) and (1,0) satisfy the given condition.
*/

#include<stdio.h>

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		long long int i,j,a[1000001] = {0};
		for(i=0;i<n;i++)
		{
			scanf("%lld",&j);
			a[j]++;
		}
		long long int ans=0;
		for(i=0;i<1000001;i++)
		{
			if(a[i]>1)
			{
				ans = ans + (a[i] * (a[i]-1));
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
