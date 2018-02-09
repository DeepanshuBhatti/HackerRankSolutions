/*
Watson gives two integers A & B to Sherlock and asks if he can count
the number of square integers between A and B (both inclusive).

A square integer is an integer which is the square of any integer.
For example, 1, 4, 9, 16 are some of the square integers
as they are squares of 1, 2, 3, 4 respectively.

Input Format 
First line contains T, the number of testcases. T test cases follow, each in a newline. 
Each testcase contains two space separated integers denoting A and B.

Output Format 
For each testcase, print the required answer in a new line.

Constraints 
1 = T = 100 
1 = A = B = 10^9

Sample Input

2
3 9
17 24
Sample output

2
0
Explanation 
In the first testcase, 4 and 9 are the square numbers. 
In second testcase no square numbers exist between 17 and 24 (both inclusive).
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{
	int t,i,x,y;
	long long int a,b,j;
	scanf("%d",&t);
	if(t<1 || t>100)
	{
		exit(0);
	}
	int ans[100]={0};
	for(i=0;i<t;i++)
	{
		scanf("%lld",&a);
		if(a<1 || a>1000000000)
		{
			exit(0);
		}
		scanf("%lld",&b);
		if(b<1 || b>1000000000 || b<a)
		{
			exit(0);
		}
		do
		{
			x = sqrt(a);
			if(a != x*x)
			{
				a++;
			}
		}
		while(x*x < a);
		x = sqrt(a);
		do
		{
			y = sqrt(b);
			if(b != y*y)
			{
				b--;
			}
		}
		while(y*y > b);
		y = sqrt(b);
		for(j=x;j<=y;j++)
		{
			ans[i]++;
		}
	}
	for(i=0;i<t;i++)
	{
		printf("%d\n",ans[i]);	
	}
    return 0;
}

