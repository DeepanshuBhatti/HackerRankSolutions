/*
You are given a square n×n map. Each cell of the map has a value in it denoting the depth of the appropriate area. We will call a cell of the map a cavity if and only if this cell is not on the border of the map and each cell adjacent to it has strictly smaller depth. Two cells are adjacent if they have a common side.

You need to find all the cavities on the map and depict them with character X.

Input Format

The first line contains an integer n (1=n=100), denoting the size of the map. Each of the following n lines contains n positive digits without spaces. A digit (1-9) denotes the depth of the appropriate area.

Output Format

Output n lines, denoting the resulting map. Each cavity should be replaced with character X.

Sample Input
4
1112
1912
1892
1234

Sample Output
1112
1X12
18X2
1234
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{
	int n,i,j,a[100][100];;
	char s[100][100];
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%s",s[i]);
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			a[i][j] = s[i][j] - 48;
		}
	}
	for(i=1;i<n-1;i++)
	{
		for(j=1;j<n-1;j++)
		{
			if(a[i][j] > a[i-1][j] && a[i][j] > a[i+1][j] && a[i][j] > a[i][j-1] && a[i][j] > a[i][j+1] )
			{
				a[i][j] = 10;
			}
		}
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(a[i][j]>9)
			{
				printf("X");
			}
			else
			{
				printf("%d",a[i][j]);
			}
		}
		printf("\n");
	}
    return 0;
}

