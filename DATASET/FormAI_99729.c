//FormAI DATASET v1.0 Category: Graph representation ; Style: automated
#include<stdio.h>
#include<stdlib.h>

struct Graph{
    int numVertices;
    int** adjList;
};

// Create Graph
struct Graph* createGraph(int vertices){
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numVertices = vertices;

    graph->adjList = (int**)malloc(vertices * sizeof(int*));

    for(int i=0;i<vertices;i++){
        graph->adjList[i] = (int*)malloc(vertices * sizeof(int));
        for(int j=0;j<vertices;j++){
            graph->adjList[i][j] = 0;
        }
    }

    return graph;
}

// Add Edges to Graph
void addEdge(struct Graph* graph, int src, int dest){
    graph->adjList[src][dest] = 1;
    graph->adjList[dest][src] = 1;
}

// Print the Graph
void printGraph(struct Graph* graph){
    printf("Graph:\n");
    for(int i=0;i<graph->numVertices;i++){
        printf("%d: ", i);
        for(int j=0;j<graph->numVertices;j++){
            printf("%d ", graph->adjList[i][j]);
        }
        printf("\n");
    }
}

int main(){
    struct Graph* graph = createGraph(6);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 3, 4);
    addEdge(graph, 4, 5);

    printGraph(graph);

    return 0;
}