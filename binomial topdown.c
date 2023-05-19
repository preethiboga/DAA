#include<stdio.h>
int a[100][100];
void main()
{
	int n,k,i,j;
	printf("enter n:");
	scanf("%d",&n);
	printf("enter k:");
	scanf("%d",&k);
	for(i=0;i<=n;i++)
	{
		for(j=0;j<=k;j++)
		{
			a[i][j]=-1;
		}
	}
	printf("%d",bin(n,k));
}
int bin(int n,int k)
{
	int i,j;
	for(i=0;i<=n;i++)
	{
		for(j=0;j<=i;j++)
		{
			if(j==0||j==i)
			a[i][j]=1;
			else
			a[i][j]=a[i-1][j-1]+a[i-1][j];
		}
	}
	return a[n][k];
}
