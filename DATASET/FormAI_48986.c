//FormAI DATASET v1.0 Category: Graph representation ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node in the graph
struct GraphNode {
    int val;
    struct GraphNode* next;
};

// Utility function to create a new node
struct GraphNode* createNode(int val) {
    struct GraphNode* newNode = (struct GraphNode*) malloc(sizeof(struct GraphNode));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

// Utility function to add an edge to the graph
void addEdge(struct GraphNode* graph[], int src, int dest) {
    struct GraphNode* newNode = createNode(dest);
    newNode->next = graph[src];
    graph[src] = newNode;

    newNode = createNode(src);
    newNode->next = graph[dest];
    graph[dest] = newNode;
}

// Utility function to print the graph
void printGraph(struct GraphNode* graph[], int n) {
    int i;
    for(i = 0; i < n; i++) {
        printf("Adjacency list of vertex %d\n", i);
        struct GraphNode* temp = graph[i];
        while(temp) {
            printf("%d -> ", temp->val);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

int main() {
    int n = 5; // number of vertices in the graph
    struct GraphNode* graph[n];
    int i;
    for(i = 0; i < n; i++) {
        graph[i] = NULL;
    }

    // Add edges to the graph
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);

    // Print the graph
    printGraph(graph, n);

    return 0;
}