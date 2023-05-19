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
	int i,j;
	for(i=1;i<=m;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(i==0||j==0)
            	 dp[i][j]=0;
        	else if(s1[i-1]==s2[j-1])
             	dp[i][j]=1+dp[i-1][j-1];
        	else
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
		}
	}
	return dp[m][n];
	
}