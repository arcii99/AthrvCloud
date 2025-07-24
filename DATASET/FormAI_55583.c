//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: Donald Knuth
#include <stdio.h>
#include <stdbool.h>
#define MAX_VERTICES 100
#define MAX_COLORS 10

int adj_matrix[MAX_VERTICES][MAX_VERTICES];
int num_vertices;
int colors[MAX_VERTICES];
bool is_safe(int vertex, int color);

int main()
{
    int i, j;
    printf("Enter the number of vertices: ");
    scanf("%d", &num_vertices);
    printf("Enter the adjacency matrix:\n");
    for (i = 0; i < num_vertices; i++)
        for (j = 0; j < num_vertices; j++)
            scanf("%d", &adj_matrix[i][j]);
    for (i = 0; i < num_vertices; i++)
        colors[i] = -1;
    for (i = 0; i < num_vertices; i++)
        for (j = 0; j < MAX_COLORS; j++)
            if (is_safe(i, j))
            {
                colors[i] = j;
                break;
            }
    printf("The color assigned to each vertex is:\n");
    for (i = 0; i < num_vertices; i++)
        printf("Vertex %d -> Color %d\n", i, colors[i]);
    return 0;
}

bool is_safe(int vertex, int color)
{
    int i;
    for (i = 0; i < num_vertices; i++)
        if (adj_matrix[vertex][i] && color == colors[i])
            return false;
    return true;
}