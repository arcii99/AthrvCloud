//FormAI DATASET v1.0 Category: Graph representation ; Style: beginner-friendly
#include <stdio.h>

#define MAX_SIZE 100

int main() {
    int graph[MAX_SIZE][MAX_SIZE];
    int vertices, edges, i, j, source, destination;

    // initialize all edges to 0
    for(i = 0; i < MAX_SIZE; i++) {
      for(j = 0; j < MAX_SIZE; j++) {
        graph[i][j] = 0;
      }
    }

    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);

    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    // populate the graph
    for(i = 0; i < edges; i++) {
        printf("Enter edge %d (source, destination): ", i+1);
        scanf("%d %d", &source, &destination);

        graph[source][destination] = 1;
        graph[destination][source] = 1;
    }

    // print the adjacency matrix
    printf("\nAdjacency Matrix:\n");
    for(i = 0; i < vertices; i++) {
      for(j = 0; j < vertices; j++) {
        printf("%d ", graph[i][j]);
      }
      printf("\n");
    }

    return 0;
}