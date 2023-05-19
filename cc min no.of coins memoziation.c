#include<stdio.h>
#include<stdlib.h>
int cc(int wt[],int n,int s);
int min(int a,int b);
void inti(int n,int s);
int dp[20][20];
void inti(int n,int s)
{
	int i,j;
	for(i=0;i<=n;i++)
	{
		for(j=0;j<=s;j++)
		{
			dp[i][j]=-1;
		}
	}
}
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
	inti(n,s);
	printf("min no.of coins=%d",cc(wt,n,s));
}
int cc(int wt[],int n,int s)
{
	if(n==0)
	return dp[n][s]=INT_MAX-20;
	if(s==0)
	return dp[n][s]=0;
	if(dp[n][s]!=-1)
	return dp[n][s];
	if(wt[n-1]<=s)
	return dp[n][s]=min((1+cc(wt,n,s-wt[n-1])),(cc(wt,n-1,s)));
	else
	return dp[n][s]=cc(wt,n-1,s);
	
}
int min(int a,int b)
{
	if(a<b)
	return a;
	else
	return b;
}