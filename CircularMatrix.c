/*
CURCULAR MATRIX

RamPrasath wants to learn about the number system with anyone of the mathematical model.so,he decided to study the number system with the matrix.

The problem is you want to print the given matrix in the following form

Input Format

Input Format 
There will be two lines of input:

n - No. of Testcases
i - No. of Rows,Columns
It is square matrix always.

1 = n,i= 100

Output Format

Output Format

CIRCULAR MATRIX

Sample Input

1

3

Sample Output

1 8 7

2 9 6

3 4 5
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{
	int t,n,i,j,k,m,o,p,z,s;
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
		int a[100][100] = {0};
		scanf("%d",&n);
		s = n;
		a[0][0] = 1;
		j = 0;
		k = 0;
		m = 1;
		o = 0;
		z = 0;
		p = (m+1)/2;
		//printf("m = %d\tp = %d\ta[%d,%d] = %d\n",m,p,j,k,a[j][k]);
		while(a[j][k]!=0 && o<pow(s,2))
		{
			p = (m+1)/2;
			o = a[j][k];
			if(p%2!=0)
			{
				if(m%2!=0)
				{
					j++;
					if(a[j][k]!=0)
					{
						j--;
						m++;
						z++;
						continue;
					}
				}
				else
				{
					k++;
					if(a[j][k]!=0)
					{
						k--;
						m++;
						z++;
						continue;
					}
				}	
			}
			else
			{
				if(m%2==0)
				{
					k--;
					if(a[j][k]!=0)
					{
						k++;
						m++;
						z++;
						continue;
					}
				}
				else
				{
					j--;
					if(a[j][k]!=0)
					{
						j++;
						m++;
						z++;
						continue;
					}
				}
			}
			a[j][k] = o+1;
			//printf("m = %d\tp = %d\ta[%d,%d] = %d\n",m,p,j,k,a[j][k]);
			if((k==j || (k+j)==n-1) && z==0)
			{
				m++;
			}
			if(z>0)
			{
				z--;
			}
		}
		//printf("\n");
		for(k=0;k<n;k++)
		{
			for(j=0;j<n;j++)
			{
				printf("%d ",a[k][j]);
			}
			printf("\n");
			printf("\n");
		}
		
	}
    return 0;
}

