//FormAI DATASET v1.0 Category: Graph representation ; Style: detailed
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 10

/* Function to print the adjacency matrix */
void print_graph(int graph[][MAX_VERTICES], int vertices) {
    printf("\nAdjacency Matrix: \n");
    for(int i = 0; i < vertices; i++) {
        for(int j = 0; j < vertices; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
}

/* Add an edge between vertices */
void add_edge(int graph[][MAX_VERTICES], int vertex1, int vertex2) {
    graph[vertex1][vertex2] = 1;
    graph[vertex2][vertex1] = 1; // Assuming undirected graph
}

int main() {
    int num_vertices, num_edges, vertex1, vertex2;
    int graph[MAX_VERTICES][MAX_VERTICES] = {0}; // Initializing all values as 0

    printf("\nEnter the number of vertices: ");
    scanf("%d", &num_vertices);

    printf("Enter the number of edges: ");
    scanf("%d", &num_edges);

    printf("\nEnter the edges (vertex1 vertex2): \n");
    for(int i = 0; i < num_edges; i++) {
        scanf("%d %d", &vertex1, &vertex2);
        add_edge(graph, vertex1, vertex2);
    }

    print_graph(graph, num_vertices);

    return 0;
}