//FormAI DATASET v1.0 Category: Graph representation ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>

int main() {
    int vertices, edges, i, j, source, destination, weight;

    printf("Welcome to the Graph Representation Program!\n\n");
    printf("Please enter the number of vertices: ");
    scanf("%d", &vertices);
    printf("Please enter the number of edges: ");
    scanf("%d", &edges);

    int graph[vertices][vertices];

    // Initialize all elements in the graph as 0
    for (i = 0; i < vertices; i++) {
        for (j = 0; j < vertices; j++) {
            graph[i][j] = 0;
        }
    }

    // Ask for user input to create the graph
    for (i = 0; i < edges; i++) {
        printf("\nPlease enter the details for edge %d:\n", i+1);
        printf("Source: ");
        scanf("%d", &source);
        printf("Destination: ");
        scanf("%d", &destination);
        printf("Weight: ");
        scanf("%d", &weight);

        // Validate input
        if (source >= 1 && source <= vertices && destination >= 1 && destination <= vertices) {
            graph[source-1][destination-1] = weight;
            graph[destination-1][source-1] = weight;
        }
        else {
            printf("\nInvalid input. Please try again.\n");
            i--;
        }
    }

    // Print the graph in an adjacency matrix form
    printf("\n\nThe graph is represented as an adjacency matrix as follows:\n\n");
    printf("       ");
    for (i = 0; i < vertices; i++) {
        printf("%5d", i+1);
    }
    printf("\n");
    printf("      --");
    for (i = 0; i < vertices; i++) {
        printf("-----");
    }
    printf("\n");
    for (i = 0; i < vertices; i++) {
        printf("%5d | ", i+1);
        for (j = 0; j < vertices; j++) {
            printf("%5d", graph[i][j]);
        }
        printf("\n");
    }

    printf("\nThank you for using this program!\n");

    return 0;
}