#include<stdio.h>
void main()
{
	int n,k;
	printf("enter n:");
	scanf("%d",&n);
	printf("enter k:");
	scanf("%d",&k);
	printf("%d",bin(n,k));
}
int bin(int n,int k)
{
	if(k==0||k==n)
	return 1;
	else
	return bin(n-1,k-1)+bin(n-1,k);
}
