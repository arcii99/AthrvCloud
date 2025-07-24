//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MAZE_SIZE 10

int maze[MAZE_SIZE][MAZE_SIZE];

void initMaze() {
    // initialize maze with all walls
    for (int i = 0; i < MAZE_SIZE; i++) {
        for (int j = 0; j < MAZE_SIZE; j++) {
            maze[i][j] = 1;
        }
    }
}

void printMaze() {
    // print maze in ASCII art
    for (int i = 0; i < MAZE_SIZE; i++) {
        for (int j = 0; j < MAZE_SIZE; j++) {
            if (maze[i][j] == 0) {
                printf("  ");
            } else {
                printf("██");
            }
        }
        printf("\n");
    }
}

bool isValid(int row, int col) {
    // check if a cell is inside the maze and not visited
    return row >= 0 && row < MAZE_SIZE && col >= 0 && col < MAZE_SIZE && maze[row][col] == 1;
}

bool hasUnvisitedNeighbors(int row, int col) {
    // check if a cell has unvisited neighbors
    return (isValid(row-1, col) && !maze[row-1][col]) || (isValid(row+1, col) && !maze[row+1][col]) ||
           (isValid(row, col-1) && !maze[row][col-1]) || (isValid(row, col+1) && !maze[row][col+1]);
}

void generateMaze(int row, int col) {
    // Recursive Depth-First Search algorithm to generate maze
    int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    maze[row][col] = 0; // mark cell as visited

    while (hasUnvisitedNeighbors(row, col)) {
        int dir = rand() % 4; // randomly choose a direction

        int newRow = row + directions[dir][0];
        int newCol = col + directions[dir][1];

        if (isValid(newRow, newCol) && maze[newRow][newCol] == 1) { // if neighbor is unvisited
            if (dir == 0) {
                maze[row-1][col] = 0;
            } else if (dir == 1) {
                maze[row+1][col] = 0;
            } else if (dir == 2) {
                maze[row][col-1] = 0;
            } else {
                maze[row][col+1] = 0;
            }
            generateMaze(newRow, newCol); // recursive call with new neighbor as current cell
        }
    }
}

int main() {
    srand(time(0)); // seed for random numbers based on time

    initMaze();
    generateMaze(0, 0);
    printMaze();

    return 0;
}