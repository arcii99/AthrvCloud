//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Constants
#define MAZE_SIZE 20
#define WALL 1
#define PATH 0
#define START 2
#define END 3

// Function prototypes
void printMaze(int maze[][MAZE_SIZE]);
int findRoute(int maze[][MAZE_SIZE], int row, int col);
void setStartAndEnd(int maze[][MAZE_SIZE], int *startRow, int *startCol, int *endRow, int *endCol);
void generateMaze(int maze[][MAZE_SIZE]);

// Main function
int main() {
    int maze[MAZE_SIZE][MAZE_SIZE];
    int startRow, startCol, endRow, endCol;

    srand(time(NULL));

    // Generate maze
    generateMaze(maze);

    // Set start and end points
    setStartAndEnd(maze, &startRow, &startCol, &endRow, &endCol);
    maze[startRow][startCol] = START;
    maze[endRow][endCol] = END;

    // Find route
    int found = findRoute(maze, startRow, startCol);

    // Print maze
    printf("MAZE ROUTE FINDER\n");
    printMaze(maze);

    if (found) {
        printf("\nRoute found!\n");
    } else {
        printf("\nNo route found.\n");
    }

    return 0;
}

// Prints the maze
void printMaze(int maze[][MAZE_SIZE]) {
    for (int i = 0; i < MAZE_SIZE; i++) {
        for (int j = 0; j < MAZE_SIZE; j++) {
            switch (maze[i][j]) {
                case WALL:
                    printf("%c", 178);
                    break;
                case PATH:
                    printf(" ");
                    break;
                case START:
                    printf("S");
                    break;
                case END:
                    printf("E");
                    break;
                default:
                    printf("?");
                    break;
            }
        }
        printf("\n");
    }
}

// Finds the route from start to end points
int findRoute(int maze[][MAZE_SIZE], int row, int col) {
    if (row < 0 || col < 0 || row >= MAZE_SIZE || col >= MAZE_SIZE) {
        return 0;
    }

    // Base case: end point is reached
    if (maze[row][col] == END) {
        return 1;
    }

    // Recursive case: check neighboring cells
    if (maze[row][col] == PATH) {
        maze[row][col] = 4;  // Mark cell as visited

        // Check neighbors
        if (findRoute(maze, row-1, col) || findRoute(maze, row+1, col) || findRoute(maze, row, col-1) || findRoute(maze, row, col+1)) {
            maze[row][col] = PATH;  // Mark as part of solution path
            return 1;
        }
    }

    return 0;
}

// Sets random start and end points for the maze
void setStartAndEnd(int maze[][MAZE_SIZE], int *startRow, int *startCol, int *endRow, int *endCol) {
    do {
        *startRow = rand() % MAZE_SIZE;
        *startCol = rand() % MAZE_SIZE;
    } while (maze[*startRow][*startCol] == WALL);

    do {
        *endRow = rand() % MAZE_SIZE;
        *endCol = rand() % MAZE_SIZE;
    } while (maze[*endRow][*endCol] == WALL || (*endRow == *startRow && *endCol == *startCol));
}

// Generates the maze using random number generator
void generateMaze(int maze[][MAZE_SIZE]) {
    // Initialize maze to all walls
    for (int i = 0; i < MAZE_SIZE; i++) {
        for (int j = 0; j < MAZE_SIZE; j++) {
            maze[i][j] = WALL;
        }
    }

    // Carve out starting point
    maze[0][0] = PATH;

    // Generate maze using depth-first search algorithm
    int stackRow[MAZE_SIZE*MAZE_SIZE], stackCol[MAZE_SIZE*MAZE_SIZE];  // Using arrays as stacks
    int stackTop = 0;
    int currRow = 0, currCol = 0;

    do {
        // Get unvisited neighbors
        int neighbors[4][2] = { {currRow-1,currCol}, {currRow+1,currCol}, {currRow,currCol-1}, {currRow,currCol+1} };
        int numNeighbors = 0;

        for (int i = 0; i < 4; i++) {
            int row = neighbors[i][0];
            int col = neighbors[i][1];

            if (row >= 0 && col >= 0 && row < MAZE_SIZE && col < MAZE_SIZE && maze[row][col] == WALL) {
                neighbors[numNeighbors][0] = row;
                neighbors[numNeighbors][1] = col;
                numNeighbors++;
            }
        }

        // If unvisited neighbors exist, pick random one and carve out path
        if (numNeighbors > 0) {
            int randIndex = rand() % numNeighbors;
            int randRow = neighbors[randIndex][0];
            int randCol = neighbors[randIndex][1];

            maze[randRow][randCol] = PATH;
            maze[(currRow+randRow)/2][(currCol+randCol)/2] = PATH;  // Carve out path between current and new cell

            stackRow[stackTop] = currRow;
            stackCol[stackTop] = currCol;
            stackTop++;

            currRow = randRow;
            currCol = randCol;
        } else {  // If no unvisited neighbors exist, backtrack
            stackTop--;
            currRow = stackRow[stackTop];
            currCol = stackCol[stackTop];
        }

    } while (stackTop > 0);
}