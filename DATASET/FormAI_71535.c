//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAZE_SIZE 10

// function to generate random integer within a range
int rand_int(int min, int max) {
    return (rand() % (max + 1 - min)) + min;
}

int main() {
    srand(time(0)); // seed for random number generation
    int maze[MAZE_SIZE][MAZE_SIZE];

    // initialize maze with all walls
    for (int i = 0; i < MAZE_SIZE; i++) {
        for (int j = 0; j < MAZE_SIZE; j++) {
            maze[i][j] = 1;
        }
    }

    // generate random starting point
    int x = rand_int(1, MAZE_SIZE-2);
    int y = rand_int(1, MAZE_SIZE-2);
    maze[x][y] = 0; // set starting point as open

    // random walk to generate maze
    while (1) {
        int dir = rand_int(0, 3); // 0=up, 1=right, 2=down, 3=left
        switch (dir) {
            case 0: // up
                if (x-2 < 0) continue; // check if out of bounds
                if (maze[x-2][y] == 1) { // check if unexplored
                    maze[x-1][y] = 0;
                    maze[x-2][y] = 0;
                    x -= 2;
                }
                break;
            case 1: // right
                if (y+2 >= MAZE_SIZE) continue;
                if (maze[x][y+2] == 1) {
                    maze[x][y+1] = 0;
                    maze[x][y+2] = 0;
                    y += 2;
                }
                break;
            case 2: // down
                if (x+2 >= MAZE_SIZE) continue;
                if (maze[x+2][y] == 1) {
                    maze[x+1][y] = 0;
                    maze[x+2][y] = 0;
                    x += 2;
                }
                break;
            case 3: // left
                if (y-2 < 0) continue;
                if (maze[x][y-2] == 1) {
                    maze[x][y-1] = 0;
                    maze[x][y-2] = 0;
                    y -= 2;
                }
                break;
        }
        int done = 1;
        for (int i = 0; i < MAZE_SIZE; i++) {
            for (int j = 0; j < MAZE_SIZE; j++) {
                if (maze[i][j] == 1) done = 0; // check if all walls are explored
            }
        }
        if (done) break;
    }

    // print maze
    for (int i = 0; i < MAZE_SIZE; i++) {
        for (int j = 0; j < MAZE_SIZE; j++) {
            if (maze[i][j] == 1) printf("#"); // print walls
            else printf(" "); // print open space
        }
        printf("\n");
    }

    return 0;
}