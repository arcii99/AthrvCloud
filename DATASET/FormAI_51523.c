//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>

#define ROWS 5
#define COLS 5

int graph[ROWS][COLS] = {
    {0, 1, 0, 1, 0},
    {1, 0, 1, 0, 1},
    {0, 1, 0, 1, 0},
    {1, 0, 1, 0, 1},
    {0, 1, 0, 1, 0},
};

int visited[ROWS];

void dfs(int node) {
    visited[node] = 1;
    printf("%d ", node);
    for (int i = 0; i < COLS; i++) {
        if (graph[node][i] && !visited[i]) {
            dfs(i);
        }
    }
}

int main() {
    // DFS Algorithm
    printf("DFS Algorithm:\n");
    dfs(0);

    // BFS Algorithm
    printf("\nBFS Algorithm:\n");
    int q[ROWS], head = 0, tail = 0;
    visited[0] = 1;
    q[tail++] = 0;
    while (head < tail) {
        int node = q[head++];
        printf("%d ", node);
        for (int i = 0; i < COLS; i++) {
            if (graph[node][i] && !visited[i]) {
                visited[i] = 1;
                q[tail++] = i;
            }
        }
    }

    return 0;
}