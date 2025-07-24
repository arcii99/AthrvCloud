//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

#define ROWS 10
#define COLS 10

int maze[ROWS][COLS] = { 
    {1, 1, 1, 1, 0, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 0, 1, 1, 1, 1, 1},
    {1, 0, 1, 1, 0, 1, 1, 1, 1, 1},
    {1, 0, 1, 0, 0, 1, 1, 0, 0, 1},
    {1, 0, 0, 0, 1, 0, 0, 0, 0, 0},
    {1, 0, 1, 0, 1, 1, 1, 0, 1, 1},
    {1, 0, 1, 1, 1, 0, 0, 0, 1, 1},
    {1, 0, 0, 0, 1, 0, 1, 1, 0, 0},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 0, 0, 0, 0, 1}
};

int start_row = 0;
int start_col = 0;
int end_row = 9;
int end_col = 9;

int solve_maze(int row, int col) {
    if(row == end_row && col == end_col) {
        maze[row][col] = 2;
        return 1;
    } else if(row < 0 || col < 0 || row >= ROWS || col >= COLS || maze[row][col] == 0 || maze[row][col] == 2) {
        return 0;
    } else {
        maze[row][col] = 2;
        if(solve_maze(row + 1, col) || solve_maze(row, col + 1) || solve_maze(row - 1, col) || solve_maze(row, col - 1)) {
            return 1;
        }
        maze[row][col] = 1;
        return 0;
    }
}

int main() {
    printf("Welcome to the Amazing Maze Route Finder!\n");
    printf("*****************************************\n\n");

    printf("Solving maze starting from row %d, column %d, ending at row %d, column %d...\n\n", start_row, start_col, end_row, end_col);

    if(solve_maze(start_row, start_col)) {
        printf("Solution found!\n\n");
        for(int i = 0; i < ROWS; i++) {
            for(int j = 0; j < COLS; j++) {
                if(maze[i][j] == 2) {
                    printf(".");
                } else {
                    printf("#");
                }
            }
            printf("\n");
        }
    } else {
        printf("Solution not found.\n\n");
    }

    return 0;
}