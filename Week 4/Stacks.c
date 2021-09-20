// Two stacks in one array

#include<stdio.h>
#include<stdlib.h>

void insert1(int *arr, int *p1, int *p2, int x);
void insert2(int *arr, int *p1, int *p2, int x);
void display(int *arr, int *p1, int *p2, int size);
void pop1(int *arr, int *p1);
void pop2(int *arr, int *p2, int size);

void insert1(int *arr, int *p1, int *p2, int x)
{
        if(((*p1)+1)==(*p2))
        {
                printf("Overflow\n");
                return;
        }
        else
        {
                (*p1)++;
                arr[*p1]=x;
        }
        
}

void insert2(int *arr, int *p1, int *p2, int x)
{
        if(((*p1)+1)==(*p2))
        {
                printf("Overflow\n");
                return;
        }
        else
        {
                (*p2)--;
                arr[*p2]=x;
        }
}

void pop1(int *arr, int *p1)
{
        if((*p1)==-1)
                printf("Underflow\n");
        else
        {
                printf("Deleting element %d\n",arr[*p1]);
                (*p1)--;
        }
}

void pop2(int *arr, int *p2, int size)
{
        if((*p2)==size)
                printf("Underflow\n");
        else
        {
                printf("Deleting element %d\n",arr[*p2]);
                (*p2)++;
        }
}

void display(int *arr, int *p1, int *p2, int size)
{
        //printf("%d\t%d\n",*p1,*p2);
        if(*p1==-1)
                printf("\nStack 1 underflow\n");
        else
        {
                for(int i=0;i<=(*p1);i++)
                        printf("%d\t",arr[i]);
        }
        printf("\n");
        if(*p2==size)
                printf("Stack 2 underflow\n");
        else
        {
                for(int i=*p2;i<size;i++)
                        printf("%d\t",arr[i]);
        }
        printf("\n\n");
}

int main()
{
        int a[10];
        int size=10;
        int p1=-1;
        int p2=size;
        int choice,x;
        while(1)
        {   
                printf("1.Push element in stack 1\n");
                printf("2.Push element in stack 2\n");
                printf("3.Pop element from stack 1\n");
                printf("4.Pop element from stack 2\n");
                scanf("%d",&choice);
                switch(choice)
                {
                        case 1: printf("Enter element: ");
                                scanf("%d",&x);
                                insert1(a,&p1,&p2,x);
                                break;
                        
                        case 2: printf("Enter element: ");
                                scanf("%d",&x);
                                insert2(a,&p1,&p2,x);
                                break;
                                
                        case 3: pop1(a,&p1);
                                break;
                        
                        case 4: pop2(a,&p2,size);
                                break;
                        
                        default: exit(0);
                                 break;
                 }
                        
                display(a,&p1,&p2,size);
        }
        return 0;
}
