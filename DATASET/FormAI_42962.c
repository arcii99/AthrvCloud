//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 10

int getRandomNumber(int min, int max) {
    return rand() % (max - min + 1) + min;
}

void printMaze(int maze[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (maze[i][j] == 0) {
                printf("# ");
            } else {
                printf(". ");
            }
        }
        printf("\n");
    }
}

void generateMaze(int maze[ROWS][COLS], int startRow, int startCol) {
    int directionOptions[4] = {1, 2, 3, 4}; // 1: up, 2: right, 3: down, 4: left
    int directionIndex, temp;
    int currentRow = startRow;
    int currentCol = startCol;
    int endRow = getRandomNumber(0, ROWS - 1);
    int endCol = getRandomNumber(0, COLS - 1);
    maze[endRow][endCol] = 2; // 2 represents the end point

    while (currentRow != endRow || currentCol != endCol) {
        directionIndex = getRandomNumber(0, 3);
        temp = directionOptions[0];
        directionOptions[0] = directionOptions[directionIndex];
        directionOptions[directionIndex] = temp;

        for (int i = 0; i < 4; i++) {
            if (directionOptions[i] == 1 && currentRow > 0 && maze[currentRow - 1][currentCol] == 0) {
                maze[currentRow - 1][currentCol] = 1;
                currentRow--;
                break;
            } else if (directionOptions[i] == 2 && currentCol < COLS - 1 && maze[currentRow][currentCol + 1] == 0) {
                maze[currentRow][currentCol + 1] = 1;
                currentCol++;
                break;
            } else if (directionOptions[i] == 3 && currentRow < ROWS - 1 && maze[currentRow + 1][currentCol] == 0) {
                maze[currentRow + 1][currentCol] = 1;
                currentRow++;
                break;
            } else if (directionOptions[i] == 4 && currentCol > 0 && maze[currentRow][currentCol - 1] == 0) {
                maze[currentRow][currentCol - 1] = 1;
                currentCol--;
                break;
            }
        }
    }
}

int main() {
    int maze[ROWS][COLS] = {0};
    srand(time(NULL));
    generateMaze(maze, 0, 0);
    printMaze(maze);
    return 0;
}