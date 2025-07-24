//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: realistic
#include <stdio.h>
#include <stdbool.h>

#define ROW 10
#define COL 10

int graph[ROW][COL] = {
    {0, 1, 1, 0, 0, 0, 0, 0, 0, 0},
    {1, 0, 0, 1, 0, 0, 0, 0, 0, 0},
    {1, 0, 0, 1, 1, 0, 0, 0, 0, 0},
    {0, 1, 1, 0, 0, 1, 0, 0, 0, 0},
    {0, 0, 1, 0, 0, 0, 1, 1, 0, 0},
    {0, 0, 0, 1, 0, 0, 1, 0, 0, 0},
    {0, 0, 0, 0, 1, 1, 0, 1, 0, 0},
    {0, 0, 0, 0, 1, 0, 1, 0, 1, 0},
    {0, 0, 0, 0, 0, 0, 0, 1, 0, 1},
    {0, 0, 0, 0, 0, 0, 0, 0, 1, 0}
};

void printPath(int path[], int dist[], int start, int end) {
    printf("Shortest path from %d to %d: ", start, end);
    int i;
    printf("%d", start);
    for (i = end; i != start; i = path[i]) {
        printf(" -> %d", i);
    }
    printf(", distance: %d\n", dist[end]);
}

void Dijkstra(int start, int end) {
    int visited[ROW], dist[ROW], path[ROW];
    int i, j, curr, minDist, next;
    
    // Initialize the visited and distance arrays
    for (i = 0; i < ROW; i++) {
        visited[i] = false;
        dist[i] = graph[start][i];
        path[i] = start;
    }
    
    visited[start] = true;
    
    // Find shortest path to each node
    for (i = 1; i < ROW; i++) {
        minDist = 99999;
        for (j = 0; j < ROW; j++) {
            if (!visited[j] && dist[j] < minDist) {
                curr = j;
                minDist = dist[j];
            }
        }
        
        visited[curr] = true;
        
        for (j = 0; j < ROW; j++) {
            if (!visited[j] && dist[curr] + graph[curr][j] < dist[j]) {
                dist[j] = dist[curr] + graph[curr][j];
                path[j] = curr;
            }
        }
    }
    
    printPath(path, dist, start, end);  
}

int main() {
    int start = 0, end = 5;
    
    Dijkstra(start, end);
    
    return 0;
}