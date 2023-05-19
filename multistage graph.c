#include<stdio.h>
#include<stdlib.h>
int a[100][100];
int mst(int n);
void main()
{
	int n;
	printf("enter no.of vertices:");
	scanf("%d",&n);
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			a[i][j]=INT_MAX;
		}
	}
	int e;
	printf("enter no.of edges:");
	scanf("%d",&e);
	int start,end,cost;
	for(i=0;i<e;i++)
	{
		printf("enter start,end,cost:");
		scanf("%d%d%d",&start,&end,&cost);
		a[start][end]=cost;
	}
	printf("mst=%d",mst(n));
}
int mst(int n)	
{
	int cost[n],i,j;
	cost[n-1]=0;
	for(i=n-2;i>=0;i--)
	{
		int min=INT_MAX;
		for(j=i+1;j<n;j++)
		{
			if(a[i][j]!=INT_MAX)
			{ 
			  int c=a[i][j]+cost[j];
			  if(c<min)
			  min=c;
				
			}
		}
		cost[i]=min;
	}	
	return cost[0];
}
