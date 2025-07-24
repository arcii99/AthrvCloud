//FormAI DATASET v1.0 Category: Graph representation ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 10
#define MAX_EDGES 10

struct edge {
    int weight;
    int from_vertex;
    int to_vertex;
};

int vertices_count = 0;
int edges_count = 0;
struct edge edges[MAX_EDGES];

int add_vertex(int vertex) {
    if (vertices_count >= MAX_VERTICES) {
        return 0;
    }

    vertices_count++;

    return 1;
}

int add_edge(int weight, int from_vertex, int to_vertex) {
    if (edges_count >= MAX_EDGES) {
        return 0;
    }

    edges[edges_count].weight = weight;
    edges[edges_count].from_vertex = from_vertex;
    edges[edges_count].to_vertex = to_vertex;
    edges_count++;

    return 1;
}

int main() {
    if (!add_vertex(1) || !add_vertex(2) || !add_vertex(3) || !add_vertex(4) || !add_vertex(5)) {
        printf("Error: Maximum number of vertices reached\n");
        return 0;
    }

    if (!add_edge(5, 1, 2) || !add_edge(3, 1, 3) || !add_edge(2, 2, 3) || !add_edge(1, 2, 4) || !add_edge(4, 3, 5)) {
        printf("Error: Maximum number of edges reached\n");
        return 0;
    }

    printf("Graph Representation:\n");
    for (int i = 0; i < edges_count; i++) {
        printf("Edge %d: %d -> %d (weight: %d)\n", i+1, edges[i].from_vertex, edges[i].to_vertex, edges[i].weight);
    }

    return 0;
}