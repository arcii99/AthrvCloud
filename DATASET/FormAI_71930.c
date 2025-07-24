//FormAI DATASET v1.0 Category: Graph representation ; Style: protected
#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 100 // Defining a macro MAXSIZE
int graph[MAXSIZE][MAXSIZE]; // 2D array to represent the graph
int num_vertices; // Number of vertices in graph
int num_edges; // Number of edges in graph

void initializeGraph() {
    int i, j;
    for (i = 0; i < num_vertices; i++) {
        for (j = 0; j < num_vertices; j++) {
            graph[i][j] = 0;
        }
    }
}

void addEdge(int source, int destination) {
    graph[source][destination] = 1;
    graph[destination][source] = 1;
}

void printGraph() {
    int i, j;
    for (i = 0; i < num_vertices; i++) {
        printf("\nAdjacent vertices of vertex %d: ", i);
        for (j = 0; j < num_vertices; j++) {
            if (graph[i][j] == 1) {
                printf("%d ", j);
            }
        }
    }
    printf("\n");
}

int main() {
    printf("Enter the number of vertices: ");
    scanf("%d", &num_vertices);
    printf("Enter the number of edges: ");
    scanf("%d", &num_edges);
    initializeGraph();
    printf("Enter the edges (source and destination vertex index):\n");
    int i, source, destination;
    for (i = 0; i < num_edges; i++) {
        scanf("%d %d", &source, &destination);
        addEdge(source, destination);
    }
    printGraph();
    return 0;
}