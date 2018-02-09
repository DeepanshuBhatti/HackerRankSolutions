/*
Problem Statement

250px-Sudoku-by-L2G-20050714_solution.svg.pngSudoku originally called Number Place, is a logic-based, combinatorial number-placement puzzle. The objective is to fill a 9×9 grid with digits so that each column, each row, and each of the nine 3×3 sub-grids that compose the grid (also called "boxes", "blocks", "regions", or "sub-squares") contains all of the digits from 1 to 9. The puzzle setter provides a partially completed grid, which for a well-posed puzzle has a unique solution.

Sudoku solving, trains your mind to process various forms of information, details, images and strategies at lightening speeds. While you devise strategies to win the game, it also builds your neural connections. It helps in extending dendrite connections in your brain cells which help improve memory. Scientists say solving them depends on neural pathways that even the most powerful computers can't replicate.

Ms Iona gave sudoku puzzles to her children for solving. The students solved the puzzles and the results were collected back.Only after conducting the contest the she realised that the task of checking if all the solutions are correct is a tedious task.

Can you help her by writing a program that accepts a sudoku solution instance as input and checks whether the particular instance is correct or not.

Input Format

A 9x9 matrix of numbers.There is no space between numbers in a row in the input.

Output Format

If the solution is correct your program should output "Correct", otherwise "Incorrect"

Sample Input

417369825
632158947
958724316
825437169
791586432
346912758
289643571
573291684
164875293

Sample Output

Correct

Explanation

http://www.sudoku.name/rules/en
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{
	char s[9][9];
	int i,j,a[9][9]={0};
	for(i=0;i<9;i++)
	{
		scanf("%s",s[i]);
	}
	for(i=0;i<9;i++)
	{
		for(j=0;j<9;j++)
		{
			a[i][j] = s[i][j]-48;
		}
	}
	for(i=0;i<9;i++)
	{
		int b[9] = {0};
		for(j=0;j<9;j++)
		{
			if(b[a[i][j]-1]==0)
			{
				b[a[i][j]-1]++;
			}
			else
			{
				printf("Incorrect\n");
				return 0;
			}
		}
	}
	for(i=0;i<9;i++)
	{
		int b[9] = {0};
		for(j=0;j<9;j++)
		{
			if(b[a[j][i]-1]==0)
			{
				b[a[j][i]-1]++;
			}
			else
			{
				printf("Incorrect\n");
				return 0;
			}
		}
	}
	printf("Correct\n");
    return 0;
}

