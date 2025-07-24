//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 20
#define COLS 30

enum Direction {
    UP,
    RIGHT,
    DOWN,
    LEFT
};

void generateMaze(int maze[ROWS][COLS]) {
    srand(time(NULL));

    int row = rand() % ROWS;
    int col = rand() % COLS;

    maze[row][col] = 0;

    int moves = 0;
    while (moves < ROWS * COLS) {
        int direction = rand() % 4;
        int newRow = row;
        int newCol = col;

        switch (direction) {
        case UP:
            newRow--;
            break;
        case RIGHT:
            newCol++;
            break;
        case DOWN:
            newRow++;
            break;
        case LEFT:
            newCol--;
            break;
        }

        if (newRow >= 0 && newRow < ROWS && newCol >= 0 && newCol < COLS && maze[newRow][newCol] == -1) {
            maze[newRow][newCol] = maze[row][col] + 1;
            row = newRow;
            col = newCol;
            moves++;
        }
    }
}

void printMaze(int maze[ROWS][COLS]) {
    printf(" ");
    for (int i = 0; i < COLS; i++) {
        printf("__");
    }
    printf("\n");

    for (int i = 0; i < ROWS; i++) {
        printf("|");
        for (int j = 0; j < COLS; j++) {
            if (maze[i][j] == -1) {
                printf("  ");
            }
            else {
                printf(" %c", maze[i][j] % 26 + 'A');
            }

            if (j < COLS - 1 && (maze[i][j + 1] == -1 || maze[i][j] % 2 == 0)) {
                printf("|");
            }
            else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

int main() {
    int maze[ROWS][COLS];

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            maze[i][j] = -1;
        }
    }

    generateMaze(maze);
    printMaze(maze);

    return 0;
}