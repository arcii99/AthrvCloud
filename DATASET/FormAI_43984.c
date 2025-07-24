//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NODES 20
#define MAX_EDGES 50
#define MAX_COLORS 5

typedef struct node {
    int id;
    int color;
} Node;

int main() {
    Node nodes[MAX_NODES];
    int edges[MAX_EDGES][2];
    int adjacency_matrix[MAX_NODES][MAX_NODES];
    int num_nodes, num_edges, num_colors;
    int i, j, k;

    // Initialize random seed
    srand(time(NULL));

    // Generate random number of nodes, edges, and colors
    num_nodes = rand() % MAX_NODES + 1;
    num_edges = rand() % MAX_EDGES + 1;
    num_colors = rand() % MAX_COLORS + 1;

    // Initialize nodes
    for (i = 0; i < num_nodes; i++) {
        nodes[i].id = i;
        nodes[i].color = 0; // 0 indicates no color
    }

    // Initialize adjacency matrix to 0
    for (i = 0; i < num_nodes; i++) {
        for (j = 0; j < num_nodes; j++) {
            adjacency_matrix[i][j] = 0;
        }
    }

    // Generate random edges
    for (i = 0; i < num_edges; i++) {
        edges[i][0] = rand() % num_nodes;
        edges[i][1] = rand() % num_nodes;

        // Check if edge already exists
        for (j = 0; j < i; j++) {
            if ((edges[i][0] == edges[j][0] && edges[i][1] == edges[j][1]) ||
                (edges[i][0] == edges[j][1] && edges[i][1] == edges[j][0])) {
                i--; // Edge already exists, generate another one
                break;
            }
        }
    }

    // Update adjacency matrix based on edges
    for (i = 0; i < num_edges; i++) {
        adjacency_matrix[edges[i][0]][edges[i][1]] = 1;
        adjacency_matrix[edges[i][1]][edges[i][0]] = 1;
    }

    // Print graph representation
    printf("Graph representation:\n");
    for (i = 0; i < num_nodes; i++) {
        printf("Node %d: ", i);
        for (j = 0; j < num_nodes; j++) {
            if (adjacency_matrix[i][j]) {
                printf("%d ", j);
            }
        }
        printf("\n");
    }

    // Color the graph
    for (i = 0; i < num_nodes; i++) {
        int used_colors[MAX_COLORS] = {0};

        // Check colors used by neighboring nodes
        for (j = 0; j < num_nodes; j++) {
            if (adjacency_matrix[i][j] && nodes[j].color > 0) {
                used_colors[nodes[j].color - 1] = 1;
            }
        }

        // Assign a color not used by neighboring nodes
        for (j = 0; j < num_colors; j++) {
            if (!used_colors[j]) {
                nodes[i].color = j + 1;
                break;
            }
        }
    }

    // Print node colors
    printf("Node colors:\n");
    for (i = 0; i < num_nodes; i++) {
        printf("Node %d: %d\n", i, nodes[i].color);
    }

    return 0;
}