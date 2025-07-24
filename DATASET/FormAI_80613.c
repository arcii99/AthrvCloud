//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define maze dimensions
#define ROWS 10
#define COLS 10

// Define start and end positions
#define START_ROW 0
#define START_COL 0
#define END_ROW 9
#define END_COL 9

// Define wall and path symbols
#define WALL '#'
#define PATH '.'

// Create maze grid
char maze[ROWS][COLS] = {
    {' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', ' '},
    {'#', '#', ' ', '#', ' ', ' ', '#', '#', ' ', '#'},
    {'#', ' ', ' ', '#', '#', ' ', '#', ' ', ' ', '#'},
    {'#', ' ', '#', '#', ' ', '#', ' ', '#', ' ', '#'},
    {'#', ' ', ' ', ' ', ' ', '#', ' ', '#', ' ', '#'},
    {'#', '#', '#', ' ', '#', '#', ' ', ' ', ' ', '#'},
    {'#', ' ', ' ', ' ', ' ', '#', '#', '#', ' ', '#'},
    {'#', '#', '#', '#', ' ', '#', '#', '#', ' ', '#'},
    {'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
    {' ', '#', '#', '#', '#', '#', '#', '#', '#', ' '}
};

// Function to check if cell is valid and not a wall
int is_valid(int row, int col) {
    if (row < 0 || row >= ROWS || col < 0 || col >= COLS) {
        return 0;
    }
    if (maze[row][col] == WALL) {
        return 0;
    }
    return 1;
}

// Recursive function to find path in maze
int find_path(int row, int col) {
    // Exit condition when end is reached
    if (row == END_ROW && col == END_COL) {
        return 1;
    }
    // Check if current cell is valid
    if (!is_valid(row, col)) {
        return 0;
    }
    // Mark current cell as part of path
    maze[row][col] = PATH;
    // Check adjacent cells recursively
    if (find_path(row-1, col) || find_path(row, col+1) || find_path(row+1, col) || find_path(row, col-1)) {
        return 1;
    }
    // Mark current cell as not part of path (backtrack)
    maze[row][col] = ' ';
    return 0;
}

int main() {
    // Print initial maze
    printf("Initial maze:\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%c ", maze[i][j]);
        }
        printf("\n");
    }
    // Find path in maze
    find_path(START_ROW, START_COL);
    // Print final maze
    printf("\nFinal maze:\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%c ", maze[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    return 0;
}