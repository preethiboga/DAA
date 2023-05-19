#include<stdio.h>
#include<math.h>
#include<stdlib.h>
struct point{
	int x;
	int y;
};
struct point a[100];
void main()
{
	int n;
	int indi,indj;
	int min=INT_MAX;
	printf("enter no.of points:");
	scanf("%d",&n);
	printf("enter points:");
	struct point a[n];
	int i,j,k;
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i].x);
		scanf("%d",&a[i].y);
	}
	for(i=0;i<n;i++)
	{
		printf("(%d,%d)\n",a[i].x,a[i].y);
	}
	for(i=0;i<n-1;i++)
	{
		for(j=i+1;j<n;j++)
		{
			k=sqrt(((a[j].x-a[i].x)*(a[j].x-a[i].x))+((a[j].y-a[i].y)*(a[j].y-a[i].y)));	
			if(k<min)
			{
		    	min=k;
		    	indi=i;
		    	indj=j;
		    }
		}
	}
	printf("closest dist:%d\n",min);
	printf("points are ((%d,%d),(%d,%d))",a[indi].x,a[indi].y,a[indj].x,a[indj].y);
}
