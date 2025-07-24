//FormAI DATASET v1.0 Category: Graph representation ; Style: shocked
#include<stdio.h>
#include<stdlib.h>

#define MAX_NODE_COUNT 10  // Maximum number of nodes in the graph
#define MAX_EDGE_COUNT 50  // Maximum number of edges in the graph

struct Edge{
    int source, dest, weight;   // Details of each edge
};

struct Graph{
    int node_count;
    int edge_count;
    struct Edge edges[MAX_EDGE_COUNT];
};

struct Graph createGraph(){
    int nodes, edges;
    printf("Enter the number of nodes in the graph (max 10): ");
    scanf("%d", &nodes);
    struct Graph g;
    g.node_count = nodes;
    printf("Enter the number of edges in the graph (max 50): ");
    scanf("%d", &edges);
    g.edge_count = edges;
    printf("Enter the details of each edge in the following format: Source Destination Weight\n");

    for(int i=0;i<edges;i++){
        scanf("%d %d %d", &(g.edges[i].source), &(g.edges[i].dest), &(g.edges[i].weight));
    }
    return g;
}

void printGraph(struct Graph g){
    printf("\nGraph Representation:\n");
    printf("Nodes: %d, Edges: %d\n", g.node_count, g.edge_count);
    printf("Edge List:\n");
    for(int i=0;i<g.edge_count;i++){
        printf("(%d, %d, %d)\n", g.edges[i].source, g.edges[i].dest, g.edges[i].weight);
    }
    printf("\n");
}

int main(){
    printf("Welcome! This program creates a graph and prints its representation.\n\n");
    struct Graph myGraph = createGraph();
    printGraph(myGraph);
    return 0;
}