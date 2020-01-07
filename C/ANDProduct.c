/*
You will be given two integers A and B. You are required to compute the bitwise AND amongst all natural numbers lying between A and B, both inclusive.

Input Format
First line of the input contains T, the number of testcases to follow. 
Each testcase in a newline contains A and B separated by a single space.

Constraints
1<=T<=200 
0<=A<=B<2^32

Output Format
Output one line per test case with the required bitwise AND.

Sample Input
3 
12 15 
2 3 
8 13

Sample Output
12 
2 
8

Explanation
For the first testcase,
12 & 13 & 14 & 15 = 12

For second testcase,
2 & 3 = 2

For the third testcase,
8 & 9 & 10 & 11 & 12 & 13 = 8
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    unsigned long long int t;
    scanf("%llu",&t);
    while(t--)
    {
    	int p;
        unsigned long long int a,b,c,d;
        scanf("%llu%llu",&a,&b);
        c = b - a;
        p = log(c)/log(2)+1;
		d = pow(2,p) - 1;
        a = a&b&(0xFFFFFFFF^d);
        printf("%llu\n",a);
    }
    return 0;
}

