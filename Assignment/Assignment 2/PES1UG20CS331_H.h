#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    int x;
    int y;
} node;

typedef struct vertex
{
    int vid;
    node loc;
    struct vertex *next;
} vertex_node;

void getcord(node *c, FILE *fp);
int num_v(FILE *fp);
void map(FILE *fp, vertex_node *adj_list);
void create_adj_list(vertex_node *adj_list, int vertices);
void insert_vnode(vertex_node *adj_list, int src, int dest);
void display_adj_list(vertex_node *adj_list, int vertices);
int find_vertex(vertex_node *adj_list, node *loc, int vertices);
void find(vertex_node *adj_list, int s_point, int e_point, int vertices, int *d_result, int *b_result, int *d_path, int *b_path);
int dfs(vertex_node *adj_list, int s, int d, int *vis, int length, int *path);
void bfs(vertex_node *adj_list, int s, int d, int *vis, int vertices, int *prev);
int reconstruct_from_bfs(vertex_node *adj_list, int s_point, int e_point, int *b_path, int *prev);
void store(vertex_node *adj_list, int s_point, int e_point, int vertices, int d_result, int b_result, int *d_path, int *b_path);
void qinsert(int *q, int *front, int *rear, int k);
int qdelete(int *q, int *front, int *rear);
int qisempty(int *front);
