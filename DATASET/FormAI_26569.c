//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 256
#define HEIGHT 256
#define MAX_COLOR 255

typedef struct {
    int r;
    int g;
    int b;
} Pixel;

// Function to generate a random pixel
Pixel random_pixel() {
    Pixel p;
    p.r = rand() % (MAX_COLOR + 1);
    p.g = rand() % (MAX_COLOR + 1);
    p.b = rand() % (MAX_COLOR + 1);
    return p;
}

// Function to generate a pixel art image
void pixel_art_generator(Pixel image[WIDTH][HEIGHT]) {
    srand(time(NULL));
    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            image[i][j] = random_pixel();
        }
    }
}

// Function to print a pixel art image
void print_image(Pixel image[WIDTH][HEIGHT]) {
    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            printf("(%d,%d,%d) ", image[i][j].r, image[i][j].g, image[i][j].b);
        }
        printf("\n");
    }
}

int main() {
    Pixel image[WIDTH][HEIGHT];
    pixel_art_generator(image);
    print_image(image);
    return 0;
}