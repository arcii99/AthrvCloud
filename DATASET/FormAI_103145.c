//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 15
#define COLS 15

// Function to generate random number within range
int randRange(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Function to print the maze
void printMaze(char maze[][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%c ", maze[i][j]);
        }
        printf("\n");
    }
}

int main(void) {
    srand(time(NULL)); // Initialize random seed

    // Create maze array and fill with walls
    char maze[ROWS][COLS];
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            maze[i][j] = '#';
        }
    }

    int currentRow = 1; // Starting row
    int currentCol = 1; // Starting column
    maze[currentRow][currentCol] = ' '; // Set starting cell to be empty

    // Loop until the end of the maze is reached
    while (currentRow != ROWS - 2 || currentCol != COLS - 2) {
        // Generate random direction
        int direction = randRange(0, 3);

        // Move in random direction
        switch(direction) {
            // Up
            case 0:
                if (currentRow - 2 > 0 && maze[currentRow - 2][currentCol] == '#') {
                    maze[currentRow - 1][currentCol] = ' ';
                    maze[currentRow - 2][currentCol] = ' ';
                    currentRow -= 2;
                }
                break;
            // Right
            case 1:
                if (currentCol + 2 < COLS - 1 && maze[currentRow][currentCol + 2] == '#') {
                    maze[currentRow][currentCol + 1] = ' ';
                    maze[currentRow][currentCol + 2] = ' ';
                    currentCol += 2;
                }
                break;
            // Down
            case 2:
                if (currentRow + 2 < ROWS - 1 && maze[currentRow + 2][currentCol] == '#') {
                    maze[currentRow + 1][currentCol] = ' ';
                    maze[currentRow + 2][currentCol] = ' ';
                    currentRow += 2;
                }
                break;
            // Left
            case 3:
                if (currentCol - 2 > 0 && maze[currentRow][currentCol - 2] == '#') {
                    maze[currentRow][currentCol - 1] = ' ';
                    maze[currentRow][currentCol - 2] = ' ';
                    currentCol -= 2;
                }
                break;
        }
    }

    // Set finish cell to be empty
    maze[ROWS - 2][COLS - 2] = ' ';

    // Print the maze
    printMaze(maze);

    return 0;
}