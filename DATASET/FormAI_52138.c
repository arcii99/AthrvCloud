//FormAI DATASET v1.0 Category: Graph representation ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 10

// Graph representation using adjacency matrix
typedef struct graph{
    int matrix[MAX_VERTICES][MAX_VERTICES];
    int num_vertices;
}Graph;

// Function to add an edge to the graph
void addEdge(Graph *g, int src, int dest){
    g->matrix[src][dest] = 1;
    g->matrix[dest][src] = 1; // if undirected graph
}

// Function to print the graph
void printGraph(Graph g){
    printf("Graph Representation:\n");
    for(int i=0; i<g.num_vertices; i++){
        for(int j=0; j<g.num_vertices; j++){
            printf("%d ", g.matrix[i][j]);
        }
        printf("\n");
    }
}

int main(){
    Graph g;
    g.num_vertices = 5;

    // Initialize graph with all zero values
    for(int i=0; i<g.num_vertices; i++){
        for(int j=0; j<g.num_vertices; j++){
            g.matrix[i][j] = 0;
        }
    }

    // Add edges to the graph
    addEdge(&g, 0, 1);
    addEdge(&g, 0, 4);
    addEdge(&g, 1, 2);
    addEdge(&g, 1, 3);
    addEdge(&g, 1, 4);
    addEdge(&g, 2, 3);
    addEdge(&g, 3, 4);

    // Print the graph
    printGraph(g);

    return 0;
}