/*
Work out the first ten digits of the sum of N 50-digit numbers.

Input Format 
First line contains N, next N lines contain a 50 digit number each.

Output Format 
Print only first 10 digit of the final sum

Constraints 
1=N=10^3

Sample Input
5
37107287533902102798797998220837590246510135740250
46376937677490009712648124896970078050417018260538
74324986199524741059474233309513058123726617309629
91942213363574161572522430563301811072406154908250
23067588207539346171171980310421047513778063246676

Sample Output
2728190129
*/

#include<stdio.h>

int main()
{
	int i,t,c,j,x,ans[100],f[100];
	scanf("%d",&t);
	char s[1001][50];
	for(i=0;i<t;i++)
	{
		scanf("%s",s[i]);
	}	
	for(i=49;i>=0;i--)
	{
		x = 0;
		for(j=0;j<t;j++)
		{
			x = x + s[j][i] - '0';
		}
		ans[i] = x;
	}
	c = 0;
	for(i=49;i>=0;i--)
	{
		ans[i] = ans[i] + c;
		f[i] = (ans[i]%10);
		c = ans[i]/10;
	}
	i = 0;
	if(c!=0)
	{
		x = c;
		while(x!=0)
		{
			x =x/10;
			i++;
		}
		printf("%d",c);
	}
	for(j=0;j<10-i;j++)
	{
		printf("%d",f[j]);
	}

	return 0;
}
