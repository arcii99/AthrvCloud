//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define ROWS 10
#define COLS 10

// Function to print the generated maze
void print_maze(int maze[][COLS])
{
    printf("\nGenerated maze:\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (maze[i][j] == 1) {
                printf("#");
            } else {
                printf(".");
            }
        }
        printf("\n");
    }
}

int main()
{
    // Seed the random number generator
    srand(time(NULL));
    
    // Initialize maze with all walls
    int maze[ROWS][COLS] = {{1}};
    
    // Random starting cell
    int current_row = rand() % ROWS;
    int current_col = rand() % COLS;
    
    // Mark starting cell as visited
    maze[current_row][current_col] = 0;
    
    // Loop until all cells are visited
    while (true) {
        // Possible moves from current cell
        bool moves[4] = {false};
        if (current_row - 2 >= 0 && maze[current_row - 2][current_col] == 1) {
            moves[0] = true;
        }
        if (current_col + 2 < COLS && maze[current_row][current_col + 2] == 1) {
            moves[1] = true;
        }
        if (current_row + 2 < ROWS && maze[current_row + 2][current_col] == 1) {
            moves[2] = true;
        }
        if (current_col - 2 >= 0 && maze[current_row][current_col - 2] == 1) {
            moves[3] = true;
        }
        
        // Check if there are any possible moves
        bool any_moves = false;
        for (int i = 0; i < 4; i++) {
            if (moves[i]) {
                any_moves = true;
                break;
            }
        }
        if (!any_moves) {
            // No possible moves, backtrack
            bool back_moves[4] = {false};
            if (current_row - 1 >= 0 && maze[current_row - 1][current_col] == 0) {
                back_moves[0] = true;
            }
            if (current_col + 1 < COLS && maze[current_row][current_col + 1] == 0) {
                back_moves[1] = true;
            }
            if (current_row + 1 < ROWS && maze[current_row + 1][current_col] == 0) {
                back_moves[2] = true;
            }
            if (current_col - 1 >= 0 && maze[current_row][current_col - 1] == 0) {
                back_moves[3] = true;
            }
            int back_move = rand() % 4;
            while (!back_moves[back_move]) {
                back_move = rand() % 4;
            }
            if (back_move == 0) {
                maze[current_row - 1][current_col] = 0;
                current_row -= 2;
            } else if (back_move == 1) {
                maze[current_row][current_col + 1] = 0;
                current_col += 2;
            } else if (back_move == 2) {
                maze[current_row + 1][current_col] = 0;
                current_row += 2;
            } else {
                maze[current_row][current_col - 1] = 0;
                current_col -= 2;
            }
        } else {
            // Choose a random possible move
            int move = rand() % 4;
            while (!moves[move]) {
                move = rand() % 4;
            }
            if (move == 0) {
                maze[current_row - 1][current_col] = 0;
                maze[current_row - 2][current_col] = 0;
                current_row -= 2;
            } else if (move == 1) {
                maze[current_row][current_col + 1] = 0;
                maze[current_row][current_col + 2] = 0;
                current_col += 2;
            } else if (move == 2) {
                maze[current_row + 1][current_col] = 0;
                maze[current_row + 2][current_col] = 0;
                current_row += 2;
            } else {
                maze[current_row][current_col - 1] = 0;
                maze[current_row][current_col - 2] = 0;
                current_col -= 2;
            }
        }
        // All cells are visited, stop loop
        bool all_visited = true;
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                if (maze[i][j] == 1) {
                    all_visited = false;
                    break;
                }
            }
            if (!all_visited) {
                break;
            }
        }
        if (all_visited) {
            break;
        }
    }
    
    // Print the generated maze
    print_maze(maze);
    
    return 0;
}