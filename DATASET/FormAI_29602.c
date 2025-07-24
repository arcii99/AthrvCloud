//FormAI DATASET v1.0 Category: Graph representation ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>

// Node structure for the graph
struct Node {
    int data;
    struct Node* next;
};

// Function to add an edge to the graph
void addEdge(struct Node* adj[], int src, int dest) {
    // Create a new node for the destination vertex
    struct Node* destNode = (struct Node*) malloc(sizeof(struct Node));
    destNode->data = dest;
    destNode->next = NULL;
    
    // If the source vertex is not present in the graph
    // Create a new node for the source vertex and add the destination vertex to its adjacency list
    if(adj[src] == NULL) {
        struct Node* srcNode = (struct Node*) malloc(sizeof(struct Node));
        srcNode->data = src;
        srcNode->next = destNode;
        adj[src] = srcNode;
    }
    // If the source vertex is present in the graph
    // Add the destination vertex to its adjacency list
    else {
        struct Node* curr = adj[src];
        while(curr->next != NULL) {
            curr = curr->next;
        }
        curr->next = destNode;
    }
}

// Function to print the graph
void printGraph(struct Node* adj[], int vertices) {
    printf("Graph:\n");
    for(int i=0; i<vertices; i++) {
        struct Node* curr = adj[i];
        printf("%d -> ", i);
        while(curr != NULL) {
            printf("%d ", curr->data);
            curr = curr->next;
        }
        printf("\n");
    }
}

// Main function
int main() {
    // Initialize the graph vertices and adjacency list with NULL values
    int vertices = 6;
    struct Node* adj[vertices];
    for(int i=0; i<vertices; i++) {
        adj[i] = NULL;
    }
    
    // Add edges to the graph
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 1, 4);
    addEdge(adj, 2, 4);
    addEdge(adj, 3, 5);
    addEdge(adj, 4, 5);
    
    // Print the graph
    printGraph(adj, vertices);
    
    return 0;
}