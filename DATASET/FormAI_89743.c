//FormAI DATASET v1.0 Category: Graph representation ; Style: post-apocalyptic
// Post-apocalyptic C Graph representation example program

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define MAX_VERTICES 10
#define INF 99999

typedef struct Graph {
    int n_vertices;
    bool is_directed;
    int edges[MAX_VERTICES][MAX_VERTICES];
} Graph;

void init_graph(Graph *graph, int n_vertices, bool is_directed) {
    graph->n_vertices = n_vertices;
    graph->is_directed = is_directed;

    for (int i=0; i<MAX_VERTICES; i++) {
        for (int j=0; j<MAX_VERTICES; j++) {
            graph->edges[i][j] = INF;
        }
    }
}

void add_edge(Graph *graph, int u, int v, int weight) {
    graph->edges[u][v] = weight;
    if (!graph->is_directed) {
        graph->edges[v][u] = weight;
    }
}

void print_graph(Graph *graph) {
    printf("    ");
    for (int i=0; i<graph->n_vertices; i++) {
        printf("%d ", i);
    }
    printf("\n");

    for (int i=0; i<graph->n_vertices; i++) {
        printf("%d: ", i);
        for (int j=0; j<graph->n_vertices; j++) {
            if (graph->edges[i][j] == INF) {
                printf(". ");
            }
            else {
                printf("%d ", graph->edges[i][j]);
            }
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));

    Graph graph;
    init_graph(&graph, MAX_VERTICES, false);

    // randomly generate edges
    for (int i=0; i<MAX_VERTICES; i++) {
        for (int j=0; j<MAX_VERTICES; j++) {
            if (rand() % 2 == 0 && i != j) {
                int weight = rand() % 10 + 1;
                add_edge(&graph, i, j, weight);
            }
        }
    }

    printf("Post-apocalyptic Graph Representation:\n");
    print_graph(&graph);

    return 0;
}