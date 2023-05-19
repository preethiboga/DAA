#include<stdio.h>
#include<stdlib.h>
int sum(int freq[],int i,int j);
int obst(int freq[],int n);
int c[100][100];
void main()
{
	int n;
	printf("enter no.of keys:");
	scanf("%d",&n);
	int f[n],i,j;
	printf("enter frequencies:");
	for(i=0;i<n;i++)
	{
		scanf("%d",&f[i]);
	}
	printf("%d",obst(f,n));
	for(i=0;i<=n;i++)
	{
		for(j=0;j<=n;j++)
		printf("%d  ",c[i][j]);
		printf("\n");
	}
}
int obst(int freq[],int n)
{
	int i,l,j,r;
	for(i=0;i<n;i++)
	c[i][i]=freq[i];
	for(l=2;l<=n;l++)
	{
		for(i=0;i<n-l+1;i++)
		{
			int j=l+i-1;
			c[i][j]=INT_MAX;
			for(r=i;r<=j;r++)
			{
				int cost=((r>i)?c[i][r-1]:0)+((r<j)?c[r+1][j]:0)+sum(freq,i,j);
				if(cost<c[i][j])
				c[i][j]=cost;
			}
		}
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%d ",c[i][j]);
		}
		printf("\n");
	}
	return c[0][n-1];
}
int sum(int f[],int i,int j)
{
	int s=0,k;
	for(k=i;k<=j;k++)
	{
		s=s+f[k];
	}
	return s;
}


