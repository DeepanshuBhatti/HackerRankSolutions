/*
Little Priyanka visited a kids' shop. There are N toys and their weight is represented by an array W=[w1,w2,…,wN]. Each toy costs 1 unit, and if she buys a toy with weight w', then she can get all other toys whose weight lies between [w',w'+4] (both inclusive) free of cost.

Input Format

The first line contains an integer N i.e. number of toys.
Next line will contain N integers, w1,w2,…,wN, representing the weight array.

Output Format

Minimum units with which Priyanka could buy all of toys.

Constraints 
1=N=10^5
0=wi=10^4,where i?[1,N]

Sample Input
5
1 2 3 17 10
Sample Output
3

Explanation

She buys 1st toy with weight 1 for 1 unit and gets 2nd and 3rd toy for free since their weight lies between [1,5]. And she has to buy last two toys separately.
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{
	int min,n,i,x,z,j,k,a[100000]={0};
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	z = 0;
	for(i=0;i<n;i++)
	{
		if(a[i]==-1)
		{
			continue;
		}
		min = a[i];
		for(j=0;j<n;j++)
		{
			if(min>a[j] && a[j]!=-1)
			{
				min = a[j];
			}
		}
		x = min;
		//printf("%d\n",min);
		z++;
		for(j=0;j<n;j++)
		{
			if(a[j]==-1)
			{
				continue;
			}
			if(a[j] >= x  && a[j] <= x+4)
			{
				a[j] = -1;
				i = -1;
			}
		}
	}
	printf("%d",z);
    return 0;
}

