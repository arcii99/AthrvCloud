//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 20
#define COLS 40
#define MAX_STEPS 800

// Function to print the maze
void print_maze(int maze[ROWS][COLS], int rowStart, int colStart, int rowEnd, int colEnd) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (i == rowStart && j == colStart) {
                printf("S "); // Start
            } else if (i == rowEnd && j == colEnd) {
                printf("E "); // End
            } else if (maze[i][j] == 1) {
                printf("# "); // Wall
            } else if (maze[i][j] == 2) {
                printf(". "); // Visited
            } else {
                printf("  "); // Empty Space
            }
        }
        printf("\n");
    }
}

// Function to generate the maze using depth-first search algorithm
void generate_maze(int maze[ROWS][COLS], int row, int col) {
    maze[row][col] = 0; // Set current cell as empty space

    // Create an array of possible neighbors
    int neighbors[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

    // Shuffle the array of neighbors randomly
    for (int i = 0; i < 4; i++) {
        int j = rand() % 4;
        int tempRow = neighbors[i][0];
        int tempCol = neighbors[i][1];
        neighbors[i][0] = neighbors[j][0];
        neighbors[i][1] = neighbors[j][1];
        neighbors[j][0] = tempRow;
        neighbors[j][1] = tempCol;
    }

    for (int i = 0; i < 4; i++) {
        int newRow = row + neighbors[i][0] * 2;
        int newCol = col + neighbors[i][1] * 2;

        // Check if the new cell is within the maze
        if (newRow >= 0 && newRow < ROWS && newCol >= 0 && newCol < COLS) {

            // Check if the new cell is not yet visited
            if (maze[newRow][newCol] == 1) {

                // Carve a path from the current cell to the new cell
                maze[row + neighbors[i][0]][col + neighbors[i][1]] = 0;
                generate_maze(maze, newRow, newCol);
            }
        }
    }
}

// Function to find the path through the maze using depth-first search algorithm
int find_path(int maze[ROWS][COLS], int row, int col, int rowEnd, int colEnd, int path[MAX_STEPS][2], int *steps) {
    if (row == rowEnd && col == colEnd) {
        // Reached the end of the maze
        return 1;
    } else if (*steps == MAX_STEPS) {
        // Reached the maximum number of steps
        return 0;
    } else if (maze[row][col] == 1 || maze[row][col] == 2) {
        // Hit a wall or visited cell
        return 0;
    } else {
        // Mark the current cell as visited
        maze[row][col] = 2;

        // Check all possible neighbors
        int neighbors[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

        for (int i = 0; i < 4; i++) {
            int newRow = row + neighbors[i][0];
            int newCol = col + neighbors[i][1];

            // Check if the new cell is within the maze
            if (newRow >= 0 && newRow < ROWS && newCol >= 0 && newCol < COLS) {

                // Recursively check the new cell
                if (find_path(maze, newRow, newCol, rowEnd, colEnd, path, steps)) {

                    // Add the current cell to the path
                    path[*steps][0] = row;
                    path[*steps][1] = col;
                    (*steps)++;
                    return 1;
                }
            }
        }

        return 0;
    }
}

int main() {
    int maze[ROWS][COLS];

    // Generate the maze
    srand(time(NULL));
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (i == 0 || j == 0 || i == ROWS - 1 || j == COLS - 1) {
                maze[i][j] = 1; // Border cells as walls
            } else {
                maze[i][j] = 2; // All other cells as not yet visited
            }
        }
    }
    generate_maze(maze, 2, 2);

    // Choose start and end points
    int rowStart = 1;
    int colStart = 1;
    int rowEnd = ROWS - 2;
    int colEnd = COLS - 2;

    // Find the path through the maze
    int path[MAX_STEPS][2];
    int steps = 0;
    find_path(maze, rowStart, colStart, rowEnd, colEnd, path, &steps);

    // Print the maze and path
    printf("MAZE:\n");
    print_maze(maze, rowStart, colStart, rowEnd, colEnd);
    printf("\nPATH:\n");
    for (int i = steps - 1; i >= 0; i--) {
        printf("(%d,%d)\n", path[i][0], path[i][1]);
    }

    return 0;
}