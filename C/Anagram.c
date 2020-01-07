/*
Sid is obsessed about reading short stories. Being a CS student, he is doing some interesting frequency analysis with the books. He has two short story books. He chooses strings having length a from the first book and strings having length b from the second one. The strings are such that the difference of length is <= 1
i.e.
|a-b|<=1, where |x| represents the absolute value of x.
He believes that both the strings should be anagrams based on his experiment.Your challenge is to help him find the minimum number of characters of the first string he needs to change to enable him to make it an anagram of the second string. He can neither add a character nor delete a character from the first string. Only replacement of the original characters with the new ones is allowed.

Input Format
The first line will contain an integer T representing the number of test cases. Each test case will contain a string having length (a+b) which will be concatenation of both the strings described above in the problem. The string will only contain small letters and there will be no spaces in the string.

Output Format
An integer corresponding to each test case is printed in a different line i.e., the number of changes required for each test case. Print '-1' if it is not possible.

Constraints
1<=T<=100 
length of input string i.e. 1<=a+b<=10000

Sample Input
5
aaabbb
ab
abc
mnop
xyyx

Sample Output
3
1
-1
2
0 

Explanation 
Test Case #00: We have to replace at least three characters from any of the string to make both of strings anagram. Here, a = "aaa" and b = "bbb". One possible solution is to replace all character 'a' in string a with character 'b'. 
Test Case #01: Either replace 'a' with 'b', which will generate "bb". Or replace 'b' with 'a' to generate "aa". Both of the solution are valid. 
Test Case #02: It is not possible for two strings of unequal length to be anagram for each other. 
Test Case #03: We have to replace both the characters of any string to make it anagram of other one. 
Test Case #04: First string will be "xy" while second string will be "yx" . so a = 2 and b = 2, where a and b are length of strings. As we can see that a and b are following relation

|a-b|<=1
and both strings are anagrams.So number of changes required = 0.
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
		int i,j,l1,l,mat1[26] = {0},mat2[26]={0},a;
		char s[10001];
		scanf("%s",s);
		l = strlen(s);
		if(l%2==1)
		{
			a  = -1;
			printf("%d\n",a);
			continue;
		}
		l1 = l/2;
		for(i=0;i<l1;i++)
		{
			mat1[s[i]-'a']++;
			mat2[s[l-i-1]-'a']++;
		}
		a = 0;
		for(i=0;i<26;i++)
		{
			a = a + abs(mat1[i] - mat2[i]);
		}
		printf("%d\n",a/2);
	}
    return 0;
}

