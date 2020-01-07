/*
Given two points P and Q, output the symmetric point of point P about Q.

Input format: 
The first line contains an integer T representing the number of testcases (T <= 15) 
Each test case contains Px Py Qx Qy representing the (x,y) coordinates of P and Q, all of them being integers.

Constraints 
1 <= T <= 15 
-100 <= x, y <= 100

Output format 
For each test case output x and y coordinates of the symmetric point

Sample input
1  
0 0 1 1

Sample output
2 2

This challenge was a part of Pragyan 12
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{
	int i,t,Px,Py,Qx,Qy,Rx,Ry;
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
		scanf("%d",&Px);
		scanf("%d",&Py);
		scanf("%d",&Qx);
		scanf("%d",&Qy);
		
		Rx = (2*Qx) - Px;
		Ry = (2*Qy) - Py;
		
		printf("%d %d\n",Rx,Ry);
		
	}
    return 0;
}

