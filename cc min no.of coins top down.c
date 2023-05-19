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
	int i,wt[n],j;
	for(i=0;i<n;i++)
	{
		scanf("%d",&wt[i]);
	}
	printf("enter sum:");
	int s;
	scanf("%d",&s);
	inti(n,s);
	printf("min no.of coins=%d\n",cc(wt,n,s));
}
int cc(int wt[],int n,int s)
{
	int i,j;
	for(i=0;i<=n;i++)
	{
		for(j=0;j<=s;j++)
		{
			if(i==0)
			dp[i][j]=INT_MAX-30;
			else if(j==0)
			dp[i][j]=0;
			else if(wt[i-1]<=j)
			dp[i][j]=min((1+dp[i][j-wt[i-1]]),(dp[i-1][j]));
			else
			dp[i][j]=dp[i-1][j];
		}
	}
	return dp[n][s];
	
}
int min(int a,int b)
{
	if(a<b)
	return a;
	else
	return b;
}