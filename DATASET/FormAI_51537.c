//FormAI DATASET v1.0 Category: Graph representation ; Style: innovative
#include <stdio.h>

int main() {
    int n;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    int adjMatrix[n][n];
    printf("Enter the adjacency matrix: \n");
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            scanf("%d", &adjMatrix[i][j]);
        }
    }

    printf("\nGraph Representation:\n\n");
    printf("    ");
    for(int i=0; i<n; i++) {
        printf("V%d ", i+1);
    }
    printf("\n   ");
    for(int i=0; i<n; i++) {
        printf("---");
    }
    printf("\n");
    for(int i=0; i<n; i++) {
        printf("V%d| ", i+1);
        for(int j=0; j<n; j++) {
            printf("%d  ", adjMatrix[i][j]);
        }
        printf("\n");
    }
    return 0;
}