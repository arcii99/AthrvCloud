//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 10

void printMaze(int maze[][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%c ", maze[i][j] == 1 ? '#' : '.');
        }
        printf("\n");
    }
}

int main() {
    int maze[ROWS][COLS] = {0};

    srand(time(NULL));

    int currentRow = 0;
    int currentCol = 0;
    maze[currentRow][currentCol] = 1;

    while (currentRow != ROWS-1 || currentCol != COLS-1) {
        int direction = rand() % 4;
        switch (direction) {
            case 0: // Up
                if (currentRow > 0 && maze[currentRow-1][currentCol] == 0) {
                    currentRow--;
                    maze[currentRow][currentCol] = 1;
                    maze[currentRow+1][currentCol] = 1;
                }
                break;
            case 1: // Down
                if (currentRow < ROWS-1 && maze[currentRow+1][currentCol] == 0) {
                    currentRow++;
                    maze[currentRow][currentCol] = 1;
                    maze[currentRow-1][currentCol] = 1;
                }
                break;
            case 2: // Left
                if (currentCol > 0 && maze[currentRow][currentCol-1] == 0) {
                    currentCol--;
                    maze[currentRow][currentCol] = 1;
                    maze[currentRow][currentCol+1] = 1;
                }
                break;
            case 3: // Right
                if (currentCol < COLS-1 && maze[currentRow][currentCol+1] == 0) {
                    currentCol++;
                    maze[currentRow][currentCol] = 1;
                    maze[currentRow][currentCol-1] = 1;
                }
                break;
        }
    }

    printMaze(maze);

    return 0;
}