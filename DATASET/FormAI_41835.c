//FormAI DATASET v1.0 Category: Graph representation ; Style: Ken Thompson
#include<stdio.h>

// Ken Thompson style C program to represent a graph

int main() {
    int n, i, j;
    printf("Enter total number of nodes: ");
    scanf("%d", &n);

    int graph[n][n];

    // Initializing all elements of matrix as 0
    for(i=0; i<n; i++) {
        for(j=0; j<n; j++) {
            graph[i][j] = 0;
        }
    }

    // Creating edges between nodes
    printf("Enter number of edges to create: ");
    int edges;
    scanf("%d", &edges);

    for(i=0; i<edges; i++) {
        int a, b;
        printf("Enter edge %d: ", i+1);
        scanf("%d %d", &a, &b);
        graph[a-1][b-1] = 1;
        graph[b-1][a-1] = 1;
    }

    // Displaying graph
    printf("\nGraph:\n\n");

    for(i=0; i<n; i++) {
        for(j=0; j<n; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }

    return 0;
}