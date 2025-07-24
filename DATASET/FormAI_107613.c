//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: irregular
// This is a mysterious maze route finder program that works in an unconventional way.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

// The maze is represented by a 10x10 char array
#define MAZE_SIZE 10

// Define the different types of cells in the maze
#define WALL '#'
#define PATH ' '
#define START 'S'
#define END 'E'

// Define the direction constants
#define NORTH 0
#define EAST 1
#define SOUTH 2
#define WEST 3

// Function prototypes
void initializeMaze(char maze[MAZE_SIZE][MAZE_SIZE]);
void printMaze(char maze[MAZE_SIZE][MAZE_SIZE]);
void generateMaze(char maze[MAZE_SIZE][MAZE_SIZE], int startX, int startY);
bool isValidMove(char maze[MAZE_SIZE][MAZE_SIZE], int row, int col, int direction);
bool findRoute(char maze[MAZE_SIZE][MAZE_SIZE], int startX, int startY, int endX, int endY, int dir);

int main()
{
    // Seed the random number generator
    srand(time(NULL));

    // Initialize the maze
    char maze[MAZE_SIZE][MAZE_SIZE];
    initializeMaze(maze);

    // Generate the maze
    generateMaze(maze, 0, 0);

    // Find the route through the maze
    if (findRoute(maze, 0, 0, MAZE_SIZE-1, MAZE_SIZE-1, EAST)) {
        printf("Congratulations, you made it through the maze!\n");
    } else {
        printf("Sorry, you got stuck in the maze!\n");
    }

    // Print the maze
    printMaze(maze);

    return 0;
}

/*
 * Initialize the maze to all walls except for the start and end cells.
 */
void initializeMaze(char maze[MAZE_SIZE][MAZE_SIZE])
{
    int row, col;

    for (row = 0; row < MAZE_SIZE; row++) {
        for (col = 0; col < MAZE_SIZE; col++) {
            if (row == 0 && col == 0) {
                maze[row][col] = START;
            } else if (row == MAZE_SIZE - 1 && col == MAZE_SIZE - 1) {
                maze[row][col] = END;
            } else {
                maze[row][col] = WALL;
            }
        }
    }
}

/*
 * Print the maze to the console.
 */
void printMaze(char maze[MAZE_SIZE][MAZE_SIZE])
{
    int row, col;

    for (row = 0; row < MAZE_SIZE; row++) {
        for (col = 0; col < MAZE_SIZE; col++) {
            printf("%c ", maze[row][col]);
        }
        printf("\n");
    }
}

/*
 * Generate the maze using a randomized depth-first search algorithm.
 */
void generateMaze(char maze[MAZE_SIZE][MAZE_SIZE], int startX, int startY)
{
    int directions[4] = {NORTH, EAST, SOUTH, WEST};

    // Shuffle the directions randomly
    int i;
    for (i = 0; i < 4; i++) {
        int j = rand() % 4;
        int temp = directions[i];
        directions[i] = directions[j];
        directions[j] = temp;
    }

    // Try each direction in a random order
    for (i = 0; i < 4; i++) {
        int direction = directions[i];

        // Compute the new row and column based on the direction
        int newRow = startY;
        int newCol = startX;
        switch (direction) {
            case NORTH:
                newRow = startY - 1;
                break;
            case EAST:
                newCol = startX + 1;
                break;
            case SOUTH:
                newRow = startY + 1;
                break;
            case WEST:
                newCol = startX - 1;
                break;
        }

        // Check if the move is valid
        if (!isValidMove(maze, newRow, newCol, direction)) {
            continue;
        }

        // Carve a path in the maze
        maze[newRow][newCol] = PATH;
        if (direction == NORTH) {
            maze[startY-1][startX] = PATH;
        } else if (direction == EAST) {
            maze[startY][startX+1] = PATH;
        } else if (direction == SOUTH) {
            maze[startY+1][startX] = PATH;
        } else {
            maze[startY][startX-1] = PATH;
        }

        // Recursively generate the rest of the maze
        generateMaze(maze, newCol, newRow);
    }
}

/*
 * Check if a move is valid within the maze.
 */
bool isValidMove(char maze[MAZE_SIZE][MAZE_SIZE], int row, int col, int direction)
{
    // Check that the move stays within the bounds of the maze
    if (row < 0 || row >= MAZE_SIZE || col < 0 || col >= MAZE_SIZE) {
        return false;
    }

    // Check that the cell doesn't already contain a path or the start/end cells
    if (maze[row][col] != WALL) {
        return false;
    }

    // Check that there are no adjacent paths
    int count = 0;
    if (row > 0 && maze[row-1][col] == PATH && direction != SOUTH) {
        count++;
    }
    if (row < MAZE_SIZE-1 && maze[row+1][col] == PATH && direction != NORTH) {
        count++;
    }
    if (col > 0 && maze[row][col-1] == PATH && direction != EAST) {
        count++;
    }
    if (col < MAZE_SIZE-1 && maze[row][col+1] == PATH && direction != WEST) {
        count++;
    }
    if (count > 1) {
        return false;
    }

    return true;
}

/*
 * Recursively search for a route through the maze.
 */
bool findRoute(char maze[MAZE_SIZE][MAZE_SIZE], int startX, int startY, int endX, int endY, int dir)
{
    // Check if we've reached the end cell
    if (startX == endX && startY == endY) {
        return true;
    }

    // Check if we've hit a dead end
    if (!isValidMove(maze, startY, startX, dir)) {
        return false;
    }

    // Mark the current cell as part of the path
    maze[startY][startX] = PATH;

    // Check each direction in a random order
    int directions[4] = {NORTH, EAST, SOUTH, WEST};
    int i;
    for (i = 0; i < 4; i++) {
        int j = rand() % 4;
        int temp = directions[i];
        directions[i] = directions[j];
        directions[j] = temp;
    }
    for (i = 0; i < 4; i++) {
        int direction = directions[i];

        // Compute the new row and column based on the direction
        int newRow = startY;
        int newCol = startX;
        switch (direction) {
            case NORTH:
                newRow = startY - 1;
                break;
            case EAST:
                newCol = startX + 1;
                break;
            case SOUTH:
                newRow = startY + 1;
                break;
            case WEST:
                newCol = startX - 1;
                break;
        }

        // Recursively search in the new direction
        if (findRoute(maze, newCol, newRow, endX, endY, direction)) {
            return true;
        }
    }

    // Unmark the current cell as part of the path
    maze[startY][startX] = WALL;

    return false;
}