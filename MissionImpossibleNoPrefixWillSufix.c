/*
Mission Impossible : No Prefixes will Suffix

Prefix and suffix are refinements of substring. A prefix of a string S is
a substring of S that occurs at the beginning of S. A suffix of a string S
is a substring that occurs at the end of S.

The hackerville intelligence agency (HIA) routers were recently attacked
by a malware that attaches a portion at the end of every message to the
beginning of the next message. HIA has a list of affected messages.
Being a cool programmer you were hired by HIA. Given a message pair you 
have to identify the part of message which was generated by the virus.

Input Format
First String
Second String

Output Format
Longest suffix of first string which is a prefix of second string.

If there is no such string print "This Message Pair is Safe!"

Sample Input

casper
perform

Sample Output

per

Explanation

per is the longest suffix of casper which is a prefix of perform.
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	char a[1000],b[1000],c[1000];
	int x,y,z,i,j,k;
	scanf("%s",a);
	x = strlen(a);
	scanf("%s",b);
	y = strlen(b);
	for(i=0;i<x;i++)
	{
		if(a[i] == b[0])
		{
			j = 0;
			k = i;
			for(z=i;z<x;z++)
			{
				if(a[z] == b[j])
				{
					c[j] = a[z];
					j++;
					k++;
				}
			}
		}
		if(k==x)
		{
			c[j]='\0';
			printf("%s\n",c);
			return 0;
		}
	}
	printf("This Message Pair is Safe!\n");
	return 0;
}
