//Check connectivity of graph and compute number of components

#include<stdio.h>
#include <stdlib.h>
#define max 10

void read(int a[][max], int n)
{
    printf("Enter elements of adjacency matrix:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            scanf("%d", &a[i][j]);
        printf("\n");
    }
}

void display(int a[][max], int n)
{
    printf("The graph is: \n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            printf("%d", a[i][j]);
        printf("\n");
    }
}

void components(int src, int a[max][max], int v[max], int n, int l)
{
    v[src] = l;
    for (int i = 0; i < n; i++)
    {
        if (a[src][i] && !v[i])
            components(i, a, v, n, l);
    }
}

void traverseDFS(int src, int a[max][max], int v[max], int n)
{
    printf("%d\t", src);
    v[src] = 1;
    for (int i = 0; i < n; i++)
    {
        if (a[src][i] && !v[i])
            traverseDFS(i, a, v, n);
    }
}

int main()
{
    int a[max][max] = {0}, visited[max] = {0}, n = 0, flag = 0, l= 1;
    printf("Enter the number of vertices:\n");
    scanf("%d", &n);
    read(a, n);
    display(a, n);
    printf("\nElements of the graph: \n");
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
            traverseDFS(i, a, visited, n);
    }
    for (int k = 0; k < n; k++)
        visited[k] = 0; 
    for (int i = 0; i < n; i++)
    {
        components(i, a, visited, n, l);
        for (int j = 0; j < n; j++)
        {
            if (visited[j] == 0)
            {
                flag = 1;
                break;
            }
        }
        if (flag)
            break;
        for (int k = 0; k < n; k++)
            visited[k] = 0;
    }
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            components(i, a, visited, n, l);
            l++;
        }
    }
    printf("\n");
    if (flag)
        printf("Unconnected Graph\n");
    else
        printf("Connected Graph\n");
    printf("Number of components: %d\n", l);
    return 0;
}
