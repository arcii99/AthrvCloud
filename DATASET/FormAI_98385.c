//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 20
#define COLS 20

int maze[ROWS][COLS];

void generateMaze() {
    srand(time(NULL));
    int i, j;
  
    // initialize maze with walls
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            if (i == 0 || i == ROWS - 1 || j == 0 || j == COLS - 1) {
                maze[i][j] = 1; // set outer walls
            } else {
                maze[i][j] = rand() % 2; // create random walls and paths
            }
        }
    }
  
    // create entrance and exit
    maze[1][0] = 0;
    maze[ROWS - 2][COLS - 1] = 0;
  
    // print maze
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            if (maze[i][j] == 1) {
                printf("#"); // wall
            } else {
                printf("."); // path
            }
        }
        printf("\n");
    }
}

int main() {
    generateMaze();
    return 0;
}