/*
At the annual meeting of Board of Directors of Acme Inc, every one starts shaking hands with everyone else in the room. Given the fact that any two persons shake hand exactly once, Can you tell the total count of handshakes?

Input Format 
The first line contains the number of test cases T, T lines follow. 
Each line then contains an integer N, the total number of Board of Directors of Acme.

Output Format

Print the number of handshakes for each test-case in a new line.

Constraints

1 <= T <= 1000 
0 < N < 10^6

Sample Input

2
1
2
Sample Output

0
1
Explanation

Case 1 : The lonely board member shakes no hands, hence 0. 
Case 2 : There are 2 board members, 1 handshake takes place.
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{
	long long int j,a,i,t,n;
	scanf("%lld",&t);
	if(t<1 || t>1000)
	{
		return 0;
	}
	for(i=0;i<t;i++)
	{
		a = 0;
		scanf("%lld",&n);
		if(n<0 || n>1000000)
		{
			return 0;
		}
		for(j=n-1;j>0;j--)
		{
			a = a + j;
		}
		printf("%lld\n",a);
	}
    return 0;
}

