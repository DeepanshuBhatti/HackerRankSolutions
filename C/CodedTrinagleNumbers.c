/*
The nth term of a sequence of triangle numbers is given by, 
tn = n*(n+1)/2

so the first ten triangle numbers are: 
1,3,6,10,15,21,28,36,45,55,...
You are given an integer. If it is a triangular number tn, print the term n corresponding to this number, else print -1

Input Format 
First line of input contains an integer T denoting the number of testcases. Each of the next T lines contains an integer.

Output Format 
Print the answer corresponding to each test case in a new line.

Constraints 
1<=T<=10^5 
1<=tn<=10^18

Sample Input #00:
3
2
3
55

Sample Output #00:
-1
2
10
*/

#include<stdio.h>
#include<math.h>
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		unsigned long long int n,a;
		scanf("%llu",&n);
		long long int b;
		double d;
		d = sqrt(1+8*n);
		d = (d-1)/2;
		b = (long long int)d;
		a = b*(b+1)/2;
		if(a==n)
		{
			printf("%lld\n",b);
		}
		else
		{
			printf("-1\n");
		}
	}
	return 0;
}
