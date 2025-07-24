//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define ROWS 10
#define COLS 20

// Function prototypes
void generateMaze(char maze[][COLS]);
void displayMaze(char maze[][COLS]);
bool validMove(int row, int col, char maze[][COLS]);
bool solveMaze(int row, int col, char maze[][COLS]);
void printRoute(int row, int col, char maze[][COLS]);

int main(void) {
    // Seed random number generator
    srand(time(NULL));

    char maze[ROWS][COLS];
    generateMaze(maze);

    printf("Initial Maze:\n\n");
    displayMaze(maze);

    int startRow, startCol;
    do {
        startRow = rand() % ROWS;
        startCol = rand() % COLS;
    } while (maze[startRow][startCol] != ' ');

    printf("Starting position: (%d, %d)\n", startRow, startCol);

    if (solveMaze(startRow, startCol, maze)) {
        printf("\nRoute found:\n\n");
        printRoute(startRow, startCol, maze);
    } else {
        printf("\nNo route found.\n");
    }

    return 0;
}

/*
 * Generates a maze using a probabilistic algorithm.
 * Walls are represented by '#', empty spaces are represented by ' '.
 */
void generateMaze(char maze[][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (i == 0 || j == 0 || i == ROWS - 1 || j == COLS - 1) {
                // Set outer walls of maze
                maze[i][j] = '#';
            } else if (rand() % 100 > 70) {
                // 30% probability of generating wall
                maze[i][j] = '#';
            } else {
                maze[i][j] = ' ';
            }
        }
    }
}

/*
 * Displays the maze in the console.
 * Walls are displayed in blue, empty spaces are displayed in white.
 */
void displayMaze(char maze[][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (maze[i][j] == '#') {
                printf("\033[34m#\033[0m");
            } else {
                printf("\033[0m ");
            }
        }
        printf("\n");
    }
}

/*
 * Returns true if (row, col) is a valid move within the maze.
 * A move is valid if it is within the maze bounds and the cell is not a wall '#' character.
 */
bool validMove(int row, int col, char maze[][COLS]) {
    if (row >= 0 && row < ROWS && col >= 0 && col < COLS && maze[row][col] != '#') {
        return true;
    }
    return false;
}

/*
 * Recursively solves the maze starting from (row, col).
 * Returns true if a solution is found, false otherwise.
 */
bool solveMaze(int row, int col, char maze[][COLS]) {
    // Mark cell as visited
    maze[row][col] = '*';

    if (row == ROWS - 1 && col == COLS - 1) {
        // Found end of maze
        return true;
    } else {
        if (validMove(row + 1, col, maze) && solveMaze(row + 1, col, maze)) {
            // Move down
            return true;
        }
        if (validMove(row, col + 1, maze) && solveMaze(row, col + 1, maze)) {
            // Move right
            return true;
        }
        if (validMove(row - 1, col, maze) && solveMaze(row - 1, col, maze)) {
            // Move up
            return true;
        }
        if (validMove(row, col - 1, maze) && solveMaze(row, col - 1, maze)) {
            // Move left
            return true;
        }

        // Mark cell as unvisited
        maze[row][col] = ' ';
        return false;
    }
}

/*
 * Prints the route taken to solve the maze in the console.
 * Start position is marked with 'S', end position is marked with 'E'.
 */
void printRoute(int row, int col, char maze[][COLS]) {
    // Mark start and end positions
    maze[row][col] = 'S';
    maze[ROWS - 1][COLS - 1] = 'E';

    // Print maze with route
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (maze[i][j] == 'S') {
                printf("\033[32mS\033[0m");
            } else if (maze[i][j] == 'E') {
                printf("\033[31mE\033[0m");
            } else if (maze[i][j] == '*' || maze[i][j] == '#') {
                printf("\033[34m%c\033[0m", maze[i][j]);
            } else {
                printf("\033[0m%c", maze[i][j]);
            }
        }
        printf("\n");
    }
}