#include<stdio.h>
int ss(int wt[],int w ,int n)
{
	if(w==0)
	return 1;
	if(n==0)
	return 0;
	if(wt[n-1]<=w)
	{
		return ((ss(wt,w-wt[n-1],n-1))||(ss(wt,w,n-1)));
	}
	return(ss(wt,w,n-1));
}
int main()
{
	int n,w,j;
	printf("enter size: ");
	scanf("%d",&n);
	int wt[n];
	printf("enter weight array:");
	int i;
	for(i=0;i<n;i++)
	{
		scanf("%d",&wt[i]);
	}
	printf("enter weight:");
	scanf("%d",&w);
	printf("%d",ss(wt,w,n));
	
}

