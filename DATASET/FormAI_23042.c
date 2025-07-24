//FormAI DATASET v1.0 Category: Graph representation ; Style: Alan Touring
// Alan Turing Style C Program for Graph Representation
#include<stdio.h>
#include<stdlib.h>
#define MAX 50

// Defining the Adjacency Matrix
int adj[MAX][MAX];

// Helper function to initialize the adjacency matrix
void initialize() {
    int i, j;
    for(i=0; i<MAX; i++) {
        for(j=0; j<MAX; j++) {
            adj[i][j] = 0;
        }
    }
}

// Function to add edges to the adjacency matrix
void addEdge(int v1, int v2) {
    adj[v1][v2] = 1;
    adj[v2][v1] = 1;
}

// Function to print the adjacency matrix
void printAdjMatrix(int n) {
    int i, j;
    printf("\n The Adjacency Matrix is: \n\n");
    for(i=0; i<n; i++) {
        for(j=0; j<n; j++) {
            printf(" %d\t", adj[i][j]);
        }
        printf("\n");
    }
}

// Main function to operate on the graph
int main() {
    // Defining the vertices of the graph
    int n = 6;
    int vertices[] = {0, 1, 2, 3, 4, 5};

    // Initializing the adjacency matrix
    initialize();

    // Adding edges to the graph
    addEdge(0, 1);
    addEdge(0, 2);
    addEdge(1, 3);
    addEdge(2, 4);
    addEdge(3, 5);
    addEdge(4, 5);

    // Printing the adjacency matrix
    printAdjMatrix(n);

    return 0;
}