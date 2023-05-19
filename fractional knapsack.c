#include<stdio.h>
#include<stdlib.h>
float fracks(float wt[],float val[],float w,int n);
void swap(float*a,float*b);
void print(int n,float val[],float wt[]);
void main()
{
	int n;
	printf("enter no.of items:");
	scanf("%d",&n);
	float val[n],wt[n],w;
	int i,j;
	printf("enter val array:");
	for(i=0;i<n;i++)
	{
		scanf("%f",&val[i]);
	}
	printf("enter weight array:");
	for(i=0;i<n;i++)
	{
	   scanf("%f",&wt[i]);
    }
    printf("enter capacity:");
    scanf("%f",&w);
    print(n,val,wt);
    for(i=0;i<n;i++)
    {
    	for(j=0;j<n-i-1;j++)
    	{
    		if((val[j+1]/wt[j+1])>=(val[j]/wt[j]))
    		{
    			swap(&val[j],&val[j+1]);
    			swap(&wt[j],&wt[j+1]);
			}
		}
	}
	printf("after sorted:");
	print(n,val,wt);
    printf("%f",fracks(wt,val,w,n));
}
float fracks(float wt[],float val[],float w,int n)
{
	int i;
	float sum=0;
	for(i=0;i<n;i++)
	{
		if(w>=wt[i])
		{
			sum=sum+val[i];
			w=w-wt[i];
		}
		else
		{
			sum=sum+((w*val[i])/wt[i]);
			break;
		}
	}
	return sum;
}
void swap(float*a,float*b)
{
	float t;
	t=*a;
	*a=*b;
	*b=t;
}
void print(int n,float val[],float wt[])
{
	int i;
	printf("val  wt\n");
	for(i=0;i<n;i++)
	{
		printf("%f %f\n",val[i],wt[i]);
	}
	printf("\n");
}