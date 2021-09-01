/*
Program implementing linked list
Operations that may be performed - 
    Insert node at the beginning
    Insert node at the end
    Delete first node
    Delete last node
    Insert node at given position
    Delete node at given position
*/

#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *link;
}Node;

void front_insert(Node **p,int x);
void back_insert(Node **p, int x);
void front_delete(Node **p);
void back_delete(Node **p);
void pos_insert(Node **p, int x, int pos);
void pos_delete(Node **p, int pos);
void display(Node **p);

void front_insert(Node **p,int x)
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

void back_insert(Node **p,int x)
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

void front_delete(Node **p)
{
    Node *tmp;
    tmp=(Node*)malloc(sizeof(Node));
    tmp=*p;

    if(*p==NULL)    //no nodes present in list
    {
        printf("Empty list\n");
    }
    else if(tmp->link==NULL)
    {
        printf("\nDeleting element %d \n",tmp->data);
        *p=NULL;
    }
    else
    {
        printf("\nDeleting element %d \n",tmp->data);
        tmp=tmp->link;
        **p=*tmp;
    }
}

void back_delete(Node **p)
{
    Node *tmp,*prev=NULL;
    tmp=(Node*)malloc(sizeof(Node));
    tmp=*p;
    

    if(*p==NULL)    //no nodes present in list
    {
        printf("Empty list\n");
    }
    else if(tmp->link==NULL)
    {
        printf("\nDeleting element %d \n",tmp->data);
        *p=NULL;
    }
    else
    {
        while(tmp->link!=NULL)
        {
            prev=tmp;
            tmp=tmp->link;
        }
        printf("\nDeleting element %d \n",tmp->data);
        prev->link=NULL;
    }
}

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
        printf("7.Exit\n");

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
                    //pos_insert(&p,x,pos);
                    break;
            
            case 6: //Deleting node at given position
                    printf("\nEnter position of node to be deleted: ");
                    scanf("%d",&pos);
                    //pos_delete(&p,pos);
                    break;

            case 7: //exiting program
                    exit(0);
                    break;

            default: printf("\nInvalid entry");
        }

        display(&p);

    }
    return 0;
}
