//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100

int adj_matrix[MAX_NODES][MAX_NODES];
int visited[MAX_NODES];
int node_count;

void dfs(int node) {
    printf("%d ", node);
    visited[node] = 1;
    for (int i = 0; i < node_count; i++) {
        if (adj_matrix[node][i] == 1 && visited[i] == 0) {
            dfs(i);
        }
    }
}

int main() {
    printf("Enter number of nodes: ");
    scanf("%d", &node_count);

    for (int i = 0; i < node_count; i++) {
        visited[i] = 0;
        for (int j = 0; j < node_count; j++) {
            adj_matrix[i][j] = 0;
        }
    }

    printf("Enter adjacency matrix...\n");
    for (int i = 0; i < node_count; i++) {
        for (int j = 0; j < node_count; j++) {
            scanf("%d", &adj_matrix[i][j]);
        }
    }

    printf("DFS traversal: ");
    dfs(0);

    return 0;
}