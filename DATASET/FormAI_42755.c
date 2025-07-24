//FormAI DATASET v1.0 Category: Graph representation ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>

#define MAXVERTICES 100

/*-----------------Structures---------------*/

/*Edge structure to represent the link between two vertices*/
typedef struct edge{
    int vertex1, vertex2;
}EDGE;


/*Graph structure to represent the entire graph*/
typedef struct graph{
    int vertices;
    EDGE edges[MAXVERTICES];
}GRAPH;

/*-----------------Function Prototypes---------------*/

void initializeGraph(GRAPH* graph);
void addEdge(GRAPH* graph, int vertex1, int vertex2);
void printGraph(GRAPH* graph);

/*-----------------Main Function---------------*/

int main(){
    GRAPH graph;
    initializeGraph(&graph);

    addEdge(&graph, 0, 1);
    addEdge(&graph, 0, 2);
    addEdge(&graph, 1, 2);
    addEdge(&graph, 2, 3);
    addEdge(&graph, 3, 4);

    printGraph(&graph);

    return 0;
}

/*-----------------Function Definitions---------------*/

/*Function to initialize the graph*/
void initializeGraph(GRAPH* graph){
    graph->vertices = 0;
    int i;
    for(i=0;i<MAXVERTICES;i++){
        (graph->edges[i]).vertex1 = -1;
        (graph->edges[i]).vertex2 = -1;
    }
}

/*Function to add an edge between two vertices*/
void addEdge(GRAPH* graph, int vertex1, int vertex2){
    if(graph->vertices == MAXVERTICES){
        printf("Maximum vertices reached\n");
        return;
    }
    (graph->edges[graph->vertices]).vertex1 = vertex1;
    (graph->edges[graph->vertices++]).vertex2 = vertex2;
}

/*Function to print the entire graph*/
void printGraph(GRAPH* graph){
    printf("The graph has the following edges:\n");
    int i;
    for(i=0;i<graph->vertices;i++){
        printf("%d --> %d\n", (graph->edges[i]).vertex1, (graph->edges[i]).vertex2);
    }
}