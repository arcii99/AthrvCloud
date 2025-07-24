//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define ROWS 10
#define COLS 20

// Function to check if a cell is valid
bool isValidCell(int row, int col, char maze[ROWS][COLS]) {
    return row >= 0 && row < ROWS && col >= 0 && col < COLS && maze[row][col] == '-';
}

// Function to print the current position of the maze runner
void printMaze(char maze[ROWS][COLS], int row, int col) {
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            if(i == row && j == col) {
                printf("*");
            } else {
                printf("%c", maze[i][j]);
            }
        }
        printf("\n");
    }
    printf("\n");
}

// Main function to find a route in the maze
void findRoute(char maze[ROWS][COLS], int startRow, int startCol) {
    // Initialize stack to store visited cells
    int stack[ROWS*COLS][2];
    int top = -1;

    // Push the starting cell onto the stack
    stack[++top][0] = startRow;
    stack[top][1] = startCol;

    // Initialize a visited array to keep track of visited cells
    bool visited[ROWS][COLS];
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            visited[i][j] = false;
        }
    }
    visited[startRow][startCol] = true;

    // Loop until stack is empty or exit is found
    while(top >= 0) {
        // Pop the top cell from the stack
        int row = stack[top][0];
        int col = stack[top][1];
        top--;

        // Check if this cell is the exit
        if(maze[row][col] == 'E') {
            printf("Exit found!\n\n");
            printMaze(maze, row, col);
            return;
        }

        // Mark this cell as visited
        visited[row][col] = true;

        // Check if there are any valid neighbors and add to the stack
        if(isValidCell(row-1, col, maze) && !visited[row-1][col]) {   // Up
            stack[++top][0] = row-1;
            stack[top][1] = col;
            visited[row-1][col] = true;
        }
        if(isValidCell(row, col+1, maze) && !visited[row][col+1]) {   // Right
            stack[++top][0] = row;
            stack[top][1] = col+1;
            visited[row][col+1] = true;
        }
        if(isValidCell(row+1, col, maze) && !visited[row+1][col]) {   // Down
            stack[++top][0] = row+1;
            stack[top][1] = col;
            visited[row+1][col] = true;
        }
        if(isValidCell(row, col-1, maze) && !visited[row][col-1]) {   // Left
            stack[++top][0] = row;
            stack[top][1] = col-1;
            visited[row][col-1] = true;
        }

        // Print the current position of the maze runner
        printMaze(maze, row, col);
        // Wait for a short amount of time to create animation effect
        for(int i = 0; i < 100000000; i++);
    }

    // If stack is empty and exit not found, print failure message
    printf("Exit not found!\n\n");
    printMaze(maze, startRow, startCol);
}

int main() {
    // Initialize the maze with obstacles and exit
    char maze[ROWS][COLS] = {
        {'+', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '+'},
        {'|', '.', '|', '.', '|', '|', '|', '|', '|', '|', '|', '|', '|', '|', '|', '|', '.', '.', '.', '|'},
        {'|', '.', '|', '.', '|', '|', '|', '|', '|', '|', '|', '|', '|', '|', '|', '|', '.', '.', '.', '|'},
        {'|', '.', '|', '.', '|', '|', '|', '|', '|', '|', '|', '|', '|', '|', '|', '|', '.', '.', '.', '|'},
        {'|', '.', '|', '.', '|', '|', '|', '|', '|', '|', '|', '|', '|', '|', '|', '|', '.', '.', '.', '|'},
        {'|', '.', '|', '.', '|', '|', '|', '|', '|', '|', '|', '|', '|', '|', '|', '|', '.', '.', '.', '|'},
        {'|', '.', '|', '.', '.', '.', '.', '.', '|', '|', '|', '|', '|', '|', '|', '|', '.', '.', '.', '|'},
        {'|', '.', '.', '.', '|', '|', '|', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '|'},
        {'|', '.', '|', '.', '.', '.', '.', '.', '|', '|', '|', '|', '|', '|', '|', '|', '.', '.', '.', '|'},
        {'+', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '+'}
    };

    // Set the start position of the maze runner
    int startRow, startCol;
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            if(maze[i][j] == '.') {
                startRow = i;
                startCol = j;
                break;
            }
        }
    }

    // Print the initial maze and starting position of the maze runner
    printMaze(maze, startRow, startCol);

    // Call the function to find the route
    findRoute(maze, startRow, startCol);

    return 0;
}