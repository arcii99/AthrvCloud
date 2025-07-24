//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10      // Number of rows in the maze
#define COLS 15      // Number of columns in the maze
#define WALL '#'
#define PATH ' '
#define START 'S'
#define END 'E'

int maze[ROWS][COLS];

// Initialize the maze with walls
void initializeMaze() {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            maze[i][j] = WALL;
        }
    }
}

// Print the maze to the console
void printMaze() {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf("%c ", maze[i][j]);
        }
        printf("\n");
    }
}

// Generate a random starting point
void generateStart() {
    int row = rand() % (ROWS - 2) + 1;
    int col = 0;
    maze[row][col] = START;
}

// Generate a random ending point
void generateEnd() {
    int row = rand() % (ROWS - 2) + 1;
    int col = COLS - 1;
    maze[row][col] = END;
}

// Recursive function to generate the maze
void generateMaze(int row, int col) {
    int directions[4] = {0, 1, 2, 3};    // 0=up, 1=right, 2=down, 3=left
    int i, j, temp, nextRow, nextCol;
    for (i = 0; i < 4; i++) {
        j = rand() % 4;     // Generate a random index
        temp = directions[i];
        directions[i] = directions[j];
        directions[j] = temp;   // Shuffle the directions array
    }
    for (i = 0; i < 4; i++) {
        switch (directions[i]) {
            case 0:     // Check if we can go up
                if (row - 2 <= 0) {
                    continue;
                }
                if (maze[row - 2][col] != PATH) {
                    maze[row - 2][col] = PATH;
                    maze[row - 1][col] = PATH;
                    nextRow = row - 2;
                    nextCol = col;
                    generateMaze(nextRow, nextCol);
                }
                break;
            case 1:     // Check if we can go right
                if (col + 2 >= COLS - 1) {
                    continue;
                }
                if (maze[row][col + 2] != PATH) {
                    maze[row][col + 2] = PATH;
                    maze[row][col + 1] = PATH;
                    nextRow = row;
                    nextCol = col + 2;
                    generateMaze(nextRow, nextCol);
                }
                break;
            case 2:     // Check if we can go down
                if (row + 2 >= ROWS - 1) {
                    continue;
                }
                if (maze[row + 2][col] != PATH) {
                    maze[row + 2][col] = PATH;
                    maze[row + 1][col] = PATH;
                    nextRow = row + 2;
                    nextCol = col;
                    generateMaze(nextRow, nextCol);
                }
                break;
            case 3:     // Check if we can go left
                if (col - 2 <= 0) {
                    continue;
                }
                if (maze[row][col - 2] != PATH) {
                    maze[row][col - 2] = PATH;
                    maze[row][col - 1] = PATH;
                    nextRow = row;
                    nextCol = col - 2;
                    generateMaze(nextRow, nextCol);
                }
                break;
        }
    }
}

int main() {
    srand(time(NULL));     // Seed the random number generator
    initializeMaze();       // Initialize the maze with walls
    generateStart();        // Generate the starting point
    generateEnd();          // Generate the ending point
    int startRow = 0, startCol = 0;
    // Find the starting point
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (maze[i][j] == START) {
                startRow = i;
                startCol = j;
                break;
            }
        }
    }
    maze[startRow][startCol + 1] = PATH;    // Open up the path beside the starting point
    generateMaze(startRow, startCol + 1);   // Generate the maze recursively
    printMaze();                            // Print the maze to the console
    return 0;
}