//FormAI DATASET v1.0 Category: Graph representation ; Style: medieval
#include <stdio.h>

int main() {
    int n, i, j, k;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    int graph[n][n];

    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            graph[i][j] = 0;
        }
    }

    printf("\nEnter the number of edges: ");
    scanf("%d", &k);

    int u, v;

    for(i = 0; i < k; i++) {
        printf("\nEnter the vertices for edge %d: ", i+1);
        scanf("%d%d", &u, &v);
        graph[u-1][v-1] = 1;
    }

    printf("\nMedieval Graph:");
    for(i = 0; i < n; i++) {
        printf("\n\t%d - ", i+1);
        for(j = 0; j < n; j++) {
            if(graph[i][j] == 1) {
                printf("|_");
            } else {
                printf("  ");
            }
        }
        printf("|");
    }

    return 0;
}