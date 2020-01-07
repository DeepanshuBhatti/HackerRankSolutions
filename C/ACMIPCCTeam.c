/*
You are given a list of N people who are attending ACM-ICPC World Finals.
Each of them are either well versed in a topic or they are not.
Find out the maximum number of topics a 2-person team can know.
And also find out how many teams can know that maximum number of topics.

Input Format

The first line contains two integers N and M separated by a single space,
where N represents the number of people, and M represents the number of topics.
N lines follow.
Each line contains a binary string of length M.
In this string, 1 indicates that the ith person knows a particular topic,
and 0 indicates that the ith person does not know the topic.

Output Format

On the first line, print the maximum number of topics a 2-person team can know. 
On the second line, print the number of 2-person teams that can know the maximum number of topics. 

Constraints

2 = N = 500 

1 = M = 500
Sample Input

4 5
10101
11100
11010
00101
Sample Output

5
2
Explanation 
(1, 3) and (3, 4) know all the 5 topics. So the maximal topics a 2-person team knows is 5, and only 2 teams can achieve this.
*/


#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void CheckOneZero(char str[])
{
	int i=0, len;
	//printf("%s\n",str);
	len = strlen(str);
	while(i<len)
	{
		//printf("\n%c",str[i]);
		if(str[i] == '1' || str[i] == '0')
		{
			i++;
		}
		else
		{
			exit(0);
		}
	}
}

int main()
{
	int N,M,i,k,len,temp;
	scanf("%d %d",&N,&M);
	if(N<2 || M<1 || N>500 || M>500)
	{
		exit(0);
	}
	int j,maxTop=0, maxTeam=0;
	char str[500][500];
	for(i=0;i<N;i++)
	{
		scanf("%s",&str[i]);
		len = strlen(str[i]);
		if(len>M)
		{
			exit(0);
		}
		CheckOneZero(str[i]);
		/*printf("\n");
		for(j=0;j<M;j++)
		{
			printf("%d\t",arr[j]);
		}
		printf("\n");*/
	}
	
	for(i=0;i<N;i++)
	{
		for(j=i+1;j<N;j++)
		{
			temp = 0;
			for(k=0;k<M;k++)
			{
				if(str[i][k] == '1' || str[j][k] == '1')
				{
					temp++;
				}
			}
			if(temp > maxTop)
			{
				maxTop = temp;
			}
		}
	}
	for(i=0;i<N;i++)
	{
		for(j=i+1;j<N;j++)
		{
			temp = 0;
			for(k=0;k<M;k++)
			{
				if(str[i][k] == '1' || str[j][k] == '1')
				{
					temp++;
				}
			}
			if(temp == maxTop)
			{
				maxTeam++;
			}
		}
	}
	printf("%d\n%d",maxTop,maxTeam);
    return 0;
}

