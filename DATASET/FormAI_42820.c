//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#define ROWS 10 // maze rows
#define COLS 10 // maze columns
  
// maze array
int maze[ROWS][COLS] = {{1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                        {1, 1, 1, 1, 0, 1, 1, 1, 1, 0},
                        {0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
                        {0, 1, 1, 1, 0, 1, 1, 1, 1, 1},
                        {0, 1, 0, 0, 0, 1, 0, 0, 0, 1},
                        {0, 1, 0, 1, 0, 1, 0, 1, 0, 0},
                        {0, 0, 0, 1, 0, 0, 0, 1, 0, 0},
                        {1, 1, 1, 1, 1, 1, 1, 1, 1, 0},
                        {0, 0, 0, 0, 0, 1, 0, 0, 1, 0},
                        {0, 1, 1, 1, 1, 1, 1, 1, 1, 1}};
// start and end positions
typedef struct{
    int row;
    int col;
} Position;
Position start = {0, 0};
Position end = {ROWS-1, COLS-1};
  
// stack structure for backtracking
typedef struct{
    int row;
    int col;
    int dir;
} Element;
Element stack[1000];
int top = -1;
  
// function prototypes
void push(int, int, int);
Element pop();
int isStackEmpty();
  
int main(){
    // direction array
    int dir[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    // mark the start position as visited
    maze[start.row][start.col] = 2;
    // push the start position onto the stack
    push(start.row, start.col, 0);
    // loop until the stack is empty or the end position has been reached
    while(!isStackEmpty()){
        // get the top element of the stack
        Element current = pop();
        // check if the current position is the end position
        if(current.row == end.row && current.col == end.col){
            // print the path from start to end
            printf("Path Found!\n");
            for(int i=top; i>=0; i--){
                printf("(%d, %d)\n", stack[i].row, stack[i].col);
            }
            return 0;
        }
        // loop through the directions
        for(int i=current.dir; i<4; i++){
            // calculate the new position
            int new_row = current.row + dir[i][0];
            int new_col = current.col + dir[i][1];
            // check if the new position is within the maze boundaries
            if(new_row >= 0 && new_row < ROWS && new_col >= 0 && new_col < COLS){
                // check if the new position is open and not visited
                if(maze[new_row][new_col] == 1){
                    // mark the new position as visited
                    maze[new_row][new_col] = 2;
                    // push the new position onto the stack
                    push(new_row, new_col, i+1);
                    // break out of the loop so we don't try other directions
                    break;
                }
            }
        }
    }
    printf("No path found!");
    return 0;
}
  
// push an element onto the stack
void push(int row, int col, int dir){
    top++;
    stack[top].row = row;
    stack[top].col = col;
    stack[top].dir = dir;
}
  
// pop an element off the stack
Element pop(){
    Element e;
    e.row = stack[top].row;
    e.col = stack[top].col;
    e.dir = stack[top].dir;
    top--;
    return e;
}
  
// check if the stack is empty
int isStackEmpty(){
    if(top == -1){
        return 1;
    }
    else{
        return 0;
    }
}