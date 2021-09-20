// Stacks implemented by arrays

#include<stdio.h>
#include<stdlib.h>

void push(int *arr, int *p, int x, int size);
void display(int *arr, int *p);
void pop(int *arr, int *p);

void push(int *arr, int *p, int x, int size)
{
        if((*p)==(size-1))
        {
                printf("Stack Overflow\n");
                return;
        }
        else
        {
                printf("Pushing element %d into stack\n",x);
                (*p)++;
                arr[*p]=x;
        }
        
}

void pop(int *arr, int *p)
{
        if((*p)==-1)
                printf("Stack Underflow\n");
        else
        {
                printf("Deleting element %d\n",arr[*p]);
                (*p)--;
        }
}

void display(int *arr, int *p)
{
        if(*p==-1)
                printf("\nStack Underflow\n");
        else
        {
                for(int i=0;i<=(*p);i++)
                        printf("%d\t",arr[i]);
        }
        printf("\n\n");
}

int main()
{
        int a[10];
        int size=10;
        int p=-1;
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
                                push(a,&p,x,size);
                                break;

                        case 2: pop(a,&p);
                                break;

                        default: exit(0);
                                 break;
                 }
                        
                display(a,&p);
        }
        return 0;
}