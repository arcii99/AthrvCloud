//FormAI DATASET v1.0 Category: Graph representation ; Style: all-encompassing
#include<stdio.h>
#include<stdlib.h>

struct Edge {
    int src, dest;
};

struct Graph {
    int V, E;
    struct Edge* edge;
};

struct Graph* createGraph(int V, int E) {
    struct Graph* graph = (struct Graph*) malloc(sizeof(struct Graph));
    graph->V = V;
    graph->E = E;
    graph->edge = (struct Edge*) malloc(graph->E * sizeof(struct Edge));
    return graph;
}

void printGraph(struct Graph* graph) {
    for(int i = 0; i < graph->E; i++) {
        printf("(%d) -> (%d)\n", graph->edge[i].src, graph->edge[i].dest);
    }
}

int main() {
    int V = 5, E = 4;
    struct Graph* graph = createGraph(V, E);

    graph->edge[0].src = 0;
    graph->edge[0].dest = 1;

    graph->edge[1].src = 1;
    graph->edge[1].dest = 2;

    graph->edge[2].src = 2;
    graph->edge[2].dest = 3;

    graph->edge[3].src = 3;
    graph->edge[3].dest = 4;

    printGraph(graph);

    return 0;
}