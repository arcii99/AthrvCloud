//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 20
#define COLS 20

void generateMaze(int maze[][COLS]);
void printMaze(int maze[][COLS]);
void clearMaze(int maze[][COLS]);

int main()
{
    int maze[ROWS][COLS];
    srand(time(NULL));

    generateMaze(maze);
    printMaze(maze);

    return 0;
}

void generateMaze(int maze[][COLS])
{
    int i, j;

    clearMaze(maze);

    // Initialize borders 
    for(i = 0; i < ROWS; i++) {
        maze[i][0] = 1;
        maze[i][COLS - 1] = 1;
    }
    for(j = 0; j < COLS; j++) {
        maze[0][j] = 1;
        maze[ROWS - 1][j] = 1;
    }

    // Create maze
    for(i = 2; i < ROWS - 1; i += 2) {
        for(j = 2; j < COLS - 1; j += 2) {
            maze[i][j] = 1;

            if((rand() % 2) == 0) {
                if(maze[i - 1][j] == 0) {
                    maze[i - 1][j] = 1;
                } else {
                    maze[i][j - 1] = 1;
                }
            } else {
                if(maze[i][j - 1] == 0) {
                    maze[i][j - 1] = 1;
                } else {
                    maze[i - 1][j] = 1;
                }
            }
        }
    }
}

void printMaze(int maze[][COLS])
{
    int i, j;
    for(i = 0; i < ROWS; i++) {
        for(j = 0; j < COLS; j++) {
            if(maze[i][j]) {
                printf("X");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

void clearMaze(int maze[][COLS])
{
    int i, j;
    for(i = 0; i < ROWS; i++) {
        for(j = 0; j < COLS; j++) {
            maze[i][j] = 0;
        }
    }
}