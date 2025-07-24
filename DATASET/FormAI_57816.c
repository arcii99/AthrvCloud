//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 10

char maze[ROWS][COLS] = {
    {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
    {'#', '.', '.', '.', '#', '.', '.', '.', '.', '#'},
    {'.', '.', '#', '.', '#', '.', '#', '#', '.', '#'},
    {'#', '#', '#', '.', '#', '.', '.', '.', '.', '#'},
    {'#', '.', '.', '.', '.', '#', '#', '#', '.', '.'},
    {'#', '#', '#', '#', '.', '#', '.', '#', '.', '#'},
    {'#', '.', '.', '#', '.', '#', '.', '#', '.', '#'},
    {'#', '#', '.', '#', '.', '#', '.', '#', '.', '#'},
    {'#', '.', '.', '.', '.', '.', '.', '.', '.', '#'},
    {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'}
};

int visited[ROWS][COLS];
int startRow, startCol;
int endRow, endCol;
int pathRow[ROWS * COLS];
int pathCol[ROWS * COLS];
int pathIndex = 0;

void printMaze();
void solveMaze(int row, int col);
int isOnPath(int row, int col);

int main()
{
    srand(time(NULL));
    startRow = rand() % ROWS;
    startCol = rand() % COLS;
    endRow = rand() % ROWS;
    endCol = rand() % COLS;

    printf("Let's solve the maze!\n");
    printf("Start at: (%d, %d)\n", startRow, startCol);
    printf("End at: (%d, %d)\n", endRow, endCol);
    printf("\n");

    solveMaze(startRow, startCol);

    if (visited[endRow][endCol]) {
        printf("Found a path to the end!\n");
        printf("Here's the path: \n");
        printMaze();
    } else {
        printf("Sorry, could not find a path to the end.\n");
        printf("Here's the maze: \n");
        printMaze();
    }

    return 0;
}

void printMaze() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (isOnPath(i, j)) {
                printf("*");
            } else {
                printf("%c", maze[i][j]);
            }
        }
        printf("\n");
    }
}

int isOnPath(int row, int col) {
    for (int i = 0; i < pathIndex; i++) {
        if (pathRow[i] == row && pathCol[i] == col) {
            return 1;
        }
    }
    return 0;
}

void solveMaze(int row, int col) {
    visited[row][col] = 1;

    if (row == endRow && col == endCol) {
        pathRow[pathIndex] = row;
        pathCol[pathIndex] = col;
        pathIndex++;
        return;
    }

    if (row > 0 && maze[row - 1][col] != '#' && visited[row - 1][col] == 0) {
        solveMaze(row - 1, col);
    }
    if (col > 0 && maze[row][col - 1] != '#' && visited[row][col - 1] == 0) {
        solveMaze(row, col - 1);
    }
    if (row < ROWS - 1 && maze[row + 1][col] != '#' && visited[row + 1][col] == 0) {
        solveMaze(row + 1, col);
    }
    if (col < COLS - 1 && maze[row][col + 1] != '#' && visited[row][col + 1] == 0) {
        solveMaze(row, col + 1);
    }

    if (visited[endRow][endCol]) {
        pathRow[pathIndex] = row;
        pathCol[pathIndex] = col;
        pathIndex++;
    }
}