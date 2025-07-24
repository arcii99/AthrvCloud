//FormAI DATASET v1.0 Category: Graph representation ; Style: authentic
#include <stdio.h>

#define MAX_VERTICES 10

void add_edge(int adjacency_matrix[][MAX_VERTICES], int start_vertex, int end_vertex) {
    adjacency_matrix[start_vertex][end_vertex] = 1;
}

void print_graph(int adjacency_matrix[][MAX_VERTICES], int num_vertices) {
    int i, j;

    printf("\n");

    for (i = 0; i < num_vertices; i++) {
        for (j = 0; j < num_vertices; j++) {
            printf("%d ", adjacency_matrix[i][j]);
        }

        printf("\n");
    }
}

int main() {
    int adjacency_matrix[MAX_VERTICES][MAX_VERTICES] = {0};
    int num_vertices, num_edges, start_vertex, end_vertex, i;

    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &num_vertices);

    printf("\nEnter the number of edges in the graph: ");
    scanf("%d", &num_edges);

    printf("\nEnter the edges (using vertex indices) in the graph one by one:\n");

    for (i = 0; i < num_edges; i++) {
        scanf("%d %d", &start_vertex, &end_vertex);
        add_edge(adjacency_matrix, start_vertex, end_vertex);
    }

    printf("\nThe graph adjacency matrix:\n");
    print_graph(adjacency_matrix, num_vertices);

    return 0;
}