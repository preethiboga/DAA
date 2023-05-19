#include<stdio.h>
#include<stdlib.h>
int s[20],d[20],w[20],n,e,parent[20];
void print();
void kruskal();
void swap(int*a,int*b);
int findparent(int i);
void main()
{
	printf("enter no.of vertices:");
	scanf("%d",&n);
	printf("enter no.of edges:");
	scanf("%d",&e);
	int i,j;
	for(i=0;i<n;i++)
	{
		parent[i]=-1;
	}
	for(i=0;i<e;i++)
	{
		printf("enter start vertex:");
		scanf("%d",&s[i]);
		printf("enter destination vertex:");
		scanf("%d",&d[i]);
		printf("enter weight:");
		scanf("%d",&w[i]);
		
	}
	print();
	for(i=0;i<e;i++)
	{
		for(j=0;j<e-i-1;j++)
		{
			if(w[j+1]<w[j])
			{
				swap(&s[j+1],&s[j]);
				swap(&d[j+1],&d[j]);
				swap(&w[j+1],&w[j]);
			}
		}
	}
	printf("after sorted:\n");
	print();
	kruskal();
}
void print()
{
	printf("s d w\n");
	int i;
	for(i=0;i<e;i++)
	{
		printf("%d %d %d\n",s[i],d[i],w[i]);
	}
	printf("\n");
}
void swap(int*a,int*b)
{
	int t;
	t=*a;
	*a=*b;
	*b=t;
}
void kruskal()
{
	int sum=0,i;
	printf("s d w\n");
	for(i=0;i<e;i++)
	{
		int l=findparent(s[i]);
		int k=findparent(d[i]);
		if(l!=k)
		{
			parent[k]=l;
			printf("%d %d %d\n",s[i],d[i],w[i]);
			sum=sum+w[i];
		}
	}
	printf("minimum weight=%d\n",sum);
}
int findparent(int i)
{
	while(parent[i]!=-1)
	{
		i=parent[i];
	}
	return i;
}
