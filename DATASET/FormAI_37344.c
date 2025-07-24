//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 20
#define COLS 30

void generateRandomMaze(int maze[][COLS]);
void printMaze(int maze[][COLS]);

int main() {
    int maze[ROWS][COLS];
    srand(time(NULL)); // set seed for randomization

    generateRandomMaze(maze); // generate the maze
    printMaze(maze); // print the maze

    return 0;
}

void generateRandomMaze(int maze[][COLS]) {
    int i, j;

    // Generate the boundaries
    for (i = 0; i < ROWS; i++) {
        maze[i][0] = 1;
        maze[i][COLS-1] = 1;
    }
    for (j = 0; j < COLS; j++) {
        maze[0][j] = 1;
        maze[ROWS-1][j] = 1;
    }

    // Generate the randomized maze
    for (i = 1; i < ROWS-1; i++) {
        for (j = 1; j < COLS-1; j++) {
            if (i % 2 == 0 && j % 2 == 0) { // if index is even
                maze[i][j] = 0; // set to open path
            }
            else {
                maze[i][j] = rand() % 2; // randomly set to open or blocked path
            }
        }
    }
}

void printMaze(int maze[][COLS]) {
    int i, j;

    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            if (maze[i][j] == 1) {
                printf("#"); // blocked path
            }
            else {
                printf(" "); // open path
            }
        }
        printf("\n");
    }
}