//FormAI DATASET v1.0 Category: Graph representation ; Style: shocked
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

typedef struct Edge
{
    int destination;
    int weight;
    struct Edge* next;
} Edge;

typedef struct Vertex
{
    int value;
    Edge* firstEdge;
} Vertex;

Vertex graph[MAX_VERTICES];
int visited[MAX_VERTICES];

int main(void)
{
    // Initialize all vertices with value 0 and no edges.
    for (int i = 0; i < MAX_VERTICES; i++)
    {
        graph[i].value = 0;
        graph[i].firstEdge = NULL;
    }

    // Add edges to vertex 0.
    Edge* edge1 = (Edge*) malloc(sizeof(Edge));
    edge1->destination = 1;
    edge1->weight = 5;
    graph[0].firstEdge = edge1;

    Edge* edge2 = (Edge*) malloc(sizeof(Edge));
    edge2->destination = 2;
    edge2->weight = 8;
    graph[0].firstEdge->next = edge2;

    // Add edges to vertex 1.
    Edge* edge3 = (Edge*) malloc(sizeof(Edge));
    edge3->destination = 3;
    edge3->weight = 9;
    graph[1].firstEdge = edge3;

    // Add edges to vertex 2.
    Edge* edge4 = (Edge*) malloc(sizeof(Edge));
    edge4->destination = 3;
    edge4->weight = 4;
    graph[2].firstEdge = edge4;

    // Add edges to vertex 3.
    Edge* edge5 = (Edge*) malloc(sizeof(Edge));
    edge5->destination = 4;
    edge5->weight = 2;
    graph[3].firstEdge = edge5;

    // Print the graph.
    printf("Graph representation:\n");

    for (int i = 0; i < MAX_VERTICES; i++)
    {
        if (graph[i].value != 0)
        {
            printf("%d -> ", graph[i].value);

            Edge* edge = graph[i].firstEdge;

            while (edge != NULL)
            {
                printf("%d(%d) ", graph[edge->destination].value, edge->weight);
                edge = edge->next;
            }

            printf("\n");
        }
    }

    return 0;
}