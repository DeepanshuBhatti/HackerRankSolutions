/*
The numbers 1 to 5 written out in words are One, Two, Three, Four, Five

First character of each word will be capital letter for example: 
104382426112 is One Hundred Four Billion Three Hundred Eighty Two Million Four Hundred Twenty Six Thousand One Hundred Twelve

Given a number, you have to write it in words.

Input Format 
The first line contains an integer T , i.e., number of test cases. 
Next T lines will contain an integer N.

Output Format 
Print the values corresponding to each test case.

Constraints 
1<=T<=10 
0<=N<=10^12

Sample Input
2
10
17

Sample Output
Ten
Seventeen
*/

#include<stdio.h>

int word(int x)
{
	if(x==1)
	{
		printf("One");
	}
	else if(x==2)
	{
		printf("Two");
	}
	else if(x==3)
	{
		printf("Three");
	}
	else if(x==4)
	{
		printf("Four");
	}
	else if(x==5)
	{
		printf("Five");
	}
	else if(x==6)
	{
		printf("Six");
	}
	else if(x==7)
	{
		printf("Seven");
	}
	else if(x==8)
	{
		printf("Eight");
	}
	else if(x==9)
	{
		printf("Nine");
	}
	else if(x==10)
	{
		printf("Ten");
	}
	else if(x==11)
	{
		printf("Eleven");
	}
	else if(x==12)
	{
		printf("Twelve");
	}
	else if(x==13)
	{
		printf("Thirteen");
	}
	else if(x==14)
	{
		printf("Fourteen");
	}
	else if(x==15)
	{
		printf("Fifteen");
	}
	else if(x==16)
	{
		printf("Sixteen");
	}
	else if(x==17)
	{
		printf("Seventeen");
	}
	else if(x==18)
	{
		printf("Eighteen");
	}
	else if(x==19)
	{
		printf("Nineteen");
	}
	else if(x==20)
	{
		printf("Twenty");
	}
	else if(x==30)
	{
		printf("Thirty");
	}
	else if(x==40)
	{
		printf("Forty");
	}
	else if(x==50)
	{
		printf("Fifty");
	}
	else if(x==60)
	{
		printf("Sixty");
	}
	else if(x==70)
	{
		printf("Seventy");
	}
	else if(x==80)
	{
		printf("Eighty");
	}
	else if(x==90)
	{
		printf("Ninety");
	}
	else if(x==100)
	{
		printf("Hundred");
	}
	else
	{
		return 0;
	}
	return 1;
}

void cal(int t)
{
	int x,a,b,c=0;
	x = t;
	a = t;
	a = a/100;
	b = word(a);
	if(b==1)
	{
		printf(" ");
		b = word(100);
		if(b==1)
		{
			printf(" ");
		}
	}
	x = x - a*100;
	b = word(x);
	if(b==1)
	printf(" ");
	if(b==0)
	{
		if(x - x%10>0)
		{
			b = word(x - x%10);
			printf(" ");
		}
		if(x%10>0)
		{
			b = word(x%10);
			printf(" ");	
		}
	}
	return;
}


int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		long long int n;
		int bi,mi,th,hu,a,b,x;
		scanf("%lld",&n);
		hu = n%1000;
		n = n/1000;
		th = n%1000;
		n = n/1000;
		mi = n%1000;
		n = n/1000;
		bi = n%1000;
		n = n/1000;
		if(bi>0)
		{
			cal(bi);
			printf("Billion ");
			if(hu==0)
			{
				printf("\b");
			}
		}
		if(mi>0)
		{
			cal(mi);
			printf("Million ");
			if(hu==0)
			{
				printf("\b");
			}
		}
		if(th>0)
		{
			cal(th);
			printf("Thousand ");
			if(hu==0)
			{
				printf("\b");
			}
		}
		if(hu>0)
		{
			cal(hu);
		}
		printf("\n");
	}
	return 0;
}
