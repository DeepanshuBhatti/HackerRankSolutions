/*
You are given a number N. Find the digits in this number that exactly divide N and display their count. For N = 24, there are 2 digits - 2 & 4. Both these digits exactly divide 24. So our answer is 2.

Note

If the same number is repeated twice at different positions, it should be counted twice, e.g., For N=122, 2 divides 122 exactly and occurs at ones' and tens' position. So it should be counted twice. So for this case, our answer is 3.
Division by 0 is undefined.

Input Format

The first line contains T (number of test cases) followed by T lines (each containing an integer N).

Constraints 
1 <=T <= 15 
0 < N < 10^10

Output Format

For each test case, display the count of digits in N that exactly divide N in separate line.

Sample Input

2
12
1012
Sample Output

2
3
Explanation

2 digits in the number 12 divide the number exactly. Digits at tens' place, 1, divides 12 exactly in 12 parts,
and digit at ones' place, 2 divides 12 equally in 6 parts.

1 divides 1012 at two places and 2 divides it at one place. Divide by 0 is an undefined behaviour and it will not be counted.
*/


#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int fun(long long int n)
{
	int count[10] = {0};
	int i,ans=0,x;
	long long int temp;
	temp = n;
	while(temp>0)
	{
		x = temp%10;
		for(i=0;i<10;i++)
		{
			if(x == i)
			{
				count[i]++;
				continue;
			}
		}
		temp = temp/10;
	}
	for(i=1;i<10;i++)
	{
		if(count[i] != 0 && n%i==0)
		{
			ans = ans + count[i];
		}
	}
	return ans;
}

int main()
{
    int T,i,ans[15]={0};
    long long int N;
    scanf("%d",&T);
    if(T<1 || T>15)
    {
    	exit(0);
    }
    for(i=0;i<T;i++)
    {
    	scanf("%lld",&N);
    	if(N<1 || N>9999999999)
    	{
    		exit(0);
    	}
    	ans[i] = fun(N);
    }
    for(i=0;i<T;i++)
    {
    	printf("%d\n",ans[i]);
    }
    return 0;
}

