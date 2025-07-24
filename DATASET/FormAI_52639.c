//FormAI DATASET v1.0 Category: Graph representation ; Style: authentic
#include <stdio.h>

// function to create a graph with n nodes
void createGraph(int n) {
    int i, j, adjMatrix[n][n];
    printf("Enter the adjacency matrix of the graph:\n");
    // taking input of the adjacency matrix
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &adjMatrix[i][j]);
        }
    }
    // printing the adjacency matrix
    printf("Adjacency matrix of the graph:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%d ", adjMatrix[i][j]);
        }
        printf("\n");
    }
    // creating a graph using the adjacency matrix
    printf("Graph representation:\n");
    for (i = 0; i < n; i++) {
        printf("%d -> ", i+1);
        for (j = 0; j < n; j++) {
            if (adjMatrix[i][j] == 1) {
                printf("%d ", j+1);
            }
        }
        printf("\n");
    }
}

int main() {
    int n;
    printf("Enter the number of nodes in the graph: ");
    scanf("%d", &n);
    createGraph(n);
    return 0;
}