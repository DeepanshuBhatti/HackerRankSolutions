/*
You are given around five-thousand first names, begin by sorting it into alphabetical order. Then working out the alphabetical value for each name, multiply this value by its alphabetical position in the list to obtain a name score.

For example, when the list in sample is sorted into alphabetical order, PAMELA, which is worth 16+1+13+5+12+1=48, is the 5th name in the list. So, PAMELA would obtain a score of 5×48=240.

You are given Q queries, each query is a name, you have to print the score.

Input Format 
The first line contains an integer N , i.e., number of names. 
Next N lines will contain a Name. 
Followed by integer Q followed by Q lines each having a word.

Output Format 
Print the values corresponding to each test case.

Constraints 
1<=N<=5200 
length of each word will be less than 12 
1<=Q<=100

Sample Input
5
ALEX
LUIS
JAMES
BRIAN
PAMELA
1
PAMELA

Sample Output
240
*/

#include<stdio.h>
#include<string.h>

void merge( char a[][13],int l, int p,int h)
{
	int j,i,t,x,y,k;	
	x = l;
	y = p+1;
	k = 0;
	char b[h-l+1][13];
	for(i=l;i<=h;i++)
	{
		if(x>p)
		{
			strcpy(b[k],a[y]);
			k++;
			y++;
		}
		else if(y>h)
		{
			strcpy(b[k],a[x]);
			k++;
			x++;
		}
		else if(strcmp(a[x],a[y])<0)
		{
			strcpy(b[k],a[x]);
			x++;
			k++;
		}
		else
		{
			strcpy(b[k],a[y]);
			y++;
			k++;
		}
	}
	for(i=0;i<k;i++)
	{
		strcpy(a[l],b[i]);
		l++;
	}
	return;
}

void sort(char a[][13],int l,int h)
{
	if(l<h)
	{
		int p = (l+h)/2;
		sort(a,l,p);
		sort(a,p+1,h);
		merge(a,l,p,h);
	}
	return;
}


int main()
{
	int n,i,q,j,p,l,ans;
	scanf("%d",&n);
	char s[n][13],c[13];
	for(i=0;i<n;i++)
	{
		scanf("%s",s[i]);
	}
	sort(s,0,n-1);
	scanf("%d",&q);
	for(i=0;i<q;i++)
	{
		p = 0;
		ans = 0;
		scanf("%s",c);
		l = strlen(c);
		for(j=0;j<n;j++)
		{
			if(strcmp(s[j],c)==0)
			{
				p = j+1;
				j = n;
			}
		}
		for(j=l-1;j>=0;j--)
		{
			ans = ans + (s[p-1][j]-'A'+1);
			//printf("%c %d\n",s[p-1][j],ans);
		}
		ans = ans*p;
		printf("%d\n",ans);
	}
	return 0;
}

