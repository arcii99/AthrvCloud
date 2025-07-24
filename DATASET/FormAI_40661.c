//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: secure
#include<stdio.h>
#include<limits.h>

#define ROW 10
#define COL 10

int minDistIndex(int dist[], int sptSet[]) {
    int min = INT_MAX, min_index;
    for(int i=0; i<ROW; i++) {
    if(sptSet[i]==0 && dist[i] < min) {
        min = dist[i];
        min_index = i;
        }
    }
    return min_index;
}

void dijkstra(int graph[ROW][COL], int src) {
    int dist[ROW];
    int sptSet[ROW];
    for(int i=0; i<ROW; i++) {
        dist[i] = INT_MAX;
        sptSet[i] = 0;
    }
    dist[src] = 0;
    for(int i=0; i<ROW-1; i++) {
        int u = minDistIndex(dist, sptSet);
        sptSet[u] = 1;
        for(int v=0; v<COL; v++) {
            if(graph[u][v] && sptSet[v]==0 && dist[u] != INT_MAX && dist[u]+graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }
    printf("Node    Distance from Source\n");
    for(int i=0; i<ROW; i++) {
        printf("%d \t%d\n", i, dist[i]);
    }
}

int main() {
    int graph[ROW][COL] = {{0, 4, 0, 0, 0, 0, 0, 8, 0},
                           {4, 0, 8, 0, 0, 0, 0, 11, 0},
                           {0, 8, 0, 7, 0, 4, 0, 0, 2},
                           {0, 0, 7, 0, 9, 14, 0, 0, 0},
                           {0, 0, 0, 9, 0, 10, 0, 0, 0},
                           {0, 0, 4, 14, 10, 0, 2, 0, 0},
                           {0, 0, 0, 0, 0, 2, 0, 1, 6},
                           {8, 11, 0, 0, 0, 0, 1, 0, 7},
                           {0, 0, 2, 0, 0, 0, 6, 7, 0}
                          };
    dijkstra(graph, 0);
    return 0;
}