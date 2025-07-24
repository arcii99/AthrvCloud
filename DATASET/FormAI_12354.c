//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 20
#define HEIGHT 10

void carveMaze(int x, int y, int maze[HEIGHT][WIDTH])
{
    int dx, dy, nx, ny;
    int directions[4][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
    int temp;

    for (int i = 0; i < 4; ++i) {
        temp = rand() % 4;
        dx = directions[temp][0];
        dy = directions[temp][1];

        nx = x + dx;
        ny = y + dy;

        if (nx >= 0 && ny >= 0 && nx < WIDTH && ny < HEIGHT
            && maze[ny][nx] == 1) {
            maze[y + dy / 2][x + dx / 2] = 0;
            maze[ny][nx] = 0;
            carveMaze(nx, ny, maze);
        }
    }
}

void printMaze(int maze[HEIGHT][WIDTH])
{
    for (int y = 0; y < HEIGHT; ++y) {
        for (int x = 0; x < WIDTH; ++x) {
            printf("%c", maze[y][x] == 1 ? '#' : ' ');
        }
        printf("\n");
    }
}

int main(void)
{
    int maze[HEIGHT][WIDTH] = {0};
    srand(time(NULL));

    for (int y = 0; y < HEIGHT; ++y) {
        maze[y][0] = 1;
        maze[y][WIDTH - 1] = 1;
    }

    for (int x = 0; x < WIDTH; ++x) {
        maze[0][x] = 1;
        maze[HEIGHT - 1][x] = 1;
    }

    maze[1][1] = 0;
    carveMaze(1, 1, maze);
    printMaze(maze);

    return 0;
}