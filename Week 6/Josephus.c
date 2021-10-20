//Josephus Problem

#include<stdio.h>
#include<stdlib.h>

typedef struct queue
{
	int *cq;
	int f,r,size;
}Q;


void init(Q *ptr);
int insert(Q *ptr,int);
int del(Q *ptr);
int isempty(Q *ptr);

int main()
{
   int ch,k,n,i;
   Q q;
   init(&q);
   n=q.size;
   for(i=1;i<=n;i++)
	   insert(&q,i);
   
   while(!isempty(&q))
   {
	   k=del(&q);
	   insert(&q,k);
	   k=del(&q);
   }
   printf("The winner is: %d\n",k);
}
   
 int isempty(Q *ptr)
 {
	 if(ptr->f==-1)
		 return 1;
	 return 0;
 }

 void init(Q *ptr)
 {
    printf("Enter the number of people: \n");
    scanf("%d",&ptr->size);
    ptr->f=ptr->r=-1;
    ptr->cq=(int*)malloc(sizeof(int)*(ptr->size));
 }	
	 
 int insert(Q *ptr, int key)
 {
	 if((ptr->r+1)%ptr->size==ptr->f)
	 {
		 printf("Queue Full\n");
		 return -1;
	 }
	 ptr->r=(ptr->r+1)%ptr->size;  
	 ptr->cq[ptr->r]=key; 
	 if(ptr->f==-1) 
		 ptr->f=0;
	 return 1;
 }
 
 int del(Q *ptr)
 {
	 int key;
	 if(ptr->f==-1)
	 {
		 printf("Queue Empty\n");
		 return -1;
	 }
	 key=ptr->cq[ptr->f];
	 if(ptr->f==ptr->r)//only one element
	    ptr->f=ptr->r=-1;
	 else
		 ptr->f=(ptr->f+1)%ptr->size;
	 return key;
 }
   
