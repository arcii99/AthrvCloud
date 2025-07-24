//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define WIDTH 512
#define HEIGHT 512

// struct for grayscale image buffer
typedef struct {
    unsigned char buf[WIDTH*HEIGHT];
} GrayImage;

// read grayscale image from disk
void read_image(char *filename, GrayImage *img) {
    FILE *fp;
    fp = fopen(filename, "rb");
    if (fp == NULL) {
        perror("Failed to open input file");
        exit(EXIT_FAILURE);
    }
    fread(img->buf, sizeof(unsigned char), WIDTH*HEIGHT, fp);
    fclose(fp);
}

// write grayscale image to disk
void write_image(char *filename, GrayImage *img) {
    FILE *fp;
    fp = fopen(filename, "wb");
    if (fp == NULL) {
        perror("Failed to open output file");
        exit(EXIT_FAILURE);
    }
    fwrite(img->buf, sizeof(unsigned char), WIDTH*HEIGHT, fp);
    fclose(fp);
}

// flip image horizontally
void flip_horizontally(GrayImage *img) {
    int x, y;
    unsigned char tmp;
    for (y = 0; y < HEIGHT; y++) {
        for (x = 0; x < (WIDTH/2); x++) {
            tmp = img->buf[y*WIDTH + x];
            img->buf[y*WIDTH + x] = img->buf[y*WIDTH + (WIDTH-x-1)];
            img->buf[y*WIDTH + (WIDTH-x-1)] = tmp;
        }
    }
}

// adjust image brightness
void adjust_brightness(GrayImage *img, int value) {
    int x, y;
    for (y = 0; y < HEIGHT; y++) {
        for (x = 0; x < WIDTH; x++) {
            int new_value = img->buf[y*WIDTH + x] + value;
            if (new_value < 0) {
                new_value = 0;
            }
            if (new_value > 255) {
                new_value = 255;
            }
            img->buf[y*WIDTH + x] = new_value;
        }
    }
}

// adjust image contrast
void adjust_contrast(GrayImage *img, int value) {
    int x, y;
    double factor = (double)(259 * (value + 255)) / (double)(255 * (259 - value));
    for (y = 0; y < HEIGHT; y++) {
        for (x = 0; x < WIDTH; x++) {
            int new_value = (int)(factor * (img->buf[y*WIDTH + x] - 128) + 128);
            if (new_value < 0) {
                new_value = 0;
            }
            if (new_value > 255) {
                new_value = 255;
            }
            img->buf[y*WIDTH + x] = new_value;
        }
    }
}

int main(void) {
    GrayImage img;
    read_image("input.img", &img);

    // flip image horizontally
    flip_horizontally(&img);

    // adjust brightness and contrast
    adjust_brightness(&img, 50);
    adjust_contrast(&img, 50);

    write_image("output.img", &img);
    return 0;
}