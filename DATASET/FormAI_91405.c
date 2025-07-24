//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: creative
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100
#define MAX_COLORS 10

typedef struct Graph {
    int vertices[MAX_VERTICES][MAX_VERTICES];
    int num_vertices;
} Graph;

int used_colors[MAX_COLORS];

void initialize_values(Graph* graph) {
    int i, j;
    graph->num_vertices = 0;
    for (i = 0; i < MAX_COLORS; i++)
        used_colors[i] = 0;
    for (i = 0; i < MAX_VERTICES; i++)
        for (j = 0; j < MAX_VERTICES; j++)
            graph->vertices[i][j] = 0;
}

void add_edge(Graph* graph, int start_vertex, int end_vertex) {
    graph->vertices[start_vertex][end_vertex] = 1;
    graph->vertices[end_vertex][start_vertex] = 1;
}

int next_vertex(Graph* graph, int start_vertex) {
    int i;
    for (i = start_vertex + 1; i < graph->num_vertices; i++)
        if (!used_colors[i])
            return i;
    return -1;
}

int coloring(Graph* graph, int vertex) {
    int i, j;
    int next_v = next_vertex(graph, vertex);
    if (next_v == -1)
        return 1;
    for (i = 0; i < MAX_COLORS; i++) {
        for (j = 0; j < graph->num_vertices; j++) {
            if (graph->vertices[next_v][j] && used_colors[j] == i)
                break;
        }
        if (j == graph->num_vertices) {
            used_colors[next_v] = i;
            if (coloring(graph, next_v))
                return 1;
        }
    }
    used_colors[next_v] = 0;
    return 0;
}

int main() {
    Graph graph;
    initialize_values(&graph);

    // Adding edges to the graph
    add_edge(&graph, 0, 1);
    add_edge(&graph, 0, 4);
    add_edge(&graph, 1, 2);
    add_edge(&graph, 1, 3);
    add_edge(&graph, 1, 4);
    add_edge(&graph, 2, 3);
    add_edge(&graph, 3, 4);
    graph.num_vertices = 5;

    if (coloring(&graph, -1)) {
        int i;
        for (i = 0; i < graph.num_vertices; i++)
            printf("Vertex %d has color %d\n", i, used_colors[i]);
    } else {
        printf("It is impossible to color the graph with %d colors", MAX_COLORS);
    }

    return 0;
}