/*
Princess Peach is trapped in one of the four corners of a square grid. You are in the center of the grid and can move one step at a time in any of the four directions. Can you rescue the princess?

Input format

The first line contains an odd integer N (3 <= N < 100) denoting the size of the grid. This is followed by an NxN grid. Each cell is denoted by '-' (ascii value: 45). The bot position is denoted by 'm' and the princess position is denoted by 'p'.

Grid is indexed using Matrix Convention

Output format

Print out the moves you will take to rescue the princess in one go. The moves must be separated by '\n', a newline. The valid moves are LEFT or RIGHT or UP or DOWN.

Sample input

3
---
-m-
p--
Sample output

DOWN
LEFT
Task

Complete the function displayPathtoPrincess which takes in two parameters - the integer N and the character array grid. The grid will be formatted exactly as you see it in the input, so for the sample input the princess is at grid[2][0]. The function shall output moves (LEFT, RIGHT, UP or DOWN) on consecutive lines to rescue/reach the princess. The goal is to reach the princess in as few moves as possible.

The above sample input is just to help you understand the format. The princess ('p') can be in any one of the four corners.

Scoring 
Your score is calculated as follows : (NxN - number of moves made to rescue the princess)/10, where N is the size of the grid (3x3 in the sample testcase).
*/


#include <stdio.h>
#include <string.h>
#include <math.h>

void displayPathtoPrincess(int n, char grid[101][101])
{
	int i,t;
	t= (n-1);
    if(grid[0][0] == 'p')
    {
    	for(i=0;i<t;i++)
    	{
    		if(i%2==0)
    		{
    			printf("LEFT\n");
    		}
    		else
    		{
    			printf("UP\n");
    		}
    	}
    }
    if(grid[n-1][0] == 'p')
    {
    	for(i=0;i<t;i++)
    	{
    		if(i%2==0)
    		{
    			printf("LEFT\n");
    		}
    		else
    		{
    			printf("DOWN\n");
    		}
    	}
    }
    if(grid[0][n-1] == 'p')
    {
    	for(i=0;i<t;i++)
    	{
    		if(i%2==0)
    		{
    			printf("RIGHT\n");
    		}
    		else
    		{
    			printf("UP\n");
    		}
    	}
    }
    if(grid[n-1][n-1] == 'p')
    {
    	for(i=0;i<t;i++)
    	{
    		if(i%2==0)
    		{
    			printf("RIGHT\n");
    		}
    		else
    		{
    			printf("DOWN\n");
    		}
    	}
    }
    
}

int main(void)
{
    int i,m;
    scanf("%d", &m);
    if(m<3 || m>100)
    {
    	return 0;
    }
    char grid[101][101]={};
    char line[101];
    for(i=0; i<m; i++)
	{
        scanf("%s", line);
        strcpy(grid[i], line);
    }
    displayPathtoPrincess(m,grid);
    return 0;
}

