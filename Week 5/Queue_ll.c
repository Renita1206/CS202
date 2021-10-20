// Queue using a List
#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};

void display(struct node *f, struct node *r);
void insert_rear(int x, struct node**f, struct node **r);
int delete_front(struct node **f,struct node **r);
int main()
{
	struct node *f,*r;
	f=r=NULL;
	int ch,x,k;
	while(1)
	{
		display(f,r);
		printf("\n1; Insert rear\n2: Delete front\n");
		printf("enter your choice\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: printf("enter the value of x\n");
				scanf("%d",&x);
				insert_rear(x,&f,&r);
				break;
			case 2: k=delete_front(&f,&r);
				break;
		}
	}
}
int delete_front(struct node **f,struct node **r)
{
	struct node *q;
	int x;
	q=*f;
	
	if(*f==NULL)
		{
		printf("List is empty\n");
		return -1;
		}
	x=q->data;
	if(*f==*r)
		{
		*f=*r=NULL;
		}
	else
		{
		(*f)=q->next;
		}
		free(q);
	return x;
}	









void insert_rear(int x, struct node**f, struct node **r)
{
	struct node *temp;
	temp=(struct node*)malloc(sizeof(struct node));
	temp->data=x;
	temp->next=NULL;
	if(*f==NULL)
		*f=*r=temp;
	else
	{
		(*r)->next=temp;
		(*r) = temp;
	}
}

void display(struct node *f, struct node *r)
{
	if(f==NULL)
		{
			printf("List is empty\n");
	
		}
	else
	{
		while(f!=r)
		{
			printf("%d-",f->data);
				f=f->next;

		}
		printf("%d-",f->data);
	}
}
