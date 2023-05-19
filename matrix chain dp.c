#include<stdio.h>
#include<stdlib.h>
int m[100][100];
void main()
{
	int n;
	printf("enter n:");
	scanf("%d",&n);
	int a[n],i;
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("%d ",mco(a,n));
	for(i=0;i<n;i++)
	m[i][i]=0;
}
int mco(int a[],int n)
{
	int d,i,k,j,q;
	for(d=1;d<n-1;d++)
	{
		for(i=1;i<n-d;i++)
		{
			j=i+d;
			m[i][j]=INT_MAX;
			for(k=i;k<=j-1;k++)
			{
				q=m[i][k]+m[k+1][j]+a[i-1]*a[k]*a[j];
				if(q<m[i][j])
				m[i][j]=q;
			}
		}
	}
	return m[1][n-1];
	
}