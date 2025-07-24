//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: statistical
#include <stdio.h>
#include <stdlib.h>

#define ROW 5
#define COL 5

int graph[ROW][COL] = {
        {0, 1, 0, 1, 0},
        {1, 0, 1, 1, 1},
        {0, 1, 0, 0, 1},
        {1, 1, 0, 0, 1},
        {0, 1, 1, 1, 0}
};

void dijkstra(int src) {
    int dist[ROW];
    int visited[ROW];
    int i, j, min_distance, next_node;

    // Initialize distance and visited arrays
    for (i = 0; i < ROW; i++) {
        dist[i] = graph[src][i];
        visited[i] = 0;
    }

    // Set the distance to the source node as 0 and the node as visited
    dist[src] = 0;
    visited[src] = 1;

    // Main loop to find the shortest path to all nodes from the source node
    for (i = 1; i < ROW; i++) {
        min_distance = 999;
        for (j = 0; j < ROW; j++) {
            if (dist[j] < min_distance && !visited[j]) {
                min_distance = dist[j];
                next_node = j;
            }
        }
        visited[next_node] = 1;

        for (j = 0; j < ROW; j++) {
            if (!visited[j]) {
                if (min_distance + graph[next_node][j] < dist[j]) {
                    dist[j] = min_distance + graph[next_node][j];
                }
            }
        }
    }

    // Print the shortest distances to all nodes from the source node
    printf("Shortest distances from node %d:\n", src);
    for (i = 0; i < ROW; i++) {
        printf("%d ", dist[i]);
    }
}

int main() {
    dijkstra(0);
    return 0;
}