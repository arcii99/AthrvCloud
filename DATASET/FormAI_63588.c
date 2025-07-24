//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Maze dimensions
#define ROW 20
#define COL 20

// Cell directions
#define NORTH 0
#define SOUTH 1
#define EAST 2
#define WEST 3

// Cell state
#define VISITED 1
#define UNVISITED 0

int maze[ROW][COL]; // 2D array to store the maze
int visited[ROW][COL]; // 2D array to mark visited cells

// Function prototypes
void initMaze();
void generateMaze(int row, int col);
int isPath(int row, int col, int dir);
void displayMaze();

int main() {
    srand(time(NULL)); // Initialize random seed

    initMaze(); // Initialize maze
    generateMaze(0, 0); // Generate maze starting from top left corner
    displayMaze(); // Display maze

    return 0;
}

// Initialize maze
void initMaze() {
    int i, j;
    for (i = 0; i < ROW; i++) {
        for (j = 0; j < COL; j++) {
            maze[i][j] = 15; // All walls are up
            visited[i][j] = UNVISITED; // All cells are unvisited
        }
    }
}

// Generate maze recursively using depth-first search algorithm
void generateMaze(int row, int col) {
    visited[row][col] = VISITED; // Mark current cell as visited

    // Shuffle the directions
    int dirs[4] = {NORTH, SOUTH, EAST, WEST};
    int i, j, tmp;
    for (i = 0; i < 4; i++) {
        j = rand() % 4;
        tmp = dirs[i];
        dirs[i] = dirs[j];
        dirs[j] = tmp;
    }

    // Visit neighbors in random order
    for (i = 0; i < 4; i++) {
        int dir = dirs[i];
        if (isPath(row, col, dir)) { // Check if neighboring cell is unvisited
            switch (dir) {
                case NORTH: // North
                    maze[row][col] &= ~1;
                    maze[row-1][col] &= ~4;
                    generateMaze(row-1, col);
                    break;
                case SOUTH: // South
                    maze[row][col] &= ~4;
                    maze[row+1][col] &= ~1;
                    generateMaze(row+1, col);
                    break;
                case EAST: // East
                    maze[row][col] &= ~2;
                    maze[row][col+1] &= ~8;
                    generateMaze(row, col+1);
                    break;
                case WEST: // West
                    maze[row][col] &= ~8;
                    maze[row][col-1] &= ~2;
                    generateMaze(row, col-1);
                    break;
            }
        }
    }
}

// Check if the neighboring cell is unvisited
int isPath(int row, int col, int dir) {
    switch (dir) {
        case NORTH: // North
            if (row-1 < 0 || visited[row-1][col] == VISITED)
                return 0;
            break;
        case SOUTH: // South
            if (row+1 >= ROW || visited[row+1][col] == VISITED)
                return 0;
            break;
        case EAST: // East
            if (col+1 >= COL || visited[row][col+1] == VISITED)
                return 0;
            break;
        case WEST: // West
            if (col-1 < 0 || visited[row][col-1] == VISITED)
                return 0;
            break;
    }
    return 1;
}

// Display maze
void displayMaze() {
    int i, j;
    for (i = 0; i < ROW; i++) {
        for (j = 0; j < COL; j++) {
            switch (maze[i][j]) {
                case 0: // Empty cell
                    printf("   ");
                    break;
                case 1: // North wall
                    printf(" _ ");
                    break;
                case 2: // East wall
                    printf("|  ");
                    break;
                case 3: // North and East walls
                    printf(" _|");
                    break;
                case 4: // South wall
                    printf("   ");
                    break;
                case 5: // North and South walls
                    printf(" _|");
                    break;
                case 6: // East and South walls
                    printf("|_ ");
                    break;
                case 7: // North, East, and South walls
                    printf("|_|");
                    break;
                case 8: // West wall
                    printf("  |");
                    break;
                case 9: // North and West walls
                    printf("_  ");
                    break;
                case 10: // East and West walls
                    printf("| |");
                    break;
                case 11: // North, East, and West walls
                    printf("_| |");
                    break;
                case 12: // South and West walls
                    printf("  _|");
                    break;
                case 13: // North, South, and West walls
                    printf("_|_ ");
                    break;
                case 14: // East, South, and West walls
                    printf("|_|");
                    break;
                case 15: // North, East, South, and West walls
                    printf("|_|");
                    break;
            }
        }
        printf("\n");
    }
}