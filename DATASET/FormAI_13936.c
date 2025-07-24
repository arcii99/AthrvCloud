//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 15
#define COLS 15

void create_maze(int maze[][COLS], int row, int col, int visited[][COLS]) {
    visited[row][col] = 1;
    int directions[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int rand_dir, new_row, new_col;
    for (int i = 0; i < 4; i++) {
        rand_dir = rand() % 4;
        new_row = row + directions[rand_dir][0];
        new_col = col + directions[rand_dir][1];
        if (new_row >= 0 && new_row < ROWS && new_col >= 0 && new_col < COLS && !visited[new_row][new_col]) {
            if (rand_dir == 0) {
                maze[row][col] |= 8;
                maze[new_row][new_col] |= 2;
            } else if (rand_dir == 1) {
                maze[row][col] |= 2;
                maze[new_row][new_col] |= 8;
            } else if (rand_dir == 2) {
                maze[row][col] |= 4;
                maze[new_row][new_col] |= 1;
            } else if (rand_dir == 3) {
                maze[row][col] |= 1;
                maze[new_row][new_col] |= 4;
            }
            create_maze(maze, new_row, new_col, visited);
        }
    }
}

void print_maze(int maze[][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (maze[i][j] & 8) {
                printf(" ");
            } else {
                printf("_");
            }
            if (maze[i][j] & 4) {
                if (maze[i][j] & 2) {
                    printf(" ");
                } else {
                    printf("|");
                }
            } else {
                if (maze[i][j] & 2) {
                    printf("|");
                } else {
                    printf(" ");
                }
            }
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));
    int maze[ROWS][COLS] = {0};
    int visited[ROWS][COLS] = {0};
    create_maze(maze, 0, 0, visited);
    print_maze(maze);
    return 0;
}