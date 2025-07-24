//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 41
#define HEIGHT 21

#define WALL 0
#define PATH 1

void generate_maze(int maze[WIDTH][HEIGHT], int x, int y) {
    srand(time(0));
    maze[x][y] = PATH;

    char dir[4] = "NESW";
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};

    for (int i = 0; i < 4; i++) {
        int r = rand() % 4;
        char temp = dir[i];
        dir[i] = dir[r];
        dir[r] = temp;
    }

    for (int i = 0; i < 4; i++) {
        char d = dir[i];
        int nx = x + dx[d - 'N'];
        int ny = y + dy[d - 'N'];

        if (nx >= 1 && ny >= 1 && nx < WIDTH - 1 && ny < HEIGHT - 1 && maze[nx][ny] == WALL) {
            maze[nx][ny] = PATH;
            int mx = (x + nx) / 2;
            int my = (y + ny) / 2;
            maze[mx][my] = PATH;
            generate_maze(maze, nx, ny);
        }
    }
}

int main() {
    int maze[WIDTH][HEIGHT];

    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            maze[i][j] = WALL;
        }
    }

    generate_maze(maze, 1, 1);

    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            if (maze[i][j] == WALL) {
                printf("X");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }

    return 0;
}