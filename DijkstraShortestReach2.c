/*
Given a graph consisting N nodes (labelled 1 to N) where a specific given node S represents the starting position S and an edge between two nodes is of a given length, which may or may not be equal to other lengths in the graph.
It is required to calculate the shortest distance from the start position (Node S) to all of the other nodes in the graph.

Note 1: If a node is unreachable , the distance is assumed as -1.

Input Format
The first line contains T, denoting the number of test cases. 
First line of each test case has two integers N, denoting the number of nodes in the graph and M, denoting the number of edges in the graph.
The next M lines each consist of three space-separated integers x y r, where x and y denote the two nodes between which the undirected edge exists, r denotes the length of edge between these corresponding nodes.
The last line has an integer S, denoting the starting position.

Constraints 
1<=T<=10 
2<=N<=3000 
1<=M<=(N*(N-1))/2 
1<=x,y,S<=N 
1<=r<=350
If there are edges between the same pair of nodes with different weights, they are to be considered as is, like multiple edges.

Output Format
For each of the T test cases, print a single line consisting N-1 space separated integers denoting the shortest distance of N-1 nodes from starting position S.
For unreachable nodes, print -1.

Sample Input
1
4 4
1 2 24
1 4 20
3 1 3
4 3 12
1

Sample Output
24 3 15

Explanation
The graph given in the test case is shown as :

Graph
The straight line is a weighted edge, denoting length of edge between the corresponding nodes.
The nodes S,B,C and D denote the obvious node 1,2,3 and 4 in the test case.
The shortest paths followed for the three nodes B,C and D are as follows :
S->B - Shortest Path Value : 24
S->C - Shortest Path Value : 3
S->C->D - Shortest Path Value : 15
*/


#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{
	int t,n,e,i,j;
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
		scanf("%d%d",&n,&e);	
		int s,k,mat[n+1][n+1],d[n+1],x,y,r,v[n+1];
		for(j=1;j<=n;j++)
		{
			d[j] = 999999;
			v[j] = 0;
			for(k=1;k<=n;k++)
			{
				mat[j][k] = 999999;
			}
		}
		for(j=0;j<e;j++)
		{
			scanf("%d%d%d",&x,&y,&r);
			if(mat[x][y] > r)
			{
				mat[x][y] = r;
				mat[y][x] = r;	
			}
		}
		scanf("%d",&s);
		d[s] = 0;
		int p,min,mind=s;
		v[mind] = 1;
		for(j=1;j<=n;j++)
		{
			for(k=1;k<=n;k++)
			{
				if(mat[mind][k] != 999999)
				{
					p = d[mind] + mat[mind][k];
					if(d[k] > p)
					{
						d[k]= p;
					}
				}
			}
			min = 9999999;
			for(k=1;k<=n;k++)
			{
				if(d[k] < min && v[k]==0)
				{
					min = d[k];
					mind = k;
				}
			}
			v[mind] = 1;
		}
		for(j=1;j<=n;j++)
		{
			if(d[j]!= 0)
			{
				if(d[j] == 999999)
				{
					printf("-1 ");
				}
				else
				{
					printf("%d ",d[j]);	
				}
				
			}
		}
		printf("\n");
	}
    return 0;
}
