#include<stdio.h>
#include<stdlib.h>
void swap(int *a,int *b);
void heapsort(int a[],int n);
void heapify(int a[],int i,int n);
void main()
{
	int n;
	printf("enter size of array:");
	scanf("%d",&n);
	int a[n],i;
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("unsorted array is:\n");
	printarray(a,n);
	heapsort(a,n);
	printf("sorted array:\n");
	printarray(a,n);
}
void printarray(int a[],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
	printf("\n");
}
void heapsort(int a[],int n)
{
	int i;
	for(i=n/2-1;i>=0;i--)
		heapify(a,i,n);
	for(i=n-1;i>=0;i--)
	{
		swap(&a[0],&a[i]);
		heapify(a,0,i);
	}
}
void heapify(int a[],int i,int n)
{
	int left=2*i+1;
	int right=2*i+2;
	int largest=i;
	if(a[left]>a[largest] && left<n)
	largest=left;
	if(a[right]>a[largest] && right<n)
	largest=right;
	if(i!=largest)
	{
		swap(&a[largest],&a[i]);
		heapify(a,largest,n);
	}
}
void swap(int *a,int *b)
{
	int t;
	t=*a;
	*a=*b;
	*b=t;
}

	
