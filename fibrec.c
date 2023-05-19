#include<stdio.h>
void main()
{
	int n,i;
	printf("enter n:");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("%d",fib(i));
	}
	printf("\n%d",fib(n-1));
	
}
int fib(int n)
{
	
	if(n<=1)
	return n;
	else
	return fib(n-1)+fib(n-2);
}
