//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAZE_SIZE 20

int maze[MAZE_SIZE][MAZE_SIZE];

void generateMaze(int x, int y) {
    maze[x][y] = 0;
    int directions[] = {-1, 0, 1, 0, -1};
    int temp, dir;
    // Shuffle the directions array
    for (int i = 0; i < 4; i++) {
        dir = rand() % 4;
        temp = directions[dir];
        directions[dir] = directions[i];
        directions[i] = temp;
    }
    // Recursive backtracking algorithm to generate the maze
    for (int i = 0; i < 4; i++) {
        int dx = directions[i], dy = directions[i+1];
        if (x + dx >= 0 && x + dx < MAZE_SIZE && y + dy >= 0 && y + dy < MAZE_SIZE && maze[x+dx][y+dy]) {
            maze[x+dx][y+dy] = 0;
            generateMaze(x+dx, y+dy);
        }
    }
}

void printMaze() {
    for (int i = 0; i < MAZE_SIZE; i++) {
        for (int j = 0; j < MAZE_SIZE; j++) {
            if (maze[i][j]) {
                printf("██");
            }
            else {
                printf("  ");
            }
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));
    // Initialize the maze with all walls
    for (int i = 0; i < MAZE_SIZE; i++) {
        for (int j = 0; j < MAZE_SIZE; j++) {
            maze[i][j] = 1;
        }
    }
    // Generate the maze starting from the middle
    generateMaze(MAZE_SIZE/2, MAZE_SIZE/2);
    // Print the maze
    printMaze();
    return 0;
}