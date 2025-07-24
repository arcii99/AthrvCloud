//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 15
#define COLS 15

// Maze struct
typedef struct maze_s {
    int map[ROWS][COLS];
} maze_t;

// Function prototypes
void print_maze(maze_t *maze);
void generate_maze(maze_t *maze, int start_row, int start_col);

int main() {
    // Initialize maze
    maze_t maze;
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            maze.map[i][j] = 1;
        }
    }

    // Generate maze
    srand(time(NULL));
    int start_row = rand() % ROWS;
    int start_col = rand() % COLS;
    generate_maze(&maze, start_row, start_col);

    // Print maze
    print_maze(&maze);

    return 0;
}

/**
 * Recursive maze generation function
 * @param maze Pointer to maze
 * @param col Column index
 * @param row Row index
 */
void generate_maze(maze_t *maze, int row, int col) {
    // Change current cell to 0
    maze->map[row][col] = 0;

    // Create array of possible directions
    int directions[4] = {0, 1, 2, 3};
    int dir_count = 4;

    // Shuffle directions
    for (int i = 0; i < dir_count; i++) {
        int temp = directions[i];
        int swap_index = rand() % dir_count;
        directions[i] = directions[swap_index];
        directions[swap_index] = temp;
    }

    // Check each direction
    for (int i = 0; i < dir_count; i++) {
        int dir = directions[i];
        switch (dir) {
            case 0: // Up
                if (row - 2 <= 0) {
                    continue;
                }
                if (maze->map[row - 2][col] == 1) {
                    maze->map[row - 1][col] = 0;
                    generate_maze(maze, row - 2, col);
                }
                break;
            case 1: // Right
                if (col + 2 >= COLS - 1) {
                    continue;
                }
                if (maze->map[row][col + 2] == 1) {
                    maze->map[row][col + 1] = 0;
                    generate_maze(maze, row, col + 2);
                }
                break;
            case 2: // Down
                if (row + 2 >= ROWS - 1) {
                    continue;
                }
                if (maze->map[row + 2][col] == 1) {
                    maze->map[row + 1][col] = 0;
                    generate_maze(maze, row + 2, col);
                }
                break;
            case 3: // Left
                if (col - 2 <= 0) {
                    continue;
                }
                if (maze->map[row][col - 2] == 1) {
                    maze->map[row][col - 1] = 0;
                    generate_maze(maze, row, col - 2);
                }
                break;
        }
    }
}

/**
 * Prints maze in console
 * @param maze Pointer to maze
 */
void print_maze(maze_t *maze) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (maze->map[i][j] == 1) {
                printf("#");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}