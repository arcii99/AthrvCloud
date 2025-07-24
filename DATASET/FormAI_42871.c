//FormAI DATASET v1.0 Category: Image Editor ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 500

struct Image {
    int width;
    int height;
    int pixels[MAX_SIZE][MAX_SIZE][3];
};

// Generate a new image
struct Image generateImage(int width, int height) {
    struct Image img = {width, height};

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            for (int k = 0; k < 3; k++) {
                img.pixels[i][j][k] = rand() % 256;
            }
        }
    }

    return img;
}

// Print an image
void printImage(struct Image img) {
    printf("P3\n"); // P3 is the code for a PPM image
    printf("%d %d\n", img.width, img.height); // Width and height
    printf("255\n"); // Max color value

    for (int i = 0; i < img.height; i++) {
        for (int j = 0; j < img.width; j++) {
            for (int k = 0; k < 3; k++) {
                printf("%d ", img.pixels[i][j][k]);
            }
        }
        printf("\n");
    }
}

// Invert an image
void invertImage(struct Image* img) {
    for (int i = 0; i < img->height; i++) {
        for (int j = 0; j < img->width; j++) {
            for (int k = 0; k < 3; k++) {
                img->pixels[i][j][k] = 255 - img->pixels[i][j][k];
            }
        }
    }
}

// Blur an image
void blurImage(struct Image* img) {
    int numPixels;

    // Loop through every pixel in the image
    for (int i = 0; i < img->height; i++) {
        for (int j = 0; j < img->width; j++) {
            numPixels = 0;
            int red = 0;
            int green = 0;
            int blue = 0;

            // Loop through neighboring pixels
            for (int m = -1; m <= 1; m++) {
                for (int n = -1; n <= 1; n++) {
                    if (i+m >= 0 && i+m < img->height && j+n >= 0 && j+n < img->width) {
                        numPixels++;
                        red += img->pixels[i+m][j+n][0];
                        green += img->pixels[i+m][j+n][1];
                        blue += img->pixels[i+m][j+n][2];
                    }
                }
            }

            // Set pixel color to average of neighboring pixels
            img->pixels[i][j][0] = red / numPixels;
            img->pixels[i][j][1] = green / numPixels;
            img->pixels[i][j][2] = blue / numPixels;
        }
    }
}

int main() {
    struct Image img = generateImage(100, 100);

    printf("Original Image:\n");
    printImage(img);

    invertImage(&img);

    printf("Inverted Image:\n");
    printImage(img);

    blurImage(&img);

    printf("Blurred Image:\n");
    printImage(img);

    return 0;
}