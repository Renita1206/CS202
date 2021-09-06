//Program to delete alternate nodes

#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
        int data;
        struct node *link;
}Node;


void insert(Node **p, int x);
void delete(Node **p);
void display(Node **p);

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

void delete(Node **p)
{
        Node *pres,*prev;
        pres=*p;
        prev=NULL;
        if(pres==NULL)
                printf("Empty list\n");
        else
        {
                pres=pres->link;
                *p=pres;
                pres=*p;
                int d=0;
                while(pres!=NULL)
                {
                        if(d==1)
                        {
                                prev->link=pres->link;
                                d=0;
                        }
                        else
                                d=1;
                        prev=pres;
                        pres=pres->link;
                }
                printf("\n");
        }
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

int main()
{
        Node *p;
        p=NULL;
        int n,x;
        printf("enter the number of elements: ");
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
                printf("enter the number: ");
                scanf("%d",&x);
                insert(&p,x);
        }
        display(&p);
        delete(&p);
        display(&p);
        return 0;
}
