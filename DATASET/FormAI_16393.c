//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Constants for the maze dimensions
#define MAZE_ROWS 31
#define MAZE_COLS 61

// Constants for the maze cells
#define MAZE_WALL '|'
#define MAZE_PATH ' '
#define MAZE_START 'S'
#define MAZE_END 'E'

// Arrays for the directions of the maze generation algorithm
const int DX[4] = {1, 0, -1, 0};
const int DY[4] = {0, 1, 0, -1};

// Structs for the cells and the maze
typedef struct {
    int x, y;
} Cell;

typedef struct {
    Cell start, end;
    char cells[MAZE_ROWS][MAZE_COLS];
} Maze;

// Function prototypes
void initMaze(Maze *maze);
void generateMaze(Maze *maze);
void printMaze(Maze maze);

/**
 * Entry point of the program. Generates a random maze and prints it.
 */
int main() {
    srand(time(NULL)); // Initialize the random number generator
    Maze maze;
    initMaze(&maze);
    generateMaze(&maze);
    printMaze(maze);
    return 0;
}

/**
 * Initializes the maze with walls and a start and end cell.
 */
void initMaze(Maze *maze) {
    // Set all cells to walls
    for (int row = 0; row < MAZE_ROWS; row++) {
        for (int col = 0; col < MAZE_COLS; col++) {
            maze->cells[row][col] = MAZE_WALL;
        }
    }
    // Choose a random start and end cell on opposite sides of the maze
    int startX = rand() % (MAZE_COLS - 2) + 1; // Exclude border columns
    int endX = rand() % (MAZE_COLS - 2) + 1;
    maze->start = (Cell) {0, startX};
    maze->end = (Cell) {MAZE_ROWS - 1, endX};
    maze->cells[maze->start.x][maze->start.y] = MAZE_START;
    maze->cells[maze->end.x][maze->end.y] = MAZE_END;
}

/**
 * Generates the maze using a randomized depth-first search algorithm.
 */
void generateMaze(Maze *maze) {
    Cell stack[MAZE_ROWS * MAZE_COLS]; // Stack for DFS
    int stackSize = 0;
    maze->cells[maze->start.x][maze->start.y] = MAZE_PATH;
    stack[stackSize++] = maze->start;
    while (stackSize > 0) {
        Cell current = stack[stackSize - 1];
        int direction = rand() % 4;
        Cell next = {current.x + DX[direction], current.y + DY[direction]};
        if (next.x >= 0 && next.x < MAZE_ROWS &&
            next.y >= 0 && next.y < MAZE_COLS &&
            maze->cells[next.x][next.y] == MAZE_WALL) {
            maze->cells[next.x][next.y] = MAZE_PATH;
            stack[stackSize++] = next;
        } else {
            stackSize--;
        }
    }
}

/**
 * Prints the maze to the console.
 */
void printMaze(Maze maze) {
    for (int row = 0; row < MAZE_ROWS; row++) {
        for (int col = 0; col < MAZE_COLS; col++) {
            printf("%c", maze.cells[row][col]);
        }
        printf("\n");
    }
}