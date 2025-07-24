//FormAI DATASET v1.0 Category: Image Editor ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WIDTH 256
#define HEIGHT 256

typedef struct {
    unsigned char r;
    unsigned char g;
    unsigned char b;
} Color;

void write_image(int width, int height, Color *image) {
    FILE *fp = fopen("output.ppm", "wb");
    fprintf(fp, "P6\n%d %d\n255\n", width, height);
    fwrite(image, sizeof(Color), width * height, fp);
    fclose(fp);
}

void grayscale(Color *image) {
    for (int i = 0; i < WIDTH * HEIGHT; i++) {
        unsigned char gray = (image[i].r + image[i].g + image[i].b) / 3;
        image[i].r = image[i].g = image[i].b = gray;
    }
}

void invert(Color *image) {
    for (int i = 0; i < WIDTH * HEIGHT; i++) {
        image[i].r = 255 - image[i].r;
        image[i].g = 255 - image[i].g;
        image[i].b = 255 - image[i].b;
    }
}

void blur(Color *image) {
    Color *new = malloc(WIDTH * HEIGHT * sizeof(Color));
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            unsigned int count = 0;
            int r = 0, g = 0, b = 0;
            for (int dy = -1; dy <= 1; dy++) {
                for (int dx = -1; dx <= 1; dx++) {
                    int nx = x + dx;
                    int ny = y + dy;
                    if (nx >= 0 && nx < WIDTH && ny >= 0 && ny < HEIGHT) {
                        count++;
                        r += image[ny * WIDTH + nx].r;
                        g += image[ny * WIDTH + nx].g;
                        b += image[ny * WIDTH + nx].b;
                    }
                }
            }
            new[y * WIDTH + x].r = r / count;
            new[y * WIDTH + x].g = g / count;
            new[y * WIDTH + x].b = b / count;
        }
    }
    memcpy(image, new, WIDTH * HEIGHT * sizeof(Color));
    free(new);
}

int main() {
    Color image[WIDTH * HEIGHT];
    for (int i = 0; i < WIDTH * HEIGHT; i++) {
        image[i].r = rand() % 256;
        image[i].g = rand() % 256;
        image[i].b = rand() % 256;
    }
    write_image(WIDTH, HEIGHT, image);
    grayscale(image);
    write_image(WIDTH, HEIGHT, image);
    invert(image);
    write_image(WIDTH, HEIGHT, image);
    blur(image);
    write_image(WIDTH, HEIGHT, image);
    return 0;
}