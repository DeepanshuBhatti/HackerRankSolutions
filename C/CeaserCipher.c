/*
Julius Caesar protected his confidential information by encrypting it in a cipher. Caesar's cipher rotated every letter in a string by a fixed number, K, making it unreadable by his enemies. Given a string, S, and a number, K, encrypt S and print the resulting string.

Note: The cipher only encrypts letters; symbols, such as -, remain unencrypted.

Input Format
The first line contains an integer, N, which is the length of the unencrypted string. 
The second line contains the unencrypted string, S. 
The third line contains the integer encryption key, K, which is the number of letters to rotate.

Constraints 
1<=N<=100 
0<=K<=100 
S is a valid ASCII string and doesn't contain any spaces.

Output Format
For each test case, print the encoded string.

Sample Input
11
middle-Outz
2

Sample Output
okffng-Qwvb

Explanation
Each unencrypted letter is replaced with the letter occurring K spaces after it when listed alphabetically. Think of the alphabet as being both case-sensitive and circular; if K rotates past the end of the alphabet, it loops back to the beginning (i.e.: the letter after z is a, and the letter after Z is A).

Selected Examples: 
m (ASCII 109) becomes o (ASCII 111). 
i (ASCII 105) becomes k (ASCII 107). 
- remains the same, as symbols are not encoded. 
O (ASCII 79) becomes Q (ASCII 81). 
z (ASCII 122) becomes b (ASCII 98); because z is the last letter of the alphabet, a (ASCII 97) is the next letter after it in lower-case rotation.
*/

#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int main(){
    int n,i,k; 
    scanf("%d",&n);
    char s[n];
    scanf("%s",s);
    scanf("%d",&k);
    k = k%26;
    for(i=0;i<n;i++)
    {
    	if(s[i] >= 65 && s[i] <= 90)
    	{
    		if(k+s[i] <= 90)
    		{
    			printf("%c",k+s[i]);
    		}
    		else
    		{
    			printf("%c",k+s[i]-26);
    		}
    	}
    	else if(s[i] >= 97 && s[i] <= 122)
    	{
    		if(k+s[i] <= 122)
    		{
    			printf("%c",k+s[i]);
    		}
    		else
    		{
    			printf("%c",k+s[i]-26);
    		}
    	}
    	else
    	{
    		printf("%c",s[i]);
    	}
    }
    return 0;
}

