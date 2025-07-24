//FormAI DATASET v1.0 Category: Graph representation ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 10

// structure for our adjacency matrix
struct Graph {
    int matrix[MAX_VERTICES][MAX_VERTICES];
    int num_vertices;
};

// function to initialize the graph with 0 values
void init_graph(struct Graph* g) {
    int i, j;
    for(i = 0; i < MAX_VERTICES; i++) {
        for(j = 0; j < MAX_VERTICES; j++) {
            g->matrix[i][j] = 0;
        }
    }
    g->num_vertices = 0;
}

// function to add a vertex to the graph
void add_vertex(struct Graph* g) {
    if(g->num_vertices < MAX_VERTICES) {
        g->num_vertices++;
    } else {
        printf("Error: cannot add vertex, graph capacity reached\n");
    }
}

// function to add an edge to the graph
void add_edge(struct Graph* g, int source, int dest) {
    if(source < g->num_vertices && dest < g->num_vertices) {
        g->matrix[source][dest] = 1;
        g->matrix[dest][source] = 1; // undirected graph, so we need to add edge in both directions
    } else {
        printf("Error: cannot add edge, invalid source/destination vertex\n");
    }
}

// function to print the graph as an adjacency matrix
void print_graph(struct Graph* g) {
    int i, j;
    printf("Graph representation:\n");
    for(i = 0; i < g->num_vertices; i++) {
        for(j = 0; j < g->num_vertices; j++) {
            printf("%d ", g->matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    // create and initialize the graph
    struct Graph g;
    init_graph(&g);

    // add some vertices
    add_vertex(&g);
    add_vertex(&g);
    add_vertex(&g);
    add_vertex(&g);

    // add some edges
    add_edge(&g, 0, 1);
    add_edge(&g, 0, 3);
    add_edge(&g, 1, 2);
    add_edge(&g, 2, 3);

    // print the graph
    print_graph(&g);

    return 0;
}