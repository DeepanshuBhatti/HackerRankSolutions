/*
n! means n×(n-1)×...×3×2×1
For example, 10!=10×9×...×3×2×1=3628800, 
and the sum of the digits in the number 10! is 3+6+2+8+8+0+0=27.

Find the sum of the digits in the number N!
Input Format 
The first line contains an integer T , i.e., number of test cases. 
Next T lines will contain an integer N.

Output Format 
Print the values corresponding to each test case.

Constraints 
1<=T<=100 
0<=N<=1000

Sample Input
2
3
6

Sample Output
6
9
*/

#include<stdio.h>
#include<math.h>

int res[10000],k=0;

void func(int x)
{
	int i,c=0;
	for(i=0;i<=k;i++)
	{
		res[i] = (res[i]*x) + c;
		c = res[i]/10;
		res[i] = res[i]%10;
	}
	while(c>0)
	{
		k++;
		res[k] = c%10;
		c= c/10;
	}
	return;
}


int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,i;
		scanf("%d",&n);
		k = 0;
		res[k] = 1;
		for(i=2;i<=n;i++)
		{
			func(i);
		}
		unsigned long long int s=0;
		for(i=k;i>=0;i--)
		{
			s = s+res[i];
		}
		printf("%llu\n",s);
	}
	return 0;
}

