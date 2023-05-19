#include<stdio.h>
#include<math.h>
int b[10]={-1};
int n;
char matrix[50][50];
int abst(int a,int b);
void nqueens(int row);
int isfeasible(int row,int col);
void print();
void mat();
void printmatrix();
int main()
{
	printf("enter n:");
	scanf("%d",&n);
	int i,j;
	matrix[n][n];
	for(i=0;i<n;i++)
	{
		b[i]=-1;
	}
	
	nqueens(0);
}
void nqueens(int row)
{
	int col;
	for(col=0;col<n;col++)
	{
		if(isfeasible(row,col))
		{
			b[row]=col;
			if(row==n-1)
			{
				print();
				mat();
				return;
			}
			nqueens(row+1);
		}
	}
	return;
}
int isfeasible(int row,int col)
{
	int i;
	for(i=0;i<row;i++)
	{
		if((b[i]==col)||((abst(row,i))==(abst(b[i],col))))
		return 0;
	}
	return 1;
}
void print()
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("%d ",b[i]);
	}
	printf("\n");
}
int abst(int a,int b)
{
	int c;
	if(a>b)
	{
		c=a-b;
	}
	else
	{
		c=b-a;
	}
	return c;
}
void mat()
{
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
		   matrix[i][j]='-';	
		}
	}
	for(i=0;i<n;i++)
	{
		matrix[i][b[i]]='Q';
	}
	printmatrix();
}
void printmatrix()
{
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%c ",matrix[i][j]);
		}
		printf("\n");
	}
}
