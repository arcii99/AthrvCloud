//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_NODES 100
#define MAX_EDGES 1000

typedef struct Node
{
    int id;
    bool visited;
} Node;

typedef struct Edge
{
    int source;
    int destination;
    int weight;
} Edge;

typedef struct Graph
{
    Node nodes[MAX_NODES];
    Edge edges[MAX_EDGES];
    int numNodes;
    int numEdges;
} Graph;

// Function to add a node to the graph
void addNode(Graph *graph, int nodeId)
{
    if (graph->numNodes < MAX_NODES)
    {
        Node node;
        node.id = nodeId;
        node.visited = false;
        graph->nodes[graph->numNodes] = node;
        graph->numNodes++;
    }
    else
    {
        printf("Error: Too many nodes in the graph\n");
    }
}

// Function to add an edge to the graph
void addEdge(Graph *graph, int sourceNode, int destNode, int weight)
{
    if (graph->numEdges < MAX_EDGES)
    {
        Edge edge;
        edge.source = sourceNode;
        edge.destination = destNode;
        edge.weight = weight;
        graph->edges[graph->numEdges] = edge;
        graph->numEdges++;
    }
    else
    {
        printf("Error: Too many edges in the graph\n");
    }
}

// Function to print the graph
void printGraph(Graph *graph)
{
    printf("Nodes: ");
    for (int i = 0; i < graph->numNodes; i++)
    {
        printf("%d ", graph->nodes[i].id);
    }
    printf("\nEdges:\n");
    for (int i = 0; i < graph->numEdges; i++)
    {
        printf("%d -> %d : %d\n", graph->edges[i].source, graph->edges[i].destination, graph->edges[i].weight);
    }
}

int main()
{
    Graph graph;
    graph.numNodes = 0;
    graph.numEdges = 0;

    // Add some nodes to the graph
    addNode(&graph, 1);
    addNode(&graph, 2);
    addNode(&graph, 3);
    addNode(&graph, 4);

    // Add some edges to the graph
    addEdge(&graph, 1, 2, 10);
    addEdge(&graph, 1, 3, 20);
    addEdge(&graph, 2, 4, 30);
    addEdge(&graph, 3, 4, 40);

    // Print the graph
    printGraph(&graph);

    return 0;
}