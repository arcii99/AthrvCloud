//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ROW 8
#define COL 8

// Create a 2D array graph
typedef struct graph {
    int matrix[ROW][COL];
} Graph;

// Initialize the graph with 0's in all cells
void initGraph(Graph *g) {
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            g->matrix[i][j] = 0;
        }
    }
}

// Add edges between a source vertex and destination vertex
void addEdge(Graph *g, int src, int dest) {
    g->matrix[src][dest] = 1;
    g->matrix[dest][src] = 1;
}

// Print the graph
void printGraph(Graph *g) {
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            printf("%d ", g->matrix[i][j]);
        }
        printf("\n");
    }
}

// Check if the destination vertex is in the queue
bool isDestInQueue(bool queue[], int dest) {
    return queue[dest];
}

// BFS algorithm to find the shortest path between a source and destination vertex
void bfs(Graph *g, int src, int dest) {
    bool visited[ROW] = {false};
    bool queue[ROW] = {false};
    int distances[ROW] = {0};
    int parents[ROW] = {-1};
    int head = 0;

    visited[src] = true;
    queue[src] = true;

    while (head < ROW) {
        int current = head++;

        for (int i = 0; i < COL; i++) {
            if (g->matrix[current][i] == 1 && !visited[i]) {
                visited[i] = true;
                distances[i] = distances[current] + 1;
                parents[i] = current;
                if (!isDestInQueue(queue, i)) {
                    queue[i] = true;
                }
            }
        }
    }

    printf("Shortest path from %d to %d: ", src, dest);

    int current = dest;
    int path[ROW] = {0};
    int count = 0;
    while (parents[current] != -1) {
        path[count++] = current;
        current = parents[current];
    }
    path[count] = src;

    for (int i = count; i >= 0; i--) {
        printf("%d ", path[i]);
    }
    printf("\n");
}

int main() {
    Graph g;
    initGraph(&g);
    addEdge(&g, 0, 1);
    addEdge(&g, 0, 2);
    addEdge(&g, 1, 3);
    addEdge(&g, 1, 4);
    addEdge(&g, 2, 4);
    addEdge(&g, 3, 5);
    addEdge(&g, 4, 5);
    addEdge(&g, 4, 6);
    addEdge(&g, 5, 7);
    addEdge(&g, 6, 7);
    printf("Graph:\n");
    printGraph(&g);
    bfs(&g, 0, 7);
    return 0;
}