/*
You are given an integer, N. Write a program to determine if N is an element of the Fibonacci Sequence.

The first few elements of fibonacci sequence are 0,1,1,2,3,5,8,13....
A fibonacci sequence is one where every element is a sum of the previous two elements in the sequence. The first two elements are 0 and 1.

Formally:

fib0 = 0 
fib1 = 1 
fibn = fibn-1 + fibn-2 ? n > 1

Input Format 
The first line contains T, number of test cases. 
T lines follows. Each line contains an integer N.

Output Format 
Display IsFibo if N is a fibonacci number and IsNotFibo if it is not a fibonacci number. The output for each test case should be displayed in a new line.

Constraints 
1 <= T <= 10^5 
1 <= N <= 10^10

Sample Input
3
5
7
8

Sample Output
IsFibo
IsNotFibo
IsFibo

Explanation 
5 is a Fibonacci number given by fib5 = 3 + 2 
7 is not a Fibonacci number 
8 is a Fibonacci number given by fib6 = 5 + 3
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>


int main()
{
    int T;
    long long int i,N,j,FibArr[50];
    FibArr[0] = 0;
    FibArr[1] = 1;
	for(i=2;i<50;i++)
    {
    	FibArr[i] = FibArr[i-1] + FibArr[i-2];
    }
    int str[100000]={0};
    scanf("%d",&T);
    if(T<1 || T>100000)
    {
    	exit(0);
    }
    for(i=0;i<T;i++)
    {
    	scanf("%lld",&N);
    	if(N<1 || N>10000000000)
    	{
    		exit(0);
    	}
    	for(j=0;j<50;j++)
    	{
    		if(FibArr[j] == N)
    		{
    			str[i]++;
    			continue;
    		}
    	}
    }
    for(i=0;i<T;i++)
    {
    	if(str[i] == 0)
    	{
    		printf("IsNotFibo\n");
    	}
    	else
    	{
    		printf("IsFibo\n");
    	}
    }
    return 0;
}

