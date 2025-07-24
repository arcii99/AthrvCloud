//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define ROW 5
#define COL 5

int graph[ROW][COL] = {
    {0, 1, 0, 0, 1},
    {1, 0, 1, 1, 0},
    {0, 1, 0, 1, 0},
    {0, 1, 1, 0, 1},
    {1, 0, 0, 1, 0}
};

int dijkstra(int graph[][COL], int source, int target) {
    int dist[ROW], visited[ROW], min_dist, min_idx, i, j;
    
    for (i = 0; i < ROW; i++) {
        dist[i] = INT_MAX;
        visited[i] = 0;
    }
    
    dist[source] = 0;
    
    for (i = 0; i < ROW; i++) {
        min_dist = INT_MAX;
        for (j = 0; j < ROW; j++) 
            if (!visited[j] && dist[j] < min_dist) {
                min_dist = dist[j];
                min_idx = j;
            }
        visited[min_idx] = 1;
        for (j = 0; j < ROW; j++) 
            if (!visited[j] && graph[min_idx][j] && dist[min_idx] + graph[min_idx][j] < dist[j])
                dist[j] = dist[min_idx] + graph[min_idx][j];
    }
    
    return dist[target];
}

int main() {
    
    int source = 0, target = 4, shortest_dist;
    
    shortest_dist = dijkstra(graph, source, target);
    
    if (shortest_dist == INT_MAX)
        printf("No path found from node %d to node %d\n", source, target);
    else 
        printf("Shortest distance from node %d to node %d is %d\n", source, target, shortest_dist);
    
    return 0;
}