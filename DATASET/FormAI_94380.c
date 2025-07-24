//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: statistical
#include <stdio.h>
#include <stdlib.h>

/* Define the number of nodes and edges in the graph */
#define N 6
#define E 8

/* Define the adjacency matrix */
int adj_matrix[N][N] = {
    {0, 1, 1, 1, 0, 0},
    {1, 0, 1, 0, 1, 1},
    {1, 1, 0, 1, 0, 1},
    {1, 0, 1, 0, 1, 0},
    {0, 1, 0, 1, 0, 1},
    {0, 1, 1, 0, 1, 0}
};

/* Define the colors */
char colors[4] = {'R', 'G', 'B', 'Y'};

/* Define the color of each node */
char node_color[N];

/* Check if the given color can be assigned to the node */
int is_safe(int node, char color) {
    /* Check if any adjacent node has the same color */
    for (int i = 0; i < N; i++) {
        if (adj_matrix[node][i] && node_color[i] == color) {
            return 0;
        }
    }
    return 1;
}

/* Assign colors to the nodes */
int graph_coloring(int node) {
    /* Check if all the nodes have been assigned colors */
    if (node == N) {
        return 1;
    }
    /* Assign a color to the node */
    for (int i = 0; i < 4; i++) {
        if (is_safe(node, colors[i])) {
            node_color[node] = colors[i];
            /* Recursively assign colors to the remaining nodes */
            if (graph_coloring(node + 1)) {
                return 1;
            }
            /* Backtrack and try a different color */
            node_color[node] = 0;
        }
    }
    return 0;
}

/* Print the adjacency matrix and the node colors */
void print_graph() {
    printf("Adjacency Matrix:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", adj_matrix[i][j]);
        }
        printf("\n");
    }
    printf("\nNode Colors:\n");
    for (int i = 0; i < N; i++) {
        printf("%c ", node_color[i]);
    }
    printf("\n");
}

int main() {
    /* Assign colors to the graph */
    if (graph_coloring(0)) {
        /* Print the adjacency matrix and the node colors */
        print_graph();
    } else {
        /* No valid coloring found */
        printf("No valid coloring found.\n");
    }
    return 0;
}