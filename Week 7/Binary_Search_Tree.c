#include<stdio.h>
#include<stdlib.h>

void insert(int t[], int x);
void preorder(int t[], int i);
void llevel(int t[],int i,int* ll);
void rlevel (int t[],int i,int* rl);

int main()
{
        int l = 0;
        int r = 0;
        int arr[200];
        for (int i =0; i<200; i++)
        {
                arr[i]=-1;
        }
        int num,x;
        printf("Enter number of elements you wan to insert\n");
        scanf("%d",&num);
        for (int i=0; i<num; i++)
        {
                printf("Enter number\n");
                scanf("%d",&x);
                insert(arr, x);
        }
        preorder(arr,0);
        printf("\n");
        llevel(arr,0,&l);
        rlevel(arr,0,&r);
        if(r>l)
        {
                printf("level is %d\n",r);
                printf("height is %d\n",r+1);
        }
        else
        {
                printf("level is %d\n",l);
                printf("height is %d\n",l+1);
        }
        return 0;
}

void insert(int t[], int x)
{
        int i =0;
        while(t[i]!=-1)
        {
                if(x>t[i])
                {
                        i = 2*i+2;
                }
                else
                {
                        i = 2*i+1;
                }
        }
        t[i] = x;
}

void preorder(int t[], int i)
{
        if (t[i]==-1)
                return;
        printf("%d-",t[i]);
        preorder(t,2*i+1);
        preorder(t,2*i+2);
}

void llevel(int t[],int i,int* ll)
{
        if (t[i]==-1)
                return;
        (*ll)++;
        llevel(t,2*i+1,ll);
        
}

void rlevel (int t[],int i,int* rl)
{
        if (t[i]==-1)
                return;
        (*rl)++;
       rlevel(t,2*i+2,rl);
}
