//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100

int graph[MAX_NODES][MAX_NODES];
int visited[MAX_NODES];
int n;

void dfs(int node) {
    int i;
    printf("%d ", node);
    visited[node] = 1;
    for (i = 0; i < n; ++i) {
        if (graph[node][i] == 1 && !visited[i]) {
            dfs(i);
        }
    }
}

int main() {
    int i, j;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    printf("Enter the adjacency matrix:\n");
    for (i = 0; i < n; ++i) {
        for (j = 0; j < n; ++j) {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("\nThe network topology is:\n");
    for (i = 0; i < n; ++i) {
        if (!visited[i]) {
            dfs(i);
        }
    }
    printf("\n");

    return 0;
}