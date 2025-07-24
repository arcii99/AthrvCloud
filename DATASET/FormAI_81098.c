//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 15
#define COLS 15
#define WALL '#'
#define PATH ' '

void generate_maze(char maze[][COLS]);
void print_maze(char maze[][COLS]);
void dfs(char maze[][COLS], int row, int col);

int main() {
    char maze[ROWS][COLS];

    srand(time(NULL));

    generate_maze(maze);
    print_maze(maze);
    printf("\n");

    dfs(maze, 0, 0);
    print_maze(maze);

    return 0;
}

void generate_maze(char maze[][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (i == 0 || j == 0 || i == ROWS - 1 || j == COLS - 1) {
                maze[i][j] = WALL;
            } else if (i % 2 == 0 && j % 2 == 0) {
                maze[i][j] = WALL;
            } else {
                maze[i][j] = PATH;
            }
        }
    }

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (i == 0 || j == 0 || i == ROWS - 1 || j == COLS - 1) {
                continue;
            }
            if (maze[i][j] == PATH) {
                int r = rand() % 2;
                if (r) {
                    maze[i][j + 1] = WALL;
                } else {
                    maze[i + 1][j] = WALL;
                }
            }
        }
    }
}

void print_maze(char maze[][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%c ", maze[i][j]);
        }
        printf("\n");
    }
}

void dfs(char maze[][COLS], int row, int col) {
    if (row < 0 || col < 0 || row >= ROWS || col >= COLS || maze[row][col] == WALL) {
        return;
    }

    maze[row][col] = 'X';

    dfs(maze, row - 1, col);
    dfs(maze, row, col + 1);
    dfs(maze, row + 1, col);
    dfs(maze, row, col - 1);
}