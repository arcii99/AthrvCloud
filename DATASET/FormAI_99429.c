//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 15
#define COLS 25

int maze[ROWS][COLS];
int visitedCells = 0;

void generateMaze(int row, int col);
void printMaze();

int main() {
    srand(time(0));
    int startRow = rand() % ROWS;
    int startCol = rand() % COLS;
    generateMaze(startRow, startCol);
    printMaze();
    return 0;
}

void generateMaze(int row, int col) {
    maze[row][col] = 1;
    visitedCells++;

    while (visitedCells < ROWS * COLS) {
        int newRow = rand() % ROWS;
        int newCol = rand() % COLS;

        if (newRow == row && newCol == col) {
            continue;
        }

        if (newRow == row) {
            int colDiff = newCol - col;

            if (colDiff == 1 && col + 1 < COLS && maze[row][col+1] == 0) {
                maze[row][col+1] = 1;
                generateMaze(row, col+1);
            } else if (colDiff == -1 && col - 1 >= 0 && maze[row][col-1] == 0) {
                maze[row][col-1] = 1;
                generateMaze(row, col-1);
            }

        } else if (newCol == col) {
            int rowDiff = newRow - row;

            if (rowDiff == 1 && row + 1 < ROWS && maze[row+1][col] == 0) {
                maze[row+1][col] = 1;
                generateMaze(row+1, col);
            } else if (rowDiff == -1 && row - 1 >= 0 && maze[row-1][col] == 0) {
                maze[row-1][col] = 1;
                generateMaze(row-1, col);
            }
        }
    }
}

void printMaze() {
    printf("+");
    for (int i = 0; i < COLS; i++) {
        printf("-");
    }
    printf("+\n");

    for (int i = 0; i < ROWS; i++) {
        printf("|");

        for (int j = 0; j < COLS; j++) {
            if (maze[i][j] == 1) {
                printf(" ");
            } else {
                printf("#");
            }
        }

        printf("|\n");
    }

    printf("+");
    for (int i = 0; i < COLS; i++) {
        printf("-");
    }
    printf("+\n");
}