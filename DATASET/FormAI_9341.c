//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAZE_WIDTH 20
#define MAZE_HEIGHT 10

int maze[MAZE_HEIGHT][MAZE_WIDTH]; // Initialize the maze
int visited[MAZE_HEIGHT][MAZE_WIDTH] = {0}; // Keep track of visited cells
int currentRow = 0;
int currentCol = 0;

// Function to create the corridors in the maze
void createCorridors(int row, int col) {
    visited[row][col] = 1;
    if(col > 0 && visited[row][col-1] == 0) {
        maze[row][col] |= 1;
        maze[row][col-1] |= 4;
        createCorridors(row, col-1);
    }
    if(col < MAZE_WIDTH-1 && visited[row][col+1] == 0) {
        maze[row][col] |= 4;
        maze[row][col+1] |= 1;
        createCorridors(row, col+1);
    }
    if(row > 0 && visited[row-1][col] == 0) {
        maze[row][col] |= 2;
        maze[row-1][col] |= 8;
        createCorridors(row-1, col);
    }
    if(row < MAZE_HEIGHT-1 && visited[row+1][col] == 0) {
        maze[row][col] |= 8;
        maze[row+1][col] |= 2;
        createCorridors(row+1, col);
    }
}

// Function to print the maze
void printMaze() {
    printf("+");
    for(int i = 0; i < MAZE_WIDTH; i++) {
        printf("---+");
    }
    printf("\n");

    for(int i = 0; i < MAZE_HEIGHT; i++) {
        printf("|");
        for(int j = 0; j < MAZE_WIDTH; j++) {
            if(maze[i][j] & 2) {
                printf("   ");
            }
            else {
                printf(" | ");
            }
        }
        printf("\n");

        printf("+");
        for(int j = 0; j < MAZE_WIDTH; j++) {
            if(maze[i][j] & 4) {
                printf("   ");
            }
            else {
                printf("---");
            }
            printf("+");
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));

    // Initialize the maze with walls
    for(int i = 0; i < MAZE_HEIGHT; i++) {
        for(int j = 0; j < MAZE_WIDTH; j++) {
            maze[i][j] = 15;
        }
    }

    // Create the corridors in the maze
    createCorridors(currentRow, currentCol);

    // Set the start and end points in the maze
    maze[0][0] &= 13;
    maze[MAZE_HEIGHT-1][MAZE_WIDTH-1] &= 14;

    // Print the maze
    printMaze();

    return 0;
}