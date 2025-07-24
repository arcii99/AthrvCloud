//FormAI DATASET v1.0 Category: Graph representation ; Style: romantic
#include<stdio.h>

int main() {
    int nodes, edges;

    printf("My love, how many nodes are there in the graph of our love?\n");
    scanf("%d", &nodes);

    printf("And how many edges connect our hearts?\n");
    scanf("%d", &edges);

    int matrix[nodes][nodes];
    int u, v;

    // Initialize the matrix with zeros
    for(int i = 0; i < nodes; i++) {
        for(int j = 0; j < nodes; j++) {
            matrix[i][j] = 0;
        }
    }

    printf("\nMy love, please tell me which nodes are connected by each edge.\n");

    // Loop through each edge and store it in the matrix
    for(int i = 1; i <= edges; i++) {
        printf("Edge %d: ", i);
        scanf("%d %d", &u, &v);
        matrix[u][v] = 1;
        matrix[v][u] = 1;
    }

    printf("\nMy sweet love, here is the matrix representation of our love graph:\n\n");

    // Print the matrix
    for(int i = 0; i < nodes; i++) {
        for(int j = 0; j < nodes; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    printf("\nMy dearest love, this is just a small representation of our infinite love that grows stronger every day. I love you with all my heart <3\n");

    return 0;
}