//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 20
#define HEIGHT 20

enum Direction {
    NORTH = 0,
    EAST,
    SOUTH,
    WEST,
    NUM_DIRECTIONS
};

struct Cell {
    unsigned int visited: 1;
    unsigned int walls: NUM_DIRECTIONS;
};

struct Maze {
    struct Cell cells[WIDTH * HEIGHT];
};

void initializeMaze(struct Maze* maze) {
    for (int i = 0; i < WIDTH * HEIGHT; ++i) {
        maze->cells[i].visited = 0;
        maze->cells[i].walls = (1 << NUM_DIRECTIONS) - 1;
    }
}

int main() {
    srand(time(NULL));

    struct Maze maze;
    initializeMaze(&maze);

    return 0;
}