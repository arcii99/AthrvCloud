//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// define row and column sizes for the maze
#define ROW_SIZE 21
#define COL_SIZE 21

// define different cell values
#define WALL 1
#define PATH 0
#define START 2
#define END 3

// function to initialize the maze with all walls
void init_maze(int maze[ROW_SIZE][COL_SIZE]) {
    int i, j;
    for (i = 0; i < ROW_SIZE; i++) {
        for (j = 0; j < COL_SIZE; j++) {
            maze[i][j] = WALL;
        }
    }
}

// function to print the maze
void print_maze(int maze[ROW_SIZE][COL_SIZE]) {
    int i, j;
    for (i = 0; i < ROW_SIZE; i++) {
        for (j = 0; j < COL_SIZE; j++) {
            switch (maze[i][j]) {
                case WALL:
                    printf("#");
                    break;
                case PATH:
                    printf(" ");
                    break;
                case START:
                    printf("S");
                    break;
                case END:
                    printf("E");
                    break;
            }
        }
        printf("\n");
    }
}

// function to generate the maze
void generate_maze(int maze[ROW_SIZE][COL_SIZE]) {
    // seed random number generator
    srand(time(NULL));
    
    // set start and end positions
    int start_row, start_col, end_row, end_col;
    start_row = rand() % ROW_SIZE;
    start_col = 0;
    end_row = rand() % ROW_SIZE;
    end_col = COL_SIZE - 1;
    maze[start_row][start_col] = START;
    maze[end_row][end_col] = END;
    
    // start generating the maze
    int curr_row, curr_col;
    curr_row = start_row;
    curr_col = start_col;
    while (curr_row != end_row || curr_col != end_col) {
        // pick next cell at random
        int next_row, next_col;
        do {
            next_row = curr_row;
            next_col = curr_col;
            int direction = rand() % 4;
            switch (direction) {
                case 0: // north
                    next_row--;
                    break;
                case 1: // east
                    next_col++;
                    break;
                case 2: // south
                    next_row++;
                    break;
                case 3: // west
                    next_col--;
                    break;
            }
        } while (next_row < 0 || next_row >= ROW_SIZE || next_col < 0 || next_col >= COL_SIZE || maze[next_row][next_col] != WALL);
        
        // remove wall and move to next cell
        if (curr_row == next_row) {
            if (curr_col < next_col) { // east
                maze[curr_row][curr_col+1] = PATH;
            } else { // west
                maze[curr_row][curr_col-1] = PATH;
            }
        } else { // north or south
            if (curr_row < next_row) { // south
                maze[curr_row+1][curr_col] = PATH;
            } else { // north
                maze[curr_row-1][curr_col] = PATH;
            }
        }
        curr_row = next_row;
        curr_col = next_col;
    }
}

int main() {
    int maze[ROW_SIZE][COL_SIZE];
    init_maze(maze);
    generate_maze(maze);
    print_maze(maze);
    return 0;
}