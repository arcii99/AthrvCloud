//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAZE_HEIGHT 5
#define MAZE_WIDTH 5

void printMaze(char maze[][MAZE_WIDTH]) {
    for (int i = 0; i < MAZE_HEIGHT; i++) {
        for (int j = 0; j < MAZE_WIDTH; j++) {
            printf("%c ", maze[i][j]);
        }
        printf("\n");
    }
}

bool isValidMove(char maze[][MAZE_WIDTH], int row, int col) {
    if (row >= 0 && row < MAZE_HEIGHT && col >= 0 && col < MAZE_WIDTH) {
        return (maze[row][col] == '.');
    }
    return false;
}

bool findRoute(char maze[][MAZE_WIDTH], int row, int col) {
    if (row == MAZE_HEIGHT - 1 && col == MAZE_WIDTH - 1) {
        maze[row][col] = '*';
        return true;
    }

    if (isValidMove(maze, row, col)) {
        maze[row][col] = '*';

        if (findRoute(maze, row + 1, col)) {
            return true;
        }
        if (findRoute(maze, row, col + 1)) {
            return true;
        }
        if (findRoute(maze, row - 1, col)) {
            return true;
        }
        if (findRoute(maze, row, col - 1)) {
            return true;
        }

        maze[row][col] = '.';
    }

    return false;
}

int main() {
    char maze[MAZE_HEIGHT][MAZE_WIDTH] = {
        {'*', '*', '*', '*', '*'},
        {'.', '.', '.', '.', '*'},
        {'*', '.', '*', '.', '*'},
        {'*', '.', '*', '.', '*'},
        {'*', '.', '.', '.', '*'}
    };
    printf("Maze before finding route:\n");
    printMaze(maze);
    printf("-----------------------\n");

    if (findRoute(maze, 0, 0)) {
        printf("Maze after finding route:\n");
        printMaze(maze);
    } else {
        printf("Route not found.");
    }

    return 0;
}