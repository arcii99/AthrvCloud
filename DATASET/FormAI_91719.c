//FormAI DATASET v1.0 Category: Graph representation ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 10

/* Graph structure */
typedef struct Graph_t
{
    int adjacency_matrix[MAX_VERTICES][MAX_VERTICES];
    int num_vertices;
} Graph;

/* Function Declarations */
void init_graph(Graph* graph);
void add_edge(Graph* graph, int vertex1, int vertex2);
void print_graph(Graph* graph);

/* Initialize graph to empty */
void init_graph(Graph* graph)
{
    int i, j;

    for (i = 0; i < MAX_VERTICES; i++)
    {
        for (j = 0; j < MAX_VERTICES; j++)
        {
            graph->adjacency_matrix[i][j] = 0;
        }
    }

    graph->num_vertices = 0;
}

/* Add edge to graph */
void add_edge(Graph* graph, int vertex1, int vertex2)
{
    if (graph->num_vertices >= MAX_VERTICES)
    {
        printf("Cannot add edge. Maximum number of vertices reached.\n");
        return;
    }

    graph->adjacency_matrix[vertex1][vertex2] = 1;
    graph->adjacency_matrix[vertex2][vertex1] = 1;

    if (vertex1 > graph->num_vertices)
    {
        graph->num_vertices = vertex1;
    }

    if (vertex2 > graph->num_vertices)
    {
        graph->num_vertices = vertex2;
    }
}

/* Print graph adjacency matrix */
void print_graph(Graph* graph)
{
    int i, j;

    for (i = 0; i <= graph->num_vertices; i++)
    {
        printf("%d: ", i);

        for (j = 0; j <= graph->num_vertices; j++)
        {
            printf("%d ", graph->adjacency_matrix[i][j]);
        }

        printf("\n");
    }
}

/* Test function */
int main()
{
    Graph graph;

    init_graph(&graph);

    add_edge(&graph, 0, 1);
    add_edge(&graph, 1, 2);
    add_edge(&graph, 2, 3);
    add_edge(&graph, 3, 4);
    add_edge(&graph, 4, 5);
    add_edge(&graph, 5, 6);
    add_edge(&graph, 6, 7);

    print_graph(&graph);

    return 0;
}