//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define N 10
#define INF 99999

// function prototypes
void dijkstra(int graph[N][N], int start);
void printPath(int parent[N], int node);

int main() {
    int graph[N][N] = {{0, 1, 3, INF, INF, INF, INF, INF, INF, INF},
                       {1, 0, 2, 5, INF, INF, INF, INF, INF, INF},
                       {3, 2, 0, 3, 1, INF, INF, INF, INF, INF},
                       {INF, 5, 3, 0, 4, 5, INF, INF, INF, INF},
                       {INF, INF, 1, 4, 0, 2, 6, INF, INF, INF},
                       {INF, INF, INF, 5, 2, 0, INF, 4, INF, INF},
                       {INF, INF, INF, INF, 6, INF, 0, 3, 6, INF},
                       {INF, INF, INF, INF, INF, 4, 3, 0, 2, 5},
                       {INF, INF, INF, INF, INF, INF, 6, 2, 0, 1},
                       {INF, INF, INF, INF, INF, INF, INF, 5, 1, 0}};
    int start = 0;
    
    printf("Finding shortest path from START Node\n\n");

    dijkstra(graph, start);

    return 0;
}

void dijkstra(int graph[N][N], int start) {
   
    int parent[N]; // for storing the path
    int distance[N];// for storing the distance
    bool visited[N]; // visited[i] will true if vertex i is included in shortest
                       // path tree or shortest distance from start to i is finalized
    // initialization
    memset(visited, false, sizeof(visited)); // initially no vertex is visited
    memset(distance, INF, sizeof(distance)); // initially distance of all vertices from start is INF
    distance[start] = 0; // distance of start node is 0
    parent[start] = -1; // no parent of start node

    // find shortest path for all vertices
    for(int count = 0; count < N - 1; count++) {
        int u = -1;
        for(int i = 0; i < N; i++) {
            if(!visited[i] && (u == -1 || distance[i] < distance[u])) {
                u = i;
            }
        }

        // Mark the picked vertex as visited
        visited[u] = true;

        // Update distance of adjacent vertices
        for(int v = 0; v < N; v++) {
            if(graph[u][v] && !visited[v] && distance[u] + graph[u][v] < distance[v]) {
                parent[v] = u;
                distance[v] = distance[u] + graph[u][v];
            }
        }
    }

    // Print the shortest path from start to each node
    for(int i = 0; i < N; i++) {
        if(i != start) {
            printf("Shortest distance from %d to %d : %d\n", start, i, distance[i]);
            printf("Path : ");
            printPath(parent, i);
            printf("\n\n");
        }
    }
}

// Print path recursively
void printPath(int parent[N], int node) {
    if(parent[node] == -1) {
        printf("%d ", node);
        return;
    }
    printPath(parent, parent[node]);
    printf("%d ", node);
}