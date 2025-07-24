//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: curious
#include <stdio.h>
#include <stdbool.h>

#define ROWS 10
#define COLS 10

// function to print the grid
void printGrid(int grid[ROWS][COLS], int startRow, int startCol, int endRow, int endCol) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (i == startRow && j == startCol) {
                printf("S ");
            } else if (i == endRow && j == endCol) {
                printf("E ");
            } else if (grid[i][j] == 0) {
                printf(". ");
            } else {
                printf("# ");
            }
        }
        printf("\n");
    }
}

// function to check if the given cell is valid
bool isValid(int row, int col) {
    return (row >= 0 && row < ROWS) && (col >= 0 && col < COLS);
}

// function to check if the given cell is blocked
bool isBlocked(int grid[ROWS][COLS], int row, int col) {
    return (grid[row][col] == 1);
}

// function to find the path
bool findPath(int grid[ROWS][COLS], int startRow, int startCol, int endRow, int endCol) {
    int rowMovements[] = {-1, 0, 1, 0};
    int colMovements[] = {0, 1, 0, -1};

    // initialize the visited array
    bool visited[ROWS][COLS];
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            visited[i][j] = false;
        }
    }

    // create a queue to store the cells
    int queue[ROWS * COLS][2];
    int front = -1;
    int rear = -1;

    // enqueue the starting cell
    queue[++rear][0] = startRow;
    queue[rear][1] = startCol;

    // mark the starting cell as visited
    visited[startRow][startCol] = true;

    // start the BFS algorithm
    while (front != rear) {
        // dequeue the front cell from the queue
        int currentRow = queue[++front][0];
        int currentCol = queue[front][1];

        // check if we have reached the end
        if (currentRow == endRow && currentCol == endCol) {
            return true;
        }

        // explore the neighboring cells
        for (int i = 0; i < 4; i++) {
            int newRow = currentRow + rowMovements[i];
            int newCol = currentCol + colMovements[i];

            // check if the neighboring cell is valid and unvisited and not blocked
            if (isValid(newRow, newCol) && !visited[newRow][newCol] && !isBlocked(grid, newRow, newCol)) {
                // enqueue the neighboring cell
                queue[++rear][0] = newRow;
                queue[rear][1] = newCol;

                // mark the neighboring cell as visited
                visited[newRow][newCol] = true;
            }
        }
    }

    // there is no valid path from start to end
    return false;
}

int main() {
    int grid[ROWS][COLS] = {
        {0, 0, 1, 0, 0, 0, 1, 0, 0, 0},
        {0, 0, 1, 0, 0, 0, 1, 0, 0, 0},
        {0, 0, 0, 0, 1, 1, 0, 1, 0, 0},
        {0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
        {0, 1, 1, 1, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 1, 0, 0, 1, 0, 0},
        {0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 1, 0, 1, 0, 1, 0},
        {0, 1, 1, 1, 0, 0, 0, 0, 1, 0},
        {0, 0, 0, 0, 1, 0, 0, 0, 0, 0}
    };

    int startRow = 0;
    int startCol = 0;
    int endRow = 9;
    int endCol = 8;

    printf("Original grid:\n");
    printGrid(grid, startRow, startCol, endRow, endCol);

    bool canReach = findPath(grid, startRow, startCol, endRow, endCol);

    if (canReach) {
        printf("Path found!\n");
        printGrid(grid, startRow, startCol, endRow, endCol);
    } else {
        printf("Path not found :(\n");
    }

    return 0;
}