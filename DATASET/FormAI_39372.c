//FormAI DATASET v1.0 Category: Graph representation ; Style: multivariable
#include <stdio.h>

#define MAX_VERTICES 1000

int main()
{
    int num_vertices, num_edges;
    printf("Enter the number of vertices: ");
    scanf("%d", &num_vertices);
    printf("Enter the number of edges: ");
    scanf("%d", &num_edges);

    int adj_matrix[MAX_VERTICES][MAX_VERTICES] = {0};

    printf("Enter the edges one by one:\n");
    for (int i = 0; i < num_edges; ++i)
    {
        int from, to, weight;
        printf("Edge %d : ", i+1);
        scanf("%d %d %d", &from, &to, &weight);
        adj_matrix[from][to] = weight;
        adj_matrix[to][from] = weight; // assuming the graph is undirected
    }

    printf("The adjacency matrix representation of the graph is:\n\n");
    printf("    ");
    for (int i = 0; i < num_vertices; ++i)
    {
        printf("%d ", i);
    }
    printf("\n");

    for (int i = 0; i < num_vertices; ++i)
    {
        printf("%d : ", i);
        for (int j = 0; j < num_vertices; ++j)
        {
            printf("%d ", adj_matrix[i][j]);
        }
        printf("\n");
    }
    return 0;
}