#include<stdio.h>
#include<stdlib.h>
struct node{
	int coeff;
	int expo;
	struct node *next;
};
void print(struct node *head);
struct node *insert(struct node *head,int coeff,int expo);
struct node *create(struct node *head);
struct node *polyadd(struct node *head1,struct node *head2);
int main()
{
	struct node *head1=NULL,*head2=NULL,*head3=NULL;
	printf("enter 1st polynomial:\n");
	head1=create(head1);
	print(head1);
	printf("enter 2nd polynomial:\n");
	head2=create(head2);
	print(head2);
	head3=polyadd(head1,head2);
	print(head3);
}
void print(struct node *head)
{
	struct node *t;
	t=head;
	while(t!=NULL)
	{
		printf("%d x^%d+",t->coeff,t->expo);
		t=t->next;
    }
    printf("\n");
}
struct node *insert(struct node *head,int coef,int ex)
{
	struct node *nn,*temp;
	nn=(struct node*)malloc(sizeof(struct node));
	nn->coeff=coef;
	nn->expo=ex;
	nn->next=NULL;
	if(head==NULL || head->expo<nn->expo)
	{
		nn->next=head;
		head=nn;
	}
	else
	{
		temp=head;
		while(temp->next!=NULL && temp->next->expo>=ex)
		{
			temp=temp->next;
		}
		nn->next=temp->next;
		temp->next=nn;
	}
	return head;
}
struct node *create(struct node *head)
{
	int n,i,coeff,expo;
	printf("enter no.of terms:");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("enter coeff:");
		scanf("%d",&coeff);
		printf("enter expo:");
		scanf("%d",&expo);
		head=insert(head,coeff,expo);
	}
	return head;
	
}
struct node *polyadd(struct node *head1,struct node *head2)
{
	struct node *t1,*t2,*head3;
	t1=head1;
	t2=head2;
	head3=NULL;
	while(t1!=NULL && t2!=NULL)
	{
		if(t1->expo==t2->expo)
		{
		   head3=insert(head3,t1->coeff+t2->coeff,t1->expo);
		   t1=t1->next;
		   t2=t2->next;
	    }
	    else if(t1->expo>t2->expo)
	    {
	    	head3=insert(head3,t1->coeff,t1->expo);
	    	t1=t1->next;
		}
		else
		{
			head3=insert(head3,t2->coeff,t2->expo);
			t2=t2->next;
		}
	}
	while(t1!=NULL)
	{
		head3=insert(head3,t1->coeff,t1->expo);
	    	t1=t1->next;
	}
	while(t2!=NULL)
	{
		head3=insert(head3,t2->coeff,t2->expo);
		t2=t2->next;
		
	}
	return head3;
	
}
