#include<stdio.h>
void swap(int *a,int *b)
{
	int t=*a;
	*a=*b;
	*b=t;
}
void heapify(int a[],int i,int n)
{
	int min=i;
	int l=2*i+1;
	int r=2*i+2;
	if(a[l]<a[min] && l<n)
	min=l;
	if(a[r]<a[min] && r<n)
	min=r;
	if(min!=i)
	{
		swap(&a[min],&a[i]);
		heapify(a,min,n);
	}
}
int heapsort(int a[],int n)
{
	int i,sum=0,v=0,add=0;
	for(i=n/2-1;i>=0;i--)
	heapify(a,i,n);
	for(i=n-1;i>=0;i--)
	{
		sum=sum+a[0];
		a[0]=a[i];
		v++;
		if(v==2)
		{
		   add=add+sum;
		   a[i]=sum;
		   v=0;
		   sum=0;
		   i++;
		   heapify(a,0,i);
		}
		else
		heapify(a,0,i);
	}
	return add;
	
}
void main()
{
	int n;
	printf("enter n:");
	scanf("%d",&n);
	int a[n],i;
	printf("enter array:");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	int k=heapsort(a,n);
	printf("%d",k);
}