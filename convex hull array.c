#include<stdlib.h>
#include<stdio.h>
#include<math.h>
void main()
{
	int n,i,j,k,a,b,c,nn,np,l;
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
			a=y[i]-y[j];
			b=x[j]-x[i];
			c=(y[j]*x[i])-(x[j]*y[i]);
			np=0,nn=0;
			for(k=0;k<n;k++)
			{
				if(k!=i && k!=j)
				{
					l=(a*x[k])+(b*y[k])+c;
					if(l>0)
					np++;
					else if(l<0) 
					nn++;
				}
			}
			if(np==0||nn==0)
			{
				printf("(%d,%d),(%d,%d)\n",x[i],y[i],x[j],y[j]);
			}
			
		}
   }
}
