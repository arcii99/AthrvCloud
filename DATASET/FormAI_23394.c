//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Define the maximum number of vertices in a graph
#define MAX_VERTICES 100

// Define a struct to represent a vertex in a graph
typedef struct Vertex {
    int parent; // Index of the parent vertex in the shortest path
    int distance; // Distance from the start vertex to this vertex
    int visited; // Flag indicating if the vertex has been visited
    int edges[MAX_VERTICES]; // Array of indices of adjacent vertices
    int weights[MAX_VERTICES]; // Array of weights for each edge
    int num_edges; // Number of edges for this vertex
} Vertex;

// Define a struct to represent a graph
typedef struct Graph {
    Vertex vertices[MAX_VERTICES]; // Array of vertices in the graph
    int num_vertices; // Number of vertices in the graph
} Graph;

// Define a function to find the vertex with the minimum distance
int find_min_distance(int distances[], int visited[], int num_vertices) {
    int min = INT_MAX;
    int min_index;
    int i;
    for (i = 0; i < num_vertices; i++) {
        if (!visited[i] && distances[i] < min) {
            min = distances[i];
            min_index = i;
        }
    }
    return min_index;
}

// Define the Dijkstra's algorithm function for finding the shortest path
void dijkstra(Graph *graph, int start_vertex) {
    int visited[MAX_VERTICES] = {0}; // Initialize all vertices as unvisited
    int distances[MAX_VERTICES]; // Array to store the shortest distances
    int i;
    for (i = 0; i < graph->num_vertices; i++) {
        distances[i] = INT_MAX; // Initialize all distances to infinity
    }
    distances[start_vertex] = 0; // Set the distance of the starting vertex to 0
    graph->vertices[start_vertex].parent = -1; // Set the parent of the starting vertex to -1
    
    int j;
    for (j = 0; j < graph->num_vertices - 1; j++) {
        int u = find_min_distance(distances, visited, graph->num_vertices);
        visited[u] = 1; // Mark the vertex as visited
        int k;
        for (k = 0; k < graph->vertices[u].num_edges; k++) {
            int v = graph->vertices[u].edges[k];
            int weight = graph->vertices[u].weights[k];
            if (!visited[v] && distances[u] != INT_MAX && distances[u] + weight < distances[v]) {
                distances[v] = distances[u] + weight;
                graph->vertices[v].parent = u;
            }
        }
    }
}

int main() {
    Graph graph;
    graph.num_vertices = 5;
    
    // Add the vertices to the graph
    int i;
    for (i = 0; i < graph.num_vertices; i++) {
        Vertex vertex;
        vertex.parent = -1;
        vertex.distance = INT_MAX;
        vertex.visited = 0;
        vertex.num_edges = 0;
        graph.vertices[i] = vertex;
    }
    
    // Add the edges to the graph
    graph.vertices[0].edges[0] = 1;
    graph.vertices[0].weights[0] = 10;
    graph.vertices[0].num_edges = 1;

    graph.vertices[1].edges[0] = 2;
    graph.vertices[1].edges[1] = 3;
    graph.vertices[1].weights[0] = 5;
    graph.vertices[1].weights[1] = 7;
    graph.vertices[1].num_edges = 2;

    graph.vertices[2].edges[0] = 4;
    graph.vertices[2].weights[0] = 3;
    graph.vertices[2].num_edges = 1;

    graph.vertices[3].edges[0] = 4;
    graph.vertices[3].weights[0] = 5;
    graph.vertices[3].num_edges = 1;

    graph.vertices[4].num_edges = 0;

    // Find the shortest path using Dijkstra's algorithm
    dijkstra(&graph, 0);

    // Print out the results
    printf("Vertex\tDistance\tPath\n");
    for (i = 0; i < graph.num_vertices; i++) {
        printf("%d\t%d\t", i, graph.vertices[i].distance);
        if (graph.vertices[i].parent >= 0) {
            printf("%d ", graph.vertices[i].parent);
        }
        printf("\n");
    }
    
    return 0;
}