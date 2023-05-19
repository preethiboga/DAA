#include<stdio.h>
int a[100][100];
void main()
{
	int n,k,i,j;
	printf("enter n:");
	scanf("%d",&n);
	printf("enter k:");
	scanf("%d",&k);
	for(i=0;i<n;i++)
	{
		for(j=0;i<k;j++)
		{
			a[i][j]=-1;
		}
	}
	printf("%d",bin(n,k));
}
int bin(int n,int k)
{
	if(k==0||k==n)
	return a[n][k]=1;
	else if(a[n][k]!=-1)
	return a[n][k];
	else
	return a[n][k]=a[n-1][k-1]+a[n-1][k];
	
}
