/*
Pentagonal numbers are generated by the formula, Pn=n(3n-1)/2. The first ten pentagonal numbers are: 
1,5,12,22,35,51,70,92,117,145,...
It can be seen that P4+P7=22+70=92=P8. Also P7-P5=70-35=35=P5 is also pentagonal.

Generalizing for a given K find all Pn,(n<N) such that Pn-Pn-K is pentagonal or Pn+Pn-K is pentagonal.

Input Format 
Input contains two integers N and K separated by space.

Output Format 
Print the pentagonal numbers corresponding to the test case in sorted order, each in a new line.

Constraints 
1<=K<=9999 
K+1<=N<=10^6

Sample Input
10 2

Sample Output
70
*/

#include<stdio.h>
#include<math.h>

unsigned long long int res[1000000],l;

int pen(unsigned long long int n)
{
	unsigned long long int a;
	long long int b;
	double d;
	d = sqrt(1+24*n);
	d = (d+1)/6;
	b = (long long int)d;
	a = b*(3*b-1)/2;
	if(a==n)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int main()
{
	unsigned long long int y,x,i,n,k,z;
	scanf("%llu%llu",&n,&k);
	l=0;
	for(i=1;i<=1000000;i++)
	{
		x = i*(3*i-1)/2;
		res[l] = x;
		l++;
	}
	for(i=k;i<n;i++)
	{
		y = res[i] + res[i-k];
		x = pen(y);
		if(x==1)
		{
			printf("%llu\n",res[i]);
			continue;
		}
		y = res[i] - res[i-k];
		x = pen(y);
		if(x==1)
		{
			printf("%llu\n",res[i]);
		}		
	}
	return 0;
}
