/*
You and your K-1 friends want to buy N flowers. Flower number i has cost ci. Unfortunately the seller does not want just one customer to buy a lot of flowers, so he tries to change the price of flowers for customers who have already bought some flowers. More precisely, if a customer has already bought x flowers, he should pay (x+1)*ci dollars to buy flower number i.
You and your K-1 friends want to buy all N flowers in such a way that you spend the least amount of money. You can buy the flowers in any order.

Input:

The first line of input contains two integers N and K (K <= N). The next line contains N space separated positive integers c1,c2,...,cN.

Output:

Print the minimum amount of money you (and your friends) have to pay in order to buy all N flowers.

Constraint :
1 <= N, K <= 100 
Any ci is not more than 1,000,000

Sample input #00
3 3
2 5 6

Sample output #00
13

Sample input #01
3 2
2 5 6

Sample output #01
15

Explanation : 
Sample Case #00: In this example, all of you should buy one flower each. Hence, you'll have to pay 13 dollars. 
Sample Case #01: Here one of the friend buys first two flowers in decreasing order of their price. So he will pay (0+1)*5 + (1+1)*2 = 9. And other friend will buy the costliest flower of cost 6. So total money need is 9+6=15.
*/

#include<stdio.h>

int main()
{
	int i, N, K, j, t;
   	long long int result=0;
	int C[102];
   	scanf("%d %d", &N, &K);
   	for(i=0; i<N; i++)
	{
    	scanf("%d", &(C[i]));
   	}
   	for(i=0; i<N-1; i++)
	{
    	for(j=i+1;j<N;j++)
    	{
    		if(C[i] > C[j])
    		{
    			t = C[j];
    			C[j] = C[i];
    			C[i] = t;
    		}
    	}
   	}
   	int z;
   	t = N/K + 1;
   	i = N-1;
	for(j=0;j<t;j++)
	{
		for(z=0;z<K && i>-1;z++)
		{
			//printf("%d\n",((j+1)*C[i]));
			result = result + ((j+1)*C[i]);
			i--;
		}
	}
	printf("%lld\n", result);

}

