#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int lcs(char s1[],char s2[],int m,int n);
int dp[100][100];
void main()
{
	char s1[100],s2[100];
	int i,j;
	printf("enter string:");
	scanf("%s",s1);
	printf("enter string:");
	scanf("%s",s2);
	int m=strlen(s1);
	int n=strlen(s2);
	for(i=0;i<=m;i++)
	{
		for(j=0;j<=n;j++)
		{
			dp[i][j]=0;
		}
	}
	printf("%d",lcs(s1,s2,m,n));
}
int max(int a,int b)
{
	return (a>b)?a:b;
}
int lcs(char s1[],char s2[],int m,int n)
{
	if(m==0||n==0)
	return dp[m][n]=0;
	if(s1[m-1]==s2[n-1])
	return dp[m][n]=1+lcs(s1,s2,m-1,n-1);
	else
	return dp[m][n]=max(lcs(s1,s2,m-1,n),lcs(s1,s2,m,n-1));
}