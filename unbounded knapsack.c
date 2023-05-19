#include<stdio.h>
int ks(int wt[],int val[],int n,int w);
void main()
{
	int n,i,w,k;
	printf("enter n:");
	scanf("%d",&n);
	int val[n],wt[n];
	printf("enter values:");
	for(i=0;i<n;i++)
	{
		scanf("%d",&val[i]);
	}
	printf("enter weights:");
	for(i=0;i<n;i++)
	{
		scanf("%d",&wt[i]);
	}
	printf("values:");
	for(i=0;i<n;i++)
	{
		printf("%d ",val[i]);
	}
	printf("\n");
	printf("weights:");
	for(i=0;i<n;i++)
	{
		printf("%d ",wt[i]);
	}
	printf("\n");
	printf("enter knapsack capacity:");
	scanf("%d",&w);
   k=ks(wt,val,n,w);
   printf("%d",k);
}
int ks(int wt[],int val[],int n,int w)
{
	int p,q;
	if(n==0||w==0)
	return 0;
	if(wt[n-1]<=w)
	{
		p=val[n-1]+ks(wt,val,n,w-wt[n-1]);
		q=ks(wt,val,n-1,w);
		if(p>=q)
		return p;
		else
		return q;
	}
	
	else
	return ks(wt,val,n-1,w);
}
	
