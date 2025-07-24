//FormAI DATASET v1.0 Category: Graph representation ; Style: Linus Torvalds
/* This is a simple program to represent a graph in C language using adjacency matrix */
#include <stdio.h>

int main() {
    int vertices, edges, i, j;
    printf("Enter number of vertices: ");
    scanf("%d", &vertices);
    printf("Enter number of edges: ");
    scanf("%d", &edges);

    int graph[vertices][vertices]; // Adjacency matrix to store graph

    // Assigning all the values in matrix to 0
    for(i=0; i<vertices; i++) {
        for(j=0; j<vertices; j++) {
            graph[i][j] = 0;
        }
    }

    // Setting the values in the matrix for edge connections
    for(i=0; i<edges; i++) {
        int from, to;
        printf("Enter from and to vertex for edge %d: ", i+1);
        scanf("%d %d", &from, &to);
        graph[from-1][to-1] = 1; // Setting the connection between two vertices
        graph[to-1][from-1] = 1; // Since the graph is undirected, setting connection both ways
    }

    // Printing the adjacency matrix
    for(i=0; i<vertices; i++) {
        printf("\n");
        for(j=0; j<vertices; j++) {
            printf("%d ", graph[i][j]);
        }
    }

    return 0;
}