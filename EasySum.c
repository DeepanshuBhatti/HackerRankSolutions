/*
Little Kevin had never heard the word 'Infinitum'. So he asked his mentor to explain the word to him. His mentor knew that 'Infinitum' is a very large number. To show him how big Infinitum can be, his mentor gave him a challenge: to sum the numbers from 1 up to N. The sum started to get really large and was out of long long int range. And so the lesson was clear.

Now his mentor introduced him to the concept of mod and asked him to retain only the remainder instead of the big number. And then, he gave him a formula to compute:

for i = 1 to N
 sum = sum + i%m

Input Format 
The first line contains T, the number of test cases. 
T lines follow, each containing 2 space separated integers N m

Output Format 
Print the result on new line corresponding to each test case.

Constraint 
1 = T = 1000 
1 = N = 10^9 
1 = m = 10^9

Sample Input
3
10 5
10 3
5 5

Sample Output
20
10
10

Explanation 
Case 1: N = 10 m = 5, 
1%5 + 2%5 + 3%5 + 4%5 + 5%5 + 6%5 + 7%5 + 8%5 + 9%5 + 10%5 = 20. 
Similar explanation follows for Case 2 and 3.
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{
	int t,i;
	long long int n,m,s,f,x;
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
		s = 0;
		f = 0;
		scanf("%lld",&n);
		scanf("%lld",&m);
		x = n/m;
		if(n%m!=0)
		{
			f = n - (x*m);
		}
		s = ((m*(m-1)/2)*x) + (f*(f+1)/2);
		printf("%lld\n",s);
	}
    return 0;
}
 
