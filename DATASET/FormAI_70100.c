//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAZE_ROW 25
#define MAZE_COL 25

int maze[MAZE_ROW][MAZE_COL];

// randomly generates a maze using recursive backtracking
void generate_maze(int row_start, int col_start, int row_end, int col_end) {
    int directions[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int dir_order[4] = {0, 1, 2, 3}; // randomize this later
    int temp, next_row, next_col, dir_index;

    // mark starting and ending points
    maze[row_start][col_start] = 2;
    maze[row_end][col_end] = 3;

    // randomize the order in which we explore each direction
    for (int i = 0; i < 4; i++) {
        dir_index = rand() % 4;
        temp = dir_order[dir_index];
        dir_order[dir_index] = dir_order[i];
        dir_order[i] = temp;
    }

    // recursively explore each direction
    for (int i = 0; i < 4; i++) {
        next_row = row_start + directions[dir_order[i]][0];
        next_col = col_start + directions[dir_order[i]][1];

        if (next_row < 0 || next_row >= MAZE_ROW || next_col < 0 || next_col >= MAZE_COL) {
            // skip if we're out of bounds
            continue;
        }
        else if (maze[next_row][next_col] != 0) {
            // skip if we've already explored this cell
            continue;
        }

        // create a path to the next cell
        maze[row_start + directions[dir_order[i]][0] / 2][col_start + directions[dir_order[i]][1] / 2] = 1;
        generate_maze(next_row, next_col, row_end, col_end);
    }
}

// draw the maze to the console
void draw_maze() {
    for (int i = 0; i < MAZE_ROW; i++) {
        for (int j = 0; j < MAZE_COL; j++) {
            if (maze[i][j] == 0) {
                printf("%c", '#');
            }
            else if (maze[i][j] == 1) {
                printf("%c", ' ');
            }
            else if (maze[i][j] == 2) {
                printf("%c", '*');
            }
            else if (maze[i][j] == 3) {
                printf("%c", '#');
            }
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));

    // randomly select starting and ending points
    int row_start = rand() % MAZE_ROW;
    int col_start = 0;
    int row_end = rand() % MAZE_ROW;
    int col_end = MAZE_COL - 1;

    // generate the maze
    generate_maze(row_start, col_start, row_end, col_end);

    // draw the maze
    draw_maze();

    return 0;
}