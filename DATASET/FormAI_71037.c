//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define WIDTH 25
#define HEIGHT 15

char maze[HEIGHT][WIDTH];
bool visited[HEIGHT][WIDTH];

int rand_dir() {
    return rand() % 4;
}

void carve(int y, int x, int dir) {
    int dx = 0;
    int dy = 0;
    if (dir == 0) dx = 1;
    else if (dir == 1) dy = 1;
    else if (dir == 2) dx = -1;
    else dy = -1;

    int nx = x + dx;
    int ny = y + dy;

    if (nx < 0 || ny < 0 || nx >= WIDTH || ny >= HEIGHT) return;
    if (maze[ny][nx] == ' ') return;

    maze[y + dy/2][x + dx/2] = ' ';
    maze[ny][nx] = ' ';

    visited[ny][nx] = true;

    int next_dir;
    do {
        next_dir = rand_dir();
    } while (dir == next_dir);
    carve(ny, nx, next_dir);
}

int main() {
    srand(time(NULL));
    int start_x, start_y, end_x, end_y;
    start_x = rand() % WIDTH;
    start_y = rand() % HEIGHT;
    end_x = rand() % WIDTH;
    end_y = rand() % HEIGHT;

    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            maze[i][j] = '#';
            visited[i][j] = false;
        }
    }
    maze[start_y][start_x] = ' ';
    maze[end_y][end_x] = ' ';

    visited[start_y][start_x] = true;
    visited[end_y][end_x] = true;

    int dir = rand_dir();
    carve(start_y, start_x, dir);

    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (maze[i][j] == '#') {
                printf("[] ");
            } else if (i == start_y && j == start_x) {
                printf("S  ");
            } else if (i == end_y && j == end_x) {
                printf("E  ");
            } else {
                printf("   ");
            }
        }
        printf("\n");
    }

    return 0;
}