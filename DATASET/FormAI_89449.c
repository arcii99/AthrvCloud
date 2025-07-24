//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAZE_SIZE 20

int maze[MAZE_SIZE][MAZE_SIZE];
int visited[MAZE_SIZE][MAZE_SIZE];

void generateMaze(int x, int y) {
    visited[x][y] = 1;

    int direction[4][2] = {
        {1, 0},
        {-1, 0},
        {0, 1},
        {0, -1}
    };

    for (int i = 0; i < 4; i++) {
        int r = rand() % 4;
        int dx = direction[r][0];
        int dy = direction[r][1];

        if ((x+dx >= 0) && (x+dx < MAZE_SIZE) && (y+dy >= 0) && (y+dy < MAZE_SIZE) && (!visited[x+dx][y+dy])) {
            maze[x+dx][y+dy] = 0;
            generateMaze(x+dx, y+dy);
        }
    }
}

void printMaze() {
    for (int i = 0; i < MAZE_SIZE; i++) {
        for (int j = 0; j < MAZE_SIZE; j++) {
            if (maze[i][j]) {
                printf("# ");
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));

    // Initialize maze with all walls
    for (int i = 0; i < MAZE_SIZE; i++) {
        for (int j = 0; j < MAZE_SIZE; j++) {
            maze[i][j] = 1;
        }
    }

    // Generate maze starting from middle point
    int startX = MAZE_SIZE/2;
    int startY = MAZE_SIZE/2;
    maze[startX][startY] = 0;
    generateMaze(startX, startY);

    // Print maze
    printMaze();

    return 0;
}