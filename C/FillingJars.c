/*
Animesh has N empty candy jars, numbered from 1 to N, with infinite capacity.
He performs M operations. Each operation is described by 3 integers a, b and k.
Here, a and b are indices of the jars, and k is the number of candies to be added inside each jar
whose index lies between a and b (both inclusive).
Can you tell the average number of candies after M operations?

Input Format 
The first line contains two integers N and M separated by a single space. 
M lines follow. Each of the M lines contain three integers a, b and k separated by single space.

Output Format 
A single line containing the average number of candies across N jars, rounded down to the nearest integer.

Note 
Rounded down means finding the greatest integer which is less than or equal to given number. Eg, 13.65 and 13.23 is rounded down to 13, while 12.98 is rounded down to 12.

Constraints 
3 <= N <= 10^7 
1 <= M <= 10^5 
1 <= a <= b <= N 
0 <= k <= 10^6

Sample Input #00
5 3
1 2 100
2 5 100
3 4 100

Sample Output #00
160

Explanation 
Initially each of the jar contains 0 candies
0 0 0 0 0  

First operation
100 100 0 0 0  

Second operation
100 200 100 100 100  

Third operation
100 200 200 200 100  

Total = 800, Average = 800/5 = 160
*/


#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{
	unsigned long long int i,N,M,a,b,k,g,t=0;
	scanf("%llu",&N);
	scanf("%llu",&M);
	for(i=0;i<M;i++)
	{
		scanf("%llu%llu%llu",&a,&b,&k);
		g = (b-a) + 1;
		t = t + (k*g);
	}
	g = t/N; 
	printf("%llu\n",g);
	return 0;
}

