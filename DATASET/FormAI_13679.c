//FormAI DATASET v1.0 Category: Image Editor ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>

#define HEIGHT 200
#define WIDTH 200

typedef struct {
    unsigned char r;
    unsigned char g;
    unsigned char b;
} pixel;

pixel img[HEIGHT][WIDTH];

void swap(pixel *a, pixel *b) {
    pixel temp = *a;
    *a = *b;
    *b = temp;
}

void grayscale(pixel img[HEIGHT][WIDTH]) {
    int x, y;
    for(y = 0; y < HEIGHT; ++y) {
        for(x = 0; x < WIDTH; ++x) {
            unsigned char gray = (img[y][x].r + img[y][x].g + img[y][x].b) / 3;
            img[y][x].r = gray;
            img[y][x].g = gray;
            img[y][x].b = gray;
        }
    }
}

void invert(pixel img[HEIGHT][WIDTH]) {
    int x, y;
    for(y = 0; y < HEIGHT; ++y) {
        for(x = 0; x < WIDTH; ++x) {
            img[y][x].r = 255 - img[y][x].r;
            img[y][x].g = 255 - img[y][x].g;
            img[y][x].b = 255 - img[y][x].b;
        }
    }
}

void horizontal_flip(pixel img[HEIGHT][WIDTH]) {
    int x, y;
    for(y = 0; y < HEIGHT; ++y) {
        for(x = 0; x < WIDTH / 2; ++x) {
            swap(&img[y][x], &img[y][WIDTH - x - 1]);
        }
    }
}

int main() {
    FILE *infile, *outfile;
    char in_filename[] = "example_in.bmp";
    char out_filename[] = "example_out.bmp";
    int x, y;
    pixel white = {255, 255, 255};
    pixel black = {0, 0, 0};

    // Fill image with white pixels
    for(y = 0; y < HEIGHT; ++y) {
        for(x = 0; x < WIDTH; ++x) {
            img[y][x] = white;
        }
    }

    // Draw a black rectangle
    int rect_x = 50, rect_y = 70, rect_w = 100, rect_h = 50;
    for(y = rect_y; y < rect_y + rect_h; ++y) {
        for(x = rect_x; x < rect_x + rect_w; ++x) {
            img[y][x] = black;
        }
    }

    // Write image to file
    if((outfile = fopen(out_filename, "wb")) == NULL) {
        perror("Error opening output file");
        exit(1);
    }
    fwrite(img, sizeof(pixel), HEIGHT * WIDTH, outfile);
    fclose(outfile);

    // Read image from file
    if((infile = fopen(in_filename, "rb")) == NULL) {
        perror("Error opening input file");
        exit(1);
    }
    fread(img, sizeof(pixel), HEIGHT * WIDTH, infile);
    fclose(infile);

    // Apply image transformations
    grayscale(img);
    invert(img);
    horizontal_flip(img);

    // Write transformed image to file
    if((outfile = fopen(out_filename, "wb")) == NULL) {
        perror("Error opening output file");
        exit(1);
    }
    fwrite(img, sizeof(pixel), HEIGHT * WIDTH, outfile);
    fclose(outfile);

    return 0;
}