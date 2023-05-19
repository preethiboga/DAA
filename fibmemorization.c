#include<stdio.h>
int a[100];
void main()
{
	int n,i;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		a[i]=-1;
	}
	printf("%d",fib(n-1));
	
}
int fib(int n)
{
	if(n==0||n==1)
	return a[n]=n;
	if(a[n]!=-1)
	return a[n];
	else
	return a[n]=fib(n-1)+fib(n-2);	
}
