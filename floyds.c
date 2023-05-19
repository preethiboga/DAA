#include<stdio.h>
int min(int a,int b);
void floyds(int p[10][10],int n);
void main()
{
	int p[10][10],w,n,e,u,v,i,j;
	printf("enter no.of vertices:");
	scanf("%d",&n);
	printf("enter no.of edges:");
	scanf("%d",&e);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(i==j)
			p[i][j]=0;
			else
			p[i][j]=999;
		}
	}
	for(i=0;i<e;i++)
	{
		printf("enter end vertices with weight:");
		scanf("%d%d%d",&u,&v,&w);
		p[u][v]=w;
	}
	printf("input matrix:\n");
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			printf("%d ",p[i][j]);
		}
		printf("\n");
	}
	floyds(p,n);
	printf("output matrix:\n");
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			printf("%d ",p[i][j]);
			
		}
		printf("\n");
	}
	printf("shortest paths are:");
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(i!=j)
			printf("<%d,%d>=%d\n",i,j,p[i][j]);
		}
	}
}
void floyds(int p[10][10],int n)
{
	int i,j,k;
	for(k=1;k<=n;k++)
	{
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				if(i==j)
				p[i][j]=0;
				else if(i==k||j==k)
				p[i][j]=p[i][j];
				else
				p[i][j]=min(p[i][j],p[i][k]+p[k][j]);
			}
		}
	}
}
int min(int a,int b)
{
	if(a<b)
	return a;
	else
	return b;
}

