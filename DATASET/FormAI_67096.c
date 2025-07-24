//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW 10
#define COL 10

void generateMaze(int maze[][COL]);
void printMaze(int maze[][COL]);
int isValidMove(int row, int col, int maze[][COL]);

int main() {
    int maze[ROW][COL];
    srand(time(NULL));
    generateMaze(maze);
    printMaze(maze);
    return 0;
}

// Function to generate a random maze
void generateMaze(int maze[][COL]) {
    // Initialize the maze to all walls (1)
    for(int i=0; i<ROW; i++) {
        for(int j=0; j<COL; j++) {
            maze[i][j] = 1;
        }
    }

    // Set the starting position
    int row = rand() % ROW;
    int col = rand() % COL;
    maze[row][col] = 0;

    // Generate the maze
    int dir;
    int newRow, newCol;
    while(1) {
        // Choose a random direction
        dir = rand() % 4;

        // Determine the new position based on the chosen direction
        if(dir == 0) { // Up
            newRow = row-1;
            newCol = col;
        } else if(dir == 1) { // Right
            newRow = row;
            newCol = col+1;
        } else if(dir == 2) { // Down
            newRow = row+1;
            newCol = col;
        } else { // Left
            newRow = row;
            newCol = col-1;
        }

        // Check if the new position is valid
        if(isValidMove(newRow, newCol, maze)) {
            // Dig the new path and move to the new position
            maze[newRow][newCol] = 0;
            row = newRow;
            col = newCol;
        }

        // Check if the maze generation is complete
        if(row == 0 || row == ROW-1 || col == 0 || col == COL-1) {
            break;
        }
    }
}

// Function to print the maze
void printMaze(int maze[][COL]) {
    for(int i=0; i<ROW; i++) {
        for(int j=0; j<COL; j++) {
            if(maze[i][j] == 1) {
                printf("X ");
            } else {
                printf("_ ");
            }
        }
        printf("\n");
    }
}

// Function to check if a move is valid
int isValidMove(int row, int col, int maze[][COL]) {
    // Check if the new position is within the maze boundaries
    if(row < 0 || row >= ROW || col < 0 || col >= COL) {
        return 0;
    }

    // Check if the new position has already been visited
    if(maze[row][col] == 0) {
        return 0;
    }

    // Check if the new position has neighboring cells that have already been visited
    int count = 0;
    if(row > 0 && maze[row-1][col] == 0) { // Up
        count++;
    }
    if(row < ROW-1 && maze[row+1][col] == 0) { // Down
        count++;
    }
    if(col > 0 && maze[row][col-1] == 0) { // Left
        count++;
    }
    if(col < COL-1 && maze[row][col+1] == 0) { // Right
        count++;
    }
    if(count > 1) {
        return 0;
    }

    // If all conditions are met, the move is valid
    return 1;
}