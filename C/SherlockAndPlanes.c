/*
Watson gives four 3-dimensional points to Sherlock and asks him if they all lie in the same plane. Your task here is to help Sherlock.

Input Format 
First line contains T, the number of testcases. 
Each test case consists of four lines. Each line contains three integers, denoting xi yi zi.

Output Format 
For each test case, print YES or NO whether all four points lie in same plane or not, respectively.

Constraints 
1 = T = 10^4 
-10^3 = xi,yi,zi = 10^3

Sample Input

1
1 2 0
2 3 0
4 0 0
0 0 0
Sample Output

YES
Explanation 
All points have zi = 0, hence they lie in the same plane, and output is YES
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{
	int t,i,j,k,a[3]={0},b[3]={0},c[3]={0},d[3]={0},x;
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
		int m[3][3]={0};
		for(j=0;j<3;j++)
		{
			scanf("%d",&a[j]);
		}
		for(j=0;j<3;j++)
		{
			scanf("%d",&b[j]);
		}
		for(j=0;j<3;j++)
		{
			scanf("%d",&c[j]);
		}
		for(j=0;j<3;j++)
		{
			scanf("%d",&d[j]);
		}
		for(j=0;j<3;j++)
		{
			m[0][j] = b[j] - a[j];
			m[1][j] = c[j] - a[j];
			m[2][j] = d[j] - a[j];
		}
		x = (m[0][0]*((m[1][1]*m[2][2]) - (m[1][2]*m[2][1]))) - (m[0][1] * ((m[1][0]*m[2][2]) - (m[1][2]*m[2][0]))) + (m[0][2]*((m[1][0]*m[2][1]) - (m[1][1]*m[2][0])));
		if(x == 0)
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	}
    return 0;
}

