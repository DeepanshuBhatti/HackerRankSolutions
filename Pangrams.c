/*
Roy wanted to increase his typing speed for programming contests. So, his friend advised him to type the sentence "The quick brown fox jumps over the lazy dog" repeatedly because it is a pangram. ( pangrams are sentences constructed by using every letter of the alphabet at least once. )

After typing the sentence several times, Roy became bored with it. So he started to look for other pangrams.

Given a sentence s, tell Roy if it is a pangram or not.

Input Format

Input consists of a line containing s.

Constraints 
Length of s can be atmost 10^3 (1<=|s|<=10^3) and it may contain spaces, lowercase and uppercase letters. Lowercase and uppercase instances of a letter are considered same.

Output Format

Output a line containing pangram if s is a pangram, otherwise output not pangram.

Sample Input #1

We promptly judged antique ivory buckles for the next prize    
Sample Output #1

pangram
Sample Input #2

We promptly judged antique ivory buckles for the prize    
Sample Output #2

not pangram
Explanation

In the first testcase, the answer is pangram because the sentence contains all the letters.
*/

#include<stdio.h>
#include<string.h>
#include<stdio.h>
int main()
{
	char s[1002];
	fflush(stdin);
	scanf("%[^\n]s",s);
	int l,i,j;
	l = strlen(s);
	if(l<1 || l>1000)
	{
		return 0;
	}
	int a[26] = {0};
	for(i=0;i<l;i++)
	{
		for(j=0;j<26;j++)
		{
			if(a[j]<1)
			{
				if(s[i] == j+65 || s[i] == j+97)
				{
					a[j]++;
					continue;
				}
			}
		}
	}
	for(i=0;i<26;i++)
	{
		if(a[i]==0)
		{
			printf("not pangram\n");
			return 0;
		}
	}
	printf("pangram\n");
	return 0;
}
