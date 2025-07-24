//FormAI DATASET v1.0 Category: Image Editor ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>

#define WIDTH 256
#define HEIGHT 256

typedef struct Pixel {
    unsigned char r, g, b;
} Pixel;

Pixel image[WIDTH][HEIGHT];

void read_image(const char* filename) {
    FILE* file = fopen(filename, "rb");
    fread(image, sizeof(Pixel), WIDTH * HEIGHT, file);
    fclose(file);
}

void write_image(const char* filename) {
    FILE* file = fopen(filename, "wb");
    fwrite(image, sizeof(Pixel), WIDTH * HEIGHT, file);
    fclose(file);
}

void grayscale() {
    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            unsigned char gray = (image[i][j].r + image[i][j].g + image[i][j].b) / 3;
            image[i][j].r = gray;
            image[i][j].g = gray;
            image[i][j].b = gray;
        }
    }
}

void sepia() {
    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            unsigned char gray = (image[i][j].r + image[i][j].g + image[i][j].b) / 3;
            image[i][j].r = gray + 40;
            image[i][j].g = gray + 20;
            image[i][j].b = gray;
        }
    }
}

void invert() {
    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            image[i][j].r = 255 - image[i][j].r;
            image[i][j].g = 255 - image[i][j].g;
            image[i][j].b = 255 - image[i][j].b;
        }
    }
}

int main() {
    read_image("input.bin");
    grayscale();
    invert();
    sepia();
    write_image("output.bin");
    return 0;
}