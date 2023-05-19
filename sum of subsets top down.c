#include<stdio.h>
int a[100][100];
int ss(int wt[],int w ,int n)
{
	int i,j;
	for(i=0;i<=n;i++)
	{
		for(j=0;j<=w;j++)
		{
			if(j==0)
			a[i][j]=1;
			else if(i==0)
			a[i][j]=0;
			else if(wt[i-1]<=j)
			a[i][j]=((a[i-1][j-wt[i-1]])||(a[i-1][j]));
			else
			a[i][j]=a[i-1][j];
			
		}
	}
	return a[n][w];
}
int main()
{
	int n,w,j;
	printf("enter size: ");
	scanf("%d",&n);
	int wt[n];
	printf("enter weight array:");
	int i;
	for(i=0;i<n;i++)
	{
		scanf("%d",&wt[i]);
	}
	printf("enter weight:");
	scanf("%d",&w);
	for(i=0;i<=n;i++)
	{
		for(j=0;j<=w;j++)
		{
			a[i][j]=-1;
		}
	}
	printf("%d",ss(wt,w,n));
	
}

