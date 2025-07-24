//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 15
#define COLS 15

int maze[ROWS][COLS];

void generateMaze(int row, int col) {
    int i, j, r, c, dir;
    int visited = 0;
    int stack[ROWS*COLS][2];

    srand(time(NULL));

    // initialize maze
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            maze[i][j] = 1;
        }
    }

    // pick random starting point
    r = rand() % ROWS;
    c = rand() % COLS;
    maze[r][c] = 0;
    stack[visited][0] = r;
    stack[visited][1] = c;

    // generate maze using DFS algorithm
    while (visited >= 0) {
        r = stack[visited][0];
        c = stack[visited][1];
        dir = rand() % 4;
        if (dir == 0 && r > 0 && maze[r-1][c] == 1) { // up
            maze[r][c] &= ~1;
            maze[r-1][c] &= ~4;
            r--;
            visited++;
            stack[visited][0] = r;
            stack[visited][1] = c;
        }
        else if (dir == 1 && r < ROWS-1 && maze[r+1][c] == 1) { // down
            maze[r][c] &= ~4;
            maze[r+1][c] &= ~1;
            r++;
            visited++;
            stack[visited][0] = r;
            stack[visited][1] = c;
        }
        else if (dir == 2 && c > 0 && maze[r][c-1] == 1) { // left
            maze[r][c] &= ~8;
            maze[r][c-1] &= ~2;
            c--;
            visited++;
            stack[visited][0] = r;
            stack[visited][1] = c;
        }
        else if (dir == 3 && c < COLS-1 && maze[r][c+1] == 1) { // right
            maze[r][c] &= ~2;
            maze[r][c+1] &= ~8;
            c++;
            visited++;
            stack[visited][0] = r;
            stack[visited][1] = c;
        }
        else {
            visited--;
        }
    }
}

void printMaze() {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            if (maze[i][j] & 1) {
                printf("* ");
            }
            else {
                printf("  ");
            }
            if (maze[i][j] & 2) {
                printf("*");
            }
            else {
                printf(" ");
            }
        }
        printf("\n");
        for (j = 0; j < COLS; j++) {
            if (maze[i][j] & 4) {
                printf("* ");
            }
            else {
                printf("  ");
            }
            if (maze[i][j] & 8) {
                printf("*");
            }
            else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

int main() {
    generateMaze(ROWS, COLS);
    printMaze();
    return 0;
}