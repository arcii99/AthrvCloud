//FormAI DATASET v1.0 Category: Graph representation ; Style: all-encompassing
#include<stdio.h>
#include<stdlib.h>
#define MAX_VERTICES 20

typedef struct{
    int vertices[MAX_VERTICES][MAX_VERTICES];
    int numVertices;
}Graph;

void initialise(Graph* graph){
    graph->numVertices = 0;
    
    for(int i=0;i<MAX_VERTICES;i++){
        for(int j=0;j<MAX_VERTICES;j++){
            graph->vertices[i][j]=0;
        }
    }
}

void insertVertex(Graph* graph, int vertex){
    if((graph->numVertices)+1>MAX_VERTICES){
        printf("Maximum number of vertices exceeded");
        return;
    }

    graph->numVertices++;
    for(int i=0;i<graph->numVertices;i++){
        graph->vertices[i][graph->numVertices-1]=0;
        graph->vertices[graph->numVertices-1][i]=0;
    }
}

void insertEdge(Graph* graph, int vertex1, int vertex2){
    if (vertex1>=graph->numVertices || vertex2>=graph->numVertices){
        printf("Invalid vertex");
        return;
    }

    graph->vertices[vertex1][vertex2]++;
    graph->vertices[vertex2][vertex1]++;
}

void displayGraph(Graph* graph){
    printf("Adjacency matrix representation of the graph:\n");
    for(int i=0;i<graph->numVertices;i++){
        for(int j=0;j<graph->numVertices;j++){
            printf("%d ",graph->vertices[i][j]);
        }
        printf("\n");
    }
}

int main(){
    Graph graph;
    initialise(&graph);

    insertVertex(&graph, 0);
    insertVertex(&graph, 1);
    insertVertex(&graph, 2);
    insertVertex(&graph, 3);
    insertEdge(&graph, 0, 1);
    insertEdge(&graph, 0, 2);
    insertEdge(&graph, 1, 3);
    insertEdge(&graph, 2, 3);

    displayGraph(&graph);

    return 0;
}