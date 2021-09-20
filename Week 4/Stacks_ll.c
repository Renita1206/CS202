//Stacks implemented by linked list

#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
}Node;

void push(Node **p, int x);
void pop(Node **p);
void display(Node *p);

void push(Node **p, int x)
{
    Node *tmp;
    tmp=(Node*)malloc(sizeof(Node));
    tmp->data=x;
    tmp->next=*p;
    *p=tmp;
    printf("Pushing element %d\n",tmp->data);
}

void pop(Node **p)
{
    if(*p==NULL)
        printf("Stack Underflow\n");
    else
    {
        Node *tmp;
        tmp=*p;
        *p=tmp->next;
        printf("Popping element %d\n",tmp->data);
        free(tmp);
    }
}

void display(Node *p)
{
    if(p==NULL)
        printf("Stack Underflow\n");
    else
    {
        while(p!=NULL)
        {
            printf("%d\t",p->data);
            p=p->next;
        }
    }
    printf("\n\n");
}

int main()
{
        Node *p;
        p=(Node*)malloc(sizeof(Node));
        p=NULL;
        int choice,x;
        while(1)
        {   
                printf("1.Push element in stack\n");
                printf("2.Pop element from stack\n");
                scanf("%d",&choice);
                switch(choice)
                {
                        case 1: printf("Enter element: ");
                                scanf("%d",&x);
                                push(&p,x);
                                break;

                        case 2: pop(&p);
                                break;

                        default: exit(0);
                                 break;
                 }
                        
                display(p);
        }
        return 0;
}