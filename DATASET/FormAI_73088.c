//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW_SIZE 20
#define COL_SIZE 20

// Function prototypes
void generateMaze(char maze[][COL_SIZE]);
void printMaze(char maze[][COL_SIZE]);
void dfs(char maze[][COL_SIZE], int row, int col);

// Main function
int main() {
    // Initialize maze with walls
    char maze[ROW_SIZE][COL_SIZE];
    for (int i = 0; i < ROW_SIZE; i++) {
        for (int j = 0; j < COL_SIZE; j++) {
            maze[i][j] = '#';
        }
    }

    // Generate maze
    generateMaze(maze);

    // Print maze
    printMaze(maze);

    return 0;
}

// Maze generation using DFS algorithm
void generateMaze(char maze[][COL_SIZE]) {
    // Seed random number generator
    srand(time(NULL));

    // Start DFS from top-left corner
    dfs(maze, 1, 1);
}

// Depth First Search algorithm
void dfs(char maze[][COL_SIZE], int row, int col) {
    // Mark current cell as visited
    maze[row][col] = ' ';

    // Generate random order of directions to explore
    int directions[4] = {0, 1, 2, 3};
    for (int i = 0; i < 4; i++) {
        int randomIndex = rand() % 4;
        int temp = directions[randomIndex];
        directions[randomIndex] = directions[i];
        directions[i] = temp;
    }

    // Explore in random order
    for (int i = 0; i < 4; i++) {
        int direction = directions[i];
        int newRow = row + (direction == 0 ? 0 : direction == 1 ? 1 : direction == 2 ? 0 : -1);
        int newCol = col + (direction == 0 ? -1 : direction == 1 ? 0 : direction == 2 ? 1 : 0);
        if (newRow < 1 || newRow >= ROW_SIZE - 1 || newCol < 1 || newCol >= COL_SIZE - 1 ||
            maze[newRow][newCol] != '#') {
            continue;
        }
        if (direction == 0) {
            maze[row][col - 1] = ' ';
        }
        if (direction == 1) {
            maze[row + 1][col] = ' ';
        }
        if (direction == 2) {
            maze[row][col + 1] = ' ';
        }
        if (direction == 3) {
            maze[row - 1][col] = ' ';
        }
        dfs(maze, newRow, newCol);
    }
}

// Print maze
void printMaze(char maze[][COL_SIZE]) {
    for (int i = 0; i < ROW_SIZE; i++) {
        for (int j = 0; j < COL_SIZE; j++) {
            printf("%c", maze[i][j]);
        }
        printf("\n");
    }
}