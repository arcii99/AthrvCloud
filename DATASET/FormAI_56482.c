//FormAI DATASET v1.0 Category: Graph representation ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>

#define MAX_ROWS 10
#define MAX_COLS 10

// Structure to represent a cell in the graph
typedef struct cell {
    int row;
    int col;
} Cell;

// Structure to represent a graph
typedef struct graph {
    int num_nodes;
    Cell nodes[MAX_ROWS * MAX_COLS];
    int adj_matrix[MAX_ROWS * MAX_COLS][MAX_ROWS * MAX_COLS];
} Graph;

// Initialize the graph
void init_graph(Graph *g) {
    g->num_nodes = 0;
    for (int i = 0; i < MAX_ROWS * MAX_COLS; i++) {
        for (int j = 0; j < MAX_ROWS * MAX_COLS; j++) {
            g->adj_matrix[i][j] = 0;
        }
    }
}

// Add a node to the graph
void add_node(Graph *g, Cell c) {
    g->nodes[g->num_nodes] = c;
    g->num_nodes++;
}

// Add an edge to the graph
void add_edge(Graph *g, Cell c1, Cell c2) {
    int i = -1, j = -1;
    for (int k = 0; k < g->num_nodes; k++) {
        if (g->nodes[k].row == c1.row && g->nodes[k].col == c1.col) {
            i = k;
        }
        if (g->nodes[k].row == c2.row && g->nodes[k].col == c2.col) {
            j = k;
        }
        if (i != -1 && j != -1) {
            break;
        }
    }
    if (i == -1 || j == -1) {
        printf("Error: invalid nodes\n");
        return;
    }
    g->adj_matrix[i][j] = 1;
    g->adj_matrix[j][i] = 1;
}

// Print the graph
void print_graph(Graph g) {
    for (int i = 0; i < g.num_nodes; i++) {
        printf("(%d, %d): ", g.nodes[i].row, g.nodes[i].col);
        for (int j = 0; j < g.num_nodes; j++) {
            if (g.adj_matrix[i][j] == 1) {
                printf("(%d, %d) ", g.nodes[j].row, g.nodes[j].col);
            }
        }
        printf("\n");
    }
}

int main() {
    Graph g;
    init_graph(&g);

    // Add nodes to the graph
    add_node(&g, (Cell){0, 0});
    add_node(&g, (Cell){0, 1});
    add_node(&g, (Cell){1, 0});
    add_node(&g, (Cell){1, 1});

    // Add edges to the graph
    add_edge(&g, (Cell){0, 0}, (Cell){0, 1});
    add_edge(&g, (Cell){0, 0}, (Cell){1, 0});
    add_edge(&g, (Cell){0, 1}, (Cell){1, 1});
    add_edge(&g, (Cell){1, 0}, (Cell){1, 1});

    // Print the graph
    print_graph(g);
    
    return 0;
}