//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define ROWS 10
#define COLS 10

void printMaze(int maze[][COLS], int rows, int cols);
void generateMaze(int maze[][COLS], int rows, int cols);

int main() {
    srand(time(NULL));

    int maze[ROWS][COLS] = {0};

    generateMaze(maze, ROWS, COLS);

    printMaze(maze, ROWS, COLS);

    return 0;
}

void generateMaze(int maze[][COLS], int rows, int cols) {
    int i, j;

    //Set the four corners as visited
    maze[0][0] = maze[0][COLS-1] = maze[ROWS-1][0] = maze[ROWS-1][COLS-1] = 1;

    int currentRow = rand() % ROWS;
    int currentCol = rand() % COLS;

    int visitedCells = 1;

    while (visitedCells < rows*cols) {
        bool moved = false;

        while (!moved) {
            int randomNumber = rand() % 4;
            switch(randomNumber) {
                case 0: //Go up
                    if (currentRow > 0 && maze[currentRow-1][currentCol] == 0) {
                        maze[currentRow][currentCol] |= 1;
                        currentRow--;
                        maze[currentRow][currentCol] |= 2;
                        visitedCells++;
                        moved = true;
                    }
                    break;
                case 1: //Go right
                    if (currentCol < cols-1 && maze[currentRow][currentCol+1] == 0) {
                        maze[currentRow][currentCol] |= 2;
                        currentCol++;
                        maze[currentRow][currentCol] |= 1;
                        visitedCells++;
                        moved = true;
                    }
                    break;
                case 2: //Go down
                    if (currentRow < rows-1 && maze[currentRow+1][currentCol] == 0) {
                        maze[currentRow][currentCol] |= 4;
                        currentRow++;
                        maze[currentRow][currentCol] |= 8;
                        visitedCells++;
                        moved = true;
                    }
                    break;
                case 3: //Go left
                    if (currentCol > 0 && maze[currentRow][currentCol-1] == 0) {
                        maze[currentRow][currentCol] |= 8;
                        currentCol--;
                        maze[currentRow][currentCol] |= 4;
                        visitedCells++;
                        moved = true;
                    }
                    break;
            }
        }
    }
}

void printMaze(int maze[][COLS], int rows, int cols) {
    int i, j;

    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("+");
            if (maze[i][j] & 1) {
                printf("--");
            } else {
                printf("  ");
            }
        }
        printf("+\n");
        for (j = 0; j < cols; j++) {
            if (maze[i][j] & 8) {
                printf("|  ");
            } else {
                printf("   ");
            }
        }
        if (maze[i][j-1] & 2) {
            printf("|\n");
        } else {
            printf(" \n");
        }
    }

    for (j = 0; j < cols; j++) {
        printf("+-");
    }
    printf("+\n");
}