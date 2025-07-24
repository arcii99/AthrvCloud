//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: medieval
#include <stdio.h>
#include <stdbool.h>

#define ROW 10
#define COL 10

bool isValid(int row, int col)
{
    return (row >= 0) && (row < ROW) && (col >= 0) && (col < COL);
}

bool isUnblocked(int maze[][COL], int row, int col)
{
    return (maze[row][col] == 1);
}

bool isDestination(int row, int col, int destRow, int destCol)
{
    return (row == destRow && col == destCol);
}

void printPath(int path[][COL], int destRow, int destCol)
{
    printf("Path:\n");
    int row = destRow, col = destCol;
    int distance = 0;
    while (path[row][col] != -1) {
        distance++;
        int prevRow = row, prevCol = col;
        row = row - path[row][col];
        col = col - path[prevRow][prevCol];
        printf("(%d, %d)\n", row, col);
    }
    printf("(%d, %d)\n", row, col);
    printf("Distance: %d\n", distance);
}

void findPath(int maze[][COL], int srcRow, int srcCol, int destRow, int destCol)
{
    if (!isValid(srcRow, srcCol)) {
        printf("Invalid starting position\n");
        return;
    }
 
    if (!isValid(destRow, destCol)) {
        printf("Invalid destination position\n");
        return;
    }
 
    if (!isUnblocked(maze, srcRow, srcCol) || !isUnblocked(maze, destRow, destCol)) {
        printf("Cannot find solution\n");
        return;
    }
 
    if (isDestination(srcRow, srcCol, destRow, destCol)) {
        printf("Starting position is the destination\n");
        return;
    }
 
    int row, col;
    int path[ROW][COL];
    for (row = 0; row < ROW; row++) {
        for (col = 0; col < COL; col++) {
            path[row][col] = -1;
        }
    }
 
    int rowMoves[] = {-1, 0, 0, 1};
    int colMoves[] = {0, -1, 1, 0};
 
    bool visited[ROW][COL];
    for (row = 0; row < ROW; row++) {
        for (col = 0; col < COL; col++) {
            visited[row][col] = false;
        }
    }
 
    visited[srcRow][srcCol] = true;
    path[srcRow][srcCol] = 0;
 
    int queueRow[ROW*COL], queueCol[ROW*COL];
    int front = 0, back = 0;
    queueRow[back] = srcRow;
    queueCol[back] = srcCol;
    back++;
 
    while (front != back) {
        int currentRow = queueRow[front];
        int currentCol = queueCol[front];
        front++;
 
        for (int k = 0; k < 4; k++) {
            int rowMove = rowMoves[k];
            int colMove = colMoves[k];
            int newRow = currentRow + rowMove;
            int newCol = currentCol + colMove;
 
            if (isValid(newRow, newCol) && isUnblocked(maze, newRow, newCol) && !visited[newRow][newCol]) {
                visited[newRow][newCol] = true;
                path[newRow][newCol] = rowMove;
                if (isDestination(newRow, newCol, destRow, destCol)) {
                    printPath(path, destRow, destCol);
                    return;
                }
                queueRow[back] = newRow;
                queueCol[back] = newCol;
                back++;
            }
        }
    }
 
    printf("Cannot find solution\n");
}

int main()
{
    int maze[ROW][COL] = 
    {
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 0, 1, 0, 1, 0, 1},
        {1, 0, 1, 1, 0, 1, 1, 1, 0, 1},
        {1, 0, 1, 0, 0, 1, 1, 0, 1, 1},
        {1, 0, 1, 1, 0, 1, 1, 0, 1, 0},
        {1, 0, 0, 1, 0, 1, 1, 0, 0, 1},
        {1, 0, 1, 1, 0, 1, 1, 0, 0, 1},
        {1, 0, 1, 0, 0, 0, 1, 1, 0, 1},
        {1, 0, 1, 1, 0, 1, 1, 1, 0, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
    };
 
    int srcRow = 1, srcCol = 2;
    int destRow = 8, destCol = 8;
 
    findPath(maze, srcRow, srcCol, destRow, destCol);
 
    return 0;
}