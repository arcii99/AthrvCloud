//FormAI DATASET v1.0 Category: Image Editor ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>

#define WIDTH 256
#define HEIGHT 256

typedef unsigned char byte;

byte image[WIDTH][HEIGHT][3];

void paint(byte color[3]) {
    int x, y;

    for(x = 0; x < WIDTH; x++) {
        for(y = 0; y < HEIGHT; y++) {
            image[x][y][0] = color[0];
            image[x][y][1] = color[1];
            image[x][y][2] = color[2];
        }
    }
}

void print() {
    int x, y;

    for(y = 0; y < HEIGHT; y++) {
        for(x = 0; x < WIDTH; x++) {
            printf("\033[38;2;%d;%d;%dm█", image[x][y][0], image[x][y][1], image[x][y][2]);
        }
        printf("\n");
    }
}

int main() {
    byte black[3] = {0, 0, 0};
    byte green[3] = {0, 255, 0};
    byte purple[3] = {255, 0, 255};

    system("clear");

    paint(black);
    print();

    getchar();

    paint(green);
    print();

    getchar();

    paint(purple);
    print();

    return 0;
}