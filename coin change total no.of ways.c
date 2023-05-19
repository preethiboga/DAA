#include<stdio.h>
int cc(int wt[],int s,int n);
void main()
{
	int n;
	printf("enter no.of coins:");
	scanf("%d",&n);
	int wt[n];
	printf("enter coins:");
	int i;
	for(i=0;i<n;i++)
	{
		scanf("%d",&wt[i]);
	}
	int s;
	printf("enter sum:");
	scanf("%d",&s);
	printf("total no.of ways=%d",cc(wt,s,n));
}
int cc(int wt[],int s,int n)
{
  if(n==0)
  return 0;
  if(s==0)
  return 1;	
  if(wt[n-1]<=s)
  return (cc(wt,s-wt[n-1],n)+cc(wt,s,n-1));
  else
  return cc(wt,s,n-1);
}
