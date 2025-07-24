//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 15
#define COLUMNS 15

void generateMaze(int maze[][COLUMNS]);
void printMaze(int maze[][COLUMNS]);
void buildWalls(int maze[][COLUMNS]);
void removeWall(int currentRow, int currentColumn, int direction, int maze[][COLUMNS]);
int checkValidMove(int currentRow, int currentColumn, int maze[][COLUMNS]);

int main() {
    srand(time(NULL));
    int maze[ROWS][COLUMNS];
    buildWalls(maze);
    generateMaze(maze);
    printMaze(maze);
    return 0;
}

void buildWalls(int maze[][COLUMNS]) {
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLUMNS; j++) {
            maze[i][j] = 1;
        }
    }
}

void generateMaze(int maze[][COLUMNS]) {
    int currentRow = 1;
    int currentColumn = 1;
    maze[currentRow][currentColumn] = 0;
    int visitedCells = 1;
    int totalCells = ROWS * COLUMNS;
    int direction;

    while (visitedCells < totalCells) {
        direction = rand() % 4;
        if (checkValidMove(currentRow, currentColumn, maze)) {
            removeWall(currentRow, currentColumn, direction, maze);
            currentRow += (direction == 0) ? 1 : 0;
            currentRow -= (direction == 1) ? 1 : 0;
            currentColumn += (direction == 2) ? 1 : 0;
            currentColumn -= (direction == 3) ? 1 : 0;
            maze[currentRow][currentColumn] = 0;
            visitedCells++;
        }
    }
}

int checkValidMove(int currentRow, int currentColumn, int maze[][COLUMNS]) {
    int validMoves = 0;

    if (currentRow - 2 > 0 && maze[currentRow - 2][currentColumn] == 1) {
        validMoves++;
    }
    if (currentRow + 2 < ROWS && maze[currentRow + 2][currentColumn] == 1) {
        validMoves++;
    }
    if (currentColumn - 2 > 0 && maze[currentRow][currentColumn - 2] == 1) {
        validMoves++;
    }
    if (currentColumn + 2 < COLUMNS && maze[currentRow][currentColumn + 2] == 1) {
        validMoves++;
    }

    if (validMoves > 0) {
        return 1;
    } else {
        return 0;
    }
}

void removeWall(int currentRow, int currentColumn, int direction, int maze[][COLUMNS]) {
    if (direction == 0) {
        maze[currentRow - 1][currentColumn] = 0;
    } else if (direction == 1) {
        maze[currentRow + 1][currentColumn] = 0;
    } else if (direction == 2) {
        maze[currentRow][currentColumn - 1] = 0;
    } else if (direction == 3) {
        maze[currentRow][currentColumn + 1] = 0;
    }
}

void printMaze(int maze[][COLUMNS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            if (maze[i][j] == 1) {
                printf("# ");
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }
}