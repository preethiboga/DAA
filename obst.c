#include<stdio.h>
#include<stdlib.h>
int sum(int freq[],int i,int j);
int obst(int freq[],int i,int j);
void main()
{
	int n;
	printf("enter no.of keys:");
	scanf("%d",&n);
	int f[n],i;
	printf("enter frequencies:");
	for(i=0;i<n;i++)
	{
		scanf("%d",&f[i]);
	}
	printf("%d",obst(f,0,n-1));
}
int obst(int f[100],int i,int j)
{
	int l,cost;
	int min=INT_MAX;
	if(i>j)
	return 0;
	if(i==j)
	return f[i];
	for(l=i;l<=j;l++)
	{
		cost=obst(f,i,l-1)+obst(f,l+1,j);
		if(cost<min)
		min=cost;
	}
	return min+sum(f,i,j);
}
int sum(int f[100],int i,int j)
{
	int s=0,k;
	for(k=i;k<=j;k++)
	{
		s=s+f[k];
	}
	return s;
}
