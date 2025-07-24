//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define ROW 5
#define COL 5

int graph[ROW][COL] = {{0, 1, 0, 0, 1},
                    {1, 0, 1, 1, 0},
                    {0, 1, 0, 1, 0},
                    {0, 1, 1, 0, 1},
                    {1, 0, 0, 1, 0}};

int visited[ROW];
int distance[ROW];

int minDistance(){
    int min = INT_MAX, min_index;

    for(int i=0; i<ROW; i++){
        if(visited[i] == 0 && distance[i] <= min){
            min = distance[i];
            min_index = i;
        }
    }
    return min_index;
}

void printPath(int parent[], int j){
    if(parent[j] == -1) return;
    printPath(parent, parent[j]);
    printf("%d ", j);
}

void dijkstra(int src){
    for(int i=0; i<ROW; i++){
        visited[i] = 0;
        distance[i] = INT_MAX;
    }

    distance[src] = 0;
    int parent[ROW];
    parent[src] = -1;

    for(int i=0; i<ROW-1; i++){
        int u = minDistance();
        visited[u] = 1;
        for(int v=0; v<ROW; v++){
            if(!visited[v] && graph[u][v] && distance[u]+graph[u][v] < distance[v]){
                parent[v] = u;
                distance[v] = distance[u]+graph[u][v];
            }
        }
    }
    printf("Vertex\tDistance\tPath\n");
    for(int i=0; i<ROW; i++){
        printf("%d\t%d\t\t%d ", i, distance[i], src);
        printPath(parent, i);
        printf("\n");
    }
}

int main(){
    dijkstra(0);
    return 0;
}