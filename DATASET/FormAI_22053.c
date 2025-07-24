//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

// Define constants for the number of vertices and edges in the graph
#define V 5
#define E 7

// Create a graph using an adjacency matrix
int graph[V][V] = {
    {0, 3, 0, 2, 0},
    {3, 0, 4, 0, 0},
    {0, 4, 0, 1, 1},
    {2, 0, 1, 0, 5},
    {0, 0, 1, 5, 0}
};

// Define a function to find the vertex with the minimum distance value
int minDistance(int dist[], bool visited[]) {
    int min = INT_MAX, min_index;
    for (int v = 0; v < V; v++) {
        if (visited[v] == false && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}

// Define a function to print the path to a vertex from the source vertex
void printPath(int parent[], int j) {
    if (parent[j] == -1) {
        printf("%d ", j);
        return;
    }
    printPath(parent, parent[j]);
    printf("%d ", j);
}

// Define a function to print the solution
void printSolution(int dist[], int parent[], int src) {
    printf("Vertex \t Distance \t Path\n");
    for (int i = 0; i < V; i++) {
        printf("%d \t %d \t\t", i, dist[i]);
        printPath(parent, i);
        printf("\n");
    }
}

// Define the Dijkstra algorithm function to find the shortest path from a given vertex to all other vertices
void dijkstra(int src) {
    int dist[V];    // Distance array to hold the shortest distance from src to i
    bool visited[V];    // Boolean array to mark visited/unvisited vertices
    int parent[V];  // Array to hold the shortest path from src to i

    // Initialize all distance values as infinite and visited[] as false
    for (int i = 0; i < V; i++) {
        parent[src] = -1;
        dist[i] = INT_MAX;
        visited[i] = false;
    }

    // Distance from source vertex to itself is always 0
    dist[src] = 0;

    // Find shortest path to all vertices
    for (int count = 0; count < V - 1; count++) {
        // Pick the minimum distance vertex from the set of unvisited vertices
        int u = minDistance(dist, visited);

        // Mark the picked vertex as visited
        visited[u] = true;

        // Update dist[] value of the adjacent vertices of the picked vertex
        for (int v = 0; v < V; v++)
            if (!visited[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) {
                parent[v] = u;
                dist[v] = dist[u] + graph[u][v];
            }
    }

    // Print the solution
    printSolution(dist, parent, src);
}

// The main function to run the code
int main() {
    // Run the algorithm for all vertices as source
    for (int i = 0; i < V; i++)
        dijkstra(i);

    return 0;
}