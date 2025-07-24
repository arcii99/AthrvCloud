//FormAI DATASET v1.0 Category: Graph representation ; Style: Romeo and Juliet
#include <stdio.h>
#define MAX_VERTICES 100

typedef struct
{
    int edges[MAX_VERTICES][MAX_VERTICES];
    int numVertices;
    int numEdges;
} Graph;

void initGraph(Graph* g)
{
    g->numVertices = 0;
    g->numEdges = 0;

    for (int i = 0; i < MAX_VERTICES; i++)
    {
        for (int j = 0; j < MAX_VERTICES; j++)
        {
            g->edges[i][j] = 0;
        }
    }
}

void addVertex(Graph* g)
{
    if (g->numVertices < MAX_VERTICES)
    {
        g->numVertices++;
    }
    else
    {
        printf("Graph is full!\n");
    }
}

void addEdge(Graph* g, int v1, int v2)
{
    if (v1 >= 0 && v1 < g->numVertices && v2 >= 0 && v2 < g->numVertices)
    {
        g->edges[v1][v2] = 1;
        g->numEdges++;
    }
    else
    {
        printf("Invalid vertices!\n");
    }
}

void printGraph(Graph* g)
{
    for (int i = 0; i < g->numVertices; i++)
    {
        printf("Adjacent to vertex %d:", i);
        for (int j = 0; j < g->numVertices; j++)
        {
            if (g->edges[i][j])
            {
                printf(" %d", j);
            }
        }
        printf("\n");
    }
}

int main()
{
    Graph g;
    initGraph(&g);
    addVertex(&g);
    addVertex(&g);
    addVertex(&g);
    addEdge(&g, 0, 1);
    addEdge(&g, 0, 2);
    addEdge(&g, 1, 2);
    printGraph(&g);
    return 0;
}