//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: irregular
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAZE_SIZE 20

void generateMaze(int maze[][MAZE_SIZE], int x, int y) {
    // Check boundaries
    if (x < 0 || y < 0 || x > MAZE_SIZE-1 || y > MAZE_SIZE-1) return;
    if (maze[x][y] != 0) return;

    // Mark current cell as visited
    maze[x][y] = 1;

    // Generate random direction to move
    int direction = rand() % 4;

    // Move up
    if (direction == 0) {
        if (y > 0 && maze[x][y-1] == 0) {
            maze[x][y-1] = 1;
            maze[x][y] |= 1<<0;
            generateMaze(maze, x, y-1);
        }
    }
    // Move down
    else if (direction == 1) {
        if (y < MAZE_SIZE-1 && maze[x][y+1] == 0) {
            maze[x][y+1] = 1;
            maze[x][y] |= 1<<1;
            generateMaze(maze, x, y+1);
        }
    }
    // Move left
    else if (direction == 2) {
        if (x > 0 && maze[x-1][y] == 0) {
            maze[x-1][y] = 1;
            maze[x][y] |= 1<<2;
            generateMaze(maze, x-1, y);
        }
    }
    // Move right
    else if (direction == 3) {
        if (x < MAZE_SIZE-1 && maze[x+1][y] == 0) {
            maze[x+1][y] = 1;
            maze[x][y] |= 1<<3;
            generateMaze(maze, x+1, y);
        }
    }
}

void printMaze(int maze[][MAZE_SIZE]) {
    for (int i = 0; i < MAZE_SIZE; i++) {
        // Draw top boundary
        printf("+");
        for (int j = 0; j < MAZE_SIZE; j++) {
            if ((maze[j][i] & 1<<0) == 0) printf("-");
            else printf(" ");
            printf("+");
        }
        printf("\n");

        // Draw left boundary and right boundary
        printf("|");
        for (int j = 0; j < MAZE_SIZE; j++) {
            if ((maze[j][i] & 1<<2) == 0) printf("|");
            else printf(" ");
            printf(" ");
            if ((maze[j][i] & 1<<3) == 0) printf("|");
            else printf(" ");
        }
        printf("\n");
    }

    // Draw bottom boundary
    printf("+");
    for (int j = 0; j < MAZE_SIZE; j++) {
        printf("-");
        printf("+");
    }
    printf("\n");
}

int main() {
    // Initialize maze to all zeros
    int maze[MAZE_SIZE][MAZE_SIZE] = {0};

    // Choose random starting point
    srand(time(NULL));
    int startX = rand() % MAZE_SIZE;
    int startY = rand() % MAZE_SIZE;

    // Generate maze
    generateMaze(maze, startX, startY);

    // Print maze
    printMaze(maze);

    return 0;
}