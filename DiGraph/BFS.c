#include<stdio.h>

int a[100][100];
int q[100];
int visit[10];
int f,r,n;

void qinsert(int v);
void create_graph();
void bfs(int v);
int qdelete();
int isEmpty();

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
    while(1)
    {
        printf("Enter source and destination values: ");
        scanf("%d %d",&i, &j);
        if(i==0 && j==0)
            break;
        else
            a[i][j]=1;
    }
}

void bfs(int v)
{
    visit[v]=1;
    printf("%d ",v);
    qinsert(v);
    while(!isEmpty())
    {
        v=qdelete();
        for(int w=1;w<=n;w++)
        {
            if(a[v][w]==1 && visit[w]==0)
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