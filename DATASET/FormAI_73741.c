//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define WIDTH 640
#define HEIGHT 480
#define MAX_PIXEL_VALUE 255

// Read image from a file and store the pixels in a 2D array
void read_image(char* file, int image[HEIGHT][WIDTH]) {
    FILE* f = fopen(file, "rb");
    if (f == NULL) {
        printf("Error opening file %s\n", file);
        exit(1);
    }
    char buffer[54];
    fread(buffer, sizeof(char), 54, f);
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            unsigned char pixel[3];
            fread(pixel, sizeof(unsigned char), 3, f);
            int grey = 0.30*pixel[2] + 0.59*pixel[1] + 0.11*pixel[0];
            image[i][j] = grey;
        }
    }
    fclose(f);
}

// Write the image to a file
void write_image(char* file, int image[HEIGHT][WIDTH]) {
    FILE* f = fopen(file, "wb");
    if (f == NULL) {
        printf("Error opening file %s\n", file);
        exit(1);
    }
    char header[54];
    for (int i = 0; i < 54; i++) {
        header[i] = 0;
    }
    header[0] = 'B';
    header[1] = 'M';
    int file_size = 54 + WIDTH*HEIGHT*3;
    header[2] = (unsigned char)(file_size);
    header[3] = (unsigned char)(file_size >> 8);
    header[4] = (unsigned char)(file_size >> 16);
    header[5] = (unsigned char)(file_size >> 24);
    header[10] = 54;
    header[14] = 40;
    header[18] = (unsigned char)(WIDTH);
    header[19] = (unsigned char)(WIDTH >> 8);
    header[20] = (unsigned char)(WIDTH >> 16);
    header[21] = (unsigned char)(WIDTH >> 24);
    header[22] = (unsigned char)(HEIGHT);
    header[23] = (unsigned char)(HEIGHT >> 8);
    header[24] = (unsigned char)(HEIGHT >> 16);
    header[25] = (unsigned char)(HEIGHT >> 24);
    header[26] = 1;
    header[28] = 24;
    fwrite(header, sizeof(char), 54, f);
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            unsigned char pixel[3];
            pixel[0] = image[i][j];
            pixel[1] = image[i][j];
            pixel[2] = image[i][j];
            fwrite(pixel, sizeof(unsigned char), 3, f);
        }
    }
    fclose(f);
}

// Flip the image horizontally
void flip_horizontal(int image[HEIGHT][WIDTH]) {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH/2; j++) {
            int temp = image[i][j];
            image[i][j] = image[i][WIDTH - j - 1];
            image[i][WIDTH - j - 1] = temp;
        }
    }
}

// Increase the brightness by a given amount
void increase_brightness(int image[HEIGHT][WIDTH], int amount) {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            int new_value = image[i][j] + amount;
            if (new_value > MAX_PIXEL_VALUE) {
                new_value = MAX_PIXEL_VALUE;
            }
            image[i][j] = new_value;
        }
    }
}

// Increase the contrast by a given amount using the formula from
// https://en.wikipedia.org/wiki/Contrast_(vision)
void increase_contrast(int image[HEIGHT][WIDTH], float amount) {
    float factor = (259*(amount + 255)) / (255*(259 - amount));
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            int new_value = factor*(image[i][j] - 128) + 128;
            if (new_value < 0) {
                new_value = 0;
            }
            if (new_value > MAX_PIXEL_VALUE) {
                new_value = MAX_PIXEL_VALUE;
            }
            image[i][j] = new_value;
        }
    }
}

int main() {
    int image[HEIGHT][WIDTH];
    read_image("input.bmp", image);
    flip_horizontal(image);
    increase_brightness(image, 50);
    increase_contrast(image, 50);
    write_image("output.bmp", image);
    return 0;
}