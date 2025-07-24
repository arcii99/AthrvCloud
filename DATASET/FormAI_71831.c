//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define WIDTH 512
#define HEIGHT 512
#define MAX_PIXEL 255
#define MIN_PIXEL 0

unsigned char image[HEIGHT][WIDTH];
unsigned char new_image[HEIGHT][WIDTH];

void read_image(char *filename) {
    FILE *fp;
    fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Cannot open file \n");
        exit(1);
    }
    fread(image, sizeof(unsigned char), WIDTH * HEIGHT, fp);
    fclose(fp);
}

void write_image(char *filename) {
    FILE *fp;
    fp = fopen(filename, "wb");
    if (fp == NULL) {
        printf("Cannot open file \n");
        exit(1);
    }
    fwrite(new_image, sizeof(unsigned char), WIDTH * HEIGHT, fp);
    fclose(fp);
}

void flip_image(int axis) {
    int i, j;

    if (axis == 0) { // flip image horizontally
        for (i = 0; i < WIDTH; i++) {
            for (j = 0; j < HEIGHT; j++) {
                new_image[j][WIDTH - 1 - i] = image[j][i];
            }
        }
    } else if (axis == 1) { // flip image vertically
        for (i = 0; i < WIDTH; i++) {
            for (j = 0; j < HEIGHT; j++) {
                new_image[HEIGHT - 1 - j][i] = image[j][i];
            }
        }
    }
}

void change_brightness(int brightness) {
    int i, j;
    int pixel_value;

    for (i = 0; i < WIDTH; i++) {
        for (j = 0; j < HEIGHT; j++) {
            pixel_value = (int) image[j][i] + brightness;
            if (pixel_value > MAX_PIXEL) {
                pixel_value = MAX_PIXEL;
            } else if (pixel_value < MIN_PIXEL) {
                pixel_value = MIN_PIXEL;
            }
            new_image[j][i] = (unsigned char) pixel_value;
        }
    }
}

void change_contrast(double contrast) {
    int i, j;
    int pixel_value;
    double normalized_pixel_value;

    for (i = 0; i < WIDTH; i++) {
        for (j = 0; j < HEIGHT; j++) {
            normalized_pixel_value = (double) image[j][i] / MAX_PIXEL;
            normalized_pixel_value -= 0.5;
            normalized_pixel_value *= contrast;
            normalized_pixel_value += 0.5;
            pixel_value = (int) (normalized_pixel_value * MAX_PIXEL);
            if (pixel_value > MAX_PIXEL) {
                pixel_value = MAX_PIXEL;
            } else if (pixel_value < MIN_PIXEL) {
                pixel_value = MIN_PIXEL;
            }
            new_image[j][i] = (unsigned char) pixel_value;
        }
    }
}

int main() {
    read_image("image.raw");

    flip_image(0); // flip image horizontally
    write_image("image_horizontally_flipped.raw");

    flip_image(1); // flip image vertically
    write_image("image_vertically_flipped.raw");

    change_brightness(50); // increase brightness by 50
    write_image("image_brightness_adjusted.raw");

    change_contrast(1.5); // increase contrast by 1.5 times
    write_image("image_contrast_adjusted.raw");

    return 0;
}