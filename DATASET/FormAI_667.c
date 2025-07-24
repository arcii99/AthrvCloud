//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ROWS 5
#define COLS 5

// Define move directions
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

// Define maze
int maze[ROWS][COLS] = {{0, 1, 0, 0, 0},
                        {0, 1, 0, 1, 0},
                        {0, 0, 0, 0, 0},
                        {0, 1, 1, 1, 0},
                        {0, 0, 0, 1, 0}};

// Define queue for BFS algorithm
int queue[ROWS*COLS][2];
bool visited[ROWS][COLS] = {{false}};

int front = 0;
int rear = -1;
int size = 0;

// Check if the cell within the maze
bool is_within_bounds(int x, int y) {
    return (x >= 0 && x < ROWS && y >= 0 && y < COLS);
}

// BFS algorithm
bool bfs(int start_x, int start_y, int end_x, int end_y) {
    // Add starting point to the queue
    queue[++rear][0] = start_x;
    queue[rear][1] = start_y;
    visited[start_x][start_y] = true;
    size++;

    while (size > 0) {
        int current_x = queue[front][0];
        int current_y = queue[front][1];

        // Check if current cell is the end cell
        if (current_x == end_x && current_y == end_y) {
            return true; // Path found
        }

        // Remove front element from the queue
        front++;
        size--;

        // Explore all the connected cells
        for (int i = 0; i < 4; i++) {
            int new_x = current_x + dx[i];
            int new_y = current_y + dy[i];

            // Check if the new cell is valid and not already visited
            if (is_within_bounds(new_x, new_y) && !visited[new_x][new_y] && maze[new_x][new_y] == 0) {
                // Add the new cell to the queue
                queue[++rear][0] = new_x;
                queue[rear][1] = new_y;
                visited[new_x][new_y] = true;
                size++;
            }
        }
    }

    return false; // Path not found
}

// Main function
int main() {
    if (bfs(0, 0, ROWS-1, COLS-1)) {
        printf("Path found!\n");
    } else {
        printf("Path not found!\n");
    }

    return 0;
}