//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: Romeo and Juliet
/* Romeo and Juliet's Pathfinding */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ROWS 10
#define COLS 10

// Define the graph as a 2D array
int graph[ROWS][COLS] = { { 1, 0, 1, 0, 0, 0, 1, 1, 1, 1 },
                          { 1, 0, 1, 1, 1, 0, 1, 0, 1, 1 },
                          { 1, 1, 1, 0, 1, 0, 1, 1, 1, 1 },
                          { 0, 0, 0, 0, 1, 0, 1, 0, 0, 1 },
                          { 1, 1, 1, 0, 1, 1, 1, 0, 1, 0 },
                          { 1, 0, 1, 1, 1, 0, 0, 0, 1, 1 },
                          { 1, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
                          { 1, 0, 1, 1, 1, 1, 1, 1, 1, 1 },
                          { 1, 1, 0, 0, 0, 0, 0, 0, 0, 1 },
                          { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 } };

// Define the start and end points
int startX = 0, startY = 0;
int endX = 9, endY = 9;

// Define the queue data structure used in BFS
struct Queue {
    int x;
    int y;
};
struct Queue queue[ROWS * COLS];
int front = 0, rear = -1;

// Define the visited array to keep track of visited nodes
bool visited[ROWS][COLS];

// Define the parent array to keep track of parents of nodes
// Used to backtrack to find the path from end to start
int parent[ROWS][COLS];

// Define the directions array to move in the four directions
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

// Define the bfs function to find the shortest path
void bfs(int startX, int startY) {
    // Add the start node to the queue
    queue[++rear] = (struct Queue){startX, startY};
    visited[startX][startY] = true;

    while (front <= rear) {
        // Dequeue the first node in the queue
        int x = queue[front].x, y = queue[front].y;
        front++;

        // If we have reached the end node, stop the search and backtrack to find the path
        if (x == endX && y == endY) {
            int path[ROWS * COLS], pathLength = 0;
            int currentX = endX, currentY = endY;
            while (currentX != startX || currentY != startY) {
                path[pathLength++] = currentX * COLS + currentY;
                int parentX = parent[currentX][currentY] / COLS;
                int parentY = parent[currentX][currentY] % COLS;
                currentX = parentX;
                currentY = parentY;
            }
            path[pathLength++] = startX * COLS + startY;
            printf("The shortest path from Romeo to Juliet has %d nodes: ", pathLength);
            for (int i = pathLength - 1; i >= 0; i--) {
                printf("(%d, %d)", path[i] / COLS, path[i] % COLS);
                if(i!=0) printf(" -> ");
            }
            return;
        }

        // Add all the unvisited neighbours of the current node to the queue
        for (int i = 0; i < 4; i++) {
            int newX = x + dx[i], newY = y + dy[i];
            if (newX >= 0 && newX < ROWS && newY >= 0 && newY < COLS && graph[newX][newY] == 1 && !visited[newX][newY]) {
                queue[++rear] = (struct Queue){newX, newY};
                visited[newX][newY] = true;
                parent[newX][newY] = x * COLS + y;
            }
        }
    }

    printf("Sorry, Romeo could not find a path to Juliet.");
}

int main() {
    printf("Romeo and Juliet's Pathfinding!\n");
    printf("The graph looks like this:\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
    printf("The start node is (%d, %d), and the end node is (%d, %d).\n", startX, startY, endX, endY);

    bfs(startX, startY);

    return 0;
}