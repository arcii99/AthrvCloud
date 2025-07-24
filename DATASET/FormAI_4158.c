//FormAI DATASET v1.0 Category: Graph representation ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 10

typedef struct _graph
{
    int adj_matrix[MAX_VERTICES][MAX_VERTICES];
    int n_vertices;
} Graph;

void init_graph(Graph *graph, int n_vertices)
{
    graph->n_vertices = n_vertices;
    for (int i = 0; i < n_vertices; ++i)
    {
        for (int j = 0; j < n_vertices; ++j)
        {
            graph->adj_matrix[i][j] = 0;
        }
    }
}

void add_edge(Graph *graph, int u, int v)
{
    graph->adj_matrix[u][v] = 1;
    graph->adj_matrix[v][u] = 1;
}

void print_graph(Graph graph)
{
    printf("\nGRAPH REPRESENTATION: \n");

    printf("  ");
    for (int i = 0; i < graph.n_vertices; ++i)
    {
        printf("%d ", i);
    }
    printf("\n");

    for (int i = 0; i < graph.n_vertices; ++i)
    {
        printf("%d ", i);
        for (int j = 0; j < graph.n_vertices; ++j)
        {
            printf("%d ", graph.adj_matrix[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    Graph graph;
    init_graph(&graph, 5);

    add_edge(&graph, 0, 1);
    add_edge(&graph, 0, 3);
    add_edge(&graph, 1, 2);
    add_edge(&graph, 1, 4);
    add_edge(&graph, 2, 3);

    print_graph(graph);

    return 0;
}