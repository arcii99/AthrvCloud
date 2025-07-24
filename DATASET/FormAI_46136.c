//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100   // Maximum number of vertices in graph

int graph[MAX][MAX];   // Adjacency matrix to store the graph
int visited[MAX];      // Array to mark whether the vertex is visited or not

int num_vertices;      // Number of vertices in the graph

// Function to initialize the adjacency matrix with all zeroes
void initialize_graph() {
    for (int i = 0; i < num_vertices; i++) {
        for (int j = 0; j < num_vertices; j++) {
            graph[i][j] = 0;
        }
    }
}

// Function to add edges to the graph
void add_edge(int u, int v) {
    graph[u][v] = 1;
    graph[v][u] = 1;
}

// Function to perform breadth first traversal of the graph
void bfs(int vertex) {
    int queue[MAX];
    int front = -1;
    int rear = -1;

    queue[++rear] = vertex;
    visited[vertex] = 1;

    while (front != rear) {
        int u = queue[++front];
        printf("%d ", u);

        for (int v = 0; v < num_vertices; v++) {
            if (graph[u][v] == 1 && visited[v] == 0) {
                visited[v] = 1;
                queue[++rear] = v;
            }
        }
    }
}

int main() {
    // Input the number of vertices in the graph
    printf("Number of vertices: ");
    scanf("%d", &num_vertices);

    // Initialize the adjacency matrix
    initialize_graph();

    // Input the edges
    printf("Enter the edges (u v): ");
    int u, v;
    while (scanf("%d%d", &u, &v) != EOF) {
        add_edge(u, v);
    }

    // Output the adjacency matrix
    printf("Adjacency matrix:\n");
    for (int i = 0; i < num_vertices; i++) {
        for (int j = 0; j < num_vertices; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }

    // Perform breadth first traversal of the graph
    printf("Breadth first traversal: ");
    for (int i = 0; i < num_vertices; i++) {
        if (visited[i] == 0) {
            bfs(i);
        }
    }
    printf("\n");

    return 0;
}