/*
Given N integers, count the number of pairs of integers whose difference is K.

Input Format
The first line contains N and K. 
The second line contains N numbers of the set. All the N numbers are unique.

Output Format
An integer that tells the number of pairs of integers whose difference is K.

Constraints: 
N<=10^5 
0<K<10^9 
Each integer will be greater than 0 and at least K smaller than 231-1.

Sample Input
5 2  
1 5 3 4 2  

Sample Output
3

Explanation
There are 3 pairs of integers in the set with a difference of 2.
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
/* Head ends here */

void merge( int a[],int l, int p,int h)
{
	int j,i,t,x,y,k;	
	x = l;
	y = p+1;
	k = 0;
	int b[h-l+1];
	for(i=l;i<=h;i++)
	{
		if(x>p)
		{
			b[k] = a[y];
			k++;
			y++;
		}
		else if(y>h)
		{
			b[k] = a[x];
			k++;
			x++;
		}
		else if(a[x]>a[y])
		{
			b[k] = a[x];
			x++;
			k++;
		}
		else
		{
			b[k] = a[y];
			y++;
			k++;
		}
	}
	for(i=0;i<k;i++)
	{
		a[l] = b[i];
		l++;
	}
	return;
}

void sort(int a[],int l,int h)
{
	if(l<h)
	{
		int p = (l+h)/2;
		//printf("%d ",p);
		sort(a,l,p);
		sort(a,p+1,h);
		
		merge(a,l,p,h);
	}
	return;
}


int pairs(int a_size, int* a, int k)
{    
   int i,j,ans=0,p=1;
   sort(a,0,a_size-1);
   for(i=0;i<a_size-1;i++)
   {
   		for(j=p;a[i]-a[j]<=k && j<a_size;j++)
   		{
   			if(a[i]-a[j]==k)
   			{
   				ans++;
   			}
   			p=j;
   		}
   }
   return ans;
}

/* Tail starts here */
int main() {
    int res;
   
    int _a_size,_a_i,_k;
    scanf("%d %d", &_a_size,&_k);
    int _a[_a_size];
    for(_a_i = 0; _a_i < _a_size; _a_i++) { 
        int _a_item;
        scanf("%d", &_a_item);
        
        _a[_a_i] = _a_item;
    }
   res=pairs(_a_size,_a,_k);
   printf("%d\n",res);    
    return 0;
}

