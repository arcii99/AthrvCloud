//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 25
#define HEIGHT 25

#define WALL 0
#define PATH 1

void print(int maze[WIDTH][HEIGHT]) {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (maze[i][j] == WALL) {
                printf("#");
            } else if (maze[i][j] == PATH) {
                printf(".");
            }
        }
        printf("\n");
    }
}

int main() {
    int maze[WIDTH][HEIGHT];

    // initialize the maze with walls
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            maze[i][j] = WALL;
        }
    }

    // seed random number generator
    srand(time(NULL));

    // set starting position to a path
    int x = rand() % WIDTH;
    int y = rand() % HEIGHT;
    maze[y][x] = PATH;

    // generate the maze
    while (1) {
        printf("\033[2J"); // clear the screen
        print(maze);

        // check if we are at a dead end
        int count = 0;
        if (x > 0 && maze[y][x-1] == WALL) {
            count++;
        }
        if (x < WIDTH-1 && maze[y][x+1] == WALL) {
            count++;
        }
        if (y > 0 && maze[y-1][x] == WALL) {
            count++;
        }
        if (y < HEIGHT-1 && maze[y+1][x] == WALL) {
            count++;
        }
        if (count == 0) {
            break;
        }

        // choose a random direction
        int dir;
        do {
            dir = rand() % 4;
        } while ((dir == 0 && x == 0) || (dir == 1 && x == WIDTH-1) ||
                 (dir == 2 && y == 0) || (dir == 3 && y == HEIGHT-1));

        // move in the chosen direction
        if (dir == 0) {
            x--;
        } else if (dir == 1) {
            x++;
        } else if (dir == 2) {
            y--;
        } else {
            y++;
        }

        // mark the new position as a path
        maze[y][x] = PATH;

        // add walls to the left and right of the path
        if (dir == 0) {
            maze[y][x+1] = WALL;
        } else if (dir == 1) {
            maze[y][x-1] = WALL;
        } else if (dir == 2) {
            maze[y+1][x] = WALL;
        } else {
            maze[y-1][x] = WALL;
        }
    }

    printf("\033[2J"); // clear the screen
    print(maze);

    return 0;
}