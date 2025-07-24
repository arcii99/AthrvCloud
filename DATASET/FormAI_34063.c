//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: Ada Lovelace
// Ada Lovelace style C program demonstrating the Breadth First Search algorithm

#include <stdio.h>

#define N 5                        // Number of nodes (vertices) in the graph

int graph[N][N] = {                // Graph adjacency matrix
    {0, 1, 0, 1, 0},
    {1, 0, 1, 1, 0},
    {0, 1, 0, 1, 1},
    {1, 1, 1, 0, 1},
    {0, 0, 1, 1, 0},
};

int visited[N] = {0};              // To keep track of visited nodes

void BFS(int start) {
    visited[start] = 1;           // Mark the starting node as visited
    int queue[N], front = -1, rear = -1;
    queue[++rear] = start;        // Add the starting node to the queue
    while (front != rear) {    // While the queue is not empty
        int node = queue[++front];      // Get the front node from the queue
        printf("%d\n", node);           // Print the visited node
        for (int i = 0; i < N; i++) {
            if (graph[node][i] == 1 && visited[i] == 0) {
                visited[i] = 1;         // Mark the adjacent node as visited
                queue[++rear] = i;      // Add the adjacent node to the queue
            }
        }
    }
}

int main() {
    printf("Graph:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", graph[i][j]);     // Print the graph
        }
        printf("\n");
    }
    printf("BFS traversal:\n");
    BFS(0);        // Starting from node 0
    return 0;
}