#include<stdio.h>
int a[100];
void main()
{
	int n,i;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		a[i]=-1;
	}
	printf("%d",fib(n)); //based on index of array
}
int fib(int n)
{
	int i;
	a[0]=0;
	a[1]=1;
	for(i=2;i<n;i++)
	{
		a[i]=a[i-1]+a[i-2];	
	}
	return a[n-1];
}
