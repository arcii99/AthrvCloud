//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 25
#define COLS 25

int maze[ROWS][COLS];

void print_maze()
{
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            if (maze[i][j] == 1) {
                printf("#");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

void generate_maze()
{
    srand(time(NULL));
    int i, j;
    // fill maze with walls
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            maze[i][j] = 1;
        }
    }
    // randomly place the starting point on the top row
    int start_col = rand() % COLS;
    maze[0][start_col] = 0;
    // randomly place the end point on the bottom row
    int end_col = rand() % COLS;
    maze[ROWS - 1][end_col] = 0;
    // generate the maze
    int row = 2;
    for (i = 0; i < ROWS - 2; i++) {
        int direction;
        int col;
        if (row == ROWS - 1) {
            col = end_col;
        } else if (row == 2) {
            col = start_col;
        } else {
            col = rand() % COLS;
        }
        if (col == start_col) {
            direction = 1; // go right
        } else if (col == end_col) {
            direction = -1; // go left
        } else if (col < start_col) {
            direction = 1; // go right
        } else {
            direction = -1; // go left
        }
        int num_dug = 0;
        while (num_dug < 6) {
            if (maze[row][col] == 1) {
                maze[row][col] = 0;
                num_dug++;
            }
            col += direction;
            if (col < 0 || col >= COLS) {
                col -= direction;
                direction = -direction;
                row++;
                break;
            }
        }
    }
}

int main()
{
    generate_maze();
    print_maze();
    return 0;
}