//FormAI DATASET v1.0 Category: Graph representation ; Style: synchronous
#include <stdio.h>

#define MAX_VERTICES 20

int adj_mat[MAX_VERTICES][MAX_VERTICES];

void add_edge(int source, int destination)
{
    adj_mat[source][destination] = 1;
    adj_mat[destination][source] = 1;
}

void display_matrix(int vertices)
{
    for (int i = 0; i < vertices; i++)
    {
        for (int j = 0; j < vertices; j++)
        {
            printf("%d ", adj_mat[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int vertices, edges, source, destination;

    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);
    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    for (int i = 0; i < edges; i++)
    {
        printf("Enter edge %d (source, destination): ", i + 1);
        scanf("%d %d", &source, &destination);
        add_edge(source, destination);
    }

    printf("Adjacency Matrix:\n");
    display_matrix(vertices);

    return 0;
}