//FormAI DATASET v1.0 Category: Graph representation ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VERTICES 50

// Structure for edges
typedef struct Edge{
    int source;
    int dest;
    int weight;
} Edge;

int edgeCount = 0;
Edge edges[MAX_VERTICES*MAX_VERTICES]; // Array of edges

void addEdge(int source, int dest, int weight){
    edges[edgeCount].source = source;
    edges[edgeCount].dest = dest;
    edges[edgeCount].weight = weight;
    edgeCount++;
}

void paranoidGraph(int vertices){
    // Generating random graph
    for(int i=0; i<vertices; i++){
        for(int j=0; j<vertices; j++){
            if(i == j){
                continue;
            }
            int random = rand() % 4;
            if(random == 0){
                addEdge(i, j, rand()%10 + 1);
            }
        }
    }
}

void printGraph(int vertices){
    // Printing the graph
    printf("Edges:\n");
    for(int i=0; i<edgeCount; i++){
        printf("(%d, %d) weight=%d\n", edges[i].source, edges[i].dest, edges[i].weight);
    }
}

int main(){
    int vertices = 6; // Number of vertices
    paranoidGraph(vertices);
    printGraph(vertices);
    return 0;
}