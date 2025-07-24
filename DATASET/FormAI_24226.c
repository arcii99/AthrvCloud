//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 20

void initMaze(char maze[ROWS][COLS])
{
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            maze[i][j] = '#';
        }
    }
}

void printMaze(char maze[ROWS][COLS])
{
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf("%c", maze[i][j]);
        }
        printf("\n");
    }
}

void generateMaze(char maze[][COLS], int row, int col)
{
    maze[row][col] = '.';
    int directions[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
    int dir_order[4] = {0,1,2,3};
    int i, j, tmp, next_row, next_col;
    for (i = 0; i < 4; i++) {
        j = i + rand() % (4 - i);
        tmp = dir_order[i];
        dir_order[i] = dir_order[j];
        dir_order[j] = tmp;
    }

    for (i = 0; i < 4; i++) {
        next_row = row + directions[dir_order[i]][0] * 2;
        next_col = col + directions[dir_order[i]][1] * 2;

        if (next_row < 0 || next_row >= ROWS || next_col < 0 || next_col >= COLS) {
            continue;
        }

        if (maze[next_row][next_col] == '#') {
            maze[row + directions[dir_order[i]][0]][col + directions[dir_order[i]][1]] = '.';
            generateMaze(maze, next_row, next_col);
        }
    }
}

int main()
{
    char maze[ROWS][COLS];
    srand(time(NULL));

    initMaze(maze);
    generateMaze(maze, 1, 1);
    printMaze(maze);

    return 0;
}