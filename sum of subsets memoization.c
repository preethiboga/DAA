#include<stdio.h>
int a[100][100];
int ss(int wt[],int w ,int n)
{
	if(w==0)
	return a[n][w]=1;
	if(n==0)
	return a[n][w]=0;
	if(wt[n-1]<=w)
	{
		return a[n][w]=((ss(wt,w-wt[n-1],n-1))||(ss(wt,w,n-1)));
	}
	return a[n][w]=(ss(wt,w,n-1));
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

