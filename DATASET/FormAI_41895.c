//FormAI DATASET v1.0 Category: Fractal Generation ; Style: systematic
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>

#define WIDTH 40
#define HEIGHT 20

bool showMap[WIDTH][HEIGHT];

void init() {
    int i, j;
    for (i = 0; i < WIDTH; i++)
        for (j = 0; j < HEIGHT; j++)
            showMap[i][j] = false;
}

void draw() {
    int i, j;
    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            if (showMap[j][i])
                printf("*");
            else if (j == (WIDTH - 1))
                printf("|");
            else if (i == (HEIGHT - 1))
                printf("--");
            else
                printf(" ");
        }
        printf("\n");
    }
}

void render() {
    int x = WIDTH / 2;
    int y = HEIGHT - 2;
    showMap[x][y] = true;

    int step = 12;
    int angle = 60;
    int times = 5;

    while(times--) {
        grow(x, y, angle, step);
        angle += 60;
        grow(x, y, angle, step);
        angle -= 120;
        grow(x, y, angle, step);
        angle += 60;
    }
}

void grow(int x, int y, int angle, int step) {
    int i;
    for (i = 1; i <= step; i++) {
        int nx = x + cos(angle * M_PI / 180.0) * i;
        int ny = y - sin(angle * M_PI / 180.0) * i;

        if (nx < 0 || nx >= WIDTH || ny < 0 || ny >= HEIGHT)
            continue;

        showMap[nx][ny] = true;
    }
}

int main() {
    init();
    render();
    draw();
    return 0;
}