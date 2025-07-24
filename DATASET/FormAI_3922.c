//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: synchronous
#include <stdio.h>
#include <stdbool.h>

#define ROWS 7
#define COLS 10

// An array to store the maze
int maze[ROWS][COLS] = { 
    {0, 1, 0, 0, 0, 1, 0, 1, 0, 0},
    {0, 1, 0, 1, 1, 1, 0, 1, 0, 1},
    {0, 1, 0, 0, 0, 1, 0, 1, 0, 0},
    {1, 1, 1, 1, 0, 1, 0, 1, 1, 1},
    {0, 0, 0, 0, 0, 1, 0, 0, 0, 0},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {0, 0, 0, 0, 0, 1, 0, 0, 0, 0},
};

// A structure to represent a point in the maze
struct Point {
    int row;
    int col;
};

// A function to check whether a given point is valid or not
bool isValid(int row, int col) {
    // Check whether row and column are valid and the current cell is not a wall
    if (row >= 0 && row < ROWS && col >= 0 && col < COLS && maze[row][col] == 0) {
        return true;
    }
    return false;
}

// A function to find the shortest path from start to end using BFS
bool findPath(struct Point start, struct Point end, struct Point path[], int *pathSize) {
    // Create a queue for BFS    
    struct Point queue[ROWS*COLS];
    int front = 0, rear = 0;

    // Create a visited array to keep track of visited cells
    bool visited[ROWS][COLS];
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            visited[i][j] = false;
        }
    }

    // Mark the start cell as visited
    visited[start.row][start.col] = true;

    // Enqueue the start cell
    queue[rear++] = start;

    // Keep traversing the maze until the end cell is found or the queue is empty
    while (front != rear) {
        // Dequeue a cell from the queue
        struct Point current = queue[front++];
        
        // Check whether the end cell has been reached
        if (current.row == end.row && current.col == end.col) {
            // Store the path in the path array
            int i = *pathSize - 1;
            while (i >= 0) {
                path[i] = current;
                current = path[i - 1];
                i--;
            }
            path[0] = start;
            return true;
        }
        
        // Check the neighboring cells of the current cell
        struct Point neighbors[4] = {{current.row - 1, current.col}, 
                                     {current.row + 1, current.col}, 
                                     {current.row, current.col - 1}, 
                                     {current.row, current.col + 1}};
        for (int i = 0; i < 4; i++) {
            int row = neighbors[i].row;
            int col = neighbors[i].col;

            // Check whether the neighbor is valid and has not been visited
            if (isValid(row, col) && !visited[row][col]) {
                visited[row][col] = true;
                queue[rear++] = neighbors[i];
            }
        }
    }
    return false; // No path from start to end exists
}

// A function to print the maze
void printMaze() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%c", maze[i][j] == 0 ? ' ' : '*');
        }
        printf("\n");
    }
}

int main() {
    struct Point start = {0, 0};
    struct Point end = {ROWS - 1, COLS - 1};
    struct Point path[ROWS*COLS];
    int pathSize = ROWS*COLS;

    printf("The maze:\n");
    printMaze();

    if (findPath(start, end, path, &pathSize)) {
        printf("\nThe shortest path from start to end:\n");
        for (int i = 0; i < pathSize; i++) {
            printf("(%d,%d) ", path[i].row, path[i].col);
        }
        printf("\n");
    } else {
        printf("\nThere is no path from start to end.\n");
    }

    return 0;
}