/*
Given an undirected weighted connected graph, it is required to find the Really Special SubTree in it. The Really Special SubTree is defined as a subgraph consisting of all the nodes in the graph and
There is only one exclusive path from a node to every other node.
The subgraph is of minimum overall weight (sum of all edges) among all such subgraphs.
While creating the Really Special SubTree, start of by picking the edge with smallest weight. If there are edges of equal weight available at an instant, then the edge to be chosen first among them is the one with minimum value of sum of the following expression :
u + wt + v , where u and v are the node numbers of the corresponding edge and wt is the weight.
Even then if there is a collision, choose any one of them.
While doing the above, ensure that no cycle is formed while picking up edges.
Finally, you need to print the overall weight of the Christmas Tree so formed using above rules.

Input Format
First line has two integers N, denoting the number of nodes in the graph and M, denoting the number of edges in the graph.
The next M lines each consist of three space separated integers x y r, where x and y denote the two nodes between which the undirected edge exists, r denotes the weight of edge between the corresponding nodes.
The last line has an integer S, denoting the starting node.

Constraints 
2<=N<=3000 
1<=M<=(N*(N-1))/2 
1<=x,y,S<=N 
0<=r<=10^5
If there are edges between the same pair of nodes with different weights, they are to be considered as is, like multiple edges.

Output Format
Print a single integer denoting the total weight (sum of weights of all edges in the MST) of the Really Special SubTree.

Sample Input
4 6
1 2 5
1 3 3
4 1 6
2 4 7
3 2 4
3 4 5
1

Sample Output
12

Explanation
The graph given in the test case is shown as :

Graph
The nodes A,B,C and D denote the obvious 1,2,3 and 4 node numbers.
The starting node is A or 1 (in the given test case)
Applying the Kruskal's algorithm, all the edges are sorted in ascending order of weight.
After sorting, the edge choices are available as :
A->C (WT. 3) , B->C (WT. 4) , A->B (WT. 5) , C->D (WT. 5) , A->D (WT. 6) and B->D (WT. 7)
Picking these edges and finalizing only if it doesnt create a cycle :
A->C : B->C
Now, when A->B edge is picked , it can be easily seen that they both belong to same set (form a cycle) and hence this edge is ignored.
The process continues and the following edge sequence is formed for the MST :
A->C : B->C : C->D
and Total weight of the hence formed Really Special SubTree is : 12
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

struct edge
{
	int x, y, l;
};

int main()
{
	int n,e,i,j;
	scanf("%d%d",&n,&e);
	struct edge a[e],t;
	for(i=0;i<e;i++)
	{
		scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].l);
	}	
	for(i=0;i<e-1;i++)
	{
		for(j=i+1;j<e;j++)
		{
			if(a[i].l > a[j].l)
			{
				t = a[i];
				a[i] = a[j];
				a[j] = t;
			}
		}
	}
	int sum=0,s,vn[3002]={0},vf,vi[n],vil,xz,yz;
	scanf("%d",&s);
	vi[0] = s;
	vil = 1;
	while(vil<n)
	{
		for(i=0;i<e;i++)
		{
			xz = 0;
			yz = 0;
			if(vn[a[i].x] == 0 || vn[a[i].y] == 0)
			{
				for(j=0;j<vil;j++)
				{
					if(a[i].x == vi[j])
					{
						xz++;			
					}
					if(a[i].y == vi[j])
					{
						yz++;
					}
				}
				if((xz==0 && yz!=0) || (yz==0 && xz!=0))
				{
					sum = sum + a[i].l;
					if(xz==0)
					{
						vi[vil] = a[i].x;
						vil++;
						vn[a[i].x]++;
					}
					else
					{
						vi[vil] = a[i].y;
						vil++;
						vn[a[i].y]++;
					}
					i = -1;
				}	
			}
		}
	}
	printf("%d\n",sum);
    return 0;
}

