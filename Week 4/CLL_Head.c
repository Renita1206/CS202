//Circular linked list with head node

#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
}Node;

typedef struct h
{
    struct node *head;
}Head;

//Function implementation to be completed

void front_insert(Head *p, int x);
void front_delete(Head *p);
void display(Head *p);

int main()
{
    Head *p=NULL;
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
                    //front_insert(p,x);
                    break;
            
            case 2: //Inserting node at the end of the list
                    printf("\nEnter the value to store: ");
                    scanf("%d",&x);
                    //back_insert(p,x);
                    break;
            
            case 3: //Deleting first node
                    //front_delete(p);
                    break;
            
            case 4: //Deleting last node
                    //back_delete(p);
                    break;

            case 5: // Inserting node at given position
                    printf("\nEnter the value to store: ");
                    scanf("%d",&x);
                    printf("\nEnter position at which node must be inserted: ");
                    scanf("%d",&pos);
                    //pos_insert(p,x,pos);
                    break;
            
            case 6: //Deleting node at given position
                    printf("\nEnter position of node to be deleted: ");
                    scanf("%d",&pos);
                    //pos_delete(p,pos);
                    break;
            
            case 7: //Reverse the list
                    //reverse(p);
                    break;

            case 8: //exiting program
                    exit(0);
                    break;

            default: printf("\nInvalid entry");
        }

        //display(p);
        printf("\n\n");

    }
    return 0;
}