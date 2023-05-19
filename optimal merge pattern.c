#include<stdio.h>
#define MAX 100
int stack[MAX];
int top=-1;
void bubble(int a[],int n)
{
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(a[j]<a[j+1])
			{
				int t=a[j];
				a[j]=a[j+1];
				a[j+1]=t;
			}
		}
	}
}
void push(int n)
{
	if(top>=MAX-1)
	{
		printf("overflow\n");
		return;
	}
	else
	stack[++top]=n;
}
int pop()
{
	if(top<0)
	{
		printf("underflow\n");
		return;
	}
	else
	return stack[top--];
}

int omp(int a[],int n)
{
	int i,x,y,c,s=0;
	for(i=0;i<n;i++)
	push(a[i]);
	
	while(top!=0)
	{
		x=pop();
		y=pop();
		c=x+y;
		s=s+c;
		push(c);
		bubble(stack,top+1);
	}
	return s;
}
int main()
{
	int n,i,val;
	printf("enter size of array:");
	scanf("%d",&n);
	int a[n];
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	bubble(a,n);
	val=omp(a,n);
	printf("value is :%d\n",val);
	return 0;
}