/*
Given a squared sized grid G of size N in which each cell has a lowercase letter. Denote the character in the ith row and in the jth column as G[i][j].

You can perform one operation as many times as you like: Swap two column adjacent characters in the same row G[i][j] and G[i][j+1] for all valid i,j.

Is it possible to rearrange the grid such that the following condition is true?

G[i][1]<=G[i][2]<=....<=G[i][N] for 1<=i<=N and 
G[1][j]<=G[2][j]<=....<=G[N][j] for 1<=j<=N
In other words, is it possible to rearrange the grid such that every row and every column is lexicographically sorted?

Note: c1=c2, if letter c1 is equal to c2 or is before c2 in the alphabet.

Input Format
The first line begins with T, the number of testcases. In each testcase you will be given N. The following N lines contain N lowercase english alphabet each, describing the grid.

Output Format
Print T lines. On the ith line print YES if it is possible to rearrange the grid in the ith testcase or NO otherwise.

Constraints 
1<=T<=100 
1<=N<=100 
G[i][j] will be a lower case letter

Sample Input
1
5
ebacd
fghij
olmkn
trpqs
xywuv

Sample Output
YES

Explanation
The grid in the first and only testcase can be reordered to
abcde
fghij
klmno
pqrst
uvwxy
This fulfills the condition since the rows 1, 2, ..., 5 and the columns 1, 2, ..., 5 are all lexicographically sorted.
*/

#include<stdio.h>
#include<string.h>

void sort(char s[],int n)
{
	int i,j;
	char c;
	for(i=0;i<n-1;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(s[i]>s[j])
			{
				c = s[i];
				s[i] = s[j];
				s[j] = c;
			}
		}
	}
	return;
}

int main()
{
	int t,i;
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
		int n,j,k;
		scanf("%d",&n);
		char s[n][n];
		for(j=0;j<n;j++)
		{
			scanf("%s",s[j]);
			sort(s[j],n);
		}
		for(j=0;j<n;j++)
		{
			for(k=0;k<n-1;k++)
			{
				if(s[k][j] > s[k+1][j])
				{
					printf("NO\n");
					k=n;
					j=n;
				}
			}
		}
		if(j==n)
		printf("YES\n");
	}
	return 0;
}
