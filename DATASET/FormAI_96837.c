//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: romantic
#include <stdio.h>
#include <limits.h>

#define ROW 10
#define COL 10

int minDistance(int dist[], int visited[]) {
    int min = INT_MAX, index;
    for(int i = 0; i < ROW * COL; i++){
        if(visited[i] == 0 && dist[i] <= min) {
            min = dist[i];
            index = i;
        }
    }
    return index;
}

void printPath(int parent[], int dest) {
    if(parent[dest] == -1) {
        printf("->%d", dest);
        return;
    }
    printPath(parent, parent[dest]);
    printf("->%d", dest);
}

void dijkstra(int graph[ROW][COL], int source, int dest) {
    int dist[ROW * COL];
    int visited[ROW * COL];
    int parent[ROW * COL];
    
    for(int i = 0; i < ROW * COL; i++) {
        dist[i] = INT_MAX;
        visited[i] = 0;
        parent[i] = -1;
    }
    
    dist[source] = 0;
    
    for(int i = 0; i < ROW * COL - 1; i++) {
        int u = minDistance(dist, visited);
        visited[u] = 1;
        
        for(int j = 0; j < ROW * COL; j++) {
            if(!visited[j] && graph[u][j] && dist[u] + graph[u][j] < dist[j]) {
                parent[j] = u;
                dist[j] = dist[u] + graph[u][j];
            }
        }
    }
    
    printf("Path from %d to %d: %d", source, dest, source);
    printPath(parent, dest);
}

int main() {
    int graph[ROW][COL] = {{0, 2, 0, 6, 0},
                        {2, 0, 3, 8, 5},
                        {0, 3, 0, 0, 7},
                        {6, 8, 0, 0, 9},
                        {0, 5, 7, 9, 0}};
    int source = 0;
    int dest = 8;
    dijkstra(graph, source, dest);
    return 0;
}