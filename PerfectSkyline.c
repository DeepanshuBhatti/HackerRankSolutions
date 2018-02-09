/*
Alice is designing a new n-building skyline for QuantumLand. The building heights are described in an array, H={h0,h1,h2...hn-1}. A perfect skyline has following properties:
Number of buildings is odd.
Building height h0<h1<...<hm, where m=n/2.
Array H is palindromic, meaning it remains unchanged when reversed.
The figure shows a perfect skyline where n=7 and H={1,5,10,20,10,5,1}
Given n and array H, determine if the skyline is Perfect or Not perfect.

Input Format
The first line consists of an integer, n, denoting the number of buildings. 
The second line contains n space-seperated integers, h0,h1,h2...hn-1, describing array H.

Constraints: 
1<=n<=10
Height of each building is between 1 to 100.

Output Format
If the skyline is perfect, print "Perfect"; otherwise, print "Not perfect".

Sample Input
Example 1:
7
1 5 10 20 10 5 1

Example 2:
7
1 5 10 20 9 8 7

Example 3:
5
9 8 5 8 9

Sample Output
Example 1:
Perfect

Example 2:
Not perfect

Example 3:
Not perfect

Explanation
Example 1: This meets all perfect criterion; n=7 is odd, the building heights in h0 through hm (m=7/2=3) are increasing, and the array is palindromic {1<5<10<20>10>5>1}.
Example 2: The array is not palindromic.
Example 3: The values in h0 through hm (m=5/2=2) are not increasing.
*/

#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int main(){
    int n; 
    scanf("%d",&n);
    int H_i, H[n];
    for(H_i = 0; H_i < n; H_i++){
       scanf("%d",&H[H_i]);
    }
    if(n%2==0)
    {
    	printf("Not perfect\n");
    	return 0;
    }
    int j,m = n/2;
    for(j=0;j<m;j++)
    {   
	    if(H[j] != H[n-1-j])
        {
        	printf("Not perfect\n");
		    return 0;
	    }
	    if(H[j] >= H[j+1])
	    {
	        printf("Not perfect\n");
	        return 0;
    	}
    }
    printf("Perfect\n");
    return 0;
}

