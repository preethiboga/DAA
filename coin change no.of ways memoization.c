#include<stdio.h>
int cc(int wt[],int s,int n);
void inti(int n,int s);
int dp[100][100];
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
	int n,j;
	printf("enter no.of coins:");
	scanf("%d",&n);
	int wt[n];
	printf("enter coins:");
	int i;
	for(i=0;i<n;i++)
	{
		scanf("%d",&wt[i]);
	}
	int s;
	printf("enter sum:");
	scanf("%d",&s);
	inti(n,s);
	printf("total no.of ways=%d",cc(wt,s,n));
	
}
int cc(int wt[],int s,int n)
{
  if(n==0)
  return dp[n][s]=0;
  if(s==0)
  return dp[n][s]=1;
  if(dp[n][s]!=-1)
  return dp[n][s];
  if(wt[n-1]<=s)
  return dp[n][s]=(cc(wt,s-wt[n-1],n)+cc(wt,s,n-1));
  else
  return dp[n][s]=cc(wt,s,n-1);
}
