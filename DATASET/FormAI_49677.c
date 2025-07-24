//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 20
#define HEIGHT 20
#define COLOR "x"
#define BG_COLOR "."

void generate_pixel_art(char pixels[][WIDTH]);

int main(void) {
    char pixels[HEIGHT][WIDTH];
    generate_pixel_art(pixels);

    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            printf("%s", pixels[i][j] == 1 ? COLOR : BG_COLOR);
        }
        printf("\n");
    }

    return 0;
}

void generate_pixel_art(char pixels[][WIDTH]) {
    srand(time(NULL));
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            pixels[i][j] = rand() % 2;
        }
    }
}