//Program to swap nodes

#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
        int data;
        struct node *link;
}Node;


void insert(Node **p, int x);
void display(Node **p);
void swap(Node **p,int, int);

void display(Node **p)
{
    printf("\nLinked List\n");
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

void insert(Node **p, int x)
{
    Node *tmp,*prev;
    tmp=(Node*)malloc(sizeof(Node));
    tmp->data=x;
    tmp->link=NULL;
    prev=*p;
    if(*p==NULL)    //no nodes present in list
    {
        *p=tmp;
    }
    else
    {
        while(prev->link!=NULL)
        {
            prev=prev->link;
        }
        prev->link=tmp;
    }
}

void swap(Node **p, int x, int y)
{
    Node *prevx=NULL, *tmpx, *tmpy, *prevy=NULL;
    tmpx=*p;
    tmpy=*p;
    int f1=0, f2=0;
    if(x==y)
        return;
    while(tmpx!=NULL)
    {
        if(tmpx->data==x)
        {
            f1=1;
            break;
        }
        prevx=tmpx;
        tmpx=tmpx->link;
    }
    while(tmpy!=NULL)
    {
        if(tmpy->data==y)
        {
            f2=1;
            break;
        }
        prevy=tmpy;
        tmpy=tmpy->link;
    }
    if(f1==1 && f2==1)
    {
        if(prevx!=NULL) // x is not head node
            prevx->link=tmpy;
        else // x is head node
            *p=tmpy;

        if(prevy!=NULL) //y is not head node
            prevy->link=tmpx;
        else    // y is head node
            *p=tmpx;

        Node *tmp;
        tmp=tmpx->link;
        tmpx->link=tmpy->link;
        tmpy->link=tmp;
    }
    else
        printf("\nInvalid elements");

}

int main()
{
        Node *p;
        p=NULL;
        int n,x,p1,p2;
        printf("enter the number of elements: ");
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
                printf("enter the number: ");
                scanf("%d",&x);
                insert(&p,x);
        }
        display(&p);
        printf("\n Enter the elements to be swapped: ");
        scanf("%d %d",&p1, &p2);
        swap(&p,p1,p2);
        display(&p);
        return 0;
}
