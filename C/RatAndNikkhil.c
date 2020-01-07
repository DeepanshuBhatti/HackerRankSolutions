/*
Nikhil was reading a book,and while reading he fall asleep.Then a rat came and he ate the book of Nikhil. The corner of the book is completely eaten by the Rat.Nikhil woke up and and find the letter scrambled on the table.

Nikhil thinks of a game and from all letters arranged(in some order) i.e Text String ,he wants to find the word (pattern) permutations in text string but continuosly. 
Can you help Nikhil in finding the word.

Constraints
1 <= T <= 100 
1 <= |Pattern| <= 1000 
1 <= |Text String| <= 100000 
Pattern and String will contain only lower-case English letters.

Input Format
First line will contain the T.Each test case contain two lines, first line contains the pattern and the next line contains a text string.

Output Format
For each test case print "YES" or "NO"(quotes for clarity) depend on whether any permutation of the pattern exists in the text string continuously.

Sample Input
5 
back 
frontbacks 
coder 
iamredoc 
anurag 
manitgaranucse 
eddy 
mad 
manit 
manjustdoit

Sample Output
YES 
YES 
YES 
NO 
NO

Explanation
Test case 1: There exists 'back' in 'front"back"s'
Test case 2: There exists 'redoc' which is a permutation of 'coder' in 'iam"redoc"
Test case 3: There exists 'garanu' which is a permutation of 'anurag' in 'manit"garanu"cse'
Test case 4: There exist no permutation of 'eddy' in 'mad'
Test case 5: There exist no continuos permutation of 'manit' in 'manjustdoit'
*/

#include<stdio.h>
#include<string.h>

void merge( char a[],int l, int p,int h)
{
	int j,i,t,x,y,k;	
	x = l;
	y = p+1;
	k = 0;
	char b[h-l+1];
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
		else if(a[x]<a[y])
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

void sort(char a[],int l,int h)
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

void substring(char s[], char sub[], int p, int l) {
   int c = 0;
 
   while (c < l) {
      sub[c] = s[p+c-1];
      c++;
   }
   sub[c] = '\0';
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int l,lt,i,a[26]={0};
		char p[1000],str[100000],cpy[100000],z[1000];
		scanf("%s",p);
		l = strlen(p);
		sort(p,0,l-1);
		for(i=0;i<l;i++)
		{
			a[p[i]-'a']++;
		}
		scanf("%s",str);
		lt = strlen(str);
		if(lt<l)
		{
			printf("NO\n");
			continue;
		}
		int x[100000]={0};
		for(i=0;i<lt;i++)
		{
			if(a[str[i]-'a']>0)
			{
				x[i]++;
			}
			//printf("%d",x[i]);
		}
		//printf("\n");
		for(i=0;i<lt-l+1;i++)
		{
			strcpy(cpy,str);
			if(x[i]==1 && x[i+l-1]==1)
			{
				sort(cpy,i,i+l-1);
				substring(cpy, z, i+1, l);
				//printf("%s ",z);
				if(strcmp(z,p)==0)
				{
					printf("YES\n");
					i = lt + l;
				}
			}
		}
		if(i!=lt+l+1)
		{
			printf("NO\n");
		}
	}
}
