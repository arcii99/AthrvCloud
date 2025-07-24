//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 20
#define COLS 20

void generateMaze(int maze[ROWS][COLS], int row, int col);
void printMaze(int maze[ROWS][COLS]);

int main() {
    int maze[ROWS][COLS];
    srand(time(NULL));
    generateMaze(maze, 0, 0);
    printMaze(maze);
    return 0;
}

void generateMaze(int maze[ROWS][COLS], int row, int col) {
    maze[row][col] = 1;
    int directions[4] = {1, 2, 3, 4}; // 1 = Up, 2 = Right, 3 = Down, 4 = Left
    int temp, randIndex;

    // Shuffle the direction array randomly
    for (int i = 3; i > 0; i--) {
        randIndex = rand() % (i + 1);
        temp = directions[i];
        directions[i] = directions[randIndex];
        directions[randIndex] = temp;
    }

    // Try each direction in random order
    for (int i = 0; i < 4; i++) {
        switch(directions[i]) {
            case 1: // Up
                if (row > 0 && maze[row-1][col] == 0) {
                    maze[row-1][col] = 1;
                    generateMaze(maze, row-1, col);
                }
                break;
            case 2: // Right
                if (col < COLS-1 && maze[row][col+1] == 0) {
                    maze[row][col+1] = 1;
                    generateMaze(maze, row, col+1);
                }
                break;
            case 3: // Down
                if (row < ROWS-1 && maze[row+1][col] == 0) {
                    maze[row+1][col] = 1;
                    generateMaze(maze, row+1, col);
                }
                break;
            case 4: // Left
                if (col > 0 && maze[row][col-1] == 0) {
                    maze[row][col-1] = 1;
                    generateMaze(maze, row, col-1);
                }
                break;
        }
    }
}

void printMaze(int maze[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (maze[i][j] == 1) {
                printf(".");
            } else {
                printf("#");
            }
        }
        printf("\n");
    }
}