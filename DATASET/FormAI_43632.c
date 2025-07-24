//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_NODES 100
#define MAX_EDGES 1000

// Data structure to store an edge
struct edge
{
    int src;
    int dest;
    int weight;
};

// Data structure to store graph
struct graph
{
    struct edge edges[MAX_EDGES]; // array of edges
    int num_edges; // current number of edges
    int num_nodes; // current number of nodes
};

// Function to add an edge to graph
void add_edge(struct graph* g, int src, int dest, int weight)
{
    g->edges[g->num_edges].src = src;
    g->edges[g->num_edges].dest = dest;
    g->edges[g->num_edges].weight = weight;

    // Increment number of edges
    g->num_edges++;
}

// Function to print graph
void print_graph(struct graph* g)
{
    printf("Graph:\n");
    printf("Number of nodes = %d\n", g->num_nodes);
    printf("Number of edges = %d\n", g->num_edges);
    printf("Edges:\n");

    for (int i = 0; i < g->num_edges; i++)
    {
        printf("(%d, %d, %d)\n", g->edges[i].src, g->edges[i].dest, g->edges[i].weight);
    }
}

int main()
{
    struct graph g;
    g.num_edges = 0;
    g.num_nodes = 0;

    // Add nodes to graph
    g.num_nodes++;
    g.num_nodes++;

    // Add edges to graph
    add_edge(&g, 0, 1, 5);
    add_edge(&g, 1, 2, 7);

    // Print graph
    print_graph(&g);

    return 0;
}