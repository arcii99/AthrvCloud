//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 20
#define COLS 30

void printMaze(char maze[][COLS], int startRow, int startCol) {
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            if(i == startRow && j == startCol)
                printf("S ");
            else
                printf("%c ", maze[i][j]);
        }
        printf("\n");
    }
}

void generateMaze(char maze[][COLS], int row, int col) {
    char directions[] = {'N', 'E', 'S', 'W'};
    int dr[] = {-1, 0, 1, 0};
    int dc[] = {0, 1, 0, -1};
    int visited[ROWS][COLS] = {{0}};
    int stackRow[ROWS * COLS], stackCol[ROWS * COLS];
    int stackTop = 0;
    int i, j, k, ni, nj, r, c, found;

    srand(time(NULL));

    r = rand() % ROWS;
    c = rand() % COLS;

    visited[r][c] = 1;
    stackRow[stackTop] = r;
    stackCol[stackTop] = c;
    stackTop++;

    while(stackTop > 0) {
        r = stackRow[stackTop - 1];
        c = stackCol[stackTop - 1];
        found = 0;

        for(k = 0; k < 4 && !found; k++) {
            i = rand() % 4;
            ni = r + dr[i];
            nj = c + dc[i];

            if(ni >= 0 && nj >= 0 && ni < ROWS && nj < COLS) {
                if(!visited[ni][nj]) {
                    maze[r + dr[i]][c + dc[i]] = ' ';
                    visited[ni][nj] = 1;
                    stackRow[stackTop] = ni;
                    stackCol[stackTop] = nj;
                    stackTop++;
                    found = 1;
                }
            }
        }

        if(!found) {
            stackTop--;
        }
    }

    maze[row][col] = 'G';
}

int main() {
    char maze[ROWS][COLS] = {{'#'}};
    int startRow, startCol;

    startRow = rand() % ROWS;
    startCol = rand() % COLS;

    generateMaze(maze, startRow, startCol);

    printMaze(maze, startRow, startCol);

    return 0;
}