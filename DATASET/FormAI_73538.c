//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define ROW 5
#define COL 5

int minDistance(int dist[], int visited[]) {
    // Find the minimum distance vertex
    int min = INT_MAX, minIndex;
    for (int i = 0; i < ROW * COL; i++) {
        if (visited[i] == 0 && dist[i] <= min) {
            min = dist[i];
            minIndex = i;
        }
    }
    return minIndex;
}

void dijkstra(int grid[ROW][COL], int srcX, int srcY, int destX, int destY) {
    int src = srcX * COL + srcY;
    int dest = destX * COL + destY;
    int dist[ROW * COL];
    int visited[ROW * COL];
    int parent[ROW * COL];

    // Initialize arrays
    for (int i = 0; i < ROW * COL; i++) {
        visited[i] = 0;
        dist[i] = INT_MAX;
        parent[i] = -1;
    }

    // Distance from source to itself is 0
    dist[src] = 0;

    // Find shortest path for all vertices
    for (int count = 0; count < ROW * COL - 1; count++) {
        int u = minDistance(dist, visited);
        visited[u] = 1;

        if (u == dest) {
            break;
        }

        // Update dist[v] only if it is not in visited,
        // there is an edge from u to v, and total weight
        // of path from src to v through u is smaller than
        // current value of dist[v]
        int x = u / COL;
        int y = u % COL;
        if (x > 0 && visited[u - COL] == 0 && grid[x - 1][y] != -1 && dist[u] + grid[x - 1][y] < dist[u - COL]) {
            dist[u - COL] = dist[u] + grid[x - 1][y];
            parent[u - COL] = u;
        }
        if (x < ROW - 1 && visited[u + COL] == 0 && grid[x + 1][y] != -1 && dist[u] + grid[x + 1][y] < dist[u + COL]) {
            dist[u + COL] = dist[u] + grid[x + 1][y];
            parent[u + COL] = u;
        }
        if (y > 0 && visited[u - 1] == 0 && grid[x][y - 1] != -1 && dist[u] + grid[x][y - 1] < dist[u - 1]) {
            dist[u - 1] = dist[u] + grid[x][y - 1];
            parent[u - 1] = u;
        }
        if (y < COL - 1 && visited[u + 1] == 0 && grid[x][y + 1] != -1 && dist[u] + grid[x][y + 1] < dist[u + 1]) {
            dist[u + 1] = dist[u] + grid[x][y + 1];
            parent[u + 1] = u;
        }
    }

    // Print path and distance
    if (parent[dest] == -1) {
        printf("No path found");
    } else {
        printf("Shortest path from (%d, %d) to (%d, %d):\n", srcX, srcY, destX, destY);
        printf("Distance: %d\n", dist[dest]);
        int path[ROW * COL], pathIndex = 0, u = dest;
        path[pathIndex++] = dest;
        while (parent[u] != -1) {
            path[pathIndex++] = parent[u];
            u = parent[u];
        }
        printf("Path: ");
        for (int i = pathIndex - 1; i >= 0; i--) {
            int x = path[i] / COL;
            int y = path[i] % COL;
            printf("(%d, %d) ", x, y);
        }
    }
}

int main() {
    int grid[ROW][COL] = {
        { 0, 1, 0, 1, 0 },
        { 1, -1, 1, -1, 1 },
        { 0, 1, 0, 1, 0 },
        { 1, -1, 1, -1, 1 },
        { 0, 1, 0, 1, 0 }
    };
    dijkstra(grid, 0, 0, 4, 4);
    return 0;
}