#include<stdio.h>
int a[100][100];
void main()
{
	int n,i,j;
	printf("enter n:");
	scanf("%d",&n);
	int val[n],wt[n];
	printf("enter value array:");
	for(i=0;i<n;i++)
	{
		scanf("%d",&val[i]);
	}
	printf("enter weight array:");
	for(i=0;i<n;i++)
	{
		scanf("%d",&wt[i]);
	}
	int w;
	printf("enter ks capacity:");
	scanf("%d",&w);
	for(i=0;i<n;i++)
	{
		for(j=0;j<w;j++)
		{
			a[i][j]=-1;
		}
	}
	int k=ks(val,wt,n,w);
	printf("%d",k);
}
int ks(int val[],int wt[],int n,int w)
{
	int i,j,p,q;
	for(i=0;i<=n;i++)
	{
		for(j=0;j<=w;j++)
		{
			if(i==0||j==0)
			a[i][j]=0;
			else if(wt[i-1]<=j)
			{
				p=val[i-1]+a[i][j-wt[i-1]];
				q=a[i-1][j];
				if(p>=q)
				a[i][j]=p;
				else 
				a[i][j]=q;
			}
			else
			a[i][j]=a[i-1][j];
		}
	}
	return a[n][w];
}
