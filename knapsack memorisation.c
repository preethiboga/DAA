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

	if(n==0||w==0)
	 return dp[n][w]=0;
	if(dp[n][w]!=-1)
	 return dp[n][w];    
	if(wt[n-1]<=w)
	   	 return dp[n][w]=max((val[n-1]+ks(wt,val,n-1,w-wt[n-1])),ks(wt,val,n-1,w));	
	 else
	    return dp[n][w]=ks(wt,val,n-1,w);  	    
}
