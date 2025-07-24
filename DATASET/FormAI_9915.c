//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 30
#define COLS 30

int maze[ROWS][COLS];

void initialize_maze() {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            if (i == 0 || j == 0 || i == ROWS - 1 || j == COLS - 1)
                maze[i][j] = 1;
            else
                maze[i][j] = 0;
        }
    }
}

void print_maze() {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            if (maze[i][j] == 1)
                printf("# ");
            else
                printf(". ");
        }
        printf("\n");
    }
}

void generate_maze(int x, int y) {
    int direction;
    int dx, dy;

    int dirs[4][2] = {
        { 0, 1 },
        { 1, 0 },
        { 0, -1 },
        { -1, 0 }
    };

    maze[x][y] = 1;
    while (1) {
        direction = rand() % 4;
        dx = x + dirs[direction][0];
        dy = y + dirs[direction][1];

        if (maze[dx][dy] == 0) {
            maze[dx][dy] = 1;
            maze[(x + dx) / 2][(y + dy) / 2] = 1;
            generate_maze(dx, dy);
        }

        if (maze[1][1] == 1 && maze[ROWS - 2][COLS - 2] == 1)
            break;
    }
}

int main() {
    srand(time(NULL));
    initialize_maze();
    generate_maze(1, 1);
    print_maze();

    return 0;
}