/*
Sansa has an array. She wants to find the value obtained by XOR-ing the contiguous subarrays, followed by XOR-ing the values thus obtained. Can you help her in this task?

Note : [5,7,5] is contiguous subarray of [4,5,7,5] while [4,7,5] is not.

Input Format 
First line contains an integer T, number of the test cases. 
The first line of each test case contains an integer N, number of elements in the array. 
The second line of each test case contains N integers that are elements of the array.

Output Format 
Print the answer corresponding to each test case in a separate line.

Constraints 
1<=T<=5 
2<=N<=10^5 
1<=numbers in array<=10^8

Sample Input
2
3
1 2 3
4
4 5 7 5

Sample Output
2
0

Explanation
Test case #00: 
1^2^3^(1^2)^(2^3)^(1^2^3)=2 

Test case #01: 
4^5^7^5^(4^5)^(5^7)^(7^5)^(4^5^7)^(5^7^5)^(4^5^7^5)=0
*/

#include<stdio.h>

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		unsigned long long int n,i,j,k,ans=0;
		scanf("%llu",&n);
		unsigned long long int a[n];
		for(i=0;i<n;i++)
		{
			scanf("%llu",&a[i]);
		}
		if(n%2==0)
		{
			printf("%llu\n",ans);
		}
		else
		{
			for(i=0;i<n;i=i+2)
			{
				ans = ans^a[i];
			}
			printf("%llu\n",ans);
		}
	}
	return 0;
}
