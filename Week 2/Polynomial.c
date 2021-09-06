//Program to add two polynomials

#include<stdio.h>
#include<stdlib.h>

typedef struct poly
{
        int coefficiant;
        int px;
        int py;
        struct poly *next;
}Polynomial;

void input(Polynomial **p,int n);
void display(Polynomial **p);
void add(Polynomial **p1, Polynomial **p2);

void input(Polynomial **p,int n)
{
        Polynomial *tmp;
        tmp=*p;
        for(int i=0;i<n;i++)
        {
                printf("\n Enter the coefficiant: ");
                scanf("%d",&(tmp->coefficiant));
                printf("\n Enter the power of x: ");
                scanf("%d",&(tmp->px));
                printf("\n Enter the power of y: ");
                scanf("%d",&(tmp->py));
                tmp=tmp->next;
        }
}

void display(Polynomial **p)
{
        Polynomial *tmp;
        tmp=*p;
        while(tmp!=NULL)
        {
                printf("%d x^%d y^%d  +",tmp->coefficiant,tmp->px,tmp->py);
                tmp=tmp->next;
        }
        printf("0\n");
}

void add(Polynomial **p1, Polynomial **p2)
{
        Polynomial *t1,*t2;
        t1=*p1;
        t2=*p2;
        while(t1!=NULL)
        {
                int sum=t1->coefficiant;
                while(t2!=NULL)
                {
                        if(t1->px ==t2->px && t1->py==t2->py)
                        {
                                sum=sum+t2->coefficiant;
                                t2->coefficiant=0;
                        }
                        t2=t2->next;
                }
                printf("%d x^%d y^%d  + ",sum,t1->px,t1->py);
                t1=t1->next;
        }
        t2=*p2;
        while(t2!=NULL)
        {
                if(t2->coefficiant!=0)
                {
                        printf("%d x^%d y^%d  + ",t2->coefficiant,t2->px,t2->py);
                }
                t2=t2->next;
        }
        printf(" 0\n");
}

int main()
{
        Polynomial *p1,*p2;
        int n1,n2;
        p1=NULL;
        p2=NULL;
        printf("Enter number of terms in first polynomial: ");
        scanf("%d",&n1);
        p1=(Polynomial*)malloc(n1*sizeof(Polynomial));
        input(&p1,n1);
        printf("Enter number of terms in second polynomial: ");
        scanf("%d",&n2);
        p2=(Polynomial*)malloc(n2*sizeof(Polynomial));
        input(&p2,n2);
        display(&p1);
        display(&p2);
        add(&p1,&p2);
        return 0;
}
