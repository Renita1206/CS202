/*
Implement a program to maintain doctor's appointment list using a queue.
The appointment list should have details like patients name, date and time of appointment.
The request should be served based on appointment slots.
The appointment will be issued on daily basis.
Display appropriate messages.
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node
{
	char name[50];
	int time;
	char date[10];
	struct node *next;
};

void display(struct node *f, struct node *r);
void insert_rear(char*, struct node**f, struct node **r);
void delete_front(struct node **f,struct node **r);

int main()
{
	struct node *f,*r;
	f=r=NULL;
	int ch,x,k;
    char name[50]; char* date;
	while(1)
	{
		display(f,r);
		printf("\n1: Book Appointment \n2: Clear Appointments\n");
		printf("enter your choice\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: printf("enter the name\n");
				scanf("%s",name);
				insert_rear(name,&f,&r);
				break;
			case 2:delete_front(&f,&r);
				break;

			default:exit(0);
		}
	}
}

void delete_front(struct node **f,struct node **r)
{
	struct node *q;
	char* x;
	q=*f;
	if(*f==NULL)
	{
		printf("No booked appointments\n");
		return;
	}
	if(*f==*r)
	{
		*f=*r=NULL;
	}
	else
	{
		(*f)=q->next;
		free(q);
	}
}	

void insert_rear(char* x, struct node**f, struct node **r)
{
	struct node *temp;
	temp=(struct node*)malloc(sizeof(struct node));
	strcpy(temp->name, x);
	temp->next=NULL;
	if(*f==NULL)
		{*f=*r=temp;
		 temp->time=8;}
	if((*r)->time==16)
	{
		printf("Appointments full...Sorry");
		return;
	}
	else
	{
		temp->time = (*r)->time + 1;
		(*r)->next=temp;
		(*r) = temp;
	}
}

void display(struct node *f, struct node *r)
{
	if(f==NULL)
		{
			printf("No booked appointments\n");
	
		}
	else
	{
		while(f!=r)
		{
			printf("%d:00 Hrs:%s\n",f->time,f->name);
				f=f->next;
		}
		printf("%d:00 Hrs:%s\n",f->time,f->name);
	}
}
