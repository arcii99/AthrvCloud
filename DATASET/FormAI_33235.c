//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 12
#define COLS 18

#define WALL '#'
#define PATH ' '
#define START 'S'
#define END 'E'

char maze[ROWS][COLS];
int visited[ROWS][COLS] = { 0 };

// function to print the maze
void print_maze() {
    for (int i = 0; i < ROWS; i++) {
        printf("%s\n", maze[i]);
    }
}

// function to generate the maze
void generate_maze(int row, int col) {
    visited[row][col] = 1;
    maze[row][col] = PATH;

    int dirs[4][2] = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};

    // shuffle the directions randomly
    for (int i = 0; i < 4; i++) {
        int j = rand() % 4;
        int tmp = dirs[i][0];
        dirs[i][0] = dirs[j][0];
        dirs[j][0] = tmp;
        tmp = dirs[i][1];
        dirs[i][1] = dirs[j][1];
        dirs[j][1] = tmp;
    }

    // check to see if we can carve out a path in each direction
    for (int i = 0; i < 4; i++) {
        int new_row = row + dirs[i][0] * 2;
        int new_col = col + dirs[i][1] * 2;
        if (new_row >= 0 && new_row < ROWS && new_col >= 0 && new_col < COLS) {
            if (visited[new_row][new_col] == 0) {
                maze[row + dirs[i][0]][col + dirs[i][1]] = PATH;
                generate_maze(new_row, new_col);
            }
        }
    }
}

int main() {
    srand(time(NULL));

    // initialize the maze with walls
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (i % 2 == 1 && j % 2 == 1) {
                maze[i][j] = PATH;
            } else {
                maze[i][j] = WALL;
            }
        }
    }

    // choose a random starting point
    int start_row = rand() % (ROWS / 2) * 2 + 1;
    int start_col = rand() % (COLS / 2) * 2 + 1;
    maze[start_row][start_col] = START;

    // generate the maze
    generate_maze(start_row, start_col);

    // choose a random ending point
    int end_row = rand() % (ROWS / 2) * 2 + 1;
    int end_col = rand() % (COLS / 2) * 2 + 1;
    maze[end_row][end_col] = END;

    // print the maze
    print_maze();

    return 0;
}