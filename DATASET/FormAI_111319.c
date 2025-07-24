//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: light-weight
#include <stdio.h>
#include <stdbool.h>

#define ROW 6 //maze rows
#define COL 12 //maze columns

//print the maze in its current state
void printMaze(char maze[][COL]) {
    for(int i=0; i<ROW; i++) {
        for(int j=0; j<COL; j++) {
            printf("%c", maze[i][j]);
        }
        printf("\n");
    }
}

//Check if position is valid and not yet visited
bool isValid(char maze[][COL], int row, int col) {
    return row>=0 && row<ROW && col>=0 && col<COL && maze[row][col]==' ';
}

//Recursive function that finds the exit
bool findExit(char maze[][COL], int row, int col) {
    if(!isValid(maze, row, col)) return false; //base case
    
    maze[row][col] = '.'; //mark current position as visited
    
    if(row==0 || row==ROW-1 || col==0 || col==COL-1) //if exit found
        return true;
    
    //try every direction
    if(findExit(maze, row, col+1)) return true;
    if(findExit(maze, row+1, col)) return true;
    if(findExit(maze, row, col-1)) return true;
    if(findExit(maze, row-1, col)) return true;
    
    maze[row][col] = ' '; // backtrack
    return false;
}

int main() {
    char maze[ROW][COL] = {
        "+-+-+-+-+-+",
        "|         |",
        "+-|+-+-| +",
        "|     |   |",
        "+-+-+-| +-+",
        "|       E|",
        "+-+-+-+-+-+"
    };
    
    int startRow = 5, startCol = 7; //start position
    
    printf("Before:\n");
    printMaze(maze);
    
    if(findExit(maze, startRow, startCol))
        printf("\nPath found!\n");
    else
        printf("\nPath not found!\n");
    
    printf("\nAfter:\n");
    printMaze(maze);
    
    return 0;
}