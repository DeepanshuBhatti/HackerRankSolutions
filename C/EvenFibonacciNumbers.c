/*
Each new term in the Fibonacci sequence is generated by adding the previous two terms. By starting with 1 and 2, the first 10 terms will be:
1,2,3,5,8,13,21,34,55,89,?
By considering the terms in the Fibonacci sequence whose values do not exceed N, find the sum of the even-valued terms.

Input Format 
First line contains T that denotes the number of test cases. This is followed by T lines, each containing an integer, N.

Output Format 
Print the required answer for each test case.

Constraints 
1<=T<=10^5 
10<=N<=4�10^16

Sample Input
2
10
100

Sample Output
10
44
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
        unsigned long long int n,a=0,b=1,s=0,x;
        scanf("%llu",&n);
        while(a+b<n)
        {
            x = a+b;
            a = b;
            b = x;
            if(b%2==0)
            {
                s = s + b;
            }
        }
        printf("%llu\n",s);
    }
    return 0;
}

