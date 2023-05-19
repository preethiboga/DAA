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
  int i,j;
  for(i=0;i<=n;i++)
  {
  	for(j=0;j<=s;j++)
  	{
  		if(i==0)
  		dp[i][j]=0;
  	    else if(j==0)
  		dp[i][j]=1;
  		else if(wt[i-1]<=j)
  		dp[i][j]=dp[i][j-wt[i-1]]+dp[i-1][j];
  		else
  		dp[i][j]=dp[i-1][j];
  		
	}
  }
  return dp[n][s];
}
