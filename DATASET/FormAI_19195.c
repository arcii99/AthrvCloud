//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define maze dimensions and walls
#define ROWS 10
#define COLS 10
#define WALL '#'
#define PATH ' '

// Recursive function to generate the maze
void generateMaze(int maze[ROWS][COLS], int row, int col) {
    maze[row][col] = PATH; // Mark current cell as visited

    // Define directions and shuffle them randomly
    int directions[4] = {0, 1, 2, 3};
    for (int i = 0; i < 4; i++) {
        int j = rand() % 4;
        int temp = directions[i];
        directions[i] = directions[j];
        directions[j] = temp;
    }

    // Loop through all directions
    for (int i = 0; i < 4; i++) {
        int nextRow = row, nextCol = col;
        if (directions[i] == 0) { // Up
            nextRow--;
        } else if (directions[i] == 1) { // Right
            nextCol++;
        } else if (directions[i] == 2) { // Down
            nextRow++;
        } else if (directions[i] == 3) { // Left
            nextCol--;
        }

        // Check if next cell is valid and not visited
        if (nextRow >= 0 && nextRow < ROWS && nextCol >= 0 && nextCol < COLS && maze[nextRow][nextCol] == WALL) {
            // Remove the wall between the current and next cell
            if (directions[i] == 0) { // Up
                maze[row-1][col] = PATH;
            } else if (directions[i] == 1) { // Right
                maze[row][col+1] = PATH;
            } else if (directions[i] == 2) { // Down
                maze[row+1][col] = PATH;
            } else if (directions[i] == 3) { // Left
                maze[row][col-1] = PATH;
            }

            // Recursively call the function for the next cell
            generateMaze(maze, nextRow, nextCol);
        }
    }
}

int main() {
    int maze[ROWS][COLS]; // Define maze array
    srand(time(0)); // Set seed for random function

    // Fill maze with walls
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            maze[i][j] = WALL;
        }
    }

    // Generate the maze starting from a random cell
    int startRow = rand() % ROWS;
    int startCol = rand() % COLS;
    generateMaze(maze, startRow, startCol);

    // Print the maze
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%c", maze[i][j]);
        }
        printf("\n");
    }

    return 0;
}