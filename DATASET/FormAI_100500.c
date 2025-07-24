//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 15
#define COLS 15

typedef enum{
    left = 0,
    right,
    up,
    down
} direction;

int maze[ROWS][COLS], visited[ROWS][COLS];

void initialise();
void generate_maze();
void print_maze();

int main(){
    srand(time(NULL)); // set seed for random number generation
    
    initialise();
    generate_maze();
    print_maze();
    
    return 0;
}

void initialise(){
    // set all cells to walls
    for(int i=0; i<ROWS; i++){
        for(int j=0; j<COLS; j++){
            if(i==0 || i==ROWS-1 || j==0 || j==COLS-1){
                maze[i][j] = 1;
            }
            else{
                maze[i][j] = 0;
            }
            visited[i][j] = 0; // none of the cells are visited yet
        }
    }
}

void generate_maze(){
    int curr_row = 2, curr_col = 2;
    visited[curr_row][curr_col] = 1;
    direction dir;
    int moves[4] = {0, 0, 0, 0};
    int rand_num, num_moves;
    
    while(1){
        num_moves = 0;
        if(curr_col > 2 && visited[curr_row][curr_col-2] == 0){ // left
            moves[num_moves++] = left;
        }
        if(curr_col < COLS-3 && visited[curr_row][curr_col+2] == 0){ // right
            moves[num_moves++] = right;
        }
        if(curr_row > 2 && visited[curr_row-2][curr_col] == 0){ // up
            moves[num_moves++] = up;
        }
        if(curr_row < ROWS-3 && visited[curr_row+2][curr_col] == 0){ // down
            moves[num_moves++] = down;
        }
        
        if(num_moves > 0){
            rand_num = rand() % num_moves; // choose a random movement
            dir = moves[rand_num];
            
            switch(dir){
                case left:
                    maze[curr_row][curr_col-1] = 0; // break wall
                    visited[curr_row][curr_col-2] = 1; // mark as visited
                    curr_col -= 2;
                    break;
                case right:
                    maze[curr_row][curr_col+1] = 0; // break wall
                    visited[curr_row][curr_col+2] = 1; // mark as visited
                    curr_col += 2;
                    break;
                case up:
                    maze[curr_row-1][curr_col] = 0; // break wall
                    visited[curr_row-2][curr_col] = 1; // mark as visited
                    curr_row -= 2;
                    break;
                case down:
                    maze[curr_row+1][curr_col] = 0; // break wall
                    visited[curr_row+2][curr_col] = 1; // mark as visited
                    curr_row += 2;
                    break;
            }
        }
        else{ // no available moves
            break;
        }
    }
}

void print_maze(){
    for(int i=0; i<ROWS; i++){
        for(int j=0; j<COLS; j++){
            if(maze[i][j] == 1){
                printf("X");
            }
            else{
                printf(" ");
            }
        }
        printf("\n");
    }
}