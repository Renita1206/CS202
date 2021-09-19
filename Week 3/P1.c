//Telephone Directory Program

#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 

typedef struct node 
{ 
 char name[20]; 
 int phone; 
 char add[20]; 
 char area[20]; 
 struct node* next; 
 struct node* prev; 
}Node; 

typedef struct customer_details
{ 
 Node* head; 
}C; 

void insert_order(Node**, char*, int, char*, char*); 
void display(Node*); 

int main() 
{ 
    C first; 
    first.head = NULL; 
    char name[50]; 
    char add[50]; 
    char area[50]; 
    int phone; 
    int ch;
    while(1) 
    { 
        printf("\nEnter 1 to insert new record in directory\n");   
        scanf("%d",&ch); 
        switch(ch) 
        { 
            case 1: printf("Enter Values of Name, Phone, Address, Area\n"); 
                    fflush(stdin); 
                    scanf("%[^\n]s",name); 
                    fflush(stdin); 
                    scanf("%d",&phone); 
                    fflush(stdin); 
                    scanf("%[^\n]s",add); 
                    fflush(stdin); 
                    scanf("%[^\n]s",area); 
                    printf("\n"); 
                    insert_order(&(first.head),name,phone,add,area);  
                    break; 
            default: exit(0); 
                    break; 
        } 
        display(first.head); 
    } 
    return 0; 
} 


void insert_order(Node** p,char* name,int phone, char* add, char* area) 
{
    Node *temp, *pres, *prev; 
    temp = (Node*)malloc(sizeof(Node)); 
    strcpy(temp->name, name); 
    temp->phone = phone; 
    strcpy(temp->add, add); 
    strcpy(temp->area,area); 
    temp->next= temp->prev = NULL; 
    prev = NULL; 
    pres = *p; 
    while(pres!=NULL && strcmp(name, pres->name)>0)  
    { 
        prev = pres; 
        pres = pres->next; 
    } 
    if(pres!=NULL) 
    { 
        if(prev==NULL) 
        { 
            temp->next = pres; 
            *p = temp; 
        } 
        else 
        { 
            prev->next = temp; 
            temp->next = pres; 
            temp->prev = prev; 
        } 
    } 
    else 
    { 
        if(prev == NULL) 
        { 
            *p = temp; 
        } 
        else 
        { 
            prev->next = temp;
            temp->prev = prev; 
            temp->next = NULL; 
        } 
    } 
} 

void display(Node* p) 
{ 
    if(p==NULL) 
        printf("List is Empty\n"); 
    else 
    { 
        while(p!=NULL) 
        { 
            printf("Name: %s\n",p->name); 
            printf("Phone: %d\n",p->phone); 
            printf("Address: %s\n",p->add);  
            printf("Area: %s\n\n",p->area);  
            p = p->next; 
        } 
    } 
    printf("\n"); 
}

