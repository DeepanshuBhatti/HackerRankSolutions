/*
Sherlock Holmes is getting paranoid about Professor Moriarty, his archenemy.
All his efforts to subdue Moriarty have been in vain. These days Sherlock is
working on a problem with Dr. Watson. Watson mentioned that the CIA has been
facing weird problems with their supercomputer, 'The Beast', recently.

This afternoon, Sherlock received a note from Moriarty, saying that he has
infected 'The Beast' with a virus. Moreover, the note had the number N printed
on it. After doing some calculations, Sherlock figured out that the key to
remove the virus is the largest 'Decent' Number having N digits.

A 'Decent' Number has -
3 or 5 or both as its digits. No other digit is allowed.
Number of times 3 appears is divisible by 5.
Number of times 5 appears is divisible by 3.

Meanwhile, the counter to destruction of 'The Beast' is running very fast.
Can you save 'The Beast', and find the key before Sherlock?

Input Format
The 1st line will contain an integer T, the number of test cases.
This is followed by T lines, each containing an integer N i.e. the number of digits in the number 

Output Format
Largest Decent number having N digits. If no such number exists, tell Sherlock that he is wrong and print '-1' 

Constraints
1<=T<=20
1<=N<=100000


Sample Input
4
1
3
5
11

Sample Output
-1
555
33333
55555533333

Explanation
For N=1, there is no such number. 
For N=3, 555 is only possible number.
For N=5, 33333 is only possible number.
For N=11, 55555533333 and all of permutations of digits are valid numbers, among them, the given number is the largest one.
*/


#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{
	int t,i;
    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
    	int j,a,b,n,x;
    	a=0,b=0;
		scanf("%d",&n);
    	a = n/3;
    	x = a*3 + b*5;
    	while(x!=n)
    	{
    		if(x<n)
    		{
    			b++;
    		}
    		else
    		{
    			a--;
    		}
    		x = a*3 + b*5;
    	}
    	if(n==1 || n==2 || n==4 || n==7)
    	{
    		printf("-1\n");
    		continue;
    	}
    	for(j=0;j<a*3;j++)
    	{
    		printf("5");
    	}
    	for(j=0;j<b*5;j++)
    	{
    		printf("3");
    	}
    	printf("\n");
    }
	return 0;
}

