//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 10

char maze[2 * ROWS + 1][2 * COLS + 1];

// Helper function to check if a cell is within the bounds of the maze
int in_bounds(int row, int col) {
    return (row >= 0 && row < ROWS && col >= 0 && col < COLS);
}

// Recursive function to create the maze using the Recursive Backtracking algorithm
void generate_maze(int row, int col) {
    // Mark current cell as visited
    maze[2 * row + 1][2 * col + 1] = ' ';

    // Create a list of unvisited neighbors
    int neighbors[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    for (int i = 0; i < 4; i++) {
        int new_row = row + neighbors[i][0];
        int new_col = col + neighbors[i][1];
        if (in_bounds(new_row, new_col) && maze[2 * new_row + 1][2 * new_col + 1] == '#') {
            maze[row + new_row + 1][col + new_col + 1] = ' ';
            generate_maze(new_row, new_col);
        }
    }
}

int main() {
    // Initialize maze with walls
    for (int i = 0; i < 2 * ROWS + 1; i++) {
        for (int j = 0; j < 2 * COLS + 1; j++) {
            if (i % 2 == 0 || j % 2 == 0)
                maze[i][j] = '#';
            else
                maze[i][j] = ' ';
        }
    }

    // Seed random number generator and generate maze starting from a random cell
    srand(time(NULL));
    int start_row = rand() % ROWS;
    int start_col = rand() % COLS;
    generate_maze(start_row, start_col);

    // Print out the maze
    for (int i = 0; i < 2 * ROWS + 1; i++) {
        for (int j = 0; j < 2 * COLS + 1; j++) {
            printf("%c", maze[i][j]);
        }
        printf("\n");
    }

    return 0;
}