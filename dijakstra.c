#include<stdio.h>
#include<stdlib.h>
int a[100][100],dist[50],visit[50],n;
void dijkastra(int src);
int findminnode();
void print();
void main()
{
	int e;
	printf("enter no.of vertices:");
	scanf("%d",&n);
	printf("enter no.of edges:");
	scanf("%d",&e);
	int i,start,w,j,end,src;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			a[i][j]=INT_MAX;
		}
	}
	for(i=0;i<n;i++)
	{
	   dist[i]=INT_MAX;
	   visit[i]=0;
	}
	for(i=0;i<e;i++)
	{
		printf("enter starting vertex:");
		scanf("%d",&start);
		printf("enter end vertex:");
		scanf("%d",&end);
		printf("enter weight:");
		scanf("%d",&w);
		a[start][end]=w;
	}
	printf("enter source:");
	scanf("%d",&src);
	dijkastra(src);
	
}
int findminnode()
{
	int i,min=INT_MAX,min_idx;
	for(i=0;i<n;i++)
	{
		if(visit[i]==0 && dist[i]<=min)
		{
			min_idx=i;
			min=dist[i];
		}
	}
	return min_idx;
}

void print()
{
	int i;
	printf("vertex\tdistance from source\n");
	for(i=0;i<n;i++)
	{
		printf("%d\t\t\%d\n",i,dist[i]);
	}
}
void dijkastra(int src)
{
   int i,j,k;
   dist[src]=0;
	for(i=0;i<n;i++)
	{
		k=findminnode();
		visit[k]=1;
		for(j=0;j<n;j++)
		{
			if(a[k][j]!=INT_MAX && visit[j]!=1 && dist[k]!=INT_MAX)
			{
				if(dist[j]>a[k][j]+dist[k])
				{
					dist[j]=a[k][j]+dist[k];	
				}
			}
			
		}
	}
	print();
}