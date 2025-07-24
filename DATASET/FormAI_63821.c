//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Macro definitions for matrix dimensions and maximum distance
#define ROWS 5
#define COLUMNS 5
#define MAX_DIST INT_MAX

// Declare function prototypes 
void dijkstra(int graph[ROWS][COLUMNS], int source);
int minDistance(int dist[], int visited[]);
void printSolution(int dist[]);

int main() {
    // Declare the adjacency matrix of the weighted graph 
    int graph[ROWS][COLUMNS] = {{0, 8, 0, 3, 0}, 
                                {8, 0, 2, 0, 4}, 
                                {0, 2, 0, 1, 0}, 
                                {3, 0, 1, 0, 5},
                                {0, 4, 0, 5, 0}};
    
    // Call the dijkstra function to find the shortest paths from vertex 0
    dijkstra(graph, 0);

    return 0;
}

// Function implementation for Dijkstra's algorithm
void dijkstra(int graph[ROWS][COLUMNS], int source) {
    int dist[ROWS];  // Store the shortest distances from the source vertex
    int visited[ROWS];  // Keep track of visited vertices

    // Initialize the distance for all vertices as maximum distance
    // and visited as unvisited
    for (int i = 0; i < ROWS; i++) {
        dist[i] = MAX_DIST;
        visited[i] = 0;
    }

    // Distance of source vertex to itself is 0
    dist[source] = 0;

    // Find shortest path for all vertices
    for (int count = 0; count < ROWS - 1; count++) {
        // Pick the minimum distance vertex from the set of unvisited vertices
        int u = minDistance(dist, visited);

        // Mark the picked vertex as visited
        visited[u] = 1;

        // Update dist value of the adjacent vertices of the picked vertex.
        for (int v = 0; v < ROWS; v++) {
            // Update dist[v] only if it's not visited, there is an edge from 
            // u to v, and the total weight of path from source to v through u 
            // is smaller than current value of dist[v]
            if (visited[v] == 0 && graph[u][v] && dist[u] != MAX_DIST 
                && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    // Print the solution
    printSolution(dist);
}

// Helper function for finding the vertex with minimum distance from the set of vertices
int minDistance(int dist[], int visited[]) {
    int min = MAX_DIST, min_index;
    
    for (int v = 0; v < ROWS; v++) {
        if (visited[v] == 0 && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }

    return min_index;
}

// Helper function for printing the shortest distances from the source vertex
void printSolution(int dist[]) {
    printf("Vertex \t Distance from Source\n");
    for (int i = 0; i < ROWS; i++) {
        printf("%d \t %d\n", i, dist[i]);
    }
}