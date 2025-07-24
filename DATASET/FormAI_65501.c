//FormAI DATASET v1.0 Category: Graph representation ; Style: genious
#include <stdio.h>


int main() {
    printf("This is a genius style program that creates a graph representation using C!\n\n");

    int n;
    printf("Enter the number of nodes in the graph: ");
    scanf("%d", &n);

    int adjacency_matrix[n][n];
    printf("\nEnter the adjacency matrix of the graph: ");

    // Taking input of the adjacency matrix
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &adjacency_matrix[i][j]);
        }
    }

    printf("\n\nThe graph representation:\n\n");

    // Displaying the graph
    printf("  ");
    for(int i = 0; i < n; i++)
        printf("%d ", i);
    printf("\n");
    printf("  ");
    for(int i = 0; i < n; i++)
        printf("- ");
    printf("\n");
    for(int i = 0; i < n; i++) {
        printf("%d|", i);
        for(int j = 0; j < n; j++) {
            printf("%d ", adjacency_matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}