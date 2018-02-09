/*
Mark and Jane are very happy after having their first kid. Their son is very fond of toys, so Mark wants to buy some. There are N different toys lying in front of him, tagged with their prices, but he has only $K. He wants to maximize the number of toys he buys with this money.

Now, you are Mark's best friend and have to help him buy as many toys as possible.

Input Format 
The first line contains two integers, N and K, followed by a line containing N space separated integers indicating the products' prices.

Output Format 
An integer that denotes maximum number of toys Mark can buy for his son.

Constraints 
1<=N<=105 
1<=K<=109 
1<=price of any toy<=109 
A toy can't be bought multiple times.

Sample Input

7 50
1 12 5 111 200 1000 10
Sample Output

4
Explanation

He can buy only 4 toys at most. These toys have the following prices: 1,12,5,10.
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    int min,n,a, i, j, k, count;
    scanf("%d%d", &n, &k);
    int *p = (int *)malloc(sizeof(int)*n);
    for(i=0; i<n; i++)
	{
        scanf("%d", &p[i]);
    }
    count = 0;
    a = 0;
    for(i=0;i<n-1;i++)
	{
		min = i;		
		for(j=i+1;j<n;j++)
		{
			if(p[min]>p[j])
			{
				min = j;
			}
		}
		if(min != i)
		{
			j = min;
			p[i] = p[i] + p[j];
        	p[j] = p[i] - p[j];
        	p[i] = p[i] - p[j];
		}
		if(count + p[i] <= k)
    	{
    		count = count + p[i];
    		a++;
    	}
    	else
    	{
    		i = n;
    	}
	}
    printf("%d\n",a);
    return 0;
}
