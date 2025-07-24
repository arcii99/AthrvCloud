//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW 15
#define COLUMN 15

int main() {
    // Initialize random seed
    srand(time(NULL));
    
    // Initialize maze
    int maze[ROW][COLUMN];
    for (int i = 0; i < ROW; i++) {
        for(int j = 0; j < COLUMN; j++) {
            maze[i][j] = 1; // Set all the cells as walls
        }
    }
    
    // Generate random start and end positions
    int start_row = rand() % ROW;
    int start_col = rand() % COLUMN;
    int end_row = rand() % ROW;
    int end_col = rand() % COLUMN;
    maze[start_row][start_col] = 0; // Set start cell as free
    maze[end_row][end_col] = 0; // Set end cell as free
    
    // Generate maze
    int current_row = start_row;
    int current_col = start_col;
    while (current_row != end_row || current_col != end_col) {
        // Check if all the neighbors are walls
        int count = 0;
        if (current_row > 0 && maze[current_row-1][current_col] == 1) count++;
        if (current_row < ROW-1 && maze[current_row+1][current_col] == 1) count++;
        if (current_col > 0 && maze[current_row][current_col-1] == 1) count++;
        if (current_col < COLUMN-1 && maze[current_row][current_col+1] == 1) count++;
        
        if (count > 1) {
            // Mark current cell as free
            maze[current_row][current_col] = 0;
            
            // Choose a random neighbor that is a wall
            int rand_dir;
            do {
                rand_dir = rand() % 4; // 0: up, 1: down, 2: left, 3: right
            } while ((rand_dir == 0 && current_row == 0) || 
                     (rand_dir == 1 && current_row == ROW-1) ||
                     (rand_dir == 2 && current_col == 0) ||
                     (rand_dir == 3 && current_col == COLUMN-1) ||
                     (rand_dir == 0 && maze[current_row-1][current_col] == 0) || 
                     (rand_dir == 1 && maze[current_row+1][current_col] == 0) ||
                     (rand_dir == 2 && maze[current_row][current_col-1] == 0) || 
                     (rand_dir == 3 && maze[current_row][current_col+1] == 0));
                     
            // Carve a passage to the chosen neighbor
            switch(rand_dir) {
                case 0: current_row--; break;
                case 1: current_row++; break;
                case 2: current_col--; break;
                case 3: current_col++; break;
            }
            maze[current_row][current_col] = 0;
        }
        else {
            // Backtrack to the previous cell
            if (current_row > 0 && maze[current_row-1][current_col] == 0) current_row--;
            else if (current_row < ROW-1 && maze[current_row+1][current_col] == 0) current_row++;
            else if (current_col > 0 && maze[current_row][current_col-1] == 0) current_col--;
            else if (current_col < COLUMN-1 && maze[current_row][current_col+1] == 0) current_col++;
        }
    }
    
    // Print maze
    printf("+");
    for (int i = 0; i < COLUMN; i++) printf("--+");
    printf("\n");
    for (int i = 0; i < ROW; i++) {
        printf("|");
        for(int j = 0; j < COLUMN; j++) {
            if (maze[i][j] == 1) printf("##|");
            else {
                if (i == start_row && j == start_col) printf("S |");
                else if (i == end_row && j == end_col) printf(" E|");
                else printf("  |");
            }
        }
        printf("\n+");
        for (int i = 0; i < COLUMN; i++) printf("--+");
        printf("\n");
    }
    
    return 0;
}