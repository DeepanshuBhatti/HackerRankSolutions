/*
Alice gives a wooden board composed of M X N wooden square pieces to Bob and asks him to find the minimal cost of breaking the board into square wooden pieces. Bob can cut the board along horizontal and vertical lines, and each cut divides the board in smaller parts. Each cut has a cost depending on whether the cut is made along a horizontal or a vertical line.
Let us denote the costs of cutting it along consecutive vertical lines by x1, x2, ..., xn-1, and the cost of cutting it along horizontal lines by y1, y2, ..., ym-1. If a cut (of cost c) is made and it passes through n segments, then total cost of this cut will be n*c.
The cost of cutting the whole board into single squares is the sum of the cost of successive cuts used to cut the whole board into square wooden pieces of size 1x1. Bob should compute the minimal cost of breaking the whole wooden board into squares of size 1x1.
Bob needs your help to find the minimal cost. Can you help Bob with this challenge?

Input Format 
A single integer in the first line T, stating the number of test cases. T testcases follow. 
For each test case, the first line contains two positive integers M and N separated by a single space. In the next line, there are integers y1, y2, ..., ym-1, separated by spaces. Following them are integers x1, x2, ..., xn-1, separated by spaces.

Output Format 
For each test-case, write an integer in separate line which denotes the minimal cost of cutting the whole wooden board into single wooden squares. Since the answer can be very large, output the answer modulo 109+7.

Constraints 
1 <= T <= 20 
2 <= M,N <= 1000000 
0 <= xi <= 10^9 
0 <= yi <= 10^9

Sample Input #00
1
2 2
2
1

Sample Output #00
4

Sample Input #01
1
6 4
2 1 3 1 4
4 1 2

Sample Output #01
42

Explanation 
Sample Case #00: At first, board should be cut horizontally, where y1 = 2, then it should be cut vertically. So total cost will be 2*1 + 1*2 = 4.
Sample Case #01: We should start cutting using y5, x1, y3, y1, x3, y2, y4 and x2, in order. First cut will be a horizontal one where cost = y5 = 4. Next we will do a vertical cut with x1. Since this cut passes through two segments (created by previous horizontal cut), it's total cost will be 2*x1 = 2*4. Similarly next horizontal cut (y3) will pass through two segments and will cost 2*y3 = 2*3. We can proceed in similar way and get overall cost as 4 + 4*2 + 3*2 + 2*2 + 2*4 + 1*3 + 1*3 + 1*6 = 42.
*/

#include<stdio.h>

void merge(unsigned long long int a[],int l, int p,int h)
{
	int j,i,t,x,y,k;	
	x = l;
	y = p+1;
	k = 0;
	unsigned long long int b[h-l+1];
	for(i=l;i<=h;i++)
	{
		if(x>p)
		{
			b[k] = a[y];
			k++;
			y++;
		}
		else if(y>h)
		{
			b[k] = a[x];
			k++;
			x++;
		}
		else if(a[x]>a[y])
		{
			b[k] = a[x];
			x++;
			k++;
		}
		else
		{
			b[k] = a[y];
			y++;
			k++;
		}
	}
	for(i=0;i<k;i++)
	{
		a[l] = b[i];
		l++;
	}
	return;
}

void sort(unsigned long long int a[],int l,int h)
{
	if(l<h)
	{
		int p = (l+h)/2;
		//printf("%d ",p);
		sort(a,l,p);
		sort(a,p+1,h);
		
		merge(a,l,p,h);
	}
	return;
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		unsigned long long int n,m,j,k;
		scanf("%llu%llu",&m,&n);
		unsigned long long int y[m],x[n];
		for(j=0;j<m-1;j++)
		{
			scanf("%llu",&y[j]);
		}
		sort(y,0,m-2);
		for(j=0;j<n-1;j++)
		{
			scanf("%llu",&x[j]);
		}
		sort(x,0,n-2);
		unsigned long long int ans=0,h=0,v=0;
		for(j=0;v<n-1&&h<m-1;j++)
		{
			if(x[v]>y[h])
			{
				ans = ans + (x[v]*(h+1))%1000000007;
				//printf("X: %llu %llu\n",x[v],h+1);
				x[v] = -1;
				v++;
			}
			else
			{
				ans = ans + (y[h]*(v+1))%1000000007;
				//printf("Y: %llu %llu\n",y[h],v+1);
				y[h] = -1;
				h++;
			}
			ans = ans%1000000007;
		}
		while(v<n-1)
		{
			ans = ans + (x[v]*(h+1))%1000000007;
			//printf("X: %llu %llu\n",x[v],h+1);
			x[v] = -1;
			v++;
		}
		while(h<m-1)
		{
			ans = ans + (y[h]*(v+1))%1000000007;
			//printf("Y: %llu %llu\n",y[h],v+1);
			y[h] = -1;
			h++;
		}
		ans = ans%1000000007;
		printf("%llu\n",ans);
	}
	return 0;
}

