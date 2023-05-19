#include<stdio.h>
int feasible(int k,int i);
void hamcycle(int k);
int a[100][100],n,path[100],c=0;
void print();
int main()
{
	int s,e,end,start;
	printf("enter no.of vertices:");
	scanf("%d",&n);
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			a[i][j]=0;
		}
	}
	for(i=0;i<n;i++)
	{
		path[i]=-1;
	}
	printf("enter edges:");
	scanf("%d",&e);
	for(i=0;i<e;i++)
	{
		printf("enter start:");
		scanf("%d",&s);
		printf("enter end:");
		scanf("%d",&end);
		a[s][end]=1;
		a[end][s]=1;
	}
	printf("enter where to start:");
	scanf("%d",&start);
	path[0]=start;
	hamcycle(1);
	if(c==0)
	printf("not possible");
	else
	printf("possible");
}
void hamcycle(int k)
{
	int i;
	for(i=0;i<n;i++)
	{
		if(feasible(k,i))
		{
			path[k]=i;
			if(k==n-1)
			{
				if(a[path[n-1]][path[0]]==1)
				{
					print();
					c++;
					return;
				}
	
			}
			hamcycle(k+1);
		}
	}
	return 0;
}
int feasible(int k,int i)
{`
	int j;
	for(j=0;j<k;j++)
	{
		if(path[j]==i)
		return 0;
	}
	if(a[path[k-1]][i]==0)
	return 0;
	return 1;
}
void print()
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("%d ",path[i]);
	}
	printf("%d ",path[0]);
	printf("\n");
}