//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 50
#define HEIGHT 50

/* Define the pixel datatype */
typedef struct Pixel {
    char c;
    int color;
} Pixel;

/* Function to generate a random color for each pixel */
int randomColor() {
    return rand() % 6 + 1;
}

int main() {
    /* Initialize random seed */
    srand(time(NULL));

    /* Initialize pixel array */
    Pixel pixels[WIDTH][HEIGHT];

    /* Generate random pixel values */
    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            pixels[i][j].c = rand() % 2 == 0 ? '#' : ' ';
            pixels[i][j].color = randomColor();
        }
    }

    /* Output the pixel art */
    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            printf("\033[3%dm%c\033[0m", pixels[i][j].color, pixels[i][j].c);
        }
        printf("\n");
    }

    return 0;
}