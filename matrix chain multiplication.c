#include<stdio.h>
#include<stdlib.h>
int mco(int a[],int i,int j);
int main()
{
	int n;
	printf("enter n:");
	scanf("%d",&n);
	int a[n],i;
	printf("enter array:");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("%d ", mco(a,1,n-1));
}
int mco(int a[],int i,int j)
{
	if(i==j)
	return 0;
	int k,count;
	int min=INT_MAX;
	for(k=i;k<j;k++)
	{
		count=mco(a,i,k)+mco(a,k+1,j)+(a[i-1]*a[k]*a[j]);
		if(count<min)
		min=count;
	}
	return min;
}
