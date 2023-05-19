#include<stdio.h>
#include<stdlib.h>
int lics(int a[],int n);
int l[100];
int max(int n);
int main()
{
	int n;
	printf("enter n:");
	scanf("%d",&n);
	int a[n];
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
		l[i]=1;
	}
	printf("%d ",lics(a,n));
}
int lics(int a[],int n)
{
	int i,j;
	for(i=1;i<n;i++)
	{
		for(j=0;j<i;j++)
		{
			if(a[i]>a[j] && l[i]<=l[j])
			l[i]=l[j]+1;
		}
	}
	int m=max(n);
	return m;
}
int max(int n)
{
	int m=l[0];
	int i;
	for(i=1;i<n;i++)
	{
		if(l[i]>m)
		m=l[i];
	}
	return m;
}