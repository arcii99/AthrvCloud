//FormAI DATASET v1.0 Category: Graph representation ; Style: immersive
#include <stdio.h>
#define MAX_VERTICES 100

int adjMatrix[MAX_VERTICES][MAX_VERTICES];
int n;

void add_edge(int u, int v) {
    adjMatrix[u][v] = 1;
    adjMatrix[v][u] = 1;
}

void display_matrix() {
    int i, j;

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%d ", adjMatrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int i, j, edges, u, v;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    for (i = 0; i < edges; i++) {
        printf("Enter edge (u, v): ");
        scanf("%d%d", &u, &v);
        add_edge(u, v);
    }

    printf("\nAdjacency Matrix:\n");
    display_matrix();

    return 0;
}