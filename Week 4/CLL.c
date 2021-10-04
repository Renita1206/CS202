// Circular linked list without head node

#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
}Node;

void front_insert(Node **p, int x);
void end_insert(Node **p, int x);
void end_del(Node **p);
void front_del(Node **p);
void display(Node *p);

void front_insert(Node **p, int x)
{
    Node *tmp;
    tmp=(Node*)malloc(sizeof(Node));
    tmp->data=x;
    tmp->next=tmp;
    if((*p)==NULL) //empty list
    {
        *p=tmp;
    }
    else
    {
        tmp->next = (*p)->next;
        (*p)->next=tmp;
    }
}

void end_insert(Node **p, int x)
{
    Node *tmp;
    tmp=(Node*)malloc(sizeof(Node));
    tmp->data=x;
    tmp->next=tmp;
    if((*p)==NULL) //empty list
    {
        *p=tmp;
    }
    else
    {
        tmp->next=(*p)->next;
        (*p)->next=tmp;
        *p=tmp;
    }
}

void end_del(Node **p)
{
    Node *tmp;
    if((*p)==NULL)
        printf("Empty List");
    else
    {
        tmp=(*p)->next;
        if((*p)==tmp)
        {
            *p=NULL;
            return;
        }
        while((tmp->next)!=(*p))
        {
            tmp=tmp->next;
        }
        tmp->next=tmp->next->next;
        *p=tmp;
    }
}

void front_del(Node **p)
{
    Node *tmp;
    if((*p)==NULL)
        printf("Empty List");
    else
    {
        tmp=(*p)->next;
        if((tmp)==(tmp->next))
        {
            (*p)=NULL;
            return;
        }
        (*p)->next=tmp->next;
        free(tmp);
    }
}

void display(Node *p)
{
    Node *tmp;
    if(p==NULL)
    {
        printf("Empty List");
        return;
    }
    tmp=p->next;
    while(tmp!=p)
    {
        printf("%d\t",tmp->data);
        tmp=tmp->next;
    }
    printf("%d\t",tmp->data);
}

void main()
{
    Node *p = NULL;
    int choice;
    int x,pos;

    while(1)
    {
        printf("Enter a choice: \n");
        printf("1.Insert node at the beginning of list\n");
        printf("2.Insert node at the end of the list\n");
        printf("3.Delete first node\n");
        printf("4.Delete the last node\n");
        printf("5.Exit\n");

        scanf("%d",&choice);

        switch(choice)
        {
            case 1: //Inserting node at the beginnning of the list
                    printf("\nEnter the value to store: ");
                    scanf("%d",&x);
                    front_insert(&p,x);
                    break;
            
            case 2: //Inserting node at the end of the list
                    printf("\nEnter the value to store: ");
                    scanf("%d",&x);
                    end_insert(&p,x);
                    break;
            
            case 3: //Deleting first node
                    front_del(&p);
                    break;
            
            case 4: //Deleting last node
                    end_del(&p);
                    break;

            case 5: //exiting program
                    exit(0);
                    break;

            default: printf("\nInvalid entry");
        }

        display(p);
        printf("\n\n");

    }
}
