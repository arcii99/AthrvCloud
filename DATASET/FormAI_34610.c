//FormAI DATASET v1.0 Category: Graph representation ; Style: inquisitive
#include<stdio.h>

/* Structure to represent a node in the graph */
struct Node {
    int data;
    struct Node* next;
};

/* Structure to represent the graph */
struct Graph {
    int V; // number of vertices
    struct Node** adjList; // array of adjacency lists
};

/* Function to create a new node with given data */
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

/* Function to create a graph with V vertices */
struct Graph* createGraph(int V) {
    struct Graph* graph = (struct Graph*) malloc(sizeof(struct Graph));
    graph->V = V;
    graph->adjList = (struct Node**) malloc(V * sizeof(struct Node*));

    // Initialize each adjacency list as empty by making it NULL
    for (int i = 0; i < V; i++)
        graph->adjList[i] = NULL;

    return graph;
}

/* Function to add an edge to an undirected graph */
void addEdge(struct Graph* graph, int src, int dest) {
    // Add an edge from src to dest
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjList[src];
    graph->adjList[src] = newNode;

    // Add an edge from dest to src
    newNode = createNode(src);
    newNode->next = graph->adjList[dest];
    graph->adjList[dest] = newNode;
}

/* Function to print the adjacency list of the graph */
void printGraph(struct Graph* graph) {
    for (int i = 0; i < graph->V; i++) {
        struct Node* temp = graph->adjList[i];
        printf("\nAdjacency list of vertex %d: ", i);
        while (temp) {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        printf("NULL");
    }
}

/* Main function */
int main() {
    // Create a sample graph with 5 vertices
    int V = 5;
    struct Graph* graph = createGraph(V);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);

    // Print the graph
    printf("Graph representation using adjacency list:\n");
    printGraph(graph);

    return 0;
}