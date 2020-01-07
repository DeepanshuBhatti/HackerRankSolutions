/*
Manasa is out on a hike with friends. She finds a trail of stones with
numbers on them. She starts following the trail and notices that two
consecutive stones have a difference of either a or b. Legend has it
that there is a treasure trove at the end of the trail and if Manasa
can guess the value of the last stone, the treasure would be hers. Given
that the number on the first stone was 0, find all the possible values for the number on the last stone.

Note : The numbers on the stones are in increasing order

Input Format 
The first line contains an integer T i.e. the number of Test cases. T testcases follow. 
Each testcase has 3 lines. The first line contains n ( the number of stones ) The second line contains a. The third line contains b.

Output Format 
Space separated list of numbers which are the possible values of the last stone in increasing order.

Constraints 
1 <= T <= 10 
1 <= n, a, b <= 10^3

Sample Input
2
3 
1
2
4
10
100

Sample Output
2 3 4 
30 120 210 300 

Explanation

All possible series for first test cases are given below.
0,1,2
0,1,3
0,2,3
0,2,4

Hence the answer 2 3 4.

Series with different number of final step for second test cases are

0, 10, 20, 30
0, 10, 20, 120
0, 10, 110, 120
0, 10, 110, 210
0, 100, 110, 120
0, 100, 110, 210
0, 100, 200, 210
0, 100, 200, 300
hence the answer 30 120 210 300
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{
	int t,n,a,b,i,j,ans;
	scanf("%d",&t);
	if(t<1 || t>10)
	{
		exit(0);
	}
	for(i=0;i<t;i++)
	{
		scanf("%d",&n);
		if(n<1 || n>1000)
		{
			exit(0);
		}
		scanf("%d",&a);
		if(a<1 || a>1000)
		{
			exit(0);
		}
		scanf("%d",&b);
		if(b<1 || b>1000)
		{
			exit(0);
		}
		if(a>b)		//swap a and b
		{
			a = a+b;
			b = a-b;
			a = a-b;
		}
		for(j=0;j<n;j++)
		{
			ans = ((n-1-j)*a) + (j*b);
			printf("%d ",ans);
			if(a==b)
			{
				break;
			}
		}
		printf("\n");
	}
    return 0;
}

