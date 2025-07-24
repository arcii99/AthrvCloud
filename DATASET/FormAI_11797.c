//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define ROWS 20
#define COLS 30

typedef enum {WALL, PATH} cell_t;

cell_t maze[ROWS][COLS];

void generate_maze(int row, int col) {
    maze[row][col] = PATH;
    
    int directions[4][2] = {{0,-1}, {0,1}, {-1,0}, {1,0}}; // Left, Right, Up, Down
    
    int order[4] = {0, 1, 2, 3}; // Randomize the order of directions
    for (int i = 0; i < 4; i++) {
        int j = rand() % 4;
        int temp = order[i];
        order[i] = order[j];
        order[j] = temp;
    }
    
    for (int i = 0; i < 4; i++) {
        int next_row = row + directions[order[i]][0];
        int next_col = col + directions[order[i]][1];
        
        if (next_row < 0 || next_row >= ROWS || next_col < 0 || next_col >= COLS || maze[next_row][next_col] != WALL) {
            continue; // Skip this direction if it leads out of bounds or to an already visited cell
        }
        
        // Break down the wall between the current cell and the next cell
        int wall_row = row + (next_row - row) / 2; // Find the row and column of the wall to break down
        int wall_col = col + (next_col - col) / 2; // It's halfway between the current cell and the next cell
        maze[wall_row][wall_col] = PATH;
        
        generate_maze(next_row, next_col); // Recursively generate from the next cell
    }
}

void display_maze() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (maze[i][j] == WALL) {
                printf("X");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));
    
    // Initialize the maze to all walls
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            maze[i][j] = WALL;
        }
    }
    
    generate_maze(1, 1); // Start generating from the top left corner
    
    display_maze();
    
    return 0;
}