//FormAI DATASET v1.0 Category: Graph representation ; Style: automated
#include <stdio.h>

#define MAX_NODES 20 // maximum number of vertices
#define MAX_EDGES 30 // maximum number of edges

// structure to represent an edge
typedef struct edge {
    int from, to;
} Edge;

// structure to represent a graph
typedef struct graph {
    int n; // number of vertices in the graph
    int m; // number of edges in the graph
    Edge edges[MAX_EDGES]; // array of edges in the graph
} Graph;

/**
 * Function to initialize a graph with n vertices and m edges
 * @param n: number of vertices
 * @param m: number of edges
 * @return: the initialized graph
 */
Graph init_graph(int n, int m) {
    Graph g = {n, m};
    return g;
}

/**
 * Function to add an edge to a graph
 * @param g: the graph
 * @param from: the vertex the edge is from
 * @param to: the vertex the edge is to
 */
void add_edge(Graph *g, int from, int to) {
    g->edges[g->m++] = (Edge) {from, to};
}

/**
 * Function to print a graph as an adjacency matrix
 * @param g: the graph
 */
void print_graph_as_matrix(Graph *g) {
    int matrix[MAX_NODES][MAX_NODES] = {0};

    // fill in the matrix
    for (int i = 0; i < g->m; i++) {
        matrix[g->edges[i].from][g->edges[i].to] = 1;
        matrix[g->edges[i].to][g->edges[i].from] = 1;
    }

    // print the matrix
    printf("Adjacency matrix representation of the graph:\n\n");
    for (int i = 0; i < g->n; i++) {
        for (int j = 0; j < g->n; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

/**
 * Function to print a graph as an adjacency list
 * @param g: the graph
 */
void print_graph_as_list(Graph *g) {
    printf("Adjacency list representation of the graph:\n\n");
    for (int i = 0; i < g->n; i++) {
        printf("%d:", i);
        for (int j = 0; j < g->m; j++) {
            if (g->edges[j].from == i) {
                printf(" %d", g->edges[j].to);
            } else if (g->edges[j].to == i) {
                printf(" %d", g->edges[j].from);
            }
        }
        printf("\n");
    }
}

int main() {
    Graph g = init_graph(5, 6);
    add_edge(&g, 0, 1);
    add_edge(&g, 0, 2);
    add_edge(&g, 0, 3);
    add_edge(&g, 1, 2);
    add_edge(&g, 1, 4);
    add_edge(&g, 2, 4);

    print_graph_as_matrix(&g);
    printf("\n");
    print_graph_as_list(&g);

    return 0;
}