/*
Ram Prasath wants to create a closure password which is the simplification of the orginal password.

The orginal and closured password is Case Sensitive.

Closure Password 
In the closure password all the characters should be unique.

Input Format 
There will be two lines of input:

n - the size of the array
ar - the array
Output Format 
Closure password.

Constraints 
1<=n<=1000 .

Sample Input 
5 
Adhar

Sample Output 
Adhar

Explanation 
Since all elements occured Once(a&A also diffeerent)

Sample Input 
10 
Ramprasath

Sample Output 
Ramprsth
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

int main(void)
{
	int i,j,n,a[256] = {0};
	scanf("%d", &n);
	char s[100];
	scanf("%s",s);
	for(i=0;i<n;i++)
	{
		if(a[s[i]-48] == 0)
		{
			a[s[i]-48]++;
			printf("%c",s[i]);
		}
	}
   	return 0;
}

