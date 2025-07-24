//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: surprised
#include <stdio.h>

// define constants
#define WIDTH 10
#define HEIGHT 10

// define struct for pixel
typedef struct Pixel {
    int r;
    int g;
    int b;
} Pixel;

// function to print pixel art
void printArt(Pixel art[WIDTH][HEIGHT]) {
    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            if (art[i][j].r == 0 && art[i][j].g == 0 && art[i][j].b == 0) {
                printf(" ");
            } else {
                printf("#");
            }
        }
        printf("\n");
    }
}

int main() {
    // define pixel art as 2D array
    Pixel art[WIDTH][HEIGHT];

    // initialize all pixels to black
    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            art[i][j].r = 0;
            art[i][j].g = 0;
            art[i][j].b = 0;
        }
    }

    // set some pixels to white to create a simple pattern
    art[2][3].r = 255;
    art[2][3].g = 255;
    art[2][3].b = 255;
    art[3][2].r = 255;
    art[3][2].g = 255;
    art[3][2].b = 255;
    art[4][2].r = 255;
    art[4][2].g = 255;
    art[4][2].b = 255;
    art[4][3].r = 255;
    art[4][3].g = 255;
    art[4][3].b = 255;
    art[4][4].r = 255;
    art[4][4].g = 255;
    art[4][4].b = 255;
    art[3][4].r = 255;
    art[3][4].g = 255;
    art[3][4].b = 255;
    art[2][4].r = 255;
    art[2][4].g = 255;
    art[2][4].b = 255;

    // print pixel art
    printArt(art);

    return 0;
}