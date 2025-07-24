//FormAI DATASET v1.0 Category: Graph representation ; Style: enthusiastic
#include <stdio.h>

#define MAX_SIZE 10

// function signature    
void graphTraversal(int graph[MAX_SIZE][MAX_SIZE], int vertices, int starting_vertex);

int main() {
    int graph[MAX_SIZE][MAX_SIZE]; // you can take inputs from the user to initialize this graph
    int vertices = 5; // just for example purposes, can be any number of vertices
    int starting_vertex = 0; // just for example purposes, can be any starting vertex

    printf("Graph Traversal Starting from Vertex %d:\n", starting_vertex);
    graphTraversal(graph, vertices, starting_vertex);

    return 0;
}

void graphTraversal(int graph[MAX_SIZE][MAX_SIZE], int vertices, int starting_vertex) {
    int i, j;
    int visited[MAX_SIZE]; // array to keep track of visited vertices
    for (i = 0; i < vertices; i++) {
        visited[i] = 0; // initialize all vertices as not visited yet
    }

    visited[starting_vertex] = 1; // mark the starting vertex as visited
    printf("%d ", starting_vertex); // print the starting vertex

    for (i = 0; i < vertices; i++) {
        if (graph[starting_vertex][i] != 0 && visited[i] == 0) { // if there is an edge and the vertex is not visited yet
            visited[i] = 1; // mark the vertex as visited
            printf("%d ", i); // print the vertex
            graphTraversal(graph, vertices, i); // recursively call the function with the new vertex
        }
    }
}