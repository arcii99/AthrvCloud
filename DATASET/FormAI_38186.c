//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAZE_SIZE 11

int maze[MAZE_SIZE][MAZE_SIZE];

void generate_maze(int row, int col);
void print_maze();

int main() {
    // Seed random number generator
    srand(time(NULL));
    
    // Initialize maze to all walls
    for (int i = 0; i < MAZE_SIZE; i++) {
        for (int j = 0; j < MAZE_SIZE; j++) {
            maze[i][j] = 15;
        }
    }
    
    // Generate maze starting at top-left corner
    generate_maze(0, 0);
    
    // Print resulting maze
    print_maze();
    
    return 0;
}

void generate_maze(int row, int col) {
    // Mark current cell as visited
    maze[row][col] -= 1;
    
    // Shuffle direction order
    int directions[4] = {0, 1, 2, 3};
    for (int i = 0; i < 4; i++) {
        int j = rand() % 4;
        int temp = directions[i];
        directions[i] = directions[j];
        directions[j] = temp;
    }
    
    // Visit adjacent cells
    for (int i = 0; i < 4; i++) {
        int next_row = row;
        int next_col = col;
        
        // Check if direction is valid
        if (directions[i] == 0 && row > 0) {
            next_row = row - 1;
        } else if (directions[i] == 1 && col < MAZE_SIZE - 1) {
            next_col = col + 1;
        } else if (directions[i] == 2 && row < MAZE_SIZE - 1) {
            next_row = row + 1;
        } else if (directions[i] == 3 && col > 0) {
            next_col = col - 1;
        }
        
        // Check if next cell is unvisited
        if (maze[next_row][next_col] == 15) {
            // Break down current wall and adjacent wall
            if (directions[i] == 0) {
                maze[row][col] -= 2;
                maze[next_row][next_col] -= 8;
            } else if (directions[i] == 1) {
                maze[row][col] -= 4;
                maze[next_row][next_col] -= 1;
            } else if (directions[i] == 2) {
                maze[row][col] -= 8;
                maze[next_row][next_col] -= 2;
            } else if (directions[i] == 3) {
                maze[row][col] -= 1;
                maze[next_row][next_col] -= 4;
            }
            
            // Generate maze from next cell
            generate_maze(next_row, next_col);
        }
    }
}

void print_maze() {
    for (int i = 0; i < MAZE_SIZE; i++) {
        for (int j = 0; j < MAZE_SIZE; j++) {
            printf("%2d ", maze[i][j]);
        }
        printf("\n");
    }
}