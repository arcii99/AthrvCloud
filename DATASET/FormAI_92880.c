//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 25
#define HEIGHT 15

struct cell {
    int visited;
    int wall[4];
};

struct maze {
    struct cell grid[HEIGHT][WIDTH];
};

void init_maze(struct maze *m) {
    int i, j;

    // Set all cells to unvisited
    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            m->grid[i][j].visited = 0;
        }
    }

    // Add outer walls
    for (i = 0; i < HEIGHT; i++) {
        m->grid[i][0].wall[3] = 1;
        m->grid[i][WIDTH - 1].wall[1] = 1;
    }
    for (j = 0; j < WIDTH; j++) {
        m->grid[0][j].wall[0] = 1;
        m->grid[HEIGHT - 1][j].wall[2] = 1;
    }

    // Add inner walls
    srand(time(NULL));
    for (i = 1; i < HEIGHT - 1; i++) {
        for (j = 1; j < WIDTH - 1; j++) {
            m->grid[i][j].wall[0] = 1;
            m->grid[i][j].wall[1] = rand() % 2;
            m->grid[i][j].wall[2] = 1;
            m->grid[i][j].wall[3] = rand() % 2;
        }
    }
}

void print_maze(struct maze *m) {
    int i, j;

    printf("+");
    for (j = 0; j < WIDTH - 1; j++) {
        printf("--+");
    }
    printf("\n");

    for (i = 0; i < HEIGHT; i++) {
        printf("|");
        for (j = 0; j < WIDTH; j++) {
            if (m->grid[i][j].wall[0]) {
                printf("  |");
            } else {
                printf("   ");
            }
        }
        printf("\n");

        printf("+");
        for (j = 0; j < WIDTH; j++) {
            if (m->grid[i][j].wall[1]) {
                printf("  +");
            } else {
                printf("--+");
            }
        }
        printf("\n");
    }
}

int main() {
    struct maze m;

    init_maze(&m);
    print_maze(&m);

    return 0;
}