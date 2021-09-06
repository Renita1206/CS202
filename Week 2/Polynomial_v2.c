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

void insert(Polynomial **p,int ,int , int);
void display(Polynomial **p);
void add(Polynomial **p1, Polynomial **p2);

void insert(Polynomial **p, int c, int x, int y)
{
      Polynomial *tmp,*pres;
      pres=*p;
      tmp=(Polynomial*)malloc(sizeof(Polynomial));
      tmp->coefficiant=c;
      tmp->px=x;
      tmp->py=y;
      tmp->next=NULL;
      if(*p==NULL)
      {
        *p=tmp;
      }
      else
      {
        while(pres->next!=NULL)
              {
                pres=pres->next;
              } 
              pres->next=tmp; 
      }
}

void display(Polynomial **p)
{
        Polynomial *tmp;
        tmp=*p;
        while(tmp!=NULL)
        {
                printf("%d x^%d y^%d  + ",tmp->coefficiant,tmp->px,tmp->py);
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
                t2=*p2;
                int sum=t1->coefficiant;
                while(t2!=NULL)
                {
                        if(t1->px ==t2->px && t1->py==t2->py)
                        {
                                sum=sum+t2->coefficiant;
                                t2->coefficiant=0;
                                break;
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
        printf("0\n");
}

int main()
{
        Polynomial *p1,*p2;
        p1=NULL;
        p2=NULL;
        int n1,n2;
        int c,x,y;
        printf("Enter number of terms in first polynomial: ");
        scanf("%d",&n1);
        for(int i=0;i<n1;i++)
        {
                printf("\n Enter the coefficiant: ");
                scanf("%d",&c);
                printf("\n Enter the power of x: ");
                scanf("%d",&x);
                printf("\n Enter the power of y: ");
                scanf("%d",&y);
                insert(&p1,c,x,y);
        }
        printf("Enter number of terms in second polynomial: ");
        scanf("%d",&n2);
        for(int i=0;i<n2;i++)
        {
                printf("\n Enter the coefficiant: ");
                scanf("%d",&c);
                printf("\n Enter the power of x: ");
                scanf("%d",&x);
                printf("\n Enter the power of y: ");
                scanf("%d",&y);
                insert(&p2,c,x,y);
        }
        display(&p1);
        display(&p2);
        add(&p1,&p2);
        return 0;
}
