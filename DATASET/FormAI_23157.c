//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 10
#define WALL_CHAR '#'
#define PATH_CHAR ' '
#define START_CHAR 'S'
#define END_CHAR 'E'

void print_maze(char maze[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%c", maze[i][j]);
        }
        printf("\n");
    }
}

void generate_maze(char maze[ROWS][COLS], int start_row, int start_col, int end_row, int end_col) {
    // Generate random maze
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (i == 0 || j == 0 || i == ROWS-1 || j == COLS-1) {
                maze[i][j] = WALL_CHAR;
            } else if (i == start_row && j == start_col) {
                maze[i][j] = START_CHAR;
            } else if (i == end_row && j == end_col) {
                maze[i][j] = END_CHAR;
            } else {
                if (rand() % 2 == 0) {
                    maze[i][j] = WALL_CHAR;
                } else {
                    maze[i][j] = PATH_CHAR;
                }
            }
        }
    }
}

int main() {
    // Initialize maze
    char maze[ROWS][COLS];

    // Set random seed
    srand(time(NULL));

    // Generate maze
    generate_maze(maze, 1, 1, ROWS-2, COLS-2);

    // Print maze
    print_maze(maze);

    return 0;
}