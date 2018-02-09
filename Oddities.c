/*
Some numbers are just, well, odd. For example, the number 3 is odd, because it is not a multiple of two.
Numbers that are a multiple of two are not odd, they are even.
More precisely, if a number n can be expressed as n = 2 * k for some integer k, then n is even.
For example, 6 = 2 * 3 is even.

Some people get confused about whether numbers are odd or even.
To see a common example, do an internet search for the query “is zero even or odd?”
(Don’t search for this now! You have a problem to solve!)

Write a program to help these confused people.

Input Format

Input begins with an integer 1 = n = 20 on a line by itself,
indicating the number of test cases that follow.
Each of the following n lines contain a test case consisting of a single integer -10 = x = 10.

Output Format

For each x, print either ‘x is odd’ or ‘x is even’ depending on whether x is odd or even.

Sample Input

3
10
9
-5

Sample Output

10 is even
9 is odd
-5 is odd

Explanation

Source: 2013 ICPC North America Qualifier
*/


#include<stdio.h>

int main()
{
	int i,t,n;
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
		scanf("%d",&n);
		if(n%2==0)
		{
			printf("%d is even\n",n);
		}
		else
		{
			printf("%d is odd\n",n);
		}
		
	}
	return 0;
}
