#include<stdlib.h>
#include<stdio.h>
#include<math.h>
void main()
{
	int n,i,j,k,min=INT_MAX,ind1,ind2;
	printf("enter no.of points:");
	scanf("%d",&n);
	int x[n],y[n];
	for(i=0;i<n;i++)
	{
		printf("enter x :");
		scanf("%d",&x[i]);
		printf("enter y:");
		scanf("%d",&y[i]);
	}
	for(i=0;i<n;i++)
	{
		printf("(%d,%d),",x[i],y[i]);
	}
	for(i=0;i<n-1;i++)
	{
		for(j=i+1;j<n;j++)
		{
			k=sqrt(((x[j]-x[i])*(x[j]-x[i]))+((y[j]-y[i])*(y[j]-y[i])));
			if(k<min)
			{
				min=k;
				ind1=i;
				ind2=j;
			}
		}
	}
	printf("\nclosest dist=%d\n",min);
	printf("closest pair=((%d,%d),(%d,%d))",x[ind1],y[ind1],x[ind2],y[ind2]);
	
}
