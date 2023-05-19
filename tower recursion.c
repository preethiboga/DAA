#include<stdio.h>
void towers(int n,char s,char d,char a);
void main()
{
	int n;
	char s,a,d;
	printf("enter no.of disks:");
	scanf("%d",&n);
	towers(n,'s','d','a');
} 
void towers(int n,char s,char d,char a)
{
	if(n==0)
	return;
	else
	{
	towers(n-1,s,a,d);
    printf("shift %c->%c\n",s,d);
	towers(n-1,a,d,s);
   }
}

