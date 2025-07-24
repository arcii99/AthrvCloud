//FormAI DATASET v1.0 Category: Graph representation ; Style: sophisticated
#include <stdio.h>

#define MAX_VERTICES 10 // Maximum number of vertices
#define MAX_EDGES 15 // Maximum number of edges

int graph[MAX_VERTICES][MAX_VERTICES] = {0}; // Initializing the graph

// Function to add an edge to the graph
void addEdge(int v1, int v2, int cost) {
    graph[v1][v2] = cost;
}

// Function to print the graph
void printGraph(int vertices) {
    printf("The graph is:\n");
    for(int i = 0; i < vertices; i++) {
        for(int j = 0; j < vertices; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int vertices, edges;
    printf("Enter the number of vertices (max 10): ");
    scanf("%d", &vertices);
    printf("Enter the number of edges (max 15): ");
    scanf("%d", &edges);
    for(int i = 0; i < edges; i++) {
        int v1, v2, cost;
        printf("Enter edge %d (vertex1 vertex2 cost): ", i+1);
        scanf("%d %d %d", &v1, &v2, &cost);
        addEdge(v1, v2, cost);
    }
    printGraph(vertices);
    return 0;
}