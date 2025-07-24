//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: Claude Shannon
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define ROWS 10
#define COLS 20

// Function prototypes
void generateMaze(int maze[ROWS][COLS]);
void printMaze(int maze[ROWS][COLS]);
int findRoute(int maze[ROWS][COLS], int startRow, int startCol, int endRow, int endCol);

int main() {
    int maze[ROWS][COLS];
    int startRow, startCol, endRow, endCol, route;

    // Seed the random number generator
    srand(time(NULL));

    // Generate the maze and print it
    generateMaze(maze);
    printMaze(maze);
    
    // Get start and end positions from user
    printf("Enter starting row and column (separated by space): ");
    scanf("%d %d", &startRow, &startCol);
    printf("Enter ending row and column (separated by space): ");
    scanf("%d %d", &endRow, &endCol);

    // Find a route from start to end and print it
    route = findRoute(maze, startRow, startCol, endRow, endCol);
    if (route) {
        printf("Route found!\n");
        printMaze(maze);
    }
    else {
        printf("No route found.\n");
    }

    return 0;
}

// Function definitions

// Generates a random maze
void generateMaze(int maze[ROWS][COLS]) {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            // 20% chance of a blocked cell
            if (rand() % 5 == 0) {
                maze[i][j] = 1;
            }
            else {
                maze[i][j] = 0;
            }
        }
    }
    // Set start and end points
    maze[0][0] = 0;
    maze[ROWS-1][COLS-1] = 0;
}

// Prints the current state of the maze
void printMaze(int maze[ROWS][COLS]) {
    int i, j;
    printf("\n");
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            if (maze[i][j] == 0) {
                printf(" ");
            }
            else {
                printf("#");
            }
        }
        printf("\n");
    }
    printf("\n");
}

// Finds a route from start to end using the right-hand rule
int findRoute(int maze[ROWS][COLS], int startRow, int startCol, int endRow, int endCol) {
    int currentRow = startRow;
    int currentCol = startCol;
    int nextRow, nextCol;
    int direction = 0;  // 0 = right, 1 = down, 2 = left, 3 = up

    while (currentRow != endRow || currentCol != endCol) {
        // Check for end of maze
        if (currentRow == ROWS-1 && currentCol == COLS-1) {
            return 1;
        }

        // Look for a clear path to the right
        if (direction == 0 && currentCol < COLS-1 && maze[currentRow][currentCol+1] == 0) {
            // Turn right
            direction = 1;
            nextRow = currentRow;
            nextCol = currentCol + 1;
        }
        // Look for a clear path down
        else if (direction == 1 && currentRow < ROWS-1 && maze[currentRow+1][currentCol] == 0) {
            // Turn down
            direction = 2;
            nextRow = currentRow + 1;
            nextCol = currentCol;
        }
        // Look for a clear path to the left
        else if (direction == 2 && currentCol > 0 && maze[currentRow][currentCol-1] == 0) {
            // Turn left
            direction = 3;
            nextRow = currentRow;
            nextCol = currentCol - 1;
        }
        // Look for a clear path up
        else if (direction == 3 && currentRow > 0 && maze[currentRow-1][currentCol] == 0) {
            // Turn up
            direction = 0;
            nextRow = currentRow - 1;
            nextCol = currentCol;
        }
        // No clear path, turn left
        else {
            direction = (direction + 3) % 4;
            switch (direction) {
                case 0:
                    nextRow = currentRow;
                    nextCol = currentCol + 1;
                    break;
                case 1:
                    nextRow = currentRow + 1;
                    nextCol = currentCol;
                    break;
                case 2:
                    nextRow = currentRow;
                    nextCol = currentCol - 1;
                    break;
                case 3:
                    nextRow = currentRow - 1;
                    nextCol = currentCol;
                    break;
            }
        }

        // Move to the next cell
        currentRow = nextRow;
        currentCol = nextCol;
    }
    return 1;
}