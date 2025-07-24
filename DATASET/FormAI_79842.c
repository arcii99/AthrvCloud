//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: creative
#include <stdio.h>
#include <stdlib.h>

// Define maze size
#define ROW 5
#define COL 5

// Define starting and ending positions
#define START_ROW 0
#define START_COL 0
#define END_ROW 4
#define END_COL 4

// Define wall and path characters
#define WALL '*'
#define PATH '-'

// Define maze structure
char maze[ROW][COL] = {
    {'-', '*', '-', '-', '-'},
    {'-', '*', '-', '*', '-'},
    {'-', '*', '-', '*', '-'},
    {'-', '*', '-', '*', '-'},
    {'-', '-', '-', '*', '-'}
};

// Define function to print maze
void printMaze() {
    for(int i = 0; i < ROW; i++) {
        for(int j = 0; j < COL; j++) {
            printf("%c ", maze[i][j]);
        }
        printf("\n");
    }
}

// Define function to check if position is valid
int isValid(int row, int col) {
    if(row < 0 || col < 0 || row >= ROW || col >= COL) {
        return 0;
    }
    if(maze[row][col] == WALL) {
        return 0;
    }
    return 1;
}

// Define function to find route
int findRoute(int row, int col) {
    if(!isValid(row, col)) {
        return 0;
    }
    if(row == END_ROW && col == END_COL) {
        maze[row][col] = PATH;
        printMaze();
        printf("Route Found!\n");
        return 1;
    }
    maze[row][col] = PATH;
    if(findRoute(row-1, col) || findRoute(row, col+1)
        || findRoute(row+1, col) || findRoute(row, col-1)) {
        return 1;
    }
    maze[row][col] = '-';
    return 0; 
}

// Define main function
int main() {
    printf("Maze Route Finder\n");
    printf("-----------------\n");
    printf("Maze:\n");
    printMaze();
    printf("\nFinding Route...\n");

    int found = findRoute(START_ROW, START_COL);
    if(!found) {
        printf("No route found!\n");
    }

    return 0;
}