//FormAI DATASET v1.0 Category: Graph representation ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 10

typedef struct Graph{
    int vertices[MAX_VERTICES];
    int edges[MAX_VERTICES][MAX_VERTICES];
    int num_vertices;
}Graph;

void add_vertex(Graph* graph, int vertex){
    graph->vertices[graph->num_vertices++] = vertex;
}

void add_edge(Graph* graph, int vertex1, int vertex2){
    graph->edges[vertex1][vertex2] = 1;
    graph->edges[vertex2][vertex1] = 1;
}

void print_graph(Graph* graph){
    printf("Vertices: ");
    for(int i = 0; i < graph->num_vertices; i++){
        printf("%d ", graph->vertices[i]);
    }
    printf("\n");

    printf("Edges: \n");
    for(int i = 0; i < graph->num_vertices; i++){
        for(int j = i+1; j < graph->num_vertices; j++){
            if(graph->edges[i][j] == 1){
                printf("(%d, %d) ", graph->vertices[i], graph->vertices[j]);
            }
        }
        printf("\n");
    }
}

int main(){
    Graph graph;
    graph.num_vertices = 0;

    add_vertex(&graph, 1);
    add_vertex(&graph, 2);
    add_vertex(&graph, 3);

    add_edge(&graph, 0, 1);
    add_edge(&graph, 1, 2);

    print_graph(&graph);

    return 0;
}