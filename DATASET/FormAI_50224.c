//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>

#define ROWS 10
#define COLUMNS 10

// Function to print the maze
void print_maze(char maze[ROWS][COLUMNS]) {
    for (int row = 0; row < ROWS; row++) {
        for (int col = 0; col < COLUMNS; col++) {
            printf("%c", maze[row][col]);
        }
        printf("\n");
    }
}

// Function to check if a cell is a valid cell to move to
int is_valid_move(char maze[ROWS][COLUMNS], int row, int col) {
    // Check if cell is within maze bounds
    if (row >= 0 && row < ROWS && col >= 0 && col < COLUMNS) {
        // Check if cell is not a wall
        if (maze[row][col] != '*') {
            return 1;
        }
    }
    return 0;
}

// Function to find the path through the maze using recursion
int find_path(char maze[ROWS][COLUMNS], int row, int col) {
    // Check if we have reached the end of the maze
    if (row == ROWS - 1 && col == COLUMNS - 1) {
        maze[row][col] = 'X';
        return 1;
    }

    // Check if current cell is a valid move
    if (is_valid_move(maze, row, col)) {
        // Mark current cell as visited
        maze[row][col] = 'X';

        // Try moving right
        if (find_path(maze, row, col + 1)) {
            return 1;
        }

        // Try moving down
        if (find_path(maze, row + 1, col)) {
            return 1;
        }

        // Try moving left
        if (find_path(maze, row, col - 1)) {
            return 1;
        }

        // Try moving up
        if (find_path(maze, row - 1, col)) {
            return 1;
        }

        // Mark current cell as unvisited
        maze[row][col] = '.';
    }

    // Path not found
    return 0;
}

int main() {
    // Define the maze
    char maze[ROWS][COLUMNS] = {
        {'*', '*', '*', '*', '*', '*', '*', '*', '*', '*'},
        {'*', '.', '.', '.', '*', '.', '.', '.', '.', '*'},
        {'*', '.', '*', '.', '*', '.', '*', '*', '.', '*'},
        {'*', '*', '*', '.', '*', '.', '.', '.', '.', '*'},
        {'*', '.', '.', '.', '.', '*', '*', '*', '.', '*'},
        {'*', '*', '*', '*', '.', '*', '*', '*', '.', '*'},
        {'*', '.', '.', '.', '.', '.', '.', '.', '.', '*'},
        {'*', '*', '*', '*', '*', '.', '*', '*', '*', '*'},
        {'*', '.', '.', '.', '.', '.', '.', '.', '.', '*'},
        {'*', '*', '*', '*', '*', '*', '*', '*', '*', '*'}
    };

    // Print the initial maze
    printf("Initial maze:\n");
    print_maze(maze);
    printf("\n");

    // Find the path through the maze
    if (find_path(maze, 0, 0)) {
        printf("Path found!\n");
    } else {
        printf("Path not found!\n");
    }

    // Print the final maze
    printf("\nFinal maze:\n");
    print_maze(maze);

    // Exit program
    return 0;
}