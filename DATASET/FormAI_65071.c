//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAZE_SIZE 20

char maze[MAZE_SIZE][MAZE_SIZE];

void generateMaze();
void printMaze();

int main() {
    srand(time(NULL)); // For random generation

    generateMaze();
    printMaze();

    return 0;
}

void generateMaze() {
    // Initialize maze with walls
    for (int i = 0; i < MAZE_SIZE; i++) {
        for (int j = 0; j < MAZE_SIZE; j++) {
            maze[i][j] = '#';
        }
    }

    // Set starting position
    int x = rand() % MAZE_SIZE;
    int y = 0;
    maze[x][y] = ' ';

    while (y < MAZE_SIZE - 1) {
        // Generate random direction
        int dir = rand() % 3 - 1;
        if (x + dir >= 0 && x + dir < MAZE_SIZE && maze[x + dir][y + 1] == '#') {
            x += dir;
            maze[x][++y] = ' ';
        }
    }

    // Set ending position
    maze[x][y] = 'E';
}

void printMaze() {
    for (int i = 0; i < MAZE_SIZE; i++) {
        for (int j = 0; j < MAZE_SIZE; j++) {
            printf("%c ", maze[i][j]);
        }
        printf("\n");
    }
}