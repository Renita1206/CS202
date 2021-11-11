#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int x;
    int y;
    struct node *right;
    struct node *down;
}Node;

void readmap()
{
    //get size
    //inp destination
    //1s n 0s
}

void insert(Node **start, int x, int y)
{
    Node *tmp;
    tmp=(Node*)malloc(sizeof(Node));
    tmp->x=x;
    tmp->y=y;
    tmp->right=NULL;
    tmp->down=NULL;
    if(*start==NULL)
    {
        *start=tmp;
        return;
    }
    //down
    Node *pres, *prev;
    pres=*start;
    prev=NULL;
    while(pres->y<y)
    {
        prev=pres;
        pres=pres->down;
    }
    tmp->down=pres;
    prev->down=tmp;
    //right
    prev=NULL;
    while(pres->x<x)
    {
        prev=pres;
        pres=pres->right;
    }
    tmp->down=pres;
    prev->down=tmp;
}

int main()
{
    readmap();
    //find_path();
    return 0;
}