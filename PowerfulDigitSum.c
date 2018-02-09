/*
A googol (100^100) is a massive number: one followed by one-hundred zeros. 100^100 is almost unimaginably large: one followed by two-hundred zeros. Despite their size, the sum of the digits in each number is only 1.

Considering natural numbers of the form, ab, where a,b<N, what is the maximum digital sum?

Input Format 
Input contains an integer N

Output Format 
Print the answer corresponding to the test case.

Constraints 
5<=N<=200

Sample Input
5

Sample Output
13

Explanation 
4^4=256 and 2+5+6=13, which is the maximum digital sum for this range.
*/

#include<stdio.h>

int res[10000],l;

void mypow(int a,int b)
{
	l = 0;
	int j,i,x,c;
	x = a;
	while(x>0)
	{
		res[l] = x%10;
		x = x/10;
		l++;
	}
	for(i=0;i<b-1;i++)
	{
		c = 0;
		for(j=0;j<l;j++)
		{
			res[j] = res[j]*a + c;
			c = res[j]/10;
			res[j] = res[j]%10;
		}
		while(c>0)
		{
			res[l] = c%10;
			l++;
			c = c/10;
		}
	}
}

int main()
{
	int j,i,n,k,s,m=0;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			s = 0;
			mypow(i,j);	
			for(k=l-1;k>=0;k--)
			{
				s = s+res[k];
			}
			if(s>m)
			{
				m=s;
			}
		}
	}
	printf("%d\n",m);
	return 0;
}
