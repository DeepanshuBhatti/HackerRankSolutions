/*
Find the greatest product of K consecutive digits in the N digit number.

Input Format 
First line contains T that denotes the number of test cases. 
First line of each test case will contain two integers N & K.
Second line of each test case will contain a N digit integer. 

Output Format 
Print the required answer for each test case.

Constraints 
1<=T<=100 
1<=K<=7 
K<=N<=1000

Sample Input
2
10 5
3675356291
10 5
2709360626

Sample Output
3150
0
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
        char s[1001];
        int l,k,i,j;
        long long int a=1,m=0;
        scanf("%d%d",&l,&k);
		scanf("%s",s);
		for(i=0;i+k<l;i++)
		{
			a = 1;
			for(j=i;j<i+k;j++)
			{
				a = a*(s[j]-'0');
			}
			if(m<a)
			{
				m = a;
			}
		}
		
        printf("%lld\n",m);
    }
    return 0;
}

