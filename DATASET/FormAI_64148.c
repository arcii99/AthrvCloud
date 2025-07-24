//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAZE_SIZE 10

int main() {

    // Seed random number generator
    srand(time(NULL));

    // Initialize maze with walls
    int maze[MAZE_SIZE][MAZE_SIZE];
    for (int i = 0; i < MAZE_SIZE; i++) {
        for (int j = 0; j < MAZE_SIZE; j++) {
            maze[i][j] = 1;
        }
    }

    // Set starting cell
    int x = rand() % MAZE_SIZE;
    int y = rand() % MAZE_SIZE;
    maze[x][y] = 0;

    // Recursive backtracking algorithm
    int stack[MAZE_SIZE * MAZE_SIZE * 2];
    int top = 1;
    stack[0] = x;
    stack[1] = y;
    while (top > 0) {
        // Get current cell
        x = stack[top - 2];
        y = stack[top - 1];

        // Check adjacent cells
        int neighbors[4][2] = {{x - 1, y}, {x + 1, y}, {x, y - 1}, {x, y + 1}};
        int unvisited[4] = {0, 0, 0, 0};
        int count = 0;
        for (int i = 0; i < 4; i++) {
            int nx = neighbors[i][0];
            int ny = neighbors[i][1];
            if (nx >= 0 && nx < MAZE_SIZE && ny >= 0 && ny < MAZE_SIZE) {
                if (maze[nx][ny] == 1) {
                    unvisited[i] = 1;
                    count++;
                }
            }
        }

        // If there are unvisited cells, choose one randomly and remove the wall
        if (count > 0) {
            int r = rand() % count;
            for (int i = 0; i < 4; i++) {
                if (unvisited[i] == 1) {
                    if (r == 0) {
                        int nx = neighbors[i][0];
                        int ny = neighbors[i][1];
                        if (nx != x) {
                            maze[(x + nx) / 2][y] = 0;
                        } else {
                            maze[x][(y + ny) / 2] = 0;
                        }
                        maze[nx][ny] = 0;
                        stack[top++] = nx;
                        stack[top++] = ny;
                        break;
                    }
                    r--;
                }
            }
        } else {
            top -= 2;
        }
    }

    // Print maze
    printf("+");
    for (int i = 0; i < MAZE_SIZE; i++) {
        printf("--+");
    }
    printf("\n");
    for (int i = 0; i < MAZE_SIZE; i++) {
        printf("|");
        for (int j = 0; j < MAZE_SIZE; j++) {
            if (maze[i][j] == 1) {
                printf("##");
            } else {
                printf("  ");
            }
            printf("|");
        }
        printf("\n+");
        for (int j = 0; j < MAZE_SIZE; j++) {
            printf("--+");
        }
        printf("\n");
    }

    return 0;
}