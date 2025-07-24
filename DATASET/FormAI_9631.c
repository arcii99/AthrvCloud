//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 10

int maze[ROWS][COLS];

int main() {
    srand(time(NULL));
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            if(i==0 || j==0 || i==ROWS-1 || j==COLS-1) {
                maze[i][j] = 1; // set border cells to wall
            } else {
                maze[i][j] = (rand() % 2); // set random value for remaining cells 
            }
        }
    }

    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            if(maze[i][j] == 1) {
                printf("██"); // print wall
            } else {
                printf("  "); // print empty space
            }
        }
        printf("\n");
    }

    return 0;
}