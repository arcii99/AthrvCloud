//FormAI DATASET v1.0 Category: Graph representation ; Style: scientific
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 20

struct Edge {
    int startVertex;
    int endVertex;
};

int numberOfVertices;
int numberOfEdges;
struct Edge edges[50];
int adjacencyMatrix[MAX_VERTICES][MAX_VERTICES];

int main(void) {
    printf("Provide the number of vertices: ");
    scanf("%d", &numberOfVertices);
    printf("Provide the number of edges: ");
    scanf("%d", &numberOfEdges);

    //edge details input
    for(int i = 0; i < numberOfEdges; i++) {
        printf("\nEnter edge[%d] data:\n", i + 1);
        printf("Start vertex: ");
        scanf("%d", &edges[i].startVertex);

        printf("End vertex: ");
        scanf("%d", &edges[i].endVertex);

        adjacencyMatrix[edges[i].startVertex][edges[i].endVertex] = 1;
        adjacencyMatrix[edges[i].endVertex][edges[i].startVertex] = 1;
    }

    //graph representation output
    printf("\nYour Graph:\n");
    for(int i = 0; i < numberOfVertices; i++) {
        for(int j = 0; j < numberOfVertices; j++) {
            printf("%d ", adjacencyMatrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}