//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: expert-level
#include <stdio.h>

// Function to find the shortest path from source to destination using Dijkstra algorithm
void dijkstra(int graph[5][5], int source, int destination) {
    int i, j, min, count, u, visited[5], prev[5], dist[5];
    
    // Initialize the arrays
    for (i = 0; i < 5; i++) {
        dist[i] = graph[source][i];
        visited[i] = 0;
        prev[i] = source;
    }
    
    // Mark the source node as visited and set the distance to 0
    visited[source] = 1;
    dist[source] = 0;
    
    // Search for the shortest path
    count = 1;
    while (count < 5 - 1) {
        min = 9999;
        
        // Select the unvisited node with the smallest distance
        for (i = 0; i < 5; i++) {
            if (dist[i] < min && !visited[i]) {
                min = dist[i];
                u = i;
            }
        }
        
        // Mark the selected node as visited
        visited[u] = 1;
        
        // Update the distance values of adjacent nodes
        for (j = 0; j < 5; j++) {
            if (!visited[j]) {
                if (min + graph[u][j] < dist[j]) {
                    dist[j] = min + graph[u][j];
                    prev[j] = u;
                }
            }
        }
        count++;
    }
    
    // Print the shortest path
    printf("Shortest path from %d to %d: ", source, destination);
    printf("%d ", destination);
    
    j = destination;
    do {
        j = prev[j];
        printf("%d ", j);
    } while (j != source);
}

int main() {
    int graph[5][5] = {
        {0, 6, 0, 1, 0},
        {6, 0, 5, 2, 2},
        {0, 5, 0, 0, 5},
        {1, 2, 0, 0, 1},
        {0, 2, 5, 1, 0}
    };
    int source = 0, destination = 4;
    
    dijkstra(graph, source, destination);
    
    return 0;
}