//FormAI DATASET v1.0 Category: Game ; Style: visionary
#include <stdio.h> 

#define ROWS 10 
#define COLS 10 

void printMaze(int maze[ROWS][COLS]);
int solveMaze(int maze[ROWS][COLS], int row, int col);

int main() 
{ 
    printf("Welcome to The Maze Of Adventure!\n"); 

    int maze[ROWS][COLS] = { 
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, 
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 1}, 
        {1, 0, 1, 1, 0, 1, 1, 1, 0, 1}, 
        {1, 0, 1, 0, 0, 1, 0, 0, 0, 1}, 
        {1, 0, 1, 0, 1, 1, 0, 1, 1, 1}, 
        {1, 0, 1, 0, 0, 0, 0, 0, 0, 1}, 
        {1, 0, 1, 1, 1, 1, 1, 1, 0, 1}, 
        {1, 0, 1, 0, 0, 0, 0, 1, 0, 1}, 
        {1, 0, 0, 0, 1, 1, 0, 0, 0, 1}, 
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1} 
    };

    printf("The current state of the maze is:\n");
    printMaze(maze);

    if (solveMaze(maze, 1, 1)) {
        printf("Congratulations! You made it through the maze!");
        printMaze(maze);
    } 
    else {
        printf("Sorry, you were unable to complete the maze. Please try again!\n");
        printMaze(maze);
    } 

    return 0; 
} 

void printMaze(int maze[ROWS][COLS]) 
{ 
    for (int i = 0; i < ROWS; i++) { 
        for (int j = 0; j < COLS; j++) { 
            printf("%d ", maze[i][j]); 
        } 
        printf("\n"); 
    } 
} 

int solveMaze(int maze[ROWS][COLS], int row, int col) 
{ 
    if (maze[row][col] == 2) { 
        return 1; 
    } 
    if (maze[row][col] == 1) { 
        return 0; 
    } 

    maze[row][col] = 1; 

    if (solveMaze(maze, row-1, col)) {
        return 1;
    }
    if (solveMaze(maze, row+1, col)) {
        return 1;
    }
    if (solveMaze(maze, row, col-1)) {
        return 1;
    }
    if (solveMaze(maze, row, col+1)) {
        return 1;
    }

    maze[row][col] = 0;

    return 0;
}