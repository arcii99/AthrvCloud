//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 15
#define COLS 20

int maze[ROWS][COLS];

void generateMaze() {
    srand(time(NULL));
    
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            if(i == 0 || j == 0 || i == ROWS-1 || j == COLS-1) {
                maze[i][j] = 1;
            } else if(rand()%3 == 0) {
                maze[i][j] = 1;
            } else {
                maze[i][j] = 0;
            }
        }
    }
    
    maze[1][1] = 0;
    maze[ROWS-2][COLS-2] = 0;
}

void printMaze() {
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            if(maze[i][j] == 1) {
                printf("██");
            } else {
                printf("░░");
            }
        }
        printf("\n");
    }
}

int main() {
    generateMaze();
    printMaze();
    
    return 0;
}