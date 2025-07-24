//FormAI DATASET v1.0 Category: Graph representation ; Style: Dennis Ritchie
#include <stdio.h>

#define MAX_VERTICES 100

// Function to add an edge between two vertices
void add_edge(int graph[][MAX_VERTICES], int u, int v) {
    graph[u][v] = 1;
    graph[v][u] = 1;
}

// Function to remove an edge between two vertices
void remove_edge(int graph[][MAX_VERTICES], int u, int v) {
    graph[u][v] = 0;
    graph[v][u] = 0;
}

// Function to print the graph
void print_graph(int graph[][MAX_VERTICES], int num_vertices) {
    printf("Graph : \n");
    for(int i=0; i<num_vertices; i++) {
        for(int j=0; j<num_vertices; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int num_vertices = 5;
    int graph[MAX_VERTICES][MAX_VERTICES];

    // Initializing the graph
    for(int i=0; i<num_vertices; i++) {
        for(int j=0; j<num_vertices; j++) {
            graph[i][j] = 0;
        }
    }

    // Adding edges to the graph
    add_edge(graph, 0, 1);
    add_edge(graph, 0, 4);
    add_edge(graph, 1, 2);
    add_edge(graph, 1, 3);
    add_edge(graph, 1, 4);
    add_edge(graph, 2, 3);
    add_edge(graph, 3, 4);

    // Printing the graph
    print_graph(graph, num_vertices);

    // Removing edges from the graph
    remove_edge(graph, 0, 4);
    remove_edge(graph, 2, 3);

    // Printing the graph after removing edges
    print_graph(graph, num_vertices);

    return 0;
}