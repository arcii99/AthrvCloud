//FormAI DATASET v1.0 Category: Graph representation ; Style: configurable
#include <stdio.h>

#define MAX_VERTICES 100
#define MAX_REPRESENTATION 10

typedef int AdjacencyList[MAX_VERTICES];

typedef struct {
    AdjacencyList list;
    int num_neighbors;
} Vertex;

typedef struct {
    Vertex vertices[MAX_VERTICES];
    int num_vertices;
} Graph;

typedef enum {
    MATRIX,
    LIST
} Representation;

void print_matrix(Graph *graph) {
    int i, j;
    printf("GRAPH REPRESENTATION: MATRIX\n\n");
    for (i = 0; i < graph->num_vertices; i++) {
        for (j = 0; j < graph->num_vertices; j++) {
            printf("%d ", graph->vertices[i].list[j]);
        }
        printf("\n");
    }
}

void print_list(Graph *graph) {
    int i, j;
    printf("GRAPH REPRESENTATION: ADJACENCY LIST\n\n");
    for (i = 0; i < graph->num_vertices; i++) {
        printf("VERTEX %d: ", i);
        for (j = 0; j < graph->vertices[i].num_neighbors; j++) {
            printf("%d ", graph->vertices[i].list[j]);
        }
        printf("\n");
    }
}

void add_edge(Graph *graph, int vertex1, int vertex2) {
    graph->vertices[vertex1].list[vertex2] = 1;
    graph->vertices[vertex2].list[vertex1] = 1;
    graph->vertices[vertex1].num_neighbors++;
    graph->vertices[vertex2].num_neighbors++;
}

void configure_graph(Graph *graph, Representation representation) {
    int i, j;
    graph->num_vertices = 4;
    for (i = 0; i < MAX_VERTICES; i++) {
        graph->vertices[i].num_neighbors = 0;
        for (j = 0; j < MAX_REPRESENTATION; j++) {
            graph->vertices[i].list[j] = 0;
        }
    }
    if (representation == MATRIX) {
        add_edge(graph, 0, 1);
        add_edge(graph, 0, 2);
        add_edge(graph, 0, 3);
        add_edge(graph, 1, 2);
    }
    else if (representation == LIST) {
        add_edge(graph, 0, 1);
        add_edge(graph, 0, 2);
        add_edge(graph, 1, 2);
        add_edge(graph, 2, 3);
    }
}

int main() {

    Graph graph;
    Representation representation = LIST;
    configure_graph(&graph, representation);

    if (representation == MATRIX) {
        print_matrix(&graph);
    }
    else if (representation == LIST) {
        print_list(&graph);
    }

    return 0;
}