//Seperate Chaining

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 10

typedef struct node
{ 
    long int ph;
    char name[30];
    struct node *next;
}NODE;

void initTable(NODE* details[N])
{
    for(int i=0;i<N;i++)
        details[i]=NULL;
}

void insert(NODE* details[N],int ph,char name[30])
{
    int hashValue=ph%N;
    NODE* temp=malloc(sizeof(NODE));
    temp->ph=ph;
    strcpy(temp->name,name);
    temp->next=NULL;
    if(details[hashValue]==NULL)
    {
        details[hashValue]=temp;
        return;
    }
    NODE *pres=details[hashValue];
    while(pres->next!=NULL)
    pres=pres->next;
    pres->next=temp;
}

int delete(NODE* details[N],int ph)
{
    int hashValue=ph%N;
    NODE *pres=details[hashValue];
    NODE *prev=NULL;
    while(pres!=NULL && pres->ph!=ph)
    {
        prev=pres;
        pres=pres->next; 
    }
    if(pres!=NULL)
    {
        if(prev==NULL)
            details[hashValue]=pres->next;
        else
            prev->next=pres->next;
        free(pres);
        return 1;
    }
    return 0;
}

int search(NODE* details[N],int ph,char name[30])
{
    int hashValue=ph%N;
    NODE *pres=details[hashValue];
    while(pres!=NULL)
    {
        if(pres->ph==ph)
        {
            strcpy(name,pres->name);
            return 1;
        }
        pres=pres->next;
    }
    return 0;
}

void display(NODE *details[N])
{
    NODE *pres;
    for(int i=0;i<N;i++)
    {
        pres=details[i];
        printf("Entry %d: ",i);
        while(pres!=NULL)
        {
            printf("%d: %s\t ",pres->ph,pres->name);
            pres=pres->next;
        }
        printf("\n");
    }
}

void destroyTable(NODE* details[N])
{
    NODE *pres,*prev;
    for(int i=0;i<N;i++)
    {
        pres=details[i];
        while(pres!=NULL)
        {
            prev=pres;
            pres=pres->next;
            free(prev);
        }
        details[i]=NULL;
    }
}

int main()
{
    NODE *details[N]; 
    initTable(details); 
    int choice,ph; 
    char name[30];
    printf("1.Insert 2.Delete 3.Search 4.Display 5.Quit\n");
    scanf("%d",&choice);
    do{
        switch(choice)
        {
            case 1: printf("Number of people: ");
                    int n;
                    scanf("%d",&n);
                    for(int i=0;i<n;i++)
                    {
                        printf("Phone No %d: ",(i+1));
                        scanf(" %d",&ph);
                        printf("Name %d: ",(i+1));
                        scanf(" %s",name);
                        insert(details,ph,name);
                    }
                    break;
            case 2: printf("Phone number: ");
                    scanf("%d",&ph);
                    if(delete(details,ph))
                        printf(" %d is deleted \n",ph);
                    else
                        printf("Does not exist\n");
                    break;
            case 3: printf("Phone number: ");
                    scanf("%d",&ph);
                    if(search(details,ph,name))
                        printf("Phone no.: %d, Name: %s \n",ph,name);
                    else
                        printf("Does not exist\n");
                    break;
            case 4: display(details);
                    break;
            case 5: destroyTable(details);
                    exit(0);
        }
        printf("1.Insert 2.Delete 3.Search 4.Display 5.Quit\n");
        printf("Choice: ");
        scanf("%d",&choice);
    }while(choice<6);
    destroyTable(details);
}