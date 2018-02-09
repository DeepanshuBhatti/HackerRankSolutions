/*
A group of scientists have broken down species DNA into sequences of integers. They determine that two species with the respective DNA sequences A and B are considered to be related if a non-decreasing sequence C of the same length can be found, such that Ci=Ai or Ci=Bi.
Given the DNA sequences for two species, help the scientists determine if they are related.

Input Format
The first line contains an integer, T, the number of test cases.
For each test case: 
The first line contains an integer, N, the length of the DNA sequence. 
The second line contains a sequence of space-separated integers describing species A. 
The third line contains a sequence of space-separated integers describing species B.

Constraints: 
1<=T<=5 
1<=N<=10^5 
0<=Ai,Bi<=10^10
Output Format
On a new line for each test case, print YES if a non-decreasing sequence of the same length can be found (i.e.: species are related) or NO if it cannot.

Sample Input
3
3
1 2 3
4 4 4
3
3 2 1
6 5 4
2
1 0
10 2

Sample Output
YES
NO
YES

Explanation
Test Case 1: We could have C=1 2 4 
Test Case 2: No non-decreasing sequence C is possible. 
Test Case 3: We could have C=1 2.
*/

#include<stdio.h>

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		unsigned long long int n,i,m;
		scanf("%llu",&n);
		unsigned long long int a[100000],b[100000];
		for(i=0;i<n;i++)
		{
			scanf("%llu",&a[i]);
		}
		for(i=0;i<n;i++)
		{
			scanf("%llu",&b[i]);
		}
		if(a[0]<b[0])
		{
			m = a[0];
		}
		else
		{
			m = b[0];
		}
		for(i=0;i<n-1;i++)
		{
			if(m<=a[i+1] && m<=b[i+1])
			{
				if(a[i+1]>b[i+1])
				{
					m = b[i+1];
				}
				else
				{
					m = a[i+1];
				}
			}
			else if(m<=a[i+1])
			{
				m = a[i+1];
			}
			else if(m<=b[i+1])
			{
				m = b[i+1];
			}
			else
			{
				printf("NO\n");
				i = n;
			}
		}
		if(i==n-1)
		{
			printf("YES\n");
		}
	}
	return 0;
}
