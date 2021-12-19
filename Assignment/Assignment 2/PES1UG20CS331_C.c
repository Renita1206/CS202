#include "PES1UG20CS331_h.h"

int main()
{
    int vertices;
    int d_result = 0;
    int b_result = 0;
    int s_point, e_point;
    FILE *fp = fopen("input.txt", "r");
    if (fp == NULL)
    {
        printf("\nFile does not exist.");
        exit(0);
    }
    node start, end;
    getcord(&start, fp);
    getcord(&end, fp);
    printf("\nStart: (%d, %d)\nEnd: (%d, %d)\n", start.x, start.y, end.x,
    end.y);
    vertices = num_v(fp);
    vertex_node *adj_list = (vertex_node *)malloc((vertices + 1) *
    sizeof(vertex_node));
    map(fp, adj_list);
    printf("\nDisplaying Adjacency List.\n");
    display_adj_list(adj_list, vertices);
    printf("\n\nFinding path:\n");
    int *d_path = (int *)calloc(vertices, sizeof(int));
    int *b_path = (int *)calloc(vertices, sizeof(int));
    s_point = find_vertex(adj_list, &start, vertices);
    e_point = find_vertex(adj_list, &end, vertices);
    find(adj_list, s_point, e_point, vertices, &d_result, &b_result, d_path, b_path);
    store(adj_list, s_point, e_point, vertices, d_result, b_result, d_path, b_path);
    free(adj_list);
    return 0;
}
