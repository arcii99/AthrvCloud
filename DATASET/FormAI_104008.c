//FormAI DATASET v1.0 Category: Graph representation ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 50

int graph[MAX_VERTICES][MAX_VERTICES];
int num_vertices = 0;

void add_edge(int src, int dest, int weight) {
    graph[src][dest] = weight;
    graph[dest][src] = weight;
}

void print_graph() {
    int i, j;
    printf("Adjacency matrix of the graph:\n");
    for (i = 0; i < num_vertices; i++) {
        for (j = 0; j < num_vertices; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
}

int main() {
    num_vertices = 5;
    add_edge(0, 1, 2);
    add_edge(1, 2, 3);
    add_edge(2, 3, 4);
    add_edge(0, 4, 5);
    print_graph();
    return 0;
}