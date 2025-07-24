//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Size of the maze
#define ROWS 20
#define COLS 20

// Structure for a cell in the maze
typedef struct {
    int row;
    int col;
    int visited;
    int walls[4]; // top, right, bottom, left
} Cell;

// Function prototypes
void initMaze(Cell maze[ROWS][COLS]);
void printMaze(Cell maze[ROWS][COLS]);
void generateMaze(Cell maze[ROWS][COLS], int startRow, int startCol);
int checkNeighbors(Cell maze[ROWS][COLS], int row, int col);

int main() {
    // Seed the random number generator
    srand(time(NULL));
    
    // Initialize the maze
    Cell maze[ROWS][COLS];
    initMaze(maze);
    
    // Generate the maze starting from the middle of the maze
    generateMaze(maze, ROWS/2, COLS/2);
    
    // Print the final maze
    printMaze(maze);
    
    return 0;
}

// Initializes the maze with walls on every side
void initMaze(Cell maze[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            maze[i][j].row = i;
            maze[i][j].col = j;
            maze[i][j].visited = 0;
            for (int k = 0; k < 4; k++) {
                maze[i][j].walls[k] = 1;
            }
        }
    }
}

// Prints the maze
void printMaze(Cell maze[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        // Print top walls
        for (int j = 0; j < COLS; j++) {
            if (maze[i][j].walls[0] == 1) {
                printf("+--");
            } else {
                printf("+  ");
            }
        }
        printf("+\n");
        
        // Print left and right walls
        for (int j = 0; j < COLS; j++) {
            if (maze[i][j].walls[3] == 1) {
                printf("|  ");
            } else {
                printf("   ");
            }
            if (maze[i][j].walls[1] == 1) {
                printf("|");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
    
    // Print bottom walls
    for (int j = 0; j < COLS; j++) {
        printf("+--");
    }
    printf("+\n");
}

// Generates the maze using recursive backtracking
void generateMaze(Cell maze[ROWS][COLS], int row, int col) {
    Cell* start = &maze[row][col];
    start->visited = 1;
    
    int neighbor = 0;
    while ((neighbor = checkNeighbors(maze, row, col)) != -1) {
        int neighborRow = row;
        int neighborCol = col;
        if (neighbor == 0) { // Top
            maze[neighborRow][neighborCol].walls[2] = 0;
            neighborRow--;
            maze[neighborRow][neighborCol].walls[0] = 0;
        } else if (neighbor == 1) { // Right
            maze[neighborRow][neighborCol].walls[1] = 0;
            neighborCol++;
            maze[neighborRow][neighborCol].walls[3] = 0;
        } else if (neighbor == 2) { // Bottom
            maze[neighborRow][neighborCol].walls[3] = 0;
            neighborRow++;
            maze[neighborRow][neighborCol].walls[0] = 0;
        } else { // Left
            maze[neighborRow][neighborCol].walls[0] = 0;
            neighborCol--;
            maze[neighborRow][neighborCol].walls[1] = 0;
        }
        generateMaze(maze, neighborRow, neighborCol);
    }
}

// Checks the neighboring cells of the current cell
int checkNeighbors(Cell maze[ROWS][COLS], int row, int col) {
    int neighbors[4] = {-1, -1, -1, -1}; // top, right, bottom, left
    int numNeighbors = 0;
    
    // Top neighbor
    if (row > 0 && maze[row-1][col].visited == 0) {
        neighbors[numNeighbors++] = 0;
    }
    // Right neighbor
    if (col < COLS-1 && maze[row][col+1].visited == 0) {
        neighbors[numNeighbors++] = 1;
    }
    // Bottom neighbor
    if (row < ROWS-1 && maze[row+1][col].visited == 0) {
        neighbors[numNeighbors++] = 2;
    }
    // Left neighbor
    if (col > 0 && maze[row][col-1].visited == 0) {
        neighbors[numNeighbors++] = 3;
    }
    
    if (numNeighbors > 0) {
        int randomIndex = rand() % numNeighbors;
        return neighbors[randomIndex];
    }
    
    return -1;
}