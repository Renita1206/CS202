// Employee Records

#include<stdio.h> 
#include<stdlib.h> 
#include<string.h> 

typedef struct department 
{ 
    char name[20]; 
    int num; 
}D; 

typedef struct node 
{  
    char ssn[20]; 
    char name[20];
    D* dept;
    char design[20];
    int salary;
    int phone;
    int age; 
    struct node* prev; 
    struct node* next; 
}Node; 

typedef struct employee 
{ 
    Node* head; 
}E; 

void insert(Node**,char*,char*,int,char*,char*,int ,int,int); 
void display(Node*); 
void display_department(Node*); 
void delete_age(Node**, int); 

int main() 
{ 
    int ch;
    char ssn[20]; 
    char name[20];
    D* dept;
    char design[20];
    int salary;
    int phone;
    int age; 
    int num; 
    char dep_name[20]; 
    E first; 
    first.head = NULL; 

    while (1) 
    { 
        printf("\n1.Insert\n"); 
        printf("2.Display\n"); 
        printf("3.Display department list\n");  printf("4.Delete 58\n"); 
        printf("Enter choice:\t"); 
        scanf("%d",&ch); 
        fflush(stdin); 
        switch(ch) 
        { 
            case 1:    printf("Enter ssn:\n"); scanf("%[^\n]s",ssn); 
                        fflush(stdin); 
                        printf("Enter name:\n"); 
                        scanf("%[^\n]s",name); 
                        fflush(stdin); 
                        printf("Enter department number:\n"); 
                        scanf("%d",&num); 
                        fflush(stdin); 
                        printf("Enter department name:\n"); 
                        scanf("%[^\n]s",dep_name);
                        fflush(stdin); 
                        printf("Enter designation:\n"); 
                        scanf("%[^\n]s",design); 
                        fflush(stdin); 
                        printf("Enter salary:\n"); 
                        scanf("%d",&salary); 
                        fflush(stdin); 
                        printf("Enter phone:\n"); 
                        scanf("%d",&phone); 
                        fflush(stdin); 
                        printf("Enter age:\n"); 
                        scanf("%d",&age); 
                        fflush(stdin); 
                        insert(&(first.head),ssn,name,num,dep_name,design,salary,phone,age); 
                        break;

            case 2:    display(first.head); 
                        break; 
            
            case 3:    display_department(first.head); 
                        break; 

            case 4:    delete_age(&(first.head),58); 
                        break; 

            default:   exit(0);
                        break; 
        } 
    } 
    return 0; 
} 


void insert(Node** p,char* ssn,char* name,int  num,char* dep_name, char* design,int sal,int ph,int  age) 
{ 
    Node* temp = (Node*)malloc(sizeof(Node)); 
    D* d = (D*) malloc(sizeof(Node));  
    strcpy(temp->ssn,ssn); 
    strcpy(temp->name,name); 
    temp->dept = d; 
    (temp->dept)->num = num; 
    strcpy(temp->dept->name,dep_name); 
    strcpy(temp->design,design); 
    temp->salary = sal; 
    temp->phone = ph; 
    temp->age = age; 
    temp->next = temp->prev = NULL; 
    if(*p == NULL) 
    { 
        *p = temp; 
    } 
    else 
    { 
        temp->next = *p; 
        (*p)->prev = temp; 
        *p = temp; 
    } 
} 

void display(Node* head) 
{
    if(head==NULL) 
    { 
        printf("List is Empty\n"); 
    } 
    else 
    { 
    while(head!=NULL) 
    { 
        printf("\n\n"); 
        printf("Name: %s\n",head->name);  
        printf("SSN: %s\n",head->ssn);  
        printf("Dept Num: %d\n",head->dept->num);  
        printf("Dept: %s\n",head->dept->name);   
        printf("Phone: %d\n",head->phone); 
        printf("Designation: %s\n",head->design);  
        printf("Age: %d\n",head->age);   
        printf("Salary: %d\n",head->salary); 
        head = head->next; 
        } 
        printf("\n\n"); 
    } 
} 

void display_department(Node* head) 
{ 
    char department[50]; 
    printf("Enter department: \n"); 
    scanf("%[^\n]s",department); 
    fflush(stdin); 
    if (head==NULL) 
        printf("List is Empty\n"); 
    else 
    { 
        while(head!=NULL) 
        { 
            if((strcmp(department,head->dept->name))==0) 
            {
                printf("\n\n"); 
                printf("Name: %s\n",head->name);  
                printf("SSN: %s\n",head->ssn);  
                printf("Dept Num: %d\n",head->dept->num);  
                printf("Dept: %s\n",head->dept->name);   
                printf("Phone: %d\n",head->phone); 
                printf("Designation: %s\n",head->design);  
                printf("Age: %d\n",head->age);   
                printf("Salary: %d\n",head->salary); 
            } 
            head = head->next; 
        } 
    } 
} 

void delete_age(Node** p, int age) 
{ 
    Node *q, *t;
    q=*p; 
    t = NULL; 
    if(*p==NULL) 
    { 
        printf("List is Empty\n"); 
    } 
    else 
    { 
        while(q != NULL) 
        { 
            if(q->age > age) 
            { 
                if(q->prev == NULL) 
                { 
                    *p = q->next; 
                    free(q); 
                    q = *p; 
                } 
                else if(q->next == NULL) 
                {
                    q->prev->next = NULL; 
                    free(q); 
                    q = NULL; 
                    return; 
                } 
                else 
                { 
                    q->prev->next = q->next;  q->next->prev = q->prev;  t = q->next; 
                    free(q); 
                    q = t; 
                } 
            } 
            else 
            { 
                q = q->next; 
            } 
        } 
    } 
}