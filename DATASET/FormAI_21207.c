//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: ultraprecise
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#define ROW 5
#define COL 5

int minDistance(int dist[], int visited[]) {
    int min = INT_MAX, min_index;
    for(int i=0;i<ROW;i++) {
        if(visited[i]==0 && dist[i]<=min) {
            min = dist[i];
            min_index = i;
        }
    }
    return min_index;
}

int dijkstra(int graph[ROW][COL], int source) {
    int dist[ROW];
    int visited[ROW];
    for(int i=0;i<ROW;i++) {
        dist[i] = INT_MAX;
        visited[i] = 0;
    }
    dist[source] = 0;
    for(int i=0;i<ROW-1;i++) {
        int u = minDistance(dist,visited);
        visited[u] = 1;
        for(int j=0;j<ROW;j++) {
            if(!visited[j] && graph[u][j] && dist[u]!=INT_MAX && (dist[u]+graph[u][j]<dist[j])) {
                dist[j] = dist[u]+graph[u][j];
            }
        }
    }
    printf("Vertex \t Distance from Source\n");
    for(int i=0;i<ROW;i++) {
        printf("%d \t\t %d\n",i,dist[i]);
    }
}

int main() {
    int graph[ROW][COL] = {{0, 1, 4, 0, 0},
                           {1, 0, 2, 5, 0},
                           {4, 2, 0, 0, 1},
                           {0, 5, 0, 0, 3},
                           {0, 0, 1, 3, 0}
                          };
    dijkstra(graph,0);
    return 0;
}