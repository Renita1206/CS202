//program to concatenate two lists

#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *link;
}Node;

void insert(Node **p, int x);
void display(Node **p);
void concatenate(Node **p1, Node **p2);

void insert(Node **p,int x)
{
    Node *tmp;
    tmp=(Node*)malloc(sizeof(Node));
    tmp->data=x;
    tmp->link=NULL;
    if(*p==NULL)    //no nodes present in list
    {
        *p=tmp;
    }
    else
    {
        tmp->link=*p;
        *p=tmp;
    }
}

void display(Node **p)
{
    Node *tmp;
    tmp=(Node*)malloc(sizeof(Node));
    tmp=*p;
    if(*p==NULL)
        printf("Empty list\n");
    else
    {
        while(tmp!=NULL)
        {
            printf("%d\t",tmp->data);
            tmp=tmp->link;
        }
        printf("\n");
    }
    printf("\n");
}

void concatenate(Node **p1, Node **p2)
{
    if(*p2==NULL) //second list is empty (no change required)
        return;
    else if(*p1==NULL) //first list is empty
    {
        *p1=*p2;
    }
    else
    {
        Node *tmp;
        tmp=(Node*)malloc(sizeof(Node));
        tmp=*p1;
        while(tmp->link!=NULL)
        {
            tmp=tmp->link;
        }
        tmp->link=*p2;
    }
}

int main()
{
        Node *p1,*p2;
        p1=NULL;
        p2=NULL;
        int n,x;
        printf("enter the number of elements for list 1: ");
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
                printf("enter the number: ");
                scanf("%d",&x);
                insert(&p1,x);
        }
        printf("\n Linked List 1:\n");
        display(&p1);
        printf("enter the number of elements for list 2: ");
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
                printf("enter the number: ");
                scanf("%d",&x);
                insert(&p2,x);
        }
        printf("\nLinked List 2:\n");
        display(&p2);
        concatenate(&p1,&p2);
        printf("\nLinked List after concatenating:\n");
        display(&p1);
        return 0;
}