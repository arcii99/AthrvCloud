//FormAI DATASET v1.0 Category: Graph representation ; Style: curious
#include <stdio.h>
#define MAX_VERTICES 10
int adjacency_matrix[MAX_VERTICES][MAX_VERTICES];

/* A curious function that generates a unique graph */
void generate_graph() {

    printf("Creating a curious graph...\n");

    // Generate random weights for vertices
    int vertex_weights[MAX_VERTICES];
    printf("Assigning random weights to vertices...\n");
    for (int i = 0; i < MAX_VERTICES; i++) {
        vertex_weights[i] = rand() % 10;
        printf("Vertex %d has weight %d\n", i, vertex_weights[i]);
    }

    // Generate unique connections between vertices
    printf("Connecting vertices in a curious way...\n");
    for (int i = 0; i < MAX_VERTICES; i++) {
        for (int j = 0; j < MAX_VERTICES; j++) {
            if (i == j) {
                adjacency_matrix[i][j] = 0;
            } else if (i % 2 == 0 && j % 2 == 0) {
                adjacency_matrix[i][j] = 1;
                printf("Vertex %d is connected to vertex %d with weight %d\n", i, j, vertex_weights[i]);
            } else if (i % 2 == 1 && j % 2 == 1) {
                adjacency_matrix[i][j] = 1;
                printf("Vertex %d is connected to vertex %d with weight %d\n", i, j, vertex_weights[i]);
            } else {
                adjacency_matrix[i][j] = 0;
            }
        }
    }
}

/* A function that prints the graph representation */
void print_graph() {

    printf("\nPrinting graph representation...\n\n");
    printf("   ");
    for (int i = 0; i < MAX_VERTICES; i++) {
        printf("%d  ", i);
    }
    printf("\n");
    for (int i = 0; i < MAX_VERTICES; i++) {
        printf("%d  ", i);
        for (int j = 0; j < MAX_VERTICES; j++) {
            printf("%d  ", adjacency_matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {

    // Generate and print graph
    generate_graph();
    print_graph();

    return 0;
}