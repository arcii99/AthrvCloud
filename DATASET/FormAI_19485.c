//FormAI DATASET v1.0 Category: Graph representation ; Style: shocked
#include <stdio.h>
#define MAX_VERTICES 100

int adj_matrix[MAX_VERTICES][MAX_VERTICES];
int visited[MAX_VERTICES];

int num_vertices = 0;

void add_edge(int start, int end) {
    adj_matrix[start][end] = 1;
    adj_matrix[end][start] = 1;
}

void dfs(int vertex) {
    visited[vertex] = 1;
    printf("%d ", vertex);
    for (int i = 0; i < num_vertices; ++i) {
        if (adj_matrix[vertex][i] && !visited[i]) {
            dfs(i);
        }
    }
}

int main() {
    printf("Enter the number of vertices: ");
    scanf("%d", &num_vertices);

    printf("Enter the edges as (start end) pairs (negative number to exit):\n");
    int start, end;
    scanf("%d %d", &start, &end);
    while (start >= 0 && end >= 0 && start < num_vertices && end < num_vertices) {
        add_edge(start, end);
        scanf("%d %d", &start, &end);
    }

    printf("DFS Traversal:\n");
    for (int i = 0; i < num_vertices; ++i) {
        if (!visited[i]) {
            dfs(i);
        }
    }
    
    return 0;
}