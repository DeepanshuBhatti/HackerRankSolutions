/*
You are given an array of numbers. Let us denote the array with A[]. Your task is very simple. You need to find the value returned by the function fun(A).

fun(A)
    sum = 0
    for i = 1 to A.length
        for j = i+1 to A.length
            sum = sum + Floor((A[i]+A[j])/(A[i]*A[j])) 
    return sum
In short, this function takes all distinct pairs of indexes from the array and adds the value (A[i]+A[j]/A[i]×A[j]) to the sum. Your task is to find the sum.

Note: (A/B) is the integer division function.

Input Format 
The first line contains T, the number of test cases to follow.

Each test case contains two lines: the first line contains N, the size of the array, and the second line contains N integers separated by spaces.

Output Format 
The output should contain exactly T lines where the ith line contains the answer for the ith test case.

Constraints 
1<=T<=15 
1<=N<=2*10^5 
1=Sum of N over all test cases =2*10^5 
1<=A[i]<=10^9

Sample Input
2
3
4 2 3
3
1 4 1

Sample Output
0
4

Explanation 
First Test Case: (6/8)+(7/12)+(5/6)=0 
Second Test Case: (5/4)+(2/1)+(5/4)=4
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{
	long long int t,i,n,j;
	scanf("%lld",&t);
	for(i=0;i<t;i++)
	{
		long long int x,arr[2]={0,0},m;
		long long int sum = 0;
		scanf("%lld",&n);
		for(j=0;j<n;j++)
		{
			scanf("%lld",&x);
			if(x==1 || x ==2)
			{
				arr[x-1]++;
			}
		}
		if(arr[0]>1)
		{
			m = n - arr[0];
			sum = sum + (arr[0]*(arr[0]-1)) + (m*arr[0]);
		}
		if(arr[0]==1)
		{
			sum = sum + n - 1;
		}
		if(arr[1] > 1)
		{
			sum = sum + (arr[1]*(arr[1]-1)/2);
		}
		printf("%lld\n",sum);
	}
    return 0;
}

