#include<stdio.h>
#include<string.h>
void main()
{
	int flag=-1,i,j;
	char s[1000],sub[1000];
	printf("enter string:");
	gets(s);
	printf("enter substring:");
	gets(sub);
	int l1=strlen(s);
	int l2=strlen(sub);
	for(i=0;i<l1-l2;i++)
	{
		for(j=i;j<i+l2;j++)
		{
			if(s[j]!=sub[j-i])
			break;
		}
	  if(j==i+l2)
	  {
		flag=i;
		break;
	  }
	}
	if(flag==-1)
	printf("not found");
	else
	{
		printf("string found at index=%d",flag);
	}
	
}
