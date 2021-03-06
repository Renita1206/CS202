// Program to implement doubly linked lists

#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
    struct node *prev;
}Node;

void front_insert(Node **p, int x);
void back_insert(Node **p, int x);
void pos_insert(Node **p, int x, int pos);
void front_delete(Node **p);
void back_delete(Node **p);
void pos_delete(Node **p, int pos);
void display(Node **p);
void reverse(Node **p);

void front_insert(Node **p, int x)
{
    Node *tmp;
    tmp=(Node*)malloc(sizeof(Node));
    tmp->data=x;
    tmp->next=NULL;
    tmp->prev=NULL;
    if(*p==NULL) //Empty list
    {
        *p=tmp;
    }
    else
    {
        tmp->next=*p;
        tmp->next->prev=tmp;
        *p=tmp;
    }
}

void back_insert(Node **p, int x)
{
    Node *tmp, *pres;
    pres=*p;
    tmp=(Node*)malloc(sizeof(Node));
    tmp->data=x;
    tmp->next=NULL;
    tmp->prev=NULL;
    if(*p==NULL)
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
        tmp->prev=pres;
    }
}

void pos_insert(Node **p, int x, int pos) // Incomplete Function
{
    Node *tmp, *pres;
    pres=*p;
    tmp=(Node*)malloc(sizeof(Node));
    tmp->data=x;
    tmp->next=NULL;
    tmp->prev=NULL;
    int i=1;
    while(pres!=NULL && pos>i)
    {
        pres=pres->next;
        i=i+1;
    }
    if(pres==NULL)
    {
        if(pos==1) //empty
            *p=tmp;
        else  if(pos==i)      //last
        {
            pres=*p;
            while(pres->next!=NULL)
            {
                pres=pres->next;
            }
            pres->next=tmp;
            tmp->prev=pres;
        }
        else 
        {
            printf("Invalid");
        }
    }
    else if(pos==i)
    {
        if(pres->prev==NULL) //first
        {
            tmp->next=pres;
            pres->prev=tmp;
            *p=tmp;
        }
        else //middle
        {
            pres->prev->next=tmp;
            tmp->prev=pres->prev;
            tmp->next=pres;
            pres->prev=tmp;
        }
    }
}

void front_delete(Node **p)
{
    Node *pres;
    pres=*p;
    if(*p==NULL) //Empty list
        printf("Empty list\n");
    else if(pres->next==NULL) // Only one node
    {
        printf("\nDeleting element - %d\n",pres->data);
        *p=NULL;
        free(pres);
    }
    else
    {
        printf("\nDeleting element - %d\n",pres->data);
        Node *tmp;
        tmp=pres;
        pres=pres->next;
        pres->prev=NULL;
        *p=pres;
        free(tmp);
    }
}

void back_delete(Node **p)
{
    Node *pres;
    pres=*p;
    if(*p==NULL) //Empty list
        printf("Empty list\n");
    else if(pres->next==NULL) // only one node
    {
        printf("\nDeleting element - %d\n",pres->data);
        *p=NULL;
        free(pres);
    }
    else
    {
        printf("\nDeleting element - %d\n",pres->data);
        while(pres->next!=NULL)
        {
            pres=pres->next;
        }
        pres->prev->next=NULL;
        free(pres);
    }
}


void pos_delete(Node **p, int pos) //Cases-> empty, front, middle, end
{
    Node *pres;
    pres=*p;
    int i=1;
    if(*p==NULL)
    {
        printf("Empty List\n");
        return;
    }
    while(pres!=NULL && pos>i)
    {
        pres=pres->next;
        i++;
    }
    if(pos==i)
    {
        printf("Deleting element %d\n",pres->data);
        if(pos==1) //first node or pres->prev==NULL
        {
            *p=pres->next;
            if(pres->next!=NULL)
                pres->next->prev=NULL;
            free(pres);
        }
        else if(pres->next==NULL)
        {
            pres->prev->next=NULL;
            free(pres); 
        }
        else //middle
        {
            pres->next->prev=pres->prev;
            pres->prev->next=pres->next;
            free(pres);
        }
    }
    else if(pres==NULL)
    {
        printf("Invalid Position\n");
    }
}

void display(Node **p)
{
    Node *t;
    t=*p;
    printf("\nLinked List\n");
    if(t==NULL)
        printf("Empty List");
    while(t!=NULL)
    {
        printf("%d\t",t->data);
        t=t->next;
    }
    printf("\n");
}

void reverse(Node **p)
{
    Node *t;
    t=*p;
    printf("\nReverse Linked List\n");
    if(t==NULL)
        printf("Empty List");
    while(t->next!=NULL)
    {
        t=t->next;
    }
    while(t!=NULL)
    {
        printf("%d\t",t->data);
        t=t->prev;
    }
    printf("\n");
}

int main()
{
    Node *p=NULL;
    int choice;
    int x,pos;

    while(1)
    {
        printf("Enter a choice: \n");
        printf("1.Insert node at the beginning of list\n");
        printf("2.Insert node at the end of the list\n");
        printf("3.Delete first node\n");
        printf("4.Delete the last node\n");
        printf("5.Insert node at given position\n");
        printf("6.Delete node at given position\n");
        printf("7.Reverse the list\n");
        printf("8.Exit\n");

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
                    back_insert(&p,x);
                    break;
            
            case 3: //Deleting first node
                    front_delete(&p);
                    break;
            
            case 4: //Deleting last node
                    back_delete(&p);
                    break;

            case 5: // Inserting node at given position
                    printf("\nEnter the value to store: ");
                    scanf("%d",&x);
                    printf("\nEnter position at which node must be inserted: ");
                    scanf("%d",&pos);
                    pos_insert(&p,x,pos);
                    break;
            
            case 6: //Deleting node at given position
                    printf("\nEnter position of node to be deleted: ");
                    scanf("%d",&pos);
                    pos_delete(&p,pos);
                    break;
            
            case 7: //Reverse the list
                    reverse(&p);
                    break;

            case 8: //exiting program
                    exit(0);
                    break;

            default: printf("\nInvalid entry");
        }

        display(&p);
        printf("\n\n");

    }
    return 0;
}

