//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: creative
#include <stdio.h>
#include <stdlib.h>

#define WIDTH 80
#define HEIGHT 40
#define MAX_COLOR 255

struct Pixel {
    int r;
    int g;
    int b;
};

struct Image {
    struct Pixel pixels[WIDTH][HEIGHT];
};

void generatePixelArt(struct Image *image) {
    // Generate random colors for each pixel
    for (int col = 0; col < WIDTH; col++) {
        for (int row = 0; row < HEIGHT; row++) {
            image->pixels[col][row].r = rand() % (MAX_COLOR + 1);
            image->pixels[col][row].g = rand() % (MAX_COLOR + 1);
            image->pixels[col][row].b = rand() % (MAX_COLOR + 1);
        }
    }
}

void printPixelArt(struct Image *image) {
    // Print out ASCII art version of image
    for (int row = 0; row < HEIGHT; row++) {
        for (int col = 0; col < WIDTH; col++) {
            int r = image->pixels[col][row].r;
            int g = image->pixels[col][row].g;
            int b = image->pixels[col][row].b;

            // Determine most prominent color of pixel
            if (r > g && r > b) {
                printf("\033[48;2;%d;%d;%dm  ", r, g, b);
            } else if (g > r && g > b) {
                printf("\033[48;2;%d;%d;%dm  ", r, g, b);
            } else if (b > r && b > g) {
                printf("\033[48;2;%d;%d;%dm  ", r, g, b);
            } else if (r == g && r > b) {
                printf("\033[48;2;%d;%d;%dm  ", r, g, b);
            } else if (r == b && r > g) {
                printf("\033[48;2;%d;%d;%dm  ", r, g, b);
            } else if (g == b && g > r) {
                printf("\033[48;2;%d;%d;%dm  ", r, g, b);
            } else {
                printf("\033[48;2;%d;%d;%dm  ", r, g, b);
            }
        }
        printf("\033[0m\n");
    }
}

int main() {
    struct Image image;
    generatePixelArt(&image);
    printPixelArt(&image);
    return 0;
}