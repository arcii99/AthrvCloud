//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 10

#define WALL 1
#define PATH 0

int maze[ROWS][COLS];

void printMaze() {
    for(int x = 0; x < ROWS; x++) {
        for(int y = 0; y < COLS; y++) {
            if(maze[x][y] == WALL) {
                printf("W ");
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }
    printf("\n");
}

void generateMaze(int x, int y) {
    maze[x][y] = PATH;

    int directions[4] = {0, 1, 2, 3};
    srand(time(NULL));
    for(int i = 0; i < 4; i++) {
        int r = rand() % 4;
        int temp = directions[r];
        directions[r] = directions[i];
        directions[i] = temp;
    }

    for(int i = 0; i < 4; i++) {
        if(directions[i] == 0) {
            if(x - 2 <= 0) {
                continue;
            } else if(maze[x - 2][y] == WALL) {
                maze[x - 1][y] = PATH;
                generateMaze(x - 2, y);
            }
        } else if(directions[i] == 1) {
            if(y + 2 >= COLS - 1) {
                continue;
            } else if(maze[x][y + 2] == WALL) {
                maze[x][y + 1] = PATH;
                generateMaze(x, y + 2);
            }
        } else if(directions[i] == 2) {
            if(x + 2 >= ROWS - 1) {
                continue;
            } else if(maze[x + 2][y] == WALL) {
                maze[x + 1][y] = PATH;
                generateMaze(x + 2, y);
            }
        } else if(directions[i] == 3) {
            if(y - 2 <= 0) {
                continue;   
            } else if(maze[x][y - 2] == WALL) {
                maze[x][y - 1] = PATH;
                generateMaze(x, y - 2);
            }
        }
    }
}

int main() {
    // initialize maze as all walls
    for(int x = 0; x < ROWS; x++) {
        for(int y = 0; y < COLS; y++) {
            maze[x][y] = WALL;
        }
    }

    // generate maze starting from (1,1)
    generateMaze(1,1);

    // print maze
    printMaze();

    return 0;
}