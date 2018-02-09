/*
If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.

Find the sum of all the multiples of 3 or 5 below N.

Input Format 
First line contains T that denotes the number of test cases. This is followed by T lines, each containing an integer, N.

Output Format 
For each test case, print an integer that denotes the sum of all the multiples of 3 or 5 below N.

Constraints 
1<=T<=10^5 
1<=N<=10^9

Sample Input
2
10
100

Sample Output
23
2318
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        unsigned long long int n,i,j,k,s=0;
        scanf("%llu",&n);
        i = (n-1)/3;
        j = i*(6 + (i-1)*3)/2;
        s = s+j;
        i = (n-1)/5;
        j = i*(10 + (i-1)*5)/2;
        s = s+j;
        i = (n-1)/15;
        j = i*(30 + (i-1)*15)/2;
        s = s-j;
        printf("%llu\n",s);
    }
    return 0;
}

