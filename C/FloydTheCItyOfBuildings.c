/*
Given a directed, weighted graph, consisting of N nodes and there are edges ,of specified length between some of them in the graph.

Given Q questions, inquring the shortest distance between a queried pair of nodes in the graph.

Answer all these questions as quickly as possible !

Input Format

First line has two integers N, denoting the number of nodes in the graph and M, denoting the number of edges in the graph. 
The next M lines each consist of three space separated integers x y r, where x and y denote the two nodes between which the directed edge (x->y) exists, r denotes the length of the edge between the corresponding edges. 
The next line contains a single integer Q, denoting number of queries. 
The next Q lines each, contain two space separated integers a and b, denoting the node numbers specified according to the question.

Constraints 
2<=N<=400 
1<=M=<N*(N-1)/2 
1<=Q<=10^5 
1<=x,y<=N 
1<=r<=350

If there are edges between the same pair of nodes with different weights, the last one (most recent) is to be considered as the only edge between them.

Output Format

Print Q lines, each containing a single integer, specifying the shortest distance between the nodes specified for that query in the input.

If the distance between a pair of nodes is infinite (not reachable), then print -1 as the shortest distance.

Sample Input

4 5
1 2 5
1 4 24
2 4 6
3 4 4
3 2 7
3
1 2
3 1
1 4
Sample Output

5
-1
11
Explanation

The graph given in the test case is shown as :

Graph

The nodes A,B,C and D denote the 1,2,3 and 4 node numbers.
The shortest paths for the 3 queries are :

A->B (Direct Path is shortest with weight 5)

-1 (There is no way of reaching node 1 from node 3, hence unreachable)

A->B->D (Indirect path is shortest with weight (5+6) = 11 units, the direct path is longer with 24 units length)

*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{
	int n,m,i,j,x,y,r,q,k,t;
	scanf("%d",&n);
	scanf("%d",&m);
	int g[401][401];
	memset(g, -1, (n+1)*sizeof(g[0]));
	for(i=1;i<=n;i++)
	{
		g[i][i] = 0;
	}
	for(i=0;i<m;i++)
	{
		scanf("%d%d%d",&x,&y,&r);
		g[x][y] = r;
	}
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            for(k=1;k<=n;k++)
            {
                if(j!=k)
                {
                	if(g[j][k] == -1)
                	{
                		t = -10000*g[j][k];
                	}
                	else
                	{
                		t = g[j][k];
                	}
                    if(g[j][i] + g[i][k] < t && g[i][k] > -1 && g[j][i] >-1)
                    {
                        g[j][k] = g[j][i] + g[i][k];
                    }
                }
            }          
        }
    }    
	scanf("%d",&q);
	for(i=0;i<q;i++)
	{
		scanf("%d%d",&x,&y);
		printf("%d\n",g[x][y]);
	}
    return 0;
}

