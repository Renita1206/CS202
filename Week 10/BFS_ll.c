//BFS implementation using linked lists

#include<stdio.h>
#include<stdlib.h>

int q[100];
int visit[10];
int f,r,n;

struct node
{
    int data;
    struct node *next;
};

struct node* a[100];

void qinsert(int v);
void create_graph();
void bfs(int v);
int qdelete();
int isEmpty();
void insert(int i, int j);

void main()
{
    int v;
    f=r=-1;
    printf("Enter the number of vertices: ");
    scanf("%d",&n);
    create_graph();
    printf("\nEnter the source vertex: ");
    scanf("%d",&v);
    printf("\nVertices reachable from source vertex: ");
    bfs(v);
}

void create_graph()
{
    int i,j;
    for(i=0;i<=n;i++)
        a[i]=NULL;
    while(1)
    {
        printf("Enter source and destination values: ");
        scanf("%d %d",&i, &j);
        if(i==0 && j==0)
            break;
        else
            insert(i,j);
    }
}

void bfs(int v)
{
    struct node *p;
    visit[v]=1;
    printf("%d ",v);
    qinsert(v);
    while(!isEmpty())
    {
        v=qdelete();
        for(p=a[v];p!=NULL;p=p->next)
        {
            int w=p->data;
            if(visit[w]==0)
            {
                visit[w]=1;
                printf("%d ",w);
                qinsert(w);
            }
        }
    }
}

void qinsert(int v)
{
    r++;
    q[r]=v;
    if(f==-1)
        f=0;
}

int qdelete()
{
    int w;
    w=q[f];
    if(f==r)
        f=r=-1;
    else
        f++;
    return w;
}

int isEmpty()
{
    if(f==-1)
        return 1;
    return 0;

}

void insert(int i, int j)
{
    struct node *tmp;
    tmp=(struct node*)malloc(sizeof(struct node));
    tmp->data=j;
    tmp->next=a[i];
    a[i]=tmp;
}