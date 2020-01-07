/*
You know my powers, my dear Watson, and yet at the end of three months I was forced to confess that I had at last met an antagonist who was my intellectual equal.

A "valid" string is a string S such that for all distinct characters in S each such character occurs the same number of times in S.

For example, aabb is a valid string because the frequency of both characters a and b is 2, whereas aabbc is not a valid string because the frequency of characters a, b, and c is not the same.

Watson gives a string S to Sherlock and asks him to remove some characters from the string such that the new string is a "valid" string.

Sherlock wants to know from you if it's possible to be done with less than or equal to one removal.

Input Format
The first and only line contains S, the string Watson gives to Sherlock.

Output Format
Output YES if string S can be converted to a "valid" string by removing less than or equal to one character. 
Else, output NO.

Constraints:
1<=size of string S<=10^5 
String S contains lowercase letters (a-z) only.

Sample Input
aabbcd

Sample Output
NO

Explanation
2 is the minimum number of removals required to make it a valid string. It can be done in following two ways:
Remove c and d to get aabb. 
Or remove a and b to get abcd.
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{
	int l,i;
	char s[100000];
	scanf("%s",s);
	l = strlen(s);
	int f[128]={0};
	for(i=0;i<l;i++)
	{
		f[s[i]]++;
	}
	int j,m=0,x=0;
	for(i=97;i<122;i++)
	{
		if(f[i]>0 && f[i+1]>0)
		{
			if(f[i] != f[i+1]&& x==0 && f[i+1]!=m)
			{
				m = f[i+1];
				x++;
			}
			else if(f[i]==f[i+1] && f[i+1]!=m)
			{
				
			}
			else
			{
				printf("NO\n");
				return 0;
			}	
		}	
		
	}
	printf("YES\n");
    return 0;
}

