//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: synchronous
#include <stdio.h>

#define N 5 // Maze size

// Maze matrix
int maze[N][N] = {
    {1, 0, 1, 1, 1},
    {1, 1, 1, 0, 1},
    {1, 0, 0, 1, 1},
    {1, 0, 0, 1, 0},
    {1, 1, 1, 1, 1},
};

// Solution matrix
int solution[N][N] = { 
    {0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0},
};

// Print the maze on console
void printMaze(int maze[N][N]) {
    printf("MAZE:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", maze[i][j]);
        }
        printf("\n");
    }
}

// Check if position is valid
int validPosition(int row, int col) {
    return (row >= 0) && (row < N) && (col >= 0) && (col < N) && maze[row][col];
}

// Recursive function to solve maze
int solveMaze(int row, int col) {
    // If we have reached the destination, return success
    if (row == N - 1 && col == N - 1) {
        solution[row][col] = 1;
        return 1;
    }

    if (validPosition(row, col)) {
        solution[row][col] = 1;

        // Move down
        if (solveMaze(row + 1, col)) {
            return 1;
        }

        // Move right
        if (solveMaze(row, col + 1)) {
            return 1;
        }

        // Backtrack
        solution[row][col] = 0;
        return 0;
    }

    return 0;
}

// Print the solution matrix on console
void printSolution(int solution[N][N]) {
    printf("\nSOLUTION:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", solution[i][j]);
        }
        printf("\n");
    }
}

// Main function
int main() {
    printMaze(maze);

    if (solveMaze(0, 0)) {
        printf("\nSolution found!\n");
        printSolution(solution);
    } else {
        printf("\nNo solution found!\n");
    }

    return 0;
}