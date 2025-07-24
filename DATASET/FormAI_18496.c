//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 20
#define COLS 40

void createMaze(int maze[][COLS]);
void printMaze(int maze[][COLS]);

int main() {
    int maze[ROWS][COLS];

    srand(time(NULL)); // seed random generator

    createMaze(maze);
    printMaze(maze);

    return 0;
}

void createMaze(int maze[][COLS]) {
    // initialize maze
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            maze[i][j] = 1; // fill with walls
        }
    }

    // create paths
    int pathRow = 1, pathCol = 1;
    maze[pathRow][pathCol] = 0; // starting point

    while(pathRow != ROWS-2 || pathCol != COLS-2) {
        // choose a random direction
        int direction = rand() % 4;
        switch(direction) {
            case 0: // up
                if(pathRow-2 > 0 && maze[pathRow-2][pathCol] != 0) {
                    maze[pathRow-1][pathCol] = 0;
                    maze[pathRow-2][pathCol] = 0;
                    pathRow -= 2;
                }
                break;
            case 1: // right
                if(pathCol+2 < COLS-1 && maze[pathRow][pathCol+2] != 0) {
                    maze[pathRow][pathCol+1] = 0;
                    maze[pathRow][pathCol+2] = 0;
                    pathCol += 2;
                }
                break;
            case 2: // down
                if(pathRow+2 < ROWS-1 && maze[pathRow+2][pathCol] != 0) {
                    maze[pathRow+1][pathCol] = 0;
                    maze[pathRow+2][pathCol] = 0;
                    pathRow += 2;
                }
                break;
            case 3: // left
                if(pathCol-2 > 0 && maze[pathRow][pathCol-2] != 0) {
                    maze[pathRow][pathCol-1] = 0;
                    maze[pathRow][pathCol-2] = 0;
                    pathCol -= 2;
                }
                break;
        }
    }
    
    // add entrance and exit
    maze[1][0] = 0;
    maze[ROWS-2][COLS-1] = 0;
}

void printMaze(int maze[][COLS]) {
    printf("\n");

    // print maze
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            if(maze[i][j] == 0) {
                printf("  ");
            }
            else {
                printf("# ");
            }
        }
        printf("\n");
    }

    printf("\n");
}