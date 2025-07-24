//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 25
#define COLS 25

// Predicate function to check if a cell is valid
int isValid(int row, int col, int maze[][COLS]) {
    return row >= 0 && row < ROWS && col >= 0 && col < COLS && maze[row][col] == -1;
}

// Recursive function to generate the maze
void generateMaze(int maze[][COLS], int row, int col, int depth) {
    // Base case
    if (depth <= 0) {
        return;
    }

    // Mark the current cell as visited
    maze[row][col] = depth;

    // Create an array of directions
    int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    // Shuffle the directions randomly
    for (int i = 0; i < 4; i++) {
        int j = rand() % 4;
        int temp1 = directions[i][0];
        int temp2 = directions[i][1];
        directions[i][0] = directions[j][0];
        directions[i][1] = directions[j][1];
        directions[j][0] = temp1;
        directions[j][1] = temp2;
    }

    // Recursively call the function for each direction
    for (int i = 0; i < 4; i++) {
        int nextRow = row + directions[i][0];
        int nextCol = col + directions[i][1];
        if (isValid(nextRow, nextCol, maze)) {
            generateMaze(maze, nextRow, nextCol, depth - 1);
        }
    }
}

int main() {
    // Initialize the maze with -1
    int maze[ROWS][COLS];
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            maze[i][j] = -1;
        }
    }

    // Seed the random number generator
    srand(time(NULL));

    // Generate the maze
    generateMaze(maze, ROWS / 2, COLS / 2, 20);

    // Print the maze
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (maze[i][j] == -1) {
                printf("#");
            } else {
                printf(" ");
            }
            printf(" ");
        }
        printf("\n");
    }

    return 0;
}