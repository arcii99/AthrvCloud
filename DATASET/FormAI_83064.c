//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: unmistakable
#include <stdio.h>
#include <stdbool.h>

#define ROWS 10
#define COLS 10

int graph[ROWS][COLS];
bool visited[ROWS][COLS];

// Function to perform BFS traversal of the graph
void bfs(int srcX, int srcY, int destX, int destY) {
    int queue[ROWS*COLS];
    int front = 0, rear = 0;

    // Mark the source node as visited and enqueue it
    visited[srcX][srcY] = true;
    queue[rear++] = srcX * COLS + srcY; // store position as 1D array index

    while (front != rear) {
        // Get the first node from the queue
        int curr = queue[front++];

        // Get x and y coordinates from 1D index
        int x = curr / COLS;
        int y = curr % COLS;

        // If the current node is the destination, we are done
        if (x == destX && y == destY) {
            printf("Path found\n");
            return;
        }

        // Add all adjacent nodes to the queue
        if (x > 0 && !visited[x-1][y] && graph[x-1][y] == 1) { // up
            visited[x-1][y] = true;
            queue[rear++] = (x-1) * COLS + y;
        }
        if (y > 0 && !visited[x][y-1] && graph[x][y-1] == 1) { // left
            visited[x][y-1] = true;
            queue[rear++] = x * COLS + (y-1);
        }
        if (x < ROWS-1 && !visited[x+1][y] && graph[x+1][y] == 1) { // down
            visited[x+1][y] = true;
            queue[rear++] = (x+1) * COLS + y;
        }
        if (y < COLS-1 && !visited[x][y+1] && graph[x][y+1] == 1) { // right
            visited[x][y+1] = true;
            queue[rear++] = x * COLS + (y+1);
        }
    }

    // If we reached here, path not found
    printf("Path not found\n");
}

int main() {
    // Initialize the graph with some obstacles
    graph[1][0] = 1;
    graph[2][1] = 1;
    graph[3][2] = 1;
    graph[4][3] = 1;
    graph[5][4] = 1;
    graph[6][5] = 1;

    // Try to find a path from (0,0) to (9,9)
    bfs(0,0,9,9);

    return 0;
}