//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 20
#define COLS 20

void generateMaze(int maze[ROWS][COLS]) {
    srand(time(NULL)); // seed the random number generator

    // set the entrance and exit
    maze[0][1] = 0;
    maze[ROWS-1][COLS-2] = 0;

    // fill the maze with walls
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            maze[i][j] = 1;
        }
    }

    // randomly place gaps in the walls to create the maze
    for (int i = 1; i < ROWS-1; i++) {
        for (int j = 1; j < COLS-1; j++) {
            if (i % 2 == 0 && j % 2 == 1) {
                if (rand() % 2 == 0) {
                    maze[i][j] = 0;
                }
            } else if (i % 2 == 1 && j % 2 == 0) {
                if (rand() % 2 == 0) {
                    maze[i][j] = 0;
                }
            }
        }
    }
}

void printMaze(int maze[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (maze[i][j] == 0) {
                printf(" ");
            } else {
                printf("#");
            }
        }
        printf("\n");
    }
}

int main() {
    int maze[ROWS][COLS];

    generateMaze(maze);
    printMaze(maze);

    return 0;
}