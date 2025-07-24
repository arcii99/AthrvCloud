//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 15
#define COLS 10
#define WALL '+'
#define SPACE ' '
#define START 'S'
#define END 'E'

void generateMaze(char maze[ROWS][COLS]);
void printMaze(char maze[ROWS][COLS]);
void fillWalls(char maze[ROWS][COLS]);
void carvePath(int x, int y, char maze[ROWS][COLS]);
void placeStartAndEnd(char maze[ROWS][COLS]);

int main() {
    char maze[ROWS][COLS];
    srand(time(0)); // Set random seed based on current time
    generateMaze(maze);
    placeStartAndEnd(maze);
    printMaze(maze);
    return 0;
}

// Generate a maze by filling it with walls and then carving a path through it
void generateMaze(char maze[ROWS][COLS]) {
    fillWalls(maze);
    carvePath(1, 1, maze); // Carve a path starting at (1, 1)
}

// Print out the generated maze
void printMaze(char maze[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%c", maze[i][j]);
        }
        printf("\n");
    }
}

// Fill the maze with walls
void fillWalls(char maze[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            maze[i][j] = WALL;
        }
    }
}

// Carve a path through the maze starting at (x, y)
void carvePath(int x, int y, char maze[ROWS][COLS]) {
    if (x < 1 || x >= ROWS - 1 || y < 1 || y >= COLS - 1 || maze[x][y] != WALL) {
        // If we've gone out of bounds or hit a non-wall, stop carving
        return;
    }
    
    // Carve out the current cell
    maze[x][y] = SPACE;
    
    // Randomly choose a direction to carve in and carve into that cell
    int choices[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}}; // Possible directions to carve
    int numChoices = 4; // Start with all possible directions to choose from
    
    // Shuffle the array of choices using the Fisher-Yates algorithm
    for (int i = numChoices - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        int tempX = choices[i][0];
        int tempY = choices[i][1];
        choices[i][0] = choices[j][0];
        choices[i][1] = choices[j][1];
        choices[j][0] = tempX;
        choices[j][1] = tempY;
    }
    
    for (int i = 0; i < numChoices; i++) {
        int nextX = x + choices[i][0] * 2; // Find the cell two steps away in this direction
        int nextY = y + choices[i][1] * 2;
        carvePath(nextX, nextY, maze); // Recursively carve out this next cell
    }
}

// Place the start and end points in the maze
void placeStartAndEnd(char maze[ROWS][COLS]) {
    maze[1][0] = START;
    maze[ROWS-2][COLS-1] = END;
}