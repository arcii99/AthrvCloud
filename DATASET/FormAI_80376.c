//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: minimalist
#include <stdio.h>
#define ROW 8
#define COL 8

// Define a function that returns true (1) if the given row and column are valid
int isValid(int row, int col)
{
    return (row >= 0) && (row < ROW) && (col >= 0) && (col < COL);
}

// Define a function that returns true if the current cell is not blocked and has not been visited
int isUnBlocked(int grid[][COL], int row, int col)
{
    return grid[row][col] == 1;
}

// Define a function that returns true if destination has been reached
int isDestination(int row, int col, int destRow, int destCol)
{
    return row == destRow && col == destCol;
}

// Define a function that will print the final path taken
void printPath(int path[][COL], int destRow, int destCol)
{
    printf("\nPath found: ");
    int row = destRow, col = destCol;
    printf("(%d,%d)", row, col);
    while (path[row][col] != -1) {
        int tempRow = row, tempCol = col;
        row = path[tempRow][tempCol] / COL;
        col = path[tempRow][tempCol] % COL;
        printf(" -> (%d,%d)", row, col);
    }
}

// Define the main function
int main()
{
    int startRow = 0, startCol = 0, destRow = 7, destCol = 7;
    int grid[ROW][COL] = {
        { 1, 0, 1, 1, 1, 1, 0, 1 },
        { 1, 0, 1, 0, 1, 1, 1, 1 },
        { 1, 1, 1, 0, 1, 1, 0, 1 },
        { 0, 0, 0, 0, 1, 0, 0, 1 },
        { 1, 1, 1, 0, 1, 1, 1, 1 },
        { 1, 1, 1, 0, 1, 1, 1, 1 },
        { 1, 1, 1, 0, 1, 1, 1, 1 },
        { 1, 0, 0, 0, 0, 0, 0, 1 }
    };
    int path[ROW][COL];
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            path[i][j] = -1;
        }
    }

    int row, col, newRow, newCol, foundDest = 0;
    int dr[] = { -1, 0, 1, 0 };
    int dc[] = { 0, 1, 0, -1 };
    int queue[ROW * COL];
    int front = -1, rear = -1;
    queue[++rear] = startRow * COL + startCol;
    path[startRow][startCol] = startRow * COL + startCol;

    while (front != rear) {
        int curr = queue[++front];
        row = curr / COL;
        col = curr % COL;

        if (isDestination(row, col, destRow, destCol)) {
            foundDest = 1;
            break;
        }

        for (int i = 0; i < 4; i++) {
            newRow = row + dr[i];
            newCol = col + dc[i];

            if (isValid(newRow, newCol) && isUnBlocked(grid, newRow, newCol) && path[newRow][newCol] == -1) {
                path[newRow][newCol] = row * COL + col;
                queue[++rear] = newRow * COL + newCol;
            }
        }
    }

    if (foundDest) {
        printPath(path, destRow, destCol);
    }
    else {
        printf("Path not found\n");
    }

    return 0;
}