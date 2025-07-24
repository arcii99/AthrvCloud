//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 10

int maze[ROWS][COLS];

/* Function Declarations */
void init_maze();
void print_maze();
void generate_maze(int row, int col);
void set_wall(int row, int col, int direction);
int get_random_number(int min, int max);

/* Main Function */
int main() {
    srand(time(NULL));  // Seed random number generator
    
    init_maze();
    generate_maze(0,0);
    print_maze();
    
    return 0;
}

/* Function Definitions */

/* Initialize maze with all walls */
void init_maze() {
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            maze[i][j] = 15;  // 15 represents all four walls
        }
    }
}

/* Print maze to console */
void print_maze() {
    printf(" ");
    for(int i=0; i<COLS; i++) {
        printf("__ ");
    }
    printf("\n");
    
    for(int i=0; i<ROWS; i++) {
        printf("|");
        for(int j=0; j<COLS; j++) {
            if(maze[i][j] & 1) {
                printf("  |");
            } else {
                printf("   ");
            }
        }
        printf("\n|");
        for(int j=0; j<COLS; j++) {
            if(maze[i][j] & 8) {
                printf("__");
            } else {
                printf("  ");
            }
            if(maze[i][j] & 4) {
                printf("|");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

/* Recursively generates the maze using a depth-first algorithm */
void generate_maze(int row, int col) {
    maze[row][col] |= 16;  // Mark cell as visited
    
    // Shuffle directions
    int directions[] = {1,2,4,8};
    for(int i=0; i<4; i++) {
        int j = get_random_number(i, 3);
        int temp = directions[i];
        directions[i] = directions[j];
        directions[j] = temp;
    }
    
    // Visit unvisited neighbors
    for(int i=0; i<4; i++) {
        int next_row = row;
        int next_col = col;
        switch(directions[i]) {
            case 1: next_row--; break;  // Up
            case 2: next_col++; break;  // Right
            case 4: next_row++; break;  // Down
            case 8: next_col--; break;  // Left
        }
        if(next_row<0 || next_row>=ROWS || next_col<0 || next_col>=COLS) {
            continue;
        }
        if(maze[next_row][next_col] & 16) {
            continue;
        }
        set_wall(row, col, directions[i]);
        set_wall(next_row, next_col, directions[i]>>2);
        generate_maze(next_row, next_col);
    }
}

/* Set wall between two adjacent cells */
void set_wall(int row, int col, int direction) {
    switch(direction) {
        case 1: maze[row][col] &= ~1; break;  // Up
        case 2: maze[row][col] &= ~2; break;  // Right
        case 4: maze[row][col] &= ~4; break;  // Down
        case 8: maze[row][col] &= ~8; break;  // Left
    }
}

/* Generate random number between min and max (inclusive) */
int get_random_number(int min, int max) {
    return rand()%(max-min+1) + min;
}