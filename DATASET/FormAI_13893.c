//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define ROWS 20
#define COLS 20

void generateMaze(int maze[][COLS], int row, int col, int startRow, int startCol) {
    int stackRows[ROWS*COLS], stackCols[ROWS*COLS];
    int topOfStack = -1;
    int visited[ROWS][COLS];
    memset(visited, 0, sizeof(visited));
    stackRows[++topOfStack] = startRow;
    stackCols[topOfStack] = startCol;
    visited[startRow][startCol] = 1;
    while (topOfStack >= 0) {
        int currentRow = stackRows[topOfStack];
        int currentCol = stackCols[topOfStack];
        int directions[4];
        int numOfDirections = 0;
        if (currentRow > 0 && visited[currentRow-1][currentCol] == 0)
            directions[numOfDirections++] = 0;
        if (currentCol < col-1 && visited[currentRow][currentCol+1] == 0)
            directions[numOfDirections++] = 1;
        if (currentRow < row-1 && visited[currentRow+1][currentCol] == 0)
            directions[numOfDirections++] = 2;
        if (currentCol > 0 && visited[currentRow][currentCol-1] == 0)
            directions[numOfDirections++] = 3;
        if (numOfDirections == 0) {
            topOfStack--;
            continue;
        }
        int selectedDirection = directions[rand()%numOfDirections];
        if (selectedDirection == 0) {
            maze[currentRow][currentCol] |= 0x1; // set North
            currentRow--;
            maze[currentRow][currentCol] |= 0x2; // set South
        }
        else if (selectedDirection == 1) {
            maze[currentRow][currentCol] |= 0x4; // set East
            currentCol++;
            maze[currentRow][currentCol] |= 0x8; // set West
        }
        else if (selectedDirection == 2) {
            maze[currentRow][currentCol] |= 0x10; // set South
            currentRow++;
            maze[currentRow][currentCol] |= 0x20; // set North
        }
        else if (selectedDirection == 3) {
            maze[currentRow][currentCol] |= 0x40; // set West
            currentCol--;
            maze[currentRow][currentCol] |= 0x80; // set East
        }
        stackRows[++topOfStack] = currentRow;
        stackCols[topOfStack] = currentCol;
        visited[currentRow][currentCol] = 1;
    }
}

void printMaze(int maze[][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if ((maze[i][j] & 0x10) == 0)
                printf("_");
            else
                printf(" ");
            if ((maze[i][j] & 0x4) == 0)
                printf("|");
            else
                printf(" ");
        }
        printf("\n");
    }
}

int main() {
    int maze[ROWS][COLS];
    memset(maze, 0, sizeof(maze));
    srand((unsigned)time(NULL));
    int startRow = rand()%ROWS;
    int startCol = rand()%COLS;
    generateMaze(maze, ROWS, COLS, startRow, startCol);
    printMaze(maze);
    return 0;
}