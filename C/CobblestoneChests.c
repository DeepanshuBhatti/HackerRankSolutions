/*
After exploring all the caves, Steve returned to his house. He was really amazed when he opened his inventory. He realized that he has M stacks of cobblestone in his inventory, with K[i] blocks in the ith stack. Now he wants to store that cobblestone into his chests. The only rule he must follow is that he has to put the cobblestone into a chest that will be completly full after that. 
Can you help him and calculate the number of chest that he should use for each stack?

Input Format
The first line of input contains the number 1 = N = 107, representing the number of chests.
The next N lines contain a single integer, 1 = S[i] = 109 representing the amount of free space in the ith chest. As you may have already noticed, Steve has a form of OCD, and that is why all the chests will be sorted in an ascending order, meaning that S[i] will always be smaller than S[i+1]. 
The next line contains the number 1 = M = 106, representing the number of cobblestone stacks in Steve's inventory. 
The next M lines contain a single integer, 1 = K[i] = 109, representing the number of cobblestone blocks in the ith stack.
The input will always be made so that every stack has a unique number of blocks in it, and that there and that there always exists a chest that has the same amount of free space in it.

Output Format
In M lines, output the index of the chest that should be used for this stack of cobblestone.

Sample Input
5
4 5 7 9 10
3
9 5 7

Sample Output
4
2
3

Explanation
The first stack has to go into the 4th chest. 
The second stack has to go into the 2nd chest. 
The third stack has to go into the 3rd chest. 
*/

#include<stdio.h>

int findloc(long long int x, long long int a[],int n)
{
	int i,m,l,h;
	l =0;
	h = n-1;
	while(1)
	{
		m = (l+h)/2;
		if(a[m] == x)
		{
			break;
		}
		else if(a[m] >x)
		{
			h = m-1;
		}
		else
		{
			l = m+1;
		}
	}
	return m;
}

int main()
{
	int n,i;
	scanf("%d",&n);
	long long int a[n];
	for(i=0;i<n;i++)
	{
		scanf("%lld",&a[i]);
	}
	int m,j;
	scanf("%d",&m);
	long long int b[m];
	for(i=0;i<m;i++)
	{
		scanf("%lld",&b[i]);
	}
	for(i=0;i<m;i++)
	{
		printf("%d\n",findloc(b[i],a,n)+1);
	}
	return 0;
}
