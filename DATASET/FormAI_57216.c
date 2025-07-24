//FormAI DATASET v1.0 Category: Graph representation ; Style: portable
#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100

struct Graph {
    int nodes[MAX_NODES][MAX_NODES];
    int n;
};

struct Graph createGraph(int n) {
    struct Graph graph;
    graph.n = n;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            graph.nodes[i][j] = 0;
        }
    }

    return graph;
}

void addEdge(struct Graph* graph, int src, int dest) {
    graph->nodes[src][dest] = 1;
    graph->nodes[dest][src] = 1;
}

void printGraph(struct Graph graph) {
    for(int i = 0; i < graph.n; i++) {
        for(int j = 0; j < graph.n; j++) {
            printf("%d ", graph.nodes[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int n = 5;
    struct Graph graph = createGraph(n);

    addEdge(&graph, 0, 1);
    addEdge(&graph, 0, 4);
    addEdge(&graph, 1, 2);
    addEdge(&graph, 1, 3);
    addEdge(&graph, 1, 4);
    addEdge(&graph, 2, 3);
    addEdge(&graph, 3, 4);

    printGraph(graph);

    return 0;
}