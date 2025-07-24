//FormAI DATASET v1.0 Category: Graph representation ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100
#define INF 999999

typedef struct {
    int weight;
    int origin;
    int destination;
} Edge;

int numVertices = 0;
int matrix[MAX_VERTICES][MAX_VERTICES];

void initializeMatrix() {
    for (int i = 0; i < MAX_VERTICES; i++) {
        for (int j = 0; j < MAX_VERTICES; j++) {
            if (i == j) {
                matrix[i][j] = 0;
            } else {
                matrix[i][j] = INF;
            }
        }
    }
}

void addVertex() {
    numVertices++;
}

void addDirectedEdge(int origin, int destination, int weight) {
    matrix[origin][destination] = weight;
}

int getEdgeWeight(int origin, int destination) {
    return matrix[origin][destination];
}

void printMatrix() {
    for (int i = 0; i < numVertices; i++) {
        printf("%d\t", i);
        for (int j = 0; j < numVertices; j++) {
            if (matrix[i][j] == INF) {
                printf("INF\t");
            } else {
                printf("%d\t", matrix[i][j]);
            }
        }
        printf("\n");
    }
}

Edge* createEdgeList(int* numEdges) {
    *numEdges = 0;
    Edge* edgeList = malloc(MAX_VERTICES * MAX_VERTICES * sizeof(Edge));
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            if (matrix[i][j] != INF) {
                edgeList[(*numEdges)].origin = i;
                edgeList[(*numEdges)].destination = j;
                edgeList[(*numEdges)].weight = matrix[i][j];
                (*numEdges)++;
            }
        }
    }
    return edgeList;
}

void printEdgeList(Edge* edgeList, int numEdges) {
    for (int i = 0; i < numEdges; i++) {
        printf("Edge %d: %d -> %d, weight %d\n", i, edgeList[i].origin, edgeList[i].destination, edgeList[i].weight);
    }
}

void floydWarshall() {
    for (int k = 0; k < numVertices; k++) {
        for (int i = 0; i < numVertices; i++) {
            for (int j = 0; j < numVertices; j++) {
                if (matrix[i][k] + matrix[k][j] < matrix[i][j]) {
                    matrix[i][j] = matrix[i][k] + matrix[k][j];
                }
            }
        }
    }
}

int main() {
    initializeMatrix();
    addVertex(); // vertex 0
    addVertex(); // vertex 1
    addVertex(); // vertex 2
    addDirectedEdge(0, 1, 5); // edge from vertex 0 to vertex 1 with weight 5
    addDirectedEdge(1, 2, 3); // edge from vertex 1 to vertex 2 with weight 3
    addDirectedEdge(0, 2, 7); // edge from vertex 0 to vertex 2 with weight 7
    printf("Initial Matrix:\n");
    printMatrix();
    int numEdges;
    Edge* edgeList = createEdgeList(&numEdges);
    printf("\nEdge List:\n");
    printEdgeList(edgeList, numEdges);
    floydWarshall();
    printf("\nShortest Path Matrix:\n");
    printMatrix();
    free(edgeList);
    return 0;
}