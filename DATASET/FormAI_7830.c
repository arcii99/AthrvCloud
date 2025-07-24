//FormAI DATASET v1.0 Category: Graph representation ; Style: grateful
#include <stdio.h>

#define MAX_NODES 10

void add_edge(int matrix[][MAX_NODES], int u, int v, int weight);
void print_graph(int matrix[][MAX_NODES], int num_nodes);

int main() {
    int matrix[MAX_NODES][MAX_NODES] = {0};
    int num_nodes, num_edges;

    printf("Enter the number of nodes: ");
    scanf("%d", &num_nodes);

    printf("Enter the number of edges: ");
    scanf("%d", &num_edges);

    for (int i = 0; i < num_edges; i++) {
        int u, v, weight;
        printf("Enter edge (u, v) and weight: ");
        scanf("%d%d%d", &u, &v, &weight);
        add_edge(matrix, u, v, weight);
    }

    printf("The graph is:\n");
    print_graph(matrix, num_nodes);

    return 0;
}

void add_edge(int matrix[][MAX_NODES], int u, int v, int weight) {
    matrix[u][v] = weight;
    matrix[v][u] = weight;
}

void print_graph(int matrix[][MAX_NODES], int num_nodes) {
    for (int i = 0; i < num_nodes; i++) {
        for (int j = 0; j < num_nodes; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}