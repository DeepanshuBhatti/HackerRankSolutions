/*
John has discovered various rocks. Each rock is composed of various elements, and each element is represented by a lowercase latin letter from 'a' to 'z'. An element can be present multiple times in a rock. An element is called a 'gem-element' if it occurs at least once in each of the rocks.

Given the list of N rocks with their compositions, display the number of gem-elements that exist in those rocks.

Input Format 
The first line consists of N, the number of rocks. 
Each of the next N lines contain rocks' composition. Each composition consists of lowercase letters of English alphabet.

Output Format 
Print the number of gem-elements that are common in these rocks. If there are none, print 0.

Constraints 
1 = N = 100 
Each composition consists of only lowercase latin letters ('a'-'z'). 
1 = Length of each composition = 100

Sample Input

3
abcdde
baccd
eeabg
Sample Output

2
Explanation 
Only "a", "b" are the two kind of gem-elements, since these are the only characters that occur in each of the rocks' composition.
*/

#include<string.h>
#include<stdio.h>

int main()
{
	int n,i,j,l,k;
	scanf("%d",&n);
	if(n<1 || n>100)
	{
		return 0;
	}
	char s[1000];
	int c[26]={0};
	for(i=0;i<n;i++)
	{
		scanf("%s",s);
		l = strlen(s);
		if(l<1 || l>100)
		{
			return 0;
		}
		for(j=0;j<l;j++)
		{
			for(k=0;k<26;k++)
			{
				if(c[k] == i)
				{
					if(s[j] == k+97)
					{
						c[k]++;
						continue;
					}
				}
			}
		}
	}
	int ans=0;
	for(i=0;i<26;i++)
	{
		//printf("%c : %d\n",i+97,c[i]);
		if(c[i] == n)
		{
			ans++;
		}
	}
	printf("%d\n",ans);
	return 0;
}
