// Program implementing queues using arrays

#include<stdio.h>
#include<stdlib.h>

void enqueue( int *q, int *f, int *r, int size, int x);
void dequeue( int *q, int *f, int *r, int size);
void display( int *q, int *f, int *r, int size);

int main()
{
        int n, choice, x;
        int f=-1;
        int r=-1;
        printf("Enter size of array: ");
        scanf("%d",&n);
        int *a;
        a=(int*)malloc(sizeof(int)*n);
        while(1)
        {
                display(a, &f, &r, n);
                printf("\n1.Enqueue\n");
                printf("2.Deque\n");
                printf("3.Exit\n");
                scanf("%d",&choice);
                switch(choice)
                {
                        case 1: printf("Enter element: ");
                                scanf("%d",&x);
                                enqueue(a, &f, &r, n, x);
                                break;
                                
                        case 2: dequeue(a, &f, &r, n);
                                break;
                                
                        case 3: exit(0);
                                
                        default: printf("Invalid entry");
                }
        }
        return 0;
}

void enqueue( int *q, int *f, int *r, int size, int x)
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

void dequeue( int *q, int *f, int *r, int size)
{
        if((*f)==-1)
        {       
                printf("Queue is empty\n");
                return;
        }
        if((*f)==(*r))
        {
                *f=-1;
                *r=-1;
                return;
        }
        printf("Deleting element %d\n",q[*f]);
        ++(*f);
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
}
