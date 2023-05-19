#include<stdio.h>
int ks(int wt[],int val[],int n,int w);
int dp[100][100];
int max(int p,int q);
void inti(int n,int w);
void inti(int n,int w)
{
    int i,j;
    for(i=0;i<=n;i++)
    {
    	for(j=0;j<=w;j++)
    	{
    		dp[i][j]=-1;
		}
	}
}
void main()
{
	int n,i,w,k,j;
	printf("enter n:");
	scanf("%d",&n);
	int val[n],wt[n];
	printf("enter values:");
	for(i=0;i<n;i++)
	{
		scanf("%d",&val[i]);
	}
	printf("enter weights:");
	for(i=0;i<n;i++)
	{
		scanf("%d",&wt[i]);
	}
	printf("enter knapsack capacity:");
	scanf("%d",&w);
	printf("values:");
	for(i=0;i<n;i++)
	{
		printf("%d ",val[i]);
	}
	printf("\n");
	printf("weights:");
	for(i=0;i<n;i++)
	{
		printf("%d ",wt[i]);
	}
	printf("\n");
	inti(n,w);
	k=ks(wt,val,n,w);
	printf("%d",k);
}
int max(int p,int q)
{
	if(p<=q)
	return q;
	else
	return p;
	
}
int ks(int wt[],int val[],int n,int w)
{
	int i,j;
	for(i=0;i<=n;i++)
	{
		for(j=0;j<=w;j++)
		{
			if(i==0||j==0)
			dp[i][j]=0;
			else if(wt[i-1]<=j)
			dp[i][j]=max((val[i-1]+dp[i-1][j-wt[i-1]]),dp[i-1][j]);
			else
			dp[i][j]=dp[i-1][j];
		}
	}
	return dp[n][w];
}
