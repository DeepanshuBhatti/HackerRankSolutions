/*
By starting at the top of the triangle below and moving to adjacent numbers on the row below, the maximum total from top to bottom is 23. The path is denoted by numbers in bold.

3 
74 
246 
8593

That is, 3+7+4+9=23.

Find the maximum total from top to bottom of the triangle given in input.

Input 
First line contains T, the number of testcases. For each testcase: 
First line contains N, the number of rows in the triangle. 
For next N lines, i'th line contains i numbers.

Output 
For each testcase, print the required answer in a newline.

Constraints 
1<=T<=10 
1<=N<=15 
numbers E [0,100)

Sample input
1
4
3
7 4
2 4 6
8 5 9 3

Sample output
23
*/

#include<stdio.h>
#include<math.h>

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,j,i,x;
		scanf("%d",&n);
		int a[n][n];
		for(i=0;i<n;i++)
		{
			for(j=0;j<=i;j++)
			{
				scanf("%d",&a[i][j]);
			}
		}
		for(i=n-1;i>0;i--)
		{
			for(j=0;j<i;j++)
			{
				if(a[i][j]<a[i][j+1] && j+1<n)
				{
					a[i-1][j] = a[i-1][j] + a[i][j+1];
				}
				else
				{
					a[i-1][j] = a[i-1][j] + a[i][j];
				}
				//printf("%d ",a[i-1][j]);
			}
			//printf("\n");
		}
		printf("%d\n",a[0][0]);
	}
	return 0;
}

