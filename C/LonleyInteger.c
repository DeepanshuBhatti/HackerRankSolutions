/*
There are N integers in an array A. All but one integer occur in pairs. Your task is to find out the number that occurs only once.

Input Format
The first line of the input contains an integer N indicating number of integers. 
The next line contains N space separated integers that form the array A.

Constraints
1 <= N < 100 
N % 2 = 1 ( N is an odd number ) 
0 <= A[i] <= 100, ? i ? [1, N]

Output Format
Output S, the number that occurs only once.

Sample Input:1
1
1

Sample Output:1
1

Sample Input:2
3
1 1 2

Sample Output:2
2

Sample Input:3
5
0 0 1 2 1

Sample Output:3
2

Explanation

In the first input, we see only 1 element and that element is the answer (1). 
In the second input, we see 3 elements, 1 is repeated twice. The element that occurs only once is 2. 
In the third input, we see 5 elements, 1 and 0 are repeated twice. And the element that occurs only once is 2.
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

int lonelyinteger(int a_size, int* a)
{
	int i,j,x;
	for(i=0;i<a_size;i++)
	{
		x = 0;
		for(j=0;j<a_size;j++)
		{
			if(a[i] == a[j])
			{
				x++;
			}
		}
		if(x==1)
		{
			return a[i];
		}
	}
	return 0;
}

int main()
{
    int res;
    int _a_size, _a_i;
    scanf("%d", &_a_size);
    int _a[_a_size];
    for(_a_i = 0; _a_i < _a_size; _a_i++)
	{ 
        int _a_item;
        scanf("%d", &_a_item);    
        _a[_a_i] = _a_item;
    }
    res = lonelyinteger(_a_size, _a);
    printf("%d\n",res);    
    return 0;
}

