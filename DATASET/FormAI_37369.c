//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: creative
// This is a program that implements a pathfinding algorithm using a grid system.
// The grid is made up of blocks that have a numerical value indicating their passibility.
// Blocks with value 0 cannot be passed through while blocks with higher values can.
// The algorithm uses breadth-first search to find the shortest path from one block to another.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Struct for our blocks in the grid.
typedef struct block {
    int x;
    int y;
    int value;
    bool visited;
} Block;

int main() {
    int grid[10][10] = {
        {1, 1, 1, 1, 0, 1, 0, 1, 1, 1},
        {1, 0, 0, 1, 0, 1, 0, 0, 0, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 1, 0, 1},
        {1, 0, 1, 1, 1, 1, 1, 1, 0, 1},
        {1, 0, 0, 0, 0, 0, 1, 0, 0, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 0, 1},
        {1, 0, 0, 0, 0, 0, 1, 0, 0, 1},
        {1, 0, 1, 1, 1, 0, 1, 1, 1, 1},
        {1, 1, 1, 0, 0, 0, 0, 0, 0, 1}
    };

    // Starting and ending points for the path.
    Block start = {1, 1, 1, false};
    Block end = {9, 8, 1, false};

    // Queue for breadth-first search.
    Block queue[100];
    int front = 0;
    int rear = 0;

    // Enqueue the starting block to begin the search.
    queue[rear++] = start;

    // While there are still blocks in the queue, continue searching.
    while (front != rear) {
        Block current = queue[front++];

        // Check if the current block is the end point.
        if (current.x == end.x && current.y == end.y) {
            printf("Path found!\n");
            return 0;
        }

        // Check the neighboring blocks and enqueue them if they haven't been visited yet.
        if (current.x > 0 && grid[current.x - 1][current.y] > 0 && !queue[(rear - 1)].visited) {
            Block left = {current.x - 1, current.y, grid[current.x - 1][current.y], false};
            queue[rear++] = left;
            left.visited = true;
        }

        if (current.x < 9 && grid[current.x + 1][current.y] > 0 && !queue[(rear - 1)].visited) {
            Block right = {current.x + 1, current.y, grid[current.x + 1][current.y], false};
            queue[rear++] = right;
            right.visited = true;
        }

        if (current.y > 0 && grid[current.x][current.y - 1] > 0 && !queue[(rear - 1)].visited) {
            Block up = {current.x, current.y - 1, grid[current.x][current.y - 1], false};
            queue[rear++] = up;
            up.visited = true;
        }

        if (current.y < 9 && grid[current.x][current.y + 1] > 0 && !queue[(rear - 1)].visited) {
            Block down = {current.x, current.y + 1, grid[current.x][current.y + 1], false};
            queue[rear++] = down;
            down.visited = true;
        }

        // Mark the current block as visited.
        current.visited = true;
    }

    // If we reach this point, no path was found.
    printf("No path found!\n");
    return 0;
}