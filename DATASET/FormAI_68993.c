//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>

#define ROWS 15 
#define COLS 15 

// The maze will be generated using a 2D array of cells
typedef struct cell {
    bool visited;
    bool top_wall;
    bool right_wall;
    bool bottom_wall;
    bool left_wall;
} cell;

cell maze[ROWS][COLS];

// Function to initialize the maze
void init_maze() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            maze[i][j].visited = false;
            maze[i][j].top_wall = true;
            maze[i][j].right_wall = true;
            maze[i][j].bottom_wall = true;
            maze[i][j].left_wall = true;
        }
    }
}

// Function to print the maze
void print_maze() {
    for (int i = 0; i < ROWS; i++) { 
        for (int j = 0; j < COLS; j++) { 
            if (maze[i][j].top_wall) {
                printf(" __");
            } else {
                printf("   ");
            }

            if (maze[i][j].right_wall) {
                printf("|");
            } else {
                printf(" ");
            }
        }

        printf("\n");

        for (int j = 0; j < COLS; j++) {
            if (maze[i][j].bottom_wall) {
                printf(" \u203E\u203E");
            } else {
                printf("   ");
            }
        }

        printf("\n");
    }
}

// Function to generate the maze using a recursive backtracker algorithm
void generate_maze(int row, int col) {
    maze[row][col].visited = true;

    int directions[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    int rand_directions[4] = {0, 1, 2, 3};

    for (int i = 0; i < 4; i++) {
        int rand_index = rand() % 4;
        int temp = rand_directions[rand_index];
        rand_directions[rand_index] = rand_directions[i];
        rand_directions[i] = temp;
    }

    for (int i = 0; i < 4; i++) {
        int next_row = row + directions[rand_directions[i]][0];
        int next_col = col + directions[rand_directions[i]][1];

        if (next_row >= 0 && next_row < ROWS && next_col >= 0 && next_col < COLS && !maze[next_row][next_col].visited) {
            if (rand_directions[i] == 0) {
                maze[row][col].top_wall = false;
                maze[next_row][next_col].bottom_wall = false;
            } else if (rand_directions[i] == 1) {
                maze[row][col].right_wall = false;
                maze[next_row][next_col].left_wall = false;
            } else if (rand_directions[i] == 2) {
                maze[row][col].bottom_wall = false;
                maze[next_row][next_col].top_wall = false;
            } else {
                maze[row][col].left_wall = false;
                maze[next_row][next_col].right_wall = false;
            }

            generate_maze(next_row, next_col);
        }
    }
}

int main() {
    srand(time(NULL));

    init_maze();
    generate_maze(0, 0);
    print_maze();

    return 0;
}