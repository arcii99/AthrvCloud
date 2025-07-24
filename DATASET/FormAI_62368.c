//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: shocked
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define ROWS 15  // maze dimensions
#define COLS 20

void generate_maze(int maze[ROWS][COLS], int start_row, int start_col);

int main()
{
    int maze[ROWS][COLS];
    srand(time(NULL));
    
    // Initialize maze with all walls present
    for(int i=0; i<ROWS; i++){
        for(int j=0; j<COLS; j++){
            maze[i][j] = 1;
        }
    }
    
    // Generate maze
    generate_maze(maze, 0, 0);
    
    // Print maze
    for(int i=0; i<ROWS; i++){
        for(int j=0; j<COLS; j++){
            if(maze[i][j] == 1){
                printf("X ");
            }
            else{
                printf("  ");
            }
        }
        printf("\n");
    }
    
    return 0;
}

void generate_maze(int maze[ROWS][COLS], int row, int col)
{
    int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};  // North, South, West, East
    int temp, temp1;
    
    // Mark current cell as visited
    maze[row][col] = 0;
    
    // Randomly shuffle directions array
    for(int i=0; i<4; i++){
        int r = rand() % 4;
        temp = directions[r][0];
        directions[r][0] = directions[i][0];
        directions[i][0] = temp;

        temp1 = directions[r][1];
        directions[r][1] = directions[i][1];
        directions[i][1] = temp1;
    }
    
    // Loop through all four directions
    for(int i=0; i<4; i++){
        int row_new = row + directions[i][0];
        int col_new = col + directions[i][1];
        
        // Check if new cell is within maze boundaries
        if(row_new<0 || row_new>=ROWS || col_new<0 || col_new>=COLS){
            continue;
        }
        
        // Check if new cell is already visited
        if(maze[row_new][col_new] == 0){
            continue;
        }
        
        // Knock down wall between current and new cell
        if(directions[i][0] == -1){
            maze[row][col] &= ~8;
            maze[row_new][col_new] &= ~2;
        }
        else if(directions[i][0] == 1){
            maze[row][col] &= ~2;
            maze[row_new][col_new] &= ~8;
        }
        else if(directions[i][1] == -1){
            maze[row][col] &= ~1;
            maze[row_new][col_new] &= ~4;
        }
        else if(directions[i][1] == 1){
            maze[row][col] &= ~4;
            maze[row_new][col_new] &= ~1;
        }
        
        // Recursively call function with new cell
        generate_maze(maze, row_new, col_new);
    }
    
}