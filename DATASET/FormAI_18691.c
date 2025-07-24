//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 11
#define COLS 11

int maze[ROWS][COLS];
int visited[ROWS][COLS];

int i, j;
int row, col;
int playerRow = 1;
int playerCol = 1;

int randDir() {
    return rand() % 4;
}

void generateMaze(int row, int col) {
    visited[row][col] = 1;
    int dir, newrow, newcol;
    int dirs[4];
    for (i = 0; i < 4; i++) {
        dirs[i] = i;
    }
    for (i = 0; i < 4; i++) {
        dir = randDir();
        int temp = dirs[dir];
        dirs[dir] = dirs[i];
        dirs[i] = temp;
    }
    for (i = 0; i < 4; i++) {
        dir = dirs[i];
        switch (dir) {
        case 0: // up
            newrow = row - 2;
            newcol = col;
            break;
        case 1: // right
            newrow = row;
            newcol = col + 2;
            break;
        case 2: // down
            newrow = row + 2;
            newcol = col;
            break;
        case 3: // left
            newrow = row;
            newcol = col - 2;
            break;
        }
        if (newrow < 0 || newrow >= ROWS || newcol < 0 || newcol >= COLS) {
            continue;
        }
        if (visited[newrow][newcol]) {
            continue;
        }
        if (dir == 0) { // up
            maze[row - 1][col] = 0;
        }
        if (dir == 1) { // right
            maze[row][col + 1] = 0;
        }
        if (dir == 2) { // down
            maze[row + 1][col] = 0;
        }
        if (dir == 3) { // left
            maze[row][col - 1] = 0;
        }
        generateMaze(newrow, newcol);
    }
}

void drawMaze() {
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            if (maze[i][j] == 1) {
                printf("#");
            }
            else if (i == playerRow && j == playerCol) {
                printf("P");
            }
            else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            maze[i][j] = 1;
            visited[i][j] = 0;
        }
    }
    generateMaze(1, 1);
    printf("Generated Maze:\n");
    drawMaze();
    return 0;
}