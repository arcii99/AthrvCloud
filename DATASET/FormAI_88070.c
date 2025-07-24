//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAZE_SIZE 20

int main(void)
{
    // seed random number generator
    srand(time(NULL));

    // initialize maze to all walls
    int maze[MAZE_SIZE][MAZE_SIZE];
    for (int i = 0; i < MAZE_SIZE; i++) {
        for (int j = 0; j < MAZE_SIZE; j++) {
            maze[i][j] = 1;
        }
    }

    // randomly select starting position
    int x = rand() % MAZE_SIZE;
    int y = rand() % MAZE_SIZE;

    maze[x][y] = 0; // carve initial path

    while (1) {
        // randomly select neighboring cell
        int dx = 0, dy = 0;
        do {
            int dir = rand() % 4;
            switch (dir) {
                case 0: dx = 1; break; // right
                case 1: dy = 1; break; // down
                case 2: dx = -1; break; // left
                case 3: dy = -1; break; // up
            }
        } while (x + dx < 0 || x + dx >= MAZE_SIZE || y + dy < 0 || y + dy >= MAZE_SIZE);

        // check if neighboring cell is unvisited
        if (maze[x + dx][y + dy]) {
            maze[x + dx / 2][y + dy / 2] = 0; // carve path to neighboring cell
            x += dx;
            y += dy;
        }

        // check if maze is complete
        int is_complete = 1;
        for (int i = 0; i < MAZE_SIZE; i++) {
            for (int j = 0; j < MAZE_SIZE; j++) {
                if (maze[i][j]) {
                    is_complete = 0;
                    break;
                }
            }
            if (!is_complete) {
                break;
            }
        }
        if (is_complete) {
            break;
        }
    }

    // print maze
    for (int i = 0; i < MAZE_SIZE; i++) {
        for (int j = 0; j < MAZE_SIZE; j++) {
            printf("%c ", maze[i][j] ? '#' : '.');
        }
        printf("\n");
    }

    return 0;
}