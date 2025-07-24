//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: intelligent
#include <stdio.h>
#define MAX 10

int graph[MAX][MAX], visited[MAX], n;

void DFS(int m) {
    int j;
    visited[m] = 1;
    printf("-> %d ", m + 1);
    for (j = 0; j < n; j++)
        if (!visited[j] && graph[m][j] == 1)
            DFS(j);
}

int main() {
    int i, j, start;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    printf("\nEnter the adjacency matrix:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);
    printf("\nEnter the starting node: ");
    scanf("%d", &start);
    start--;
    for (i = 0; i < n; i++)
        visited[i] = 0;
    printf("\nDFS traversal: ");
    DFS(start);
    printf("\n");
    return 0;
}