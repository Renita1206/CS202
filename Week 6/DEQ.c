// Double ended queue using arrays

#include<stdio.h>
#include<stdlib.h>

void rear_insert( int *q, int *f, int *r, int size, int x);
void front_insert( int *q, int *f, int *r, int size, int x);
void front_del( int *q, int *f, int *r, int size);
void rear_del( int *q, int *f, int *r, int size);
void display( int *q, int *f, int *r, int size);

void rear_insert( int *q, int *f, int *r, int size, int x)
{       
        if(*r==(size-1))
        {
                printf("Queue is full\n");
                return;
        }
        (*r)++;
        q[*r]=x;
        if((*f)==-1)
                *f=0;
        return;
         
}

void front_insert( int *q, int *f, int *r, int size, int x)
{       
        if((*f)==(0))
        {
                if(*r==(size-1))
                {
                        printf("Queue is full\n");
                        return;
                }
                else
                {
                        for(int i=(*r)+1;i>0;i--)
                        {
                            q[i]=q[i-1];
                        } 
                        q[0]=x;
                        (*r)++;
                        return;    
                }
        }
        if((*f)==(-1))
        {
                (*f)++;
                q[*f]=x;
                if((*r)==-1)
                        *r=0;
                return;
        }
        (*f)--;
        q[*f]=x;
        return;
         
}

void front_del( int *q, int *f, int *r, int size)
{
        if((*f)==(-1))
        {       
                printf("Queue is empty\n");
                return;
        }
        printf("Deleting element %d\n",q[*f]);
        if((*f)==(*r))
        {
                *f=-1;
                *r=-1;
                return;
        }
        ++(*f);
}

void rear_del( int *q, int *f, int *r, int size)
{
        if((*f)==-1)
        {       
                printf("Queue is empty\n");
                return;
        }
        printf("Deleting element %d\n",q[*r]);
        if((*f)==(*r))
        {
                *f=-1;
                *r=-1;
                return;
        }
        --(*r);
}

void display(int *q, int *f, int *r, int size)
{
        if((*f)==-1)
        {       
                printf("Queue is empty\n");
                return;
        }
        for(int i=(*f);i<=(*r);i++)
        {
                printf("%d\t",q[i]);
        }
        printf("\n");
        printf("Front: %d Rear: %d\n\n",(*f),(*r));
}

int main()
{
        int f=-1;
        int r=-1;
        int size, choice, x;
        printf("Enter the size of the array: ");
        scanf("%d",&size);
        int *a = (int*)malloc(sizeof(int)*size);
        while(1)
        {
                display(a, &f, &r, size);
                printf("\n1.Rear Insertion\n");
                printf("2. Front Insertion\n");
                printf("3.Front deletion\n");
                printf("4.Rear deletion\n");
                printf("5.Exit\n");
                scanf("%d",&choice);
                switch(choice)
                {
                        case 1: printf("Enter element: ");
                                scanf("%d",&x);
                                rear_insert(a, &f, &r, size, x);
                                break;
                        
                        case 2: printf("Enter element: ");
                                scanf("%d",&x);
                                front_insert(a, &f, &r, size, x);
                                break;
                                
                        case 3: front_del(a, &f, &r, size);
                                break;
                                
                        case 4: rear_del(a, &f, &r, size);
                                break;
                                
                        case 5: exit(0);
                                
                        default: printf("Invalid entry\n");
                }
        }
        return 0;
}
