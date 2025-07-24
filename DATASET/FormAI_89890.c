//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAZE_WIDTH 30
#define MAZE_HEIGHT 20

int maze[MAZE_HEIGHT][MAZE_WIDTH];

int main() {
    // Initialize the maze with all walls and borders
    for (int i = 0; i < MAZE_HEIGHT; ++i) {
        for (int j = 0; j < MAZE_WIDTH; ++j) {
            if (i == 0 || j == 0 || i == MAZE_HEIGHT - 1 || j == MAZE_WIDTH - 1) {
                maze[i][j] = 1;
            } else {
                maze[i][j] = (i % 2 == 0 && j % 2 == 0) ? 0 : 1;
            }
        }
    }

    // Randomized depth-first search to generate maze
    srand(time(NULL));
    int stack[MAZE_WIDTH * MAZE_HEIGHT][2], top = 0;
    int curr[2] = {1, 1};
    while (1) {
        maze[curr[0]][curr[1]] = 0;
        int neighbors[4][2] = {{curr[0] - 2, curr[1]}, {curr[0], curr[1] - 2},
                               {curr[0] + 2, curr[1]}, {curr[0], curr[1] + 2}};
        int unvisited = 0;
        for (int i = 0; i < 4; ++i) {
            if (maze[neighbors[i][0]][neighbors[i][1]] == 1) {
                ++unvisited;
            }
        }
        if (unvisited) {
            stack[top][0] = curr[0];
            stack[top][1] = curr[1];
            ++top;
            int index;
            do {
                index = rand() % 4;
            } while (maze[neighbors[index][0]][neighbors[index][1]] == 0);
            if (index == 0) {
                maze[curr[0] - 1][curr[1]] = 0;
                curr[0] -= 2;
            } else if (index == 1) {
                maze[curr[0]][curr[1] - 1] = 0;
                curr[1] -= 2;
            } else if (index == 2) {
                maze[curr[0] + 1][curr[1]] = 0;
                curr[0] += 2;
            } else {
                maze[curr[0]][curr[1] + 1] = 0;
                curr[1] += 2;
            }
        } else if (top) {
            --top;
            curr[0] = stack[top][0];
            curr[1] = stack[top][1];
        } else {
            break;
        }
    }

    // Output the maze as ASCII art
    for (int i = 0; i < MAZE_HEIGHT; ++i) {
        for (int j = 0; j < MAZE_WIDTH; ++j) {
            printf("%c", maze[i][j] ? '#' : ' ');
        }
        printf("\n");
    }

    return 0;
}