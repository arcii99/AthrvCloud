//FormAI DATASET v1.0 Category: Graph representation ; Style: authentic
#include <stdio.h>

#define MAX_VERTICES 10

int graph[MAX_VERTICES][MAX_VERTICES];

int main() {
    int num_vertices, num_edges, i, j, vertex, edge;
    
    // Get input for number of vertices and edges
    printf("Enter the number of vertices: ");
    scanf("%d", &num_vertices);
    printf("Enter the number of edges: ");
    scanf("%d", &num_edges);
    
    // Initialize graph to zeros
    for (i = 0; i < MAX_VERTICES; i++) {
        for (j = 0; j < MAX_VERTICES; j++) {
            graph[i][j] = 0;
        }
    }
    
    // Get input for edges and update graph
    for (i = 0; i < num_edges; i++) {
        printf("Enter edge %d: ", i+1);
        scanf("%d %d", &vertex, &edge);
        graph[vertex][edge] = 1;
        graph[edge][vertex] = 1;
    }
    
    // Print out the graph
    printf("Graph representation:\n");
    for (i = 0; i < num_vertices; i++) {
        for (j = 0; j < num_vertices; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}