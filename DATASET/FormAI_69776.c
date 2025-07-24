//FormAI DATASET v1.0 Category: Graph representation ; Style: interoperable
#include <stdio.h>

int main() {
    int n;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    int adjMatrix[n][n];

    printf("Enter the adjacency matrix:\n");
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            scanf("%d", &adjMatrix[i][j]);
        }
    }

    printf("\nAdjacency matrix:\n");
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            printf("%d ", adjMatrix[i][j]);
        }
        printf("\n");
    }

    printf("\nGraph representation:\n");
    printf("Vertices: ");
    for (int i=0; i<n; i++) {
        printf("%d ", i);
    }

    printf("\nEdges: ");
    for (int i=0; i<n; i++) {
        for (int j=i; j<n; j++) {
            if (adjMatrix[i][j] == 1) {
                printf("(%d,%d) ", i, j);
            }
        }
    }

    return 0;
}