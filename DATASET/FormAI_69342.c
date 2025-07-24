//FormAI DATASET v1.0 Category: Graph representation ; Style: mathematical
#include <stdio.h>

#define MAXVERTICES 10

struct graph{
    int matrix[MAXVERTICES][MAXVERTICES];
    int numVertices;
};

struct graph *createGraph(int vertices){
    struct graph *graph = malloc(sizeof(struct graph));
    graph->numVertices = vertices;

    for (int i = 0; i < vertices; i++){
        for (int j = 0; j < vertices; j++){
            graph->matrix[i][j] = 0;
        }
    }
    return graph;
}

void addEdge(struct graph *graph, int src, int dest){
    graph->matrix[src][dest] = 1;
    graph->matrix[dest][src] = 1;
}

void printGraph(struct graph *graph){
    printf("Adjacency matrix of the given graph:\n");
    for (int i = 0; i < graph->numVertices; i++){
        for (int j = 0; j < graph->numVertices; j++){
            printf("%d ", graph->matrix[i][j]);
        }
        printf("\n");
    }
}

int main(){
    struct graph *graph = createGraph(5);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);
    printGraph(graph);
    return 0;
}