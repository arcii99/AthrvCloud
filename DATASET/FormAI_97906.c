//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: complete
#include <stdio.h>
#include <stdlib.h>

/* Define image dimensions */
#define WIDTH 640
#define HEIGHT 480

/* Open, read, and close image file */
void read_image(char *filename, unsigned char *image) {
    FILE *file = fopen(filename, "rb");
    fread(image, WIDTH * HEIGHT, 1, file);
    fclose(file);
}

/* Write image to file */
void write_image(char *filename, unsigned char *image) {
    FILE *file = fopen(filename, "wb");
    fwrite(image, WIDTH * HEIGHT, 1, file);
    fclose(file);
}

/* Flip image vertically */
void flip_vertical(unsigned char *image) {
    unsigned char temp[WIDTH];
    for (int y = 0; y < HEIGHT / 2; y++) {
        for (int x = 0; x < WIDTH; x++) {
            temp[x] = image[y * WIDTH + x];
            image[y * WIDTH + x] = image[(HEIGHT - y - 1) * WIDTH + x];
            image[(HEIGHT - y - 1) * WIDTH + x] = temp[x];
        }
    }
}

/* Adjust image brightness */
void adjust_brightness(unsigned char *image, int brightness) {
    for (int i = 0; i < WIDTH * HEIGHT; i++) {
        int value = (int)image[i] + brightness;
        image[i] = (unsigned char)(value > 255 ? 255 : (value < 0 ? 0 : value));
    }
}

/* Adjust image contrast */
void adjust_contrast(unsigned char *image, float contrast) {
    float factor = (259.0f * (contrast + 255.0f)) / (255.0f * (259.0f - contrast));
    for (int i = 0; i < WIDTH * HEIGHT; i++) {
        int value = (int)(factor * (image[i] - 128) + 128);
        image[i] = (unsigned char)(value > 255 ? 255 : (value < 0 ? 0 : value));
    }
}

/* Main function */
int main() {
    /* Load image from file */
    unsigned char image[WIDTH * HEIGHT];
    read_image("image.raw", image);

    /* Flip image vertically */
    flip_vertical(image);

    /* Adjust image brightness */
    adjust_brightness(image, 50);

    /* Adjust image contrast */
    adjust_contrast(image, 50);

    /* Save image to file */
    write_image("output.raw", image);

    return 0;
}