//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define ROWS 10
#define COLS 10

char maze[ROWS][COLS]; // maze array

// recursive function to find the path to the end of the maze
bool findPath(int row, int col){
    // check if we have reached the end of the maze
    if(maze[row][col] == 'X'){
        printf("You have reached the end of the maze!\n");
        return true;
    }
    // check if we are out of bounds or hit a wall
    if(row < 0 || row >= ROWS || col < 0 || col >= COLS || maze[row][col] == '#'){
        return false;
    }
    // mark current position as visited
    maze[row][col] = '.';
    // recursive calls to find the path in all directions
    if(findPath(row-1, col) || findPath(row, col+1) || findPath(row+1, col) || findPath(row, col-1)){
        printf("(%d,%d)\n", row, col);
        return true;
    }
    // backtracking if no path is found in any direction
    maze[row][col] = '*';
    return false;
}

int main(){
    int startRow, startCol, endRow, endCol;
    srand(time(NULL)); // random seed

    // initialize maze with walls and empty spaces
    for(int i=0; i<ROWS; i++){
        for(int j=0; j<COLS; j++){
            maze[i][j] = (rand() % 3 == 0) ? '#' : '_';
            printf("%c ", maze[i][j]);
        }
        printf("\n");
    }

    // randomly select start and end points
    startRow = rand() % ROWS;
    startCol = rand() % COLS;
    endRow = rand() % ROWS;
    endCol = rand() % COLS;

    maze[startRow][startCol] = 'S';
    maze[endRow][endCol] = 'X';

    printf("Starting at (%d,%d), ending at (%d,%d)\n", startRow, startCol, endRow, endCol);

    if(!findPath(startRow, startCol)){
        printf("No path found :(\n");
    }

    return 0;
}