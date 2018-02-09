/*
Given a triangle of numbers where each number is equal to the sum of the three numbers on top of it,
find the first even number in a row.

Explanatory Note: The vertex of the triangle (at the top) is 1. The structure of the triangle is shown below.
Each number is equal to the sum of the numbers at the following positions: Position X: immediately above it.
Position Y: to the immediate left of X. Position Z: to the immediate right of X. If there are no numbers at positions X, Y, or Z,
then assume those positions are occupied by a zero (0). This can occur for positions at the edge. 

Here are four rows of the triangle:
          1
      1   1  1
   1  2   3  2  1
1  3  6   7  6  3  1

Input Format and Constraints 
First line contains a number T (number of test cases).
Each of the next T lines contain a number N (the row number, assuming that the top vertex of the triangle is Row 1).

Output Format 
For each test case, display an integer that denotes the position of the first even number. 
Note: Assume that the left most number in a row is Position 1.
If there is no even number in a row, print -1.

Constraints 
1<=T<=100 
3<=N<=1000000000

Sample Input 
2
3
4

Sample Output 
2
3
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{
	int t,i;
	long long int n,j;
	scanf("%d",&t);
	if(t<1 || t>100)
	{
		exit(0);
	}
	for(i=0;i<t;i++)
	{
		scanf("%lld",&n);
		if(n<3 || n>1000000000)
		{
			exit(0);
		}
		if(n%2 != 0)
		{
			printf("2\n");
		}
		else
		{
			n = n/2;
			if(n%2 == 0)
			{
				printf("3\n");
			}
			else
			{
				printf("4\n");
			}
		}
	}
    return 0;
}

