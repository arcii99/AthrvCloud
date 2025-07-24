//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 15
#define COLS 15
#define WALL 1
#define PATH 0

int maze[ROWS][COLS];

void initializeMaze() {
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            if (i == 0 || j == 0 || i == ROWS - 1 || j == COLS - 1) {
                maze[i][j] = WALL;
            } else {
                maze[i][j] = PATH;
            }
        }
    }
}

void printMaze() {
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            if (maze[i][j] == WALL) {
                printf("# ");
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }
}

void generateMaze(int row, int col) {
    maze[row][col] = WALL;

    while (1) {
        int directions[4] = {0, 1, 2, 3};
        for(int i = 0; i < 4; i++) {
            int j = rand() % 4;
            int temp = directions[i];
            directions[i] = directions[j];
            directions[j] = temp;
        }

        int done = 1;
        for(int i = 0; i < 4; i++) {
            int x = 0;
            int y = 0;
            if (directions[i] == 0 && row > 2) {
                x = -2;
            }
            if (directions[i] == 1 && col < COLS - 3) {
                y = 2;
            }
            if (directions[i] == 2 && row < ROWS - 3) {
                x = 2;
            }
            if (directions[i] == 3 && col > 2) {
                y = -2;
            }
            if (maze[row+x][col+y] == PATH) {
                maze[row+x][col+y] = WALL;
                maze[row+x/2][col+y/2] = WALL;
                generateMaze(row+x,col+y);
                done = 0;
                break;
            }
        }

        if (done == 1) {
            break;
        }
    }
}

int main() {
    srand(time(NULL));
    initializeMaze();
    generateMaze(2,2);
    printMaze();
    return 0;
}