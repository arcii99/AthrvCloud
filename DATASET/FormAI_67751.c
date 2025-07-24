//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: systematic
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define ROWS 15
#define COLS 15

int maze[ROWS][COLS];
int visited[ROWS][COLS];

//function to print the maze
void print_maze(){
    for(int i=0; i<ROWS; i++){
        for(int j=0; j<COLS; j++){
            if(maze[i][j] == 1){
                printf("* ");
            }
            else{
                printf("  ");
            }
        }
        printf("\n");
    }   
}

//function to randomly generate the maze
void generate_maze(int row, int col){
    
    //initialize all cells as unvisited
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            visited[i][j] = 0;
        }
    }
    
    //start at a random cell
    srand(time(NULL));
    int current_row = rand() % row;
    int current_col = rand() % col;
    
    visited[current_row][current_col] = 1;
    
    //initialize stack
    int stack_size = 1;
    int stack_row[row*col];
    int stack_col[row*col];
    stack_row[0] = current_row;
    stack_col[0] = current_col;
    
    //generate maze
    while(stack_size != 0){
        current_row = stack_row[stack_size-1];
        current_col = stack_col[stack_size-1];
        
        //check if current cell has any unvisited neighbors
        int unvisited_count = 0;
        int neighbors[4][2] = {{current_row-1,current_col},{current_row+1,current_col},{current_row,current_col-1},{current_row,current_col+1}};
        for(int i=0; i<4; i++){
            int row = neighbors[i][0];
            int col = neighbors[i][1];
            if(row >= 0 && row < ROWS && col >= 0 && col < COLS){
                if(visited[row][col] == 0){
                    unvisited_count++;
                }
            }
        }
        
        if(unvisited_count == 0){
            stack_size--;
        }
        else{
            //choose a random unvisited neighbor
            int random_index = rand() % 4;
            int row = neighbors[random_index][0];
            int col = neighbors[random_index][1];
            
            if(row >= 0 && row < ROWS && col >= 0 && col < COLS){
                if(visited[row][col] == 0){
                    //remove wall between current cell and chosen neighbor
                    if(row == current_row-1){
                        maze[current_row][current_col] &= ~1;
                        maze[row][col] &= ~4;
                    }
                    else if(row == current_row+1){
                        maze[current_row][current_col] &= ~4;
                        maze[row][col] &= ~1;
                    }
                    else if(col == current_col-1){
                        maze[current_row][current_col] &= ~8;
                        maze[row][col] &= ~2;
                    }
                    else{
                        maze[current_row][current_col] &= ~2;
                        maze[row][col] &= ~8;
                    }
                    
                    //mark chosen neighbor as visited and push to stack
                    visited[row][col] = 1;
                    stack_size++;
                    stack_row[stack_size-1] = row;
                    stack_col[stack_size-1] = col;
                }
            }
        }
        
    }
    
}

int main(){
    
    //initialize all cells as walls
    for(int i=0; i<ROWS; i++){
        for(int j=0; j<COLS; j++){
            maze[i][j] = 15;
        }
    }
    
    generate_maze(ROWS, COLS);
    print_maze();
    
    return 0;
}