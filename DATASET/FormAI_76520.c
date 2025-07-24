//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 25
#define COLS 25

// Generate a random integer between min and max, inclusive
int randInt(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Print the maze to the console
void printMaze(char maze[ROWS][COLS]) {
    for (int row = 0; row < ROWS; row++) {
        for (int col = 0; col < COLS; col++) {
            printf("%c", maze[row][col]);
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL)); // Seed the random number generator
    char maze[ROWS][COLS]; // Create the maze

    // Initialize the maze with walls ('#')
    for (int row = 0; row < ROWS; row++) {
        for (int col = 0; col < COLS; col++) {
            maze[row][col] = '#';
        }
    }

    // Generate the maze
    int currentRow = 1;
    int currentCol = 1;
    maze[currentRow][currentCol] = ' '; // Mark the starting position as empty

    while (currentRow != ROWS - 2 || currentCol != COLS - 2) { // Loop until we reach the end
        // Choose a random direction to move in (up, down, left, or right)
        int direction = randInt(1, 4);

        // Try to move in the chosen direction
        if (direction == 1 && currentRow > 2 && maze[currentRow - 2][currentCol] == '#') {
            maze[currentRow - 1][currentCol] = ' ';
            maze[currentRow - 2][currentCol] = ' ';
            currentRow -= 2;
        }
        else if (direction == 2 && currentRow < ROWS - 3 && maze[currentRow + 2][currentCol] == '#') {
            maze[currentRow + 1][currentCol] = ' ';
            maze[currentRow + 2][currentCol] = ' ';
            currentRow += 2;
        }
        else if (direction == 3 && currentCol > 2 && maze[currentRow][currentCol - 2] == '#') {
            maze[currentRow][currentCol - 1] = ' ';
            maze[currentRow][currentCol - 2] = ' ';
            currentCol -= 2;
        }
        else if (direction == 4 && currentCol < COLS - 3 && maze[currentRow][currentCol + 2] == '#') {
            maze[currentRow][currentCol + 1] = ' ';
            maze[currentRow][currentCol + 2] = ' ';
            currentCol += 2;
        }
    }

    // Add the entrance and exit to the maze
    maze[1][0] = ' ';
    maze[ROWS - 2][COLS - 1] = ' ';

    // Print the maze
    printMaze(maze);

    return 0; // Success
}