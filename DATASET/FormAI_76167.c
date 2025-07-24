//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: immersive
#include<stdio.h>
#include<stdlib.h>

#define ROWS 10
#define COLS 10

// Maze represented as 2D Character Array
char maze[ROWS][COLS+1] = {
    "+--------+",
    "|        |",
    "| |----| |",
    "| |    | |",
    "| | |----|",
    "| |      |",
    "| |------|",
    "|        |",
    "|----|   |",
    "+--------+"
};

// Function to print the maze
void printMaze() {
    printf("\n");
    for(int i=0;i<ROWS;i++) {
        printf("%s\n",maze[i]);
    }
}

// Function to check whether the given row and column positions are valid
int isValidMove(int row, int col) {
    if(row >= 0 && row < ROWS && col >= 0 && col < COLS) {
        if(maze[row][col] == ' ')
            return 1;
    }
    return 0;
}

// Recursive function to find the route i.e., path from start to end in the maze
int findRoute(int row, int col) {
    if(maze[row][col] == 'E') {
        return 1;
    }
    if(isValidMove(row, col)) {
        maze[row][col] = '.';
        if(findRoute(row+1, col) || findRoute(row-1, col) || 
           findRoute(row, col+1) || findRoute(row, col-1)) {
            return 1;
        }
        maze[row][col] = ' ';
    }
    return 0;
}

int main() {
    printf("Welcome to the C Maze Route Finder program\n");
    printf("Please find the path from Start to End in the following maze\n");
    printMaze();
    printf("\n");
    if(findRoute(1,1)) {
        printf("Path Found!\n");
        printMaze();
    }
    else {
        printf("No Path Found.\n");
    }
    return 0;
}