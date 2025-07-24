//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 10

int maze[ROWS][COLS];

// Function to initialize the maze with random walls
void initializeMaze() {
    srand(time(NULL));
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            if(i==0 || i==ROWS-1 || j==0 || j==COLS-1) {
                maze[i][j] = 1;
            } else {
                maze[i][j] = rand() % 2;
            }
        }
    }
}

// Function to print the maze
void printMaze() {
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            if(maze[i][j] == 1) {
                printf("* ");
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }
}

// Function to generate the maze using recursive backtracking algorithm
void generateMaze(int row, int col) {
    maze[row][col] = 2;
    int directions[4][2] = {{-1,0}, {1,0}, {0,-1}, {0,1}};
    for(int i=0; i<4; i++) {
        int r = row + directions[i][0];
        int c = col + directions[i][1];
        if(r>=0 && r<ROWS && c>=0 && c<COLS && maze[r][c]!=2 && maze[r][c]!=1) {
            maze[(row+r)/2][(col+c)/2] = 2;
            generateMaze(r, c);
        }
    }
}

int main() {
    initializeMaze();
    printf("Initial Maze:\n");
    printMaze();

    generateMaze(1, 1);
    printf("\nGenerated Maze:\n");
    printMaze();

    return 0;
}