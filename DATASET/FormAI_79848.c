//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 20
#define COLS 40

void generate_maze(int maze[ROWS][COLS], int row, int col);
void print_maze(int maze[ROWS][COLS]);

int main() {
    int maze[ROWS][COLS];
    srand(time(0)); // Seed the random number generator

    generate_maze(maze, 1, 1); // Generate the maze starting at (1,1)
    print_maze(maze); // Print the maze

    return 0;
}

// Recursive function to generate the maze
void generate_maze(int maze[ROWS][COLS], int row, int col) {
    int directions[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}}; // Possible directions
    int dir_order[4] = {0, 1, 2, 3}; // Randomize the order in which directions are tried
    int temp, rand_dir;

    // Randomize the direction order
    for (int i = 0; i < 4; i++) {
        rand_dir = rand() % 4;
        temp = dir_order[i];
        dir_order[i] = dir_order[rand_dir];
        dir_order[rand_dir] = temp;
    }

    // Try each direction
    for (int i = 0; i < 4; i++) {
        int new_row = row + directions[dir_order[i]][0] * 2; // New row to check
        int new_col = col + directions[dir_order[i]][1] * 2; // New column to check

        // Check if new row and column are within maze bounds
        if (new_row >= 0 && new_row < ROWS && new_col >= 0 && new_col < COLS) {
            if (maze[new_row][new_col] == 0) { // Check if cell has not been visited
                maze[new_row - directions[dir_order[i]][0]][new_col - directions[dir_order[i]][1]] = 1; // Mark wall as passage
                maze[new_row][new_col] = 1; // Mark new cell as visited
                generate_maze(maze, new_row, new_col); // Recursive call for new cell
            }
        }
    }
}

// Function to print the maze
void print_maze(int maze[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (maze[i][j] == 0) { // Print wall
                printf("X");
            } else if (maze[i][j] == 1) { // Print passage
                printf(" ");
            }
        }
        printf("\n");
    }
}