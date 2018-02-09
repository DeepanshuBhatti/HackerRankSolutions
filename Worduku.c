/*
Since her students were so good at sudoku , Ms Iona decided them to test them further. She modified the game of sudoku to create a new game 'wordoku'.

The rules of Wordoku are very similar to that of sudoku.
*Every letter for the Wordoku must appear once.
*In each of the columns.
*in each of the rows.
*in each of the nine boxes.
To add a bit more level of challenge she decided to include a nine letter word in the Wordoku . On successfully solving the Wordoku the word will appear on one of the rows/columns. The winner will be exempted from weekly assignments.Little Bunn wants to be the winner.However being not so good at programming he decided to consult you.

Will you help him ?

Input Format

A 9x9 matrix of letters with dotes(.) denoting the missing letters.
The word to be found.

Output Format

Print number of the Row/Column where the word is found along with word "Row" or "Column".

Sample Input

f...s...r
.e..o..b.
..ie.rt..
..o...b..
tt.....io
..r...e..
..to.tf..
.s..i..o.
e...r...b
frostbite

Sample Output

Column 1

Explanation

Solution of wordoku is 
fttbsioer
restoftbi
obietrtfs
sfoietbrt
tterfbsio
birstoetf
irtobtfse
tsbfierot
eoftrsitb

frostbite can be found in Column 1
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{
	int i,j,x[2][9]={0},max,z,f;
	char a[9][9],b[9];
	for(i=0;i<9;i++)
	{
		scanf("%s",a[i]);
	}
	scanf("%s",b);
	for(i=0;i<9;i++)
	{
		for(j=0;j<9;j++)
		{
			if(a[i][j] == b[j])
			{
				x[0][i]++;
			}
		}
	}
	for(i=0;i<9;i++)
	{
		for(j=0;j<9;j++)
		{
			if(a[j][i] == b[j])
			{
				x[1][i]++;
			}
		}
	}
	max = x[0][0];
	z=0;
	for(i=0;i<2;i++)
	{
		for(j=0;j<9;j++)
		{
			//printf("%d ",x[i][j]);
			if(max<x[i][j])
			{
				max = x[i][j];
				f = j;
				z = i;
			}
		}
		//printf("\n");
	}
	//printf("%d\n",max);
	if(z==1)
	{
		printf("Column %d\n",f+1);
	}
	else
	{
		printf("Row %d\n",f+1);
	}
    return 0;
}

