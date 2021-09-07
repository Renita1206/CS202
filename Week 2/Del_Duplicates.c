// Program to delete duplicate nodes in a unsorted linked list

#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
}Node;

void insert(Node **p, int x);
void display(Node **p);
void del(Node **p);

void insert(Node **p, int x)
{
    Node *tmp, *pres;
    tmp=(Node*)malloc(sizeof(Node));
    tmp->data=x;
    tmp->next=NULL;
    pres=*p;
    if(pres==NULL)
    {
        *p=tmp;
    }
    else
    {
        while(pres->next!=NULL)
        {
            pres=pres->next;
        }
        pres->next=tmp;
    }
}

void display(Node **p)
{
    Node *tmp;
    tmp=*p;
    if(*p==NULL)
    {
        printf("Empty list\n");
    }
    else
    {
        while(tmp!=NULL)
        {
            printf("%d\t",tmp->data);
            tmp=tmp->next;
        }
    }
    printf("\n");
}

void del(Node **p)
{
    // yet to implement
}

int main()
{
    Node *p;
    p=NULL;
    int n,x;
    printf("\nEnter the number of elements in the list: ");
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        printf("Enter the elements: ");
        scanf("%d",&x);
        insert(&p,x);
    }
    printf("\nLinked list before deleting duplicates: \n");
    display(&p);
    //del(&p);
    printf("\nLinked list after deleting duplicates: \n");
    display(&p);
    return 0;
}