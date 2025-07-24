//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 15
#define HEIGHT 10

void generateMaze(int maze[HEIGHT][WIDTH]);
void printMaze(int maze[HEIGHT][WIDTH]);

int main() {
    int maze[HEIGHT][WIDTH];

    generateMaze(maze);
    printMaze(maze);

    return 0;
}

void generateMaze(int maze[HEIGHT][WIDTH]) {
    srand(time(NULL));

    // initialize everything to walls
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            maze[y][x] = 1;
        }
    }

    // pick a random starting point
    int x = rand() % (WIDTH-2) + 1;
    int y = rand() % (HEIGHT-2) + 1;
    maze[y][x] = 0;

    // create path by randomly opening up walls
    while (1) {
        int direction = rand() % 4;

        if (direction == 0 && x > 1 && maze[y][x-2] != 0) { // left
            maze[y][x-1] = 0;
            maze[y][x-2] = 0;
            x -= 2;
        } else if (direction == 1 && x < WIDTH-2 && maze[y][x+2] != 0) { // right
            maze[y][x+1] = 0;
            maze[y][x+2] = 0;
            x += 2;
        } else if (direction == 2 && y > 1 && maze[y-2][x] != 0) { // up
            maze[y-1][x] = 0;
            maze[y-2][x] = 0;
            y -= 2;
        } else if (direction == 3 && y < HEIGHT-2 && maze[y+2][x] != 0) { // down
            maze[y+1][x] = 0;
            maze[y+2][x] = 0;
            y += 2;
        }

        if (maze[y][x-2] != 0 && maze[y][x+2] != 0 && maze[y-2][x] != 0 && maze[y+2][x] != 0) {
            break;
        }
    }

    // randomly add some gaps in walls
    for (int y = 1; y < HEIGHT-1; y++) {
        for (int x = 1; x < WIDTH-1; x++) {
            if (maze[y][x] == 1 && rand() % 5 == 0) {
                maze[y][x] = 0;
            }
        }
    }

    // add start and end points
    maze[rand()%(HEIGHT-2) + 1][0] = 2;
    maze[rand()%(HEIGHT-2) + 1][WIDTH-1] = 3;
}

void printMaze(int maze[HEIGHT][WIDTH]) {
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            if (maze[y][x] == 0) {
                printf(" ");
            } else if (maze[y][x] == 1) {
                printf("#");
            } else if (maze[y][x] == 2) {
                printf("S");
            } else if (maze[y][x] == 3) {
                printf("E");
            }
        }
        printf("\n");
    }
}