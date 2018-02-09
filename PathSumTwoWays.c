/*
In the 5×5 matrix below, the minimal path sum from the top left to the bottom right, by only moving to the right and down, is indicated in bold and is equal to 2427.

131 673 234 103 18
201 96 342 965 150
630 803 746 422 111
537 699 497 121 956
805 732 524 37 331

Find the minimum path sum in given matrix.

Input Format 
Each testcase begins with an integer N followed by N lines containing the description of the matrix.

Constraints 
1<=N<=1000 
1<=values of elements in matrix<=10^9

Output Format 
A single line for each testcase containing the value of the minimal path sum.

Sample Input
5
131 673 234 103 18
201 96 342 965 150
630 803 746 422 111
537 699 497 121 956
805 732 524 37 331

Sample Output
2427
*/

#include<stdio.h>

int main()
{
	int i,j,n;
	scanf("%d",&n);
	long long int a[n][n];
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%lld",&a[i][j]);
			if(i==0 && j>0)
			{
				a[i][j] = a[i][j] + a[i][j-1];
			}
			if(j==0 && i>0)
			{
				a[i][j] = a[i][j] + a[i-1][j];
			}
		}
	}
	for(i=1;i<n;i++)
	{
		for(j=1;j<n;j++)
		{
			if(a[i-1][j]>a[i][j-1])
			{
				a[i][j] = a[i][j] + a[i][j-1];
			}
			else
			{
				a[i][j] = a[i][j] + a[i-1][j];
			}
		}
	}
	printf("%lld \n",a[n-1][n-1]);
	return 0;
}
