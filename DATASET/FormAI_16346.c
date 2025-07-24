//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 15

void print_maze(int maze[ROWS][COLS]);

int main(void) {
    srand(time(NULL));

    int maze[ROWS][COLS];

    // Initialize maze with all walls
    for (int row = 0; row < ROWS; row++) {
        for (int col = 0; col < COLS; col++) {
            maze[row][col] = 15;
        }
    }

    // Choose random starting position
    int row = rand() % ROWS;
    int col = rand() % COLS;
    maze[row][col] &= ~8; // Remove top wall of starting position

    // Generate maze using depth first search algorithm
    int stack[ROWS*COLS][2];
    int stack_top = 0;
    stack[stack_top][0] = row;
    stack[stack_top][1] = col;
    stack_top++;
    while (stack_top > 0) {
        // Pop top of stack
        stack_top--;
        int curr_row = stack[stack_top][0];
        int curr_col = stack[stack_top][1];
        maze[curr_row][curr_col] |= 16; // Mark cell as visited

        // Choose random unvisited neighbor
        int neighbors[4][2] = {{curr_row-1, curr_col}, {curr_row, curr_col+1}, {curr_row+1, curr_col}, {curr_row, curr_col-1}};
        int unvisited_neighbors[4][2];
        int num_unvisited_neighbors = 0;
        for (int i = 0; i < 4; i++) {
            int neighbor_row = neighbors[i][0];
            int neighbor_col = neighbors[i][1];
            if (neighbor_row >= 0 && neighbor_row < ROWS && neighbor_col >= 0 && neighbor_col < COLS && !(maze[neighbor_row][neighbor_col] & 16)) {
                unvisited_neighbors[num_unvisited_neighbors][0] = neighbor_row;
                unvisited_neighbors[num_unvisited_neighbors][1] = neighbor_col;
                num_unvisited_neighbors++;
            }
        }
        if (num_unvisited_neighbors > 0) {
            int random_neighbor_index = rand() % num_unvisited_neighbors;
            int new_row = unvisited_neighbors[random_neighbor_index][0];
            int new_col = unvisited_neighbors[random_neighbor_index][1];

            // Remove wall between current and new cell
            if (new_row < curr_row) {
                maze[curr_row][curr_col] &= ~8; // Remove top wall of current cell
                maze[new_row][new_col] &= ~2; // Remove bottom wall of new cell
            } else if (new_col > curr_col) {
                maze[curr_row][curr_col] &= ~2; // Remove right wall of current cell
                maze[new_row][new_col] &= ~4; // Remove left wall of new cell
            } else if (new_row > curr_row) {
                maze[curr_row][curr_col] &= ~4; // Remove bottom wall of current cell
                maze[new_row][new_col] &= ~8; // Remove top wall of new cell
            } else {
                maze[curr_row][curr_col] &= ~1; // Remove left wall of current cell
                maze[new_row][new_col] &= ~16; // Remove right wall of new cell
            }

            // Push new cell onto stack
            stack[stack_top][0] = new_row;
            stack[stack_top][1] = new_col;
            stack_top++;
        }
    }

    print_maze(maze);

    return 0;
}

void print_maze(int maze[ROWS][COLS]) {
    for (int col = 0; col < COLS; col++) {
        printf(" _");
    }
    printf("\n");

    for (int row = 0; row < ROWS; row++) {
        printf("|");
        for (int col = 0; col < COLS; col++) {
            if (maze[row][col] & 8) { // Check top wall
                printf("_");
            } else {
                printf(" ");
            }
            if (maze[row][col] & 2) { // Check right wall
                printf("|");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}