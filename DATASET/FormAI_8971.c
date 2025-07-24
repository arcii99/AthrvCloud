//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Define the maximum number of vertices in the graph
#define MAX_VERTICES 10

// Define the graph structure
struct Graph {
    int vertices[MAX_VERTICES][MAX_VERTICES];  // adjacency matrix
    int num_vertices;   // number of vertices in the graph
};

// A utility function to initialize the graph
void init_graph(struct Graph *g, int num_vertices) {
    // Set the number of vertices in the graph
    g->num_vertices = num_vertices;

    // Initialize the adjacency matrix to all zeroes
    for (int i = 0; i < MAX_VERTICES; i++) {
        for (int j = 0; j < MAX_VERTICES; j++) {
            g->vertices[i][j] = 0;
        }
    }
}

// A utility function to add an edge to the graph
void add_edge(struct Graph *g, int source, int dest, int weight) {
    // Add an edge from source to dest with the given weight
    g->vertices[source][dest] = weight;
}

// The Dijkstra's algorithm function to find the shortest path
void dijkstra(struct Graph *g, int start_vertex) {
    int dist[MAX_VERTICES];   // distance array
    int visited[MAX_VERTICES];  // visited array

    // Initialize the distance array and visited array
    for (int i = 0; i < MAX_VERTICES; i++) {
        dist[i] = INT_MAX;
        visited[i] = 0;
    }

    // Set the distance of the starting vertex to 0
    dist[start_vertex] = 0;

    // Loop through all the vertices in the graph
    for (int i = 0; i < g->num_vertices; i++) {
        // Find the vertex with the minimum distance
        int min_dist = INT_MAX;
        int min_vertex = -1;
        for (int j = 0; j < g->num_vertices; j++) {
            if (!visited[j] && dist[j] < min_dist) {
                min_dist = dist[j];
                min_vertex = j;
            }
        }

        // Mark the minimum vertex as visited
        visited[min_vertex] = 1;

        // Update the distance of the neighbors of the minimum vertex
        for (int k = 0; k < g->num_vertices; k++) {
            int edge_weight = g->vertices[min_vertex][k];
            if (edge_weight > 0) {
                int new_dist = dist[min_vertex] + edge_weight;
                if (new_dist < dist[k]) {
                    dist[k] = new_dist;
                }
            }
        }
    }

    // Print out the shortest path from the starting vertex to all other vertices
    for (int i = 0; i < g->num_vertices; i++) {
        printf("Shortest path from vertex %d to vertex %d is %d\n", start_vertex, i, dist[i]);
    }
}

// The main function
int main() {
    struct Graph g;
    int num_vertices = 5;   // 5 vertices in the graph

    // Initialize the graph
    init_graph(&g, num_vertices);

    // Add the edges to the graph
    add_edge(&g, 0, 1, 4);
    add_edge(&g, 0, 2, 1);
    add_edge(&g, 2, 1, 2);
    add_edge(&g, 1, 3, 1);
    add_edge(&g, 2, 3, 5);
    add_edge(&g, 3, 4, 3);

    // Call the Dijkstra's algorithm function to find the shortest path
    dijkstra(&g, 0);

    return 0;
}