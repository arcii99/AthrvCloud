//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 25
#define COLS 25

int maze[ROWS][COLS];

void initMaze() {
    int i, j;
    for (i=0; i<ROWS; i++) {
        for (j=0; j<COLS; j++) {
            maze[i][j] = 1;
        }
    }
}

void printMaze() {
    int i, j;
    for (i=0; i<ROWS; i++) {
        for (j=0; j<COLS; j++) {
            printf("%d", maze[i][j]);
        }
        printf("\n");
    }
}

void generateMaze(int row, int col) {
    int i, j;
    maze[row][col] = 0;
    int direction[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    for (i=0; i<4; i++) {
        int r = row + direction[i][0] * 2;
        int c = col + direction[i][1] * 2;
        if (r < 1 || r >= ROWS-1 || c < 1 || c >= COLS-1 || maze[r][c] == 0) {
            continue;
        }
        int r1 = row + direction[i][0];
        int c1 = col + direction[i][1];
        maze[r1][c1] = 0;
        generateMaze(r, c);
    }
}

int main() {
    srand(time(NULL));
    initMaze();
    generateMaze(1, 1);
    printMaze();
    return 0;
}