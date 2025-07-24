//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: accurate
#include <stdio.h>
#define ROW 10
#define COLUMN 10

void printMaze(char maze[ROW][COLUMN]){
    // A simple function to print the current maze
    printf("\n");
    for(int i=0; i<ROW; i++){
        for(int j=0; j<COLUMN; j++){
            printf("%c ", maze[i][j]);
        }
        printf("\n");
    }
}

void solveMaze(char maze[ROW][COLUMN], int x, int y){
    // We solve the maze using a recursive algorithm
    
    // First we check if we have reached the end of the maze
    if(x == ROW-1 && y == COLUMN-1){
        printf("\nMaze solved!\n");
        printMaze(maze);
        return;
    }
    
    // Mark current cell as visited
    maze[x][y] = '.';
    
    // Check if we can move right
    if(y+1 < COLUMN && maze[x][y+1] == ' '){
        solveMaze(maze, x, y+1); // Recursively solve the maze by moving right
    }
    
    // Check if we can move down
    if(x+1 < ROW && maze[x+1][y] == ' '){
        solveMaze(maze, x+1, y); // Recursively solve the maze by moving down
    }
    
    // Check if we can move left
    if(y-1 >= 0 && maze[x][y-1] == ' '){
        solveMaze(maze, x, y-1); // Recursively solve the maze by moving left
    }
    
    // Check if we can move up
    if(x-1 >= 0 && maze[x-1][y] == ' '){
        solveMaze(maze, x-1, y); // Recursively solve the maze by moving up
    }
    
    // Backtracking
    maze[x][y] = ' '; // Mark current cell as unvisited
}

int main(){
    char maze[ROW][COLUMN] = { // This is the maze we are trying to solve
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', '*', '*', '*', ' ', '*', '*', ' ', '*', ' '},
        {' ', ' ', ' ', '*', ' ', ' ', '*', ' ', '*', ' '},
        {' ', '*', ' ', '*', '*', ' ', '*', '*', '*', ' '},
        {' ', '*', ' ', ' ', ' ', '*', ' ', ' ', ' ', ' '},
        {' ', '*', '*', '*', ' ', '*', '*', '*', ' ', ' '},
        {' ', '*', ' ', ' ', ' ', '*', ' ', ' ', '*', ' '},
        {' ', '*', '*', '*', ' ', ' ', '*', '*', '*', ' '},
        {' ', ' ', ' ', ' ', ' ', '*', ' ', ' ', ' ', ' '},
        {' ', ' ', '*', '*', '*', '*', '*', '*', ' ', ' '}
    };
    
    printf("Maze before solving:\n");
    printMaze(maze);
    
    solveMaze(maze, 0, 0); // We start solving the maze from the top left cell
    
    return 0;
}