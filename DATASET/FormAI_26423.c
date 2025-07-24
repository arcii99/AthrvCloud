//FormAI DATASET v1.0 Category: Graph representation ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>

// Defining the maximum number of nodes in the graph
#define MAX_NODES 100

// Defining an adjacency list node
typedef struct adj_node {
    int data;
    struct adj_node* next;
} AdjNode;

// Defining a graph
typedef struct graph {
    int num_nodes;
    AdjNode* adj_list[MAX_NODES];
} Graph;

// Function to create a new AdjNode
AdjNode* newAdjNode(int data) {
    AdjNode* new_node = (AdjNode*)malloc(sizeof(AdjNode));
    new_node -> data = data;
    new_node -> next = NULL;
    return new_node;
}

// Function to create a new Graph
Graph* newGraph(int num_nodes) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph -> num_nodes = num_nodes;
    int i;
    for(i=0;i<num_nodes;i++) {
        graph -> adj_list[i] = NULL;
    }
    return graph;
}

// Function to add an edge to the graph
void addEdge(Graph* graph, int src, int dest) {
    // Adding an edge from source to destination
    AdjNode* new_node = newAdjNode(dest);
    new_node -> next = graph -> adj_list[src];
    graph -> adj_list[src] = new_node;
    
    // Adding an edge from destination to source
    new_node = newAdjNode(src);
    new_node -> next = graph -> adj_list[dest];
    graph -> adj_list[dest] = new_node;
}

// Function to print the adjacency list of the graph
void printGraph(Graph* graph) {
    int i;
    for(i=0;i<graph->num_nodes;i++) {
        AdjNode* node = graph -> adj_list[i];
        printf("Adjacency list for vertex %d: ", i);
        while(node!=NULL) {
            printf("%d -> ", node->data);
            node = node -> next;
        }
        printf("NULL\n");
    }
}

// Main function
int main() {
    Graph* graph = newGraph(5); // Creating a graph with 5 nodes
    
    // Adding edges to the graph
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);
    
    // Printing the graph
    printGraph(graph);
    
    return 0;
}