/*
The sum of the primes below 10 is 2+3+5+7=17.

Find the sum of all the primes not greater than given N.

Input Format 
The first line contains an integer T i.e. number of the test cases. 
The next T lines will contains an integer N.

Output Format 
Print the value corresponding to each test case in seperate line.

Constraints 
1<=T<=10^4 
1<=N<=10^6

Sample Input
2
5
10

Sample Output
10
17
*/

#include<stdio.h>
#include<math.h>

int res[100000]={0},k=0;

void countprime(int r)
{
	int i,j,t,x=0,p,d=0;
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
	}
	return;
}

int main()
{
	int r,t;
	res[0] = 2;
	res[1] = 3;
	k=2;
	countprime(1000000);
	scanf("%d",&t);
	while(t--)
	{
		int n,i;
		scanf("%d",&n);
		unsigned long long int sum=0;
		for(i=0;n>=res[i];i++)
		{
			sum = sum + res[i];
		}
		printf("%llu\n",sum);
	}
	return 0;
}
