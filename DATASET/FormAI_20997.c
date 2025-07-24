//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>

#define MAX_ROWS 10
#define MAX_COLS 10

int maze[MAX_ROWS][MAX_COLS]; // maze array
int sol[MAX_ROWS][MAX_COLS]; // solution array

// function that checks if a move is valid
int validMove(int row, int col) {
    if (row >= 0 && row < MAX_ROWS && col >= 0 && col < MAX_COLS && maze[row][col] != 0) {
        return 1;
    }
    return 0;
}

// function that prints the solution
void printSolution() {
    printf("\nSolution:\n");
    for (int i = 0; i < MAX_ROWS; i++) {
        for (int j = 0; j < MAX_COLS; j++) {
            printf("%d ", sol[i][j]);
        }
        printf("\n");
    }
}

// function that finds the route in the maze
int findRoute(int row, int col) {
    if (row == MAX_ROWS-1 && col == MAX_COLS-1) { // if we have reached the end of maze
        sol[row][col] = 1;
        return 1;
    }
    if (validMove(row, col)) { // if the current move is valid
        sol[row][col] = 1;
        if (findRoute(row+1, col)) { // check if we can move down
            return 1;
        }
        if (findRoute(row, col+1)) { // check if we can move right
            return 1;
        }
        sol[row][col] = 0; // backtrack
    }
    return 0;
}

int main(void) {
    // initialize maze array
    int mazeArray[MAX_ROWS][MAX_COLS] = {
        {1, 0, 1, 1, 1, 1, 0, 1, 1, 1},
        {1, 0, 1, 0, 1, 1, 1, 0, 1, 1},
        {1, 1, 1, 0, 1, 1, 0, 1, 0, 1},
        {0, 0, 0, 0, 1, 0, 0, 0, 0, 1},
        {1, 1, 1, 0, 1, 1, 1, 0, 1, 0},
        {1, 0, 1, 1, 1, 1, 0, 1, 0, 0},
        {1, 0, 0, 0, 0, 1, 0, 0, 0, 1},
        {1, 1, 1, 1, 1, 1, 0, 1, 1, 1},
        {0, 0, 0, 0, 0, 1, 0, 0, 1, 0},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
    };
    // copy the maze array to global maze array
    for (int i = 0; i < MAX_ROWS; i++) {
        for (int j = 0; j < MAX_COLS; j++) {
            maze[i][j] = mazeArray[i][j];
        }
    }
    if (findRoute(0, 0)) { // start the search from the top-left corner
        printSolution(); // if we have found a route, print the solution
    } else {
        printf("\nNo solution found.");
    }
    return 0;
}