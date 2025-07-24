//FormAI DATASET v1.0 Category: Graph representation ; Style: happy
#include <stdio.h>

int main() {
    int n;
    printf("How many happy vertices do you want to have? ");
    scanf("%d", &n);
    printf("\nAwesome! Let's create a happy graph with %d vertices.\n", n);

    int adjMatrix[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            adjMatrix[i][j] = 0;
        }
    }

    printf("\nTime to add some happy edges!\n");
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            printf("Is there an edge between vertex %d and vertex %d? (1 for YES, 0 for NO): ", i, j);
            scanf("%d", &adjMatrix[i][j]);
            adjMatrix[j][i] = adjMatrix[i][j]; // update the opposite entry
        }
    }

    printf("\nGreat job! Here's the happy graph you created:\n");
    printf("  ");
    for (int i = 0; i < n; i++) {
        printf("%d ", i);
    }
    printf("\n");

    for (int i = 0; i < n; i++) {
        printf("%d ", i);
        for (int j = 0; j < n; j++) {
            printf("%d ", adjMatrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}