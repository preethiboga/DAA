#include<stdio.h>
#include<stdlib.h>
int cc(int wt[],int n,int s);
int min(int a,int b);
void main()
{
	int n;
	printf("enter no.of coins:");
	scanf("%d",&n);
	printf("enter coins:");
	int i,wt[n];
	for(i=0;i<n;i++)
	{
		scanf("%d",&wt[i]);
	}
	printf("enter sum:");
	int s;
	scanf("%d",&s);
	printf("min no.of coins=%d",cc(wt,n,s));
}
int cc(int wt[],int n,int s)
{
	if(n==0)
	return INT_MAX-20;
	if(s==0)
	return 0;
	if(wt[n-1]<=s)
	return min((1+cc(wt,n,s-wt[n-1])),(cc(wt,n-1,s)));
	else
	return cc(wt,n-1,s);
	
}
int min(int a,int b)
{
	if(a<b)
	return a;
	else
	return b;
}