//FormAI DATASET v1.0 Category: Image Editor ; Style: authentic
#include <stdio.h>
#include <stdlib.h>

#define WIDTH 512
#define HEIGHT 512
#define MAX_COLOR_VALUE 255

typedef struct {
    unsigned char red;
    unsigned char green;
    unsigned char blue;
} pixel;

pixel image[WIDTH][HEIGHT];

void clearImage() {
    int x, y;
    for (y = 0; y < HEIGHT; y++) {
        for (x = 0; x < WIDTH; x++) {
            image[x][y].red = 0;
            image[x][y].green = 0;
            image[x][y].blue = 0;
        }
    }
}

void invertImage() {
    int x, y;
    for (y = 0; y < HEIGHT; y++) {
        for (x = 0; x < WIDTH; x++) {
            image[x][y].red = MAX_COLOR_VALUE - image[x][y].red;
            image[x][y].green = MAX_COLOR_VALUE - image[x][y].green;
            image[x][y].blue = MAX_COLOR_VALUE - image[x][y].blue;
        }
    }
}

void darkerImage() {
    int x, y;
    for (y = 0; y < HEIGHT; y++) {
        for (x = 0; x < WIDTH; x++) {
            image[x][y].red /= 2;
            image[x][y].green /= 2;
            image[x][y].blue /= 2;
        }
    }
}

void brighterImage() {
    int x, y;
    for (y = 0; y < HEIGHT; y++) {
        for (x = 0; x < WIDTH; x++) {
            if (image[x][y].red + 50 <= MAX_COLOR_VALUE) {
                image[x][y].red += 50;
            }
            if (image[x][y].green + 50 <= MAX_COLOR_VALUE) {
                image[x][y].green += 50;
            }
            if (image[x][y].blue + 50 <= MAX_COLOR_VALUE) {
                image[x][y].blue += 50;
            }
        }
    }
}

void writeImageToFile(const char* fileName) {
    FILE* file;
    int x, y;
    file = fopen(fileName, "wb");
    if (!file) {
        fprintf(stderr, "Error: unable to open file %s.\n", fileName);
        return;
    }

    fprintf(file, "P6 %d %d %d\n", WIDTH, HEIGHT, MAX_COLOR_VALUE);
    for (y = 0; y < HEIGHT; y++) {
        for (x = 0; x < WIDTH; x++) {
            fwrite(&image[x][y], 1, 3, file);
        }
    }
    fclose(file);
}

int main() {
    clearImage();

    int x, y;
    for (y = 0; y < HEIGHT; y++) {
        for (x = 0; x < WIDTH; x++) {
            image[x][y].red = x % MAX_COLOR_VALUE;
            image[x][y].green = y % MAX_COLOR_VALUE;
            image[x][y].blue = (x + y) % MAX_COLOR_VALUE;
        }
    }

    brighterImage();
    writeImageToFile("brighterImage.ppm");

    invertImage();
    writeImageToFile("invertedImage.ppm");

    darkerImage();
    writeImageToFile("darkImage.ppm");

    printf("Image files written successfully.\n");
    return 0;
}