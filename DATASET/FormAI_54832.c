//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAZE_SIZE 21 // odd number
#define WALL '+'
#define PATH ' '
#define ROW_EDGE '-'
#define COL_EDGE '|'

char maze[MAZE_SIZE][MAZE_SIZE];

void display_maze() {
    for(int row = 0; row < MAZE_SIZE; row++) {
        for(int col = 0; col < MAZE_SIZE; col++) {
            printf("%c ", maze[row][col]);
        }
        printf("\n");
    }
}

void generate_maze() {
    // initialize maze with walls
    for(int row = 0; row < MAZE_SIZE; row++) {
        for(int col = 0; col < MAZE_SIZE; col++) {
            if(row == 0 || col == 0 || row == MAZE_SIZE - 1 || col == MAZE_SIZE - 1) {
                maze[row][col] = WALL; // maze edge wall
            } else if(row % 2 == 0 && col % 2 == 0) {
                maze[row][col] = WALL; // wall
            } else {
                maze[row][col] = PATH; // path
            }
        }
    }
    
    // randomly remove walls
    srand(time(0));
    
    for(int row = 2; row < MAZE_SIZE - 1; row += 2) {
        for(int col = 2; col < MAZE_SIZE - 1; col += 2) {
            int random_row = row + (rand() % 3) - 1; // choose a random neighboring row
            int random_col = col + (rand() % 3) - 1; // choose a random neighboring column
            
            if(random_row != row) { // remove vertical wall
                maze[(random_row + row) / 2][col] = PATH;
            } else if(random_col != col) { // remove horizontal wall
                maze[row][(random_col + col) / 2] = PATH;
            }
        }
    }
}

int main() {
    generate_maze();
    display_maze();
    
    return 0;
}