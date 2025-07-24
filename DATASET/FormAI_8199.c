//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#define MAX_ROWS 10
#define MAX_COLS 10

void printMaze(char maze[MAX_ROWS][MAX_COLS]) {
    int i, j;
    for (i = 0; i < MAX_ROWS; i++) {
        for (j = 0; j < MAX_COLS; j++) {
            printf("%c", maze[i][j]);
        }
        printf("\n");
    }
}

int findPath(char maze[MAX_ROWS][MAX_COLS], int row, int col) {
    if (row < 0 || col < 0 || row >= MAX_ROWS || col >= MAX_COLS) {
        return 0; // out of bounds
    } else if (maze[row][col] == 'X' || maze[row][col] == '.') {
        return 0; // obstacle or already visited
    } else if (maze[row][col] == 'G') {
        maze[row][col] = '*';
        return 1; // found exit
    } else {
        maze[row][col] = '.'; // mark as visited
        if (findPath(maze, row + 1, col) || findPath(maze, row - 1, col) ||
                findPath(maze, row, col + 1) || findPath(maze, row, col - 1)) {
            maze[row][col] = '*'; // mark as part of solution
            return 1;
        }
        return 0;
    }
}

int main() {
    int i;
    char maze[MAX_ROWS][MAX_COLS] = {
            {'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X'},
            {'X', ' ', ' ', ' ', 'X', ' ', ' ', ' ', ' ', 'X'},
            {'X', ' ', 'X', ' ', 'X', ' ', 'X', 'X', ' ', 'X'},
            {'X', ' ', 'X', ' ', 'X', ' ', 'X', ' ', ' ', 'X'},
            {'X', ' ', 'X', ' ', ' ', ' ', 'X', 'X', 'X', 'X'},
            {'X', ' ', 'X', 'X', 'X', 'X', 'X', ' ', ' ', 'X'},
            {'X', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'X'},
            {'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', ' ', 'X'},
            {'X', ' ', ' ', ' ', ' ', 'X', ' ', ' ', ' ', 'X'},
            {'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X'},
    };

    printf("Welcome to the Maze Route Finder!\n\n");
    printf("Here is the starting maze:\n");
    printMaze(maze);

    if (findPath(maze, 1, 1)) {
        printf("\nCongratulations! You found a path to the exit!\n");
    } else {
        printf("\nSorry, there is no path to the exit.\n");
    }

    printf("\nHere is the final maze:\n");
    printMaze(maze);

    printf("\nGoodbye!\n");
    return 0;
}