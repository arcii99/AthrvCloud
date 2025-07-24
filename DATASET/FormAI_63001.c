//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 30
#define HEIGHT 15

char maze[HEIGHT][WIDTH];

void generateMaze(int y, int x) {
    maze[y][x] = ' ';

    int dirs[4] = {0, 1, 2, 3};
    int tmp, swap;
    for (int i = 0; i < 4; i++) {
        int r = rand() % 4;
        tmp = dirs[r];
        dirs[r] = dirs[i];
        dirs[i] = tmp;
    }

    for (int i = 0; i < 4; i++) {
        int dx = 0, dy = 0;
        if (dirs[i] == 0) dy = -1;
        if (dirs[i] == 1) dy = 1;
        if (dirs[i] == 2) dx = -1;
        if (dirs[i] == 3) dx = 1;

        int newX = x + (dx*2);
        int newY = y + (dy*2);

        if (newY > 0 && newY < HEIGHT && newX > 0 && newX < WIDTH && maze[newY][newX] == '#') {
            maze[y+dy][x+dx] = ' ';
            generateMaze(newY, newX);
        }
    }
}

void printMaze() {
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            printf("%c", maze[y][x]);
        }
        printf("\n");
    }
}

int main() {
    srand(time(0));

    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            if (x == 0 || y == 0 || x == WIDTH-1 || y == HEIGHT-1) {
                maze[y][x] = '#';
            } else {
                maze[y][x] = '#';
            }
        }
    }

    generateMaze(2, 2);
    printMaze();

    return 0;
}