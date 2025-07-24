//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW 10 // number of rows in the maze
#define COL 20 // number of columns in the maze

void init_maze(int maze[][COL]) {
    // Initialize the maze with all walls
    for(int i=0; i<ROW; i++) {
        for(int j=0; j<COL; j++) {
            maze[i][j] = 1;
        }
    }
}

void print_maze(int maze[][COL]) {
    // Print the maze with walls as #-s and paths as spaces
    for(int i=0; i<ROW; i++) {
        for(int j=0; j<COL; j++) {
            if(maze[i][j] == 1) {
                printf("#");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

void generate_maze(int maze[][COL], int row, int col) {
    // Generate a maze using recursive backtracking algorithm
    int row_dir[] = {-1, 0, 1, 0}; // directions taken for row movement
    int col_dir[] = {0, 1, 0, -1}; // directions taken for column movement
    int rand_dir[4] = {0, 1, 2, 3}; // randomize direction of movement
    int temp;
    int rand_index;
    
    // Shuffle random direction array
    for(int i=0; i<4; i++) {
        rand_index = rand() % 4;
        temp = rand_dir[i];
        rand_dir[i] = rand_dir[rand_index];
        rand_dir[rand_index] = temp;
    }
    
    // Try to make a path from current cell
    for(int i=0; i<4; i++) {
        int adj_row = row + row_dir[rand_dir[i]];
        int adj_col = col + col_dir[rand_dir[i]];
        
        // Check if adjacent cell is within bounds and has a wall
        if(adj_row>=0 && adj_row<ROW && adj_col>=0 && adj_col<COL && maze[adj_row][adj_col]==1) {
            // Break the wall and call the function recursively on adjacent cell
            if(rand_dir[i] == 0) {
                maze[row][col] &= ~1; // remove northern wall
                maze[adj_row][adj_col] &= ~4; // remove southern wall
            } else if(rand_dir[i] == 1) {
                maze[row][col] &= ~2; // remove eastern wall
                maze[adj_row][adj_col] &= ~8; // remove western wall
            } else if(rand_dir[i] == 2) {
                maze[row][col] &= ~4; // remove southern wall
                maze[adj_row][adj_col] &= ~1; // remove northern wall
            } else if(rand_dir[i] == 3) {
                maze[row][col] &= ~8; // remove western wall
                maze[adj_row][adj_col] &= ~2; // remove eastern wall
            }
            generate_maze(maze, adj_row, adj_col);
        }
    }
}

int main() {
    srand(time(NULL)); // seed random number generator
    int maze[ROW][COL];
    init_maze(maze);
    generate_maze(maze, 0, 0);
    print_maze(maze);
    return 0;
}