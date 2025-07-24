//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 21
#define COLS 41

void generateMaze(int maze[][COLS]);
void printMaze(int maze[][COLS]);

int main(void) {
    int maze[ROWS][COLS];

    // Generate a random seed for the level generation
    srand(time(NULL));

    // Generate and print the maze
    generateMaze(maze);
    printMaze(maze);

    return 0;
}

void generateMaze(int maze[][COLS]) {
    // Initialize the maze with walls
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            maze[i][j] = 1;
        }
    }

    // Generate a random starting point
    int x = rand() % (ROWS - 2);
    int y = rand() % (COLS - 2);
    maze[x][y] = 0;

    // Generate the maze using a depth-first search algorithm
    int stack[ROWS*COLS][2];
    int top = 0;
    stack[top][0] = x;
    stack[top][1] = y;

    while (top >= 0) {
        // Pop the top cell off the stack
        int currX = stack[top][0];
        int currY = stack[top][1];
        top--;

        // Check if the current cell has any unvisited neighbors
        int neighbors[4][2] = {{currX-2, currY}, {currX, currY+2}, {currX+2, currY}, {currX, currY-2}};
        int unvisitedNeighbors[4][2];
        int numUnvisitedNeighbors = 0;

        for (int i = 0; i < 4; i++) {
            int x = neighbors[i][0];
            int y = neighbors[i][1];

            if (x >= 0 && x < ROWS && y >= 0 && y < COLS && maze[x][y] == 1) {
                unvisitedNeighbors[numUnvisitedNeighbors][0] = x;
                unvisitedNeighbors[numUnvisitedNeighbors][1] = y;
                numUnvisitedNeighbors++;
            }
        }

        if (numUnvisitedNeighbors > 0) {
            // Randomly choose a neighboring cell to connect to
            int randIndex = rand() % numUnvisitedNeighbors;
            int newX = unvisitedNeighbors[randIndex][0];
            int newY = unvisitedNeighbors[randIndex][1];

            // Remove the wall between the current cell and the new cell
            maze[(currX+newX)/2][(currY+newY)/2] = 0;
            maze[newX][newY] = 0;

            // Push the new cell onto the stack
            top++;
            stack[top][0] = newX;
            stack[top][1] = newY;
        }
    }
}

void printMaze(int maze[][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (maze[i][j] == 1) printf("██");
            else printf("  ");
        }
        printf("\n");
    }
    printf("\n");
}