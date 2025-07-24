//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define ROWS 10
#define COLS 10

// print the maze
void printMaze(char maze[][COLS]){
    for(int i = 0; i < ROWS; i++){
        for(int j = 0; j < COLS; j++){
            printf("%c ", maze[i][j]);
        }
        printf("\n");
    }
}

// check if a given cell is valid
bool isSafe(char maze[][COLS], int row, int col){
    if(row < 0 || row >= ROWS || col < 0 || col >= COLS || maze[row][col] == '#' || maze[row][col] == 'X'){
        return false;
    }
    return true;
}

// recursive function to find the path to the end
bool findPath(char maze[][COLS], int row, int col){
    if(row == ROWS-1 && col == COLS-1){ // base case: reached the end
        return true;
    }
    if(isSafe(maze, row, col)){ // check if current cell is valid
        maze[row][col] = 'X'; // mark current cell as visited
        
        // move in all possible directions
        if(findPath(maze, row-1, col) || findPath(maze, row+1, col) || findPath(maze, row, col-1) || findPath(maze, row, col+1)){
            return true;
        }
        maze[row][col] = '.'; // backtrack
    }
    return false;
}

int main(){
    char maze[ROWS][COLS];
    
    // generate random maze
    srand(time(NULL));
    for(int i = 0; i < ROWS; i++){
        for(int j = 0; j < COLS; j++){
            int r = rand() % 5;
            if(r == 0){
                maze[i][j] = '#';
            } else {
                maze[i][j] = '.';
            }
        }
    }
    maze[ROWS-1][COLS-1] = '.'; // set the end point
    
    // print the generated maze
    printf("Generated Maze:\n");
    printMaze(maze);
    
    // solve the maze
    if(findPath(maze, 0, 0)){
        printf("\nPath found!\n");
        printMaze(maze);
    } else {
        printf("\nNo path found!\n");
    }
    
    return 0;
}