//FormAI DATASET v1.0 Category: Graph representation ; Style: shocked
#include <stdio.h>
#define MAX_NODES 100

int adj_matrix[MAX_NODES][MAX_NODES] = {0};
int visited[MAX_NODES] = {0};

int main() {
    int num_nodes, num_edges;
    printf("Enter number of nodes in the graph: ");
    scanf("%d", &num_nodes);
    printf("Enter number of edges in the graph: ");
    scanf("%d", &num_edges);

    printf("Enter the edges of the graph as pairs of integers (e.g. 1 2):\n");
    for (int i = 0; i < num_edges; i++) {
        int node1, node2;
        scanf("%d %d", &node1, &node2);
        adj_matrix[node1][node2] = 1;
        adj_matrix[node2][node1] = 1; // assuming undirected graph
    }

    printf("Adjacency Matrix:\n");
    for (int i = 0; i < num_nodes; i++) {
        for (int j = 0; j < num_nodes; j++) {
            printf("%d ", adj_matrix[i][j]);
        }
        printf("\n");
    }

    printf("DFS traversal starting from node 0: ");
    dfs(0, num_nodes);
    printf("\n");

    printf("BFS traversal starting from node 0: ");
    bfs(0, num_nodes);
    printf("\n");

    return 0;
}

void dfs(int node, int num_nodes) {
    printf("%d ", node);
    visited[node] = 1;
    for (int i = 0; i < num_nodes; i++) {
        if (adj_matrix[node][i] && !visited[i]) {
            dfs(i, num_nodes);
        }
    }
}

void bfs(int start_node, int num_nodes) {
    int q[MAX_NODES] = {start_node};
    int front = 0, rear = 1;
    visited[start_node] = 1;
    while (front != rear) {
        int node = q[front++];
        printf("%d ", node);
        for (int i = 0; i < num_nodes; i++) {
            if (adj_matrix[node][i] && !visited[i]) {
                q[rear++] = i;
                visited[i] = 1;
            }
        }
    }
}