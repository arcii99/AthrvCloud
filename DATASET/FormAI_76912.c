//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 20
#define COLS 20

int maze[ROWS][COLS];

void display_maze() {
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            if(maze[i][j] == 0) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

void generate_maze() {
    srand(time(NULL));  // Seed random number generator
    
    // Initialize maze to all walls
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            maze[i][j] = 0;
        }
    }
    
    // Choose random start cell
    int start_row = rand() % ROWS;
    int start_col = rand() % COLS;
    maze[start_row][start_col] = 1;
    
    // Generate maze using depth-first search algorithm
    int stack[ROWS*COLS][2];
    stack[0][0] = start_row;
    stack[0][1] = start_col;
    int top = 1;
    
    while(top > 0) {
        int current_row = stack[top-1][0];
        int current_col = stack[top-1][1];
        top--;
        
        // Check if current cell has unvisited neighbors
        int neighbors[4][2] = {{current_row-1, current_col}, {current_row, current_col+1}, {current_row+1, current_col}, {current_row, current_col-1}};
        int num_neighbors = 0;
        for(int i = 0; i < 4; i++) {
            int row = neighbors[i][0];
            int col = neighbors[i][1];
            if(row >= 0 && row < ROWS && col >= 0 && col < COLS && maze[row][col] == 0) {
                num_neighbors++;
            }
        }
        
        if(num_neighbors == 0) {
            continue;  // Backtrack if no unvisited neighbors
        }
        
        // Randomly choose an unvisited neighbor
        int random_index = rand() % num_neighbors;
        int chosen_row, chosen_col;
        int count = 0;
        for(int i = 0; i < 4; i++) {
            int row = neighbors[i][0];
            int col = neighbors[i][1];
            if(row >= 0 && row < ROWS && col >= 0 && col < COLS && maze[row][col] == 0) {
                if(count == random_index) {
                    chosen_row = row;
                    chosen_col = col;
                    break;
                }
                count++;
            }
        }
        
        // Remove wall between current cell and chosen neighbor
        if(chosen_row < current_row) {
            maze[current_row-1][current_col] = 1;
        } else if(chosen_col > current_col) {
            maze[current_row][current_col+1] = 1;
        } else if(chosen_row > current_row) {
            maze[current_row+1][current_col] = 1;
        } else {
            maze[current_row][current_col-1] = 1;
        }
        
        stack[top][0] = chosen_row;
        stack[top][1] = chosen_col;
        top++;
    }
}

int main() {
    generate_maze();
    display_maze();
    return 0;
}