//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

#define ROW 6
#define COL 6

int minDist(int dist[], bool visited[]) {
    int min = INT_MAX, min_index;
    for (int i = 0; i < ROW * COL; i++) {
        if (visited[i] == false && dist[i] <= min) {
            min = dist[i], min_index = i;
        }
    }
    return min_index;
}

void dijkstra(int graph[ROW][COL], int source) {
    int dist[ROW * COL]; 
    bool visited[ROW * COL];
    for (int i = 0; i < ROW * COL; i++) {
        dist[i] = INT_MAX, visited[i] = false;
    }
    dist[source] = 0;
    for (int count = 0; count < ROW * COL - 1; count++) {
        int u = minDist(dist, visited);
        visited[u] = true;
        for (int v = 0; v < ROW * COL; v++) {
            if (!visited[v] && graph[u/ROW][u%COL] && dist[u] != INT_MAX && dist[u] + graph[u/ROW][u%COL] < dist[v]) {
                dist[v] = dist[u] + graph[u/ROW][u%COL];
            }
        }
    }
    printf("Vertex   Distance from Source\n");
    for (int i = 0; i < ROW * COL; i++) {
        printf("%d        %d\n", i, dist[i]);
    }
}

int main() {
    int graph[ROW][COL] = {{0, 3, 0, 0, 8, 0},
                           {3, 0, 5, 0, 0, 0},
                           {0, 5, 0, 7, 0, 0},
                           {0, 0, 7, 0, 1, 4},
                           {8, 0, 0, 1, 0, 9},
                           {0, 0, 0, 4, 9, 0}};
    dijkstra(graph, 0);
    return 0;
}