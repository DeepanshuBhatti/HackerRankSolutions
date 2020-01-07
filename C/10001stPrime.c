/*
By listing the first six prime numbers: 2,3,5,7,11 and 13, we can see that the 6th prime is 13. 
What is the N'th prime number?

Input Format 
First line contains T that denotes the number of test cases. This is followed by T lines, each containing an integer, N.

Output Format 
Print the required answer for each test case.

Constraints 
1<=T<=10^3 
1<=N<=10^4

Sample Input
2
3
6

Sample Output
5
13
*/

#include<stdio.h>
#include<math.h>

unsigned long long int res[1000000]={0},k=0;

void countprime(unsigned long long int l,unsigned long long int r)
{
	unsigned long long int i,j,t,x=0,p,d=0;
	i = 5;
	while(i<=r)
	{
		t = 0;
		for(j=0;j<k;j++)
		{
			p = res[j];
			if(p > sqrt(i))
			{
				j=k;
			}
			if(i%p == 0)
			{
				t = 1;
				j = k;
			}
		}
		if(t==0)
		{
			res[k] = i;
			k++;
			if(i>=l)
			{
				x++;
			}
		}
		if(d==0)
		{
			i = i+2;
			d = 1;
		}
		else
		{
			i = i+4;
			d = 0;
		}
		if(k>10002)
		{
			return;	
		}
	}
	
}

int main()
{
	int t;
	res[0] = 2;
	res[1] = 3;
	k=2;
	countprime(1,200000);
	scanf("%d",&t);
	while(t--)
	{
		unsigned long long int n;
		scanf("%llu",&n);
		printf("%llu\n",res[n-1]);
	}
	return 0;
}
