#include <stdio.h>
int x[100],n,c=0;
void print(int wt[]);
void ss(int wt[],int w,int n)
{
	if(w==0)
	{
		print(wt);
		c++;
		return;
	}
	if(n==0)
	{
		return;
		 
	}
	if(wt[n-1]<=w)
	{
		x[n-1]=1;
		ss(wt,w-wt[n-1],n-1);
	}
	x[n-1]=0;
	ss(wt,w,n-1);
}
void print(int wt[])
{
	int i;
	for(i=0;i<n;i++)
	{
		if(x[i]==1)
		{
			printf("%d ",wt[i]);
		}
		
	}
	printf("\n");
}
int main()
{
	printf("enter size:");
	scanf("%d",&n);
	int i;
	int wt[n],w;
	printf("enter weight:");
	for(i=0;i<n;i++)
	{
		scanf("%d",&wt[i]);
	}
	for(i=0;i<n;i++)
	{
		x[i]=-1;
	}
	printf("enter w:");
	scanf("%d",&w);
	ss(wt,w,n);
	if(c==0)
	printf("not exists\n");
}