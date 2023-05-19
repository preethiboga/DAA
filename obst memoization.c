#include<stdio.h>
#include<stdlib.h>
int sum(int freq[],int i,int j);
int obst(int freq[],int i,int j);
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
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			c[i][j]=-1;
		}
	}
	printf("%d",obst(f,0,n-1));
}
int obst(int f[],int i,int j)
{
	if(i>j)
	return c[i][j]=0;
	if(c[i][j]!=-1)
	return c[i][j];
	if(i==j)
	return c[i][j]=f[i];
	int min=INT_MAX,l;
	for(l=i;l<=j;l++)
	{
		int cost=obst(f,i,l-1)+obst(f,l+1,j);
		if(cost<min)
		min=cost;
	}
	return c[i][j]=min+sum(f,i,j);
	
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
