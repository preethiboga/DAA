#include<stdio.h>
#include<stdlib.h>
int a[100][100],dist[50],par[50],visit[50],n;
void prim();
int findminode();
void print();
void main()
{
	int e;
	printf("enter no.of vertices:");
	scanf("%d",&n);
	printf("enter no.of edges:");
	scanf("%d",&e);
	int i,start,w,j,end;
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
	   par[i]=-1;
	   visit[i]=0;
	}
	dist[0]=0;
	for(i=0;i<e;i++)
	{
		printf("enter starting vertex:");
		scanf("%d",&start);
		printf("enter end vertex:");
		scanf("%d",&end);
		printf("enter weight:");
		scanf("%d",&w);
		a[start][end]=w;
		a[end][start]=w;
	}
	prim();
	
}
void prim()
{
	int i,j,k;
	for(i=0;i<n;i++)
	{
		k=findminode();
		visit[k]=1;
		for(j=0;j<n;j++)
		{
			if(a[k][j]!=INT_MAX && visit[j]!=1)
			{
				if(dist[j]>a[k][j])
				{
					dist[j]=a[k][j];
					par[j]=k;
				}
			}
			
		}
	}
	print();
	
}
int findminode()
{
	int i,min=INT_MAX,min_idx;
	for(i=0;i<n;i++)
	{
		if((visit[i]==0) && dist[i]<min)
		{
	    	min=dist[i];
	    	min_idx=i;
	    }
		
	}
	return min_idx;
}
void print()
{
	int i;
	printf("edge\tweight\n");
	for(i=0;i<n;i++)
	{
	  printf("%d-%d\t%d\n",par[i],i,a[par[i]][i]);	
	}
	
}