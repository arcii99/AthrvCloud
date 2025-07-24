//FormAI DATASET v1.0 Category: Graph representation ; Style: complex
#include<stdio.h>
#include<stdlib.h>

struct node {       // Node structure for graph
    int vertex;     // Node vertex
    struct node *next;  // Next node
};

struct Graph {   // Graph structure
    int num_vertices;    // Number of vertices
    struct node **adj_lists;   // Array of adjacency lists
};

// Function to create a new node
struct node *createNode(int v) {
    struct node *newNode = malloc(sizeof(struct node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// Function to create a graph
struct Graph *createGraph(int vertices) {
    struct Graph *graph = malloc(sizeof(struct Graph));
    graph->num_vertices = vertices;
    graph->adj_lists = malloc(vertices * sizeof(struct node *));
    int i;
    for (i = 0; i < vertices; i++) {
        graph->adj_lists[i] = NULL;
    }
    return graph;
}

// Function to add an edge
void addEdge(struct Graph *graph, int src, int dest) {
    // Add edge from src to dest
    struct node *newNode = createNode(dest);
    newNode->next = graph->adj_lists[src];
    graph->adj_lists[src] = newNode;

    // Add edge from dest to src
    newNode = createNode(src);
    newNode->next = graph->adj_lists[dest];
    graph->adj_lists[dest] = newNode;
}

// Function to print the graph
void printGraph(struct Graph *graph) {
    int v;
    for (v = 0; v < graph->num_vertices; v++) {
        struct node *temp = graph->adj_lists[v];
        printf("\n Adjacency list of vertex %d\n ", v);
        while (temp) {
            printf("%d -> ", temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }
}

// Main function
int main() {
    struct Graph *graph = createGraph(6);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);
    addEdge(graph, 4, 5);

    printGraph(graph);

    return 0;
}