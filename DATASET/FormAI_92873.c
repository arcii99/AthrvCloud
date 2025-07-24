//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 15 // Change this value to modify the size of the maze
#define COLS 25 // Change this value to modify the size of the maze

void printMaze(char maze[ROWS][COLS]) {
    // Print the maze
    for (int row = 0; row < ROWS; row++) {
        for (int col = 0; col < COLS; col++) {
            printf("%c", maze[row][col]);
        }
        printf("\n");
    }
}

void generateMaze(char maze[ROWS][COLS]) {
    // Set all cells to walls
    for (int row = 0; row < ROWS; row++) {
        for (int col = 0; col < COLS; col++) {
            maze[row][col] = '#';
        }
    }

    srand(time(NULL));
    int currentRow = rand() % (ROWS - 2) + 1; // Start in a random row between the outer walls
    int currentCol = rand() % (COLS - 2) + 1; // Start in a random column between the outer walls
    maze[currentRow][currentCol] = ' '; // Set the starting cell to empty

    int visitedCells = 1; // Start with 1 visited cell (the starting cell)
    while (visitedCells < ROWS * COLS) {
        // Find all unvisited neighbors of the current cell
        int neighborList[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}}; // Up, down, left, right
        int numNeighbors = 0;
        for (int i = 0; i < 4; i++) {
            int newRow = currentRow + neighborList[i][0];
            int newCol = currentCol + neighborList[i][1];
            if (newRow >= 0 && newRow < ROWS && newCol >= 0 && newCol < COLS) {
                if (maze[newRow][newCol] == '#') {
                    numNeighbors++;
                }
            }
        }

        // If there are unvisited neighbors, choose one at random and knock down the wall between it and the current cell
        if (numNeighbors > 0) {
            int chosenIndex = rand() % numNeighbors;
            int chosenNeighbor[2];
            int count = 0;
            for (int i = 0; i < 4; i++) {
                int newRow = currentRow + neighborList[i][0];
                int newCol = currentCol + neighborList[i][1];
                if (newRow >= 0 && newRow < ROWS && newCol >= 0 && newCol < COLS) {
                    if (maze[newRow][newCol] == '#') {
                        if (count == chosenIndex) {
                            chosenNeighbor[0] = newRow;
                            chosenNeighbor[1] = newCol;
                            break;
                        }
                        count++;
                    }
                }
            }

            if (chosenNeighbor[0] < currentRow) { // Knock down the top wall of the current cell
                maze[currentRow][currentCol] = ' ';
                maze[chosenNeighbor[0]][chosenNeighbor[1]] = ' ';
            } else if (chosenNeighbor[0] > currentRow) { // Knock down the bottom wall of the current cell
                maze[currentRow][currentCol] = ' ';
                maze[chosenNeighbor[0]][chosenNeighbor[1]] = ' ';
            } else if (chosenNeighbor[1] < currentCol) { // Knock down the left wall of the current cell
                maze[currentRow][currentCol] = ' ';
                maze[chosenNeighbor[0]][chosenNeighbor[1]] = ' ';
            } else if (chosenNeighbor[1] > currentCol) { // Knock down the right wall of the current cell
                maze[currentRow][currentCol] = ' ';
                maze[chosenNeighbor[0]][chosenNeighbor[1]] = ' ';
            }

            currentRow = chosenNeighbor[0];
            currentCol = chosenNeighbor[1];
            visitedCells++;
        } else { // If there are no unvisited neighbors, backtrack to the nearest visited cell
            int backtrackList[4][2]; // List of visited cells to which we can backtrack
            int numBacktracks = 0;
            for (int i = 0; i < 4; i++) {
                int newRow = currentRow + neighborList[i][0];
                int newCol = currentCol + neighborList[i][1];
                if (newRow >= 0 && newRow < ROWS && newCol >= 0 && newCol < COLS) {
                    if (maze[newRow][newCol] == ' ') {
                        backtrackList[numBacktracks][0] = newRow;
                        backtrackList[numBacktracks][1] = newCol;
                        numBacktracks++;
                    }
                }
            }

            if (numBacktracks > 0) {
                int chosenIndex = rand() % numBacktracks;
                currentRow = backtrackList[chosenIndex][0];
                currentCol = backtrackList[chosenIndex][1];
            }
        }
    }
}

int main() {
    char maze[ROWS][COLS];
    generateMaze(maze);
    printMaze(maze);
    return 0;
}