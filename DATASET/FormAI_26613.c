//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// define maze size
#define ROWS 10
#define COLS 10

// define directions
#define UP 0
#define RIGHT 1
#define DOWN 2
#define LEFT 3

int maze[ROWS][COLS]; // maze array to hold the maze layout

// function to generate random directions to move
int generateRandomDirection(int currentRow, int currentCol) {
    int directions[4] = {UP, RIGHT, DOWN, LEFT}; // all directions
    int numDirections = 4;

    // shuffle directions randomly
    for(int i=0; i<numDirections; i++) {
        int randomIndex = rand() % numDirections;
        int temp = directions[i];
        directions[i] = directions[randomIndex];
        directions[randomIndex] = temp;
    }

    // check if each direction is valid
    for(int i=0; i<numDirections; i++) {
        int direction = directions[i];
        int newRow = currentRow, newCol = currentCol;

        if(direction == UP) newRow--;
        else if(direction == RIGHT) newCol++;
        else if(direction == DOWN) newRow++;
        else if(direction == LEFT) newCol--;

        if(newRow >= 0 && newRow < ROWS && newCol >= 0 && newCol < COLS && maze[newRow][newCol] == 0) {
            // valid direction
            return direction;
        }
    }

    // no valid direction found
    return -1;
}

// function to generate the maze
void generateMaze() {
    // initialize maze with all walls
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            maze[i][j] = 1;
        }
    }

    // select random starting point
    int currentRow = rand() % ROWS;
    int currentCol = rand() % COLS;

    maze[currentRow][currentCol] = 0; // open starting cell

    // loop until all cells have been visited
    while(1) {
        // generate a random direction
        int direction = generateRandomDirection(currentRow, currentCol);

        if(direction == -1) {
            // no valid direction found, backtrack
            int hasBacktracked = 0;
            for(int i=0; i<4; i++) {
                int newRow = currentRow, newCol = currentCol;

                if(i == UP) newRow--;
                else if(i == RIGHT) newCol++;
                else if(i == DOWN) newRow++;
                else if(i == LEFT) newCol--;

                if(newRow >= 0 && newRow < ROWS && newCol >= 0 && newCol < COLS && maze[newRow][newCol] == 2) {
                    // backtrack to previous cell
                    currentRow = newRow;
                    currentCol = newCol;
                    maze[currentRow][currentCol] = 0; // open cell
                    hasBacktracked = 1;
                    break;
                }
            }

            if(hasBacktracked == 0) {
                // maze generation complete
                break;
            }
        }
        else {
            // valid direction found, move to new cell
            int newRow = currentRow, newCol = currentCol;

            if(direction == UP) newRow--;
            else if(direction == RIGHT) newCol++;
            else if(direction == DOWN) newRow++;
            else if(direction == LEFT) newCol--;

            // open new cell and remove wall between current cell and new cell
            maze[newRow][newCol] = 0;
            if(direction == UP) maze[currentRow-1][currentCol] = 0;
            else if(direction == RIGHT) maze[currentRow][currentCol+1] = 0;
            else if(direction == DOWN) maze[currentRow+1][currentCol] = 0;
            else if(direction == LEFT) maze[currentRow][currentCol-1] = 0;

            currentRow = newRow;
            currentCol = newCol;
        }
    }
}

// function to print the maze
void printMaze() {
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            if(maze[i][j] == 1) printf("#"); // wall
            else printf("."); // opening
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL)); // seed random number generator
    generateMaze(); // generate the maze
    printMaze(); // print the maze
    return 0;
}