//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Function to flip the image horizontally
void flip_horizontal(int *image, int width, int height) {
    int temp;

    for(int row = 0; row < height; row++) {
        for(int col = 0; col < width / 2; col++) {
            temp = *(image + row * width + col);
            *(image + row * width + col) = *(image + row * width + (width - col - 1));
            *(image + row * width + (width - col - 1)) = temp;
        }
    }
}

// Function to adjust the brightness of the image
void adjust_brightness(int *image, int width, int height, int brightness) {
    for(int row = 0; row < height; row++) {
        for(int col = 0; col < width; col++) {
            *(image + row * width + col) = *(image + row * width + col) + brightness;
        }
    }
}

// Function to adjust the contrast of the image
void adjust_contrast(int *image, int width, int height, double contrast) {
    double factor = (259.0 * (contrast + 255.0)) / (255.0 * (259.0 - contrast));

    for(int row = 0; row < height; row++) {
        for(int col = 0; col < width; col++) {
            int value = (int)(factor * (*(image + row * width + col) - 128) + 128);
            if(value < 0) {
                *(image + row * width + col) = 0; // ensure pixel values are within range
            } else if(value > 255) {
                *(image + row * width + col) = 255;
            } else {
                *(image + row * width + col) = value;
            }
        }
    }
}

int main() {
    int width = 3;
    int height = 3;
    int image[9] = {0, 128, 255, 64, 192, 32, 96, 224, 160};
    int brightness = 50;
    double contrast = 50.0;

    printf("Original Image:\n");
    for(int row = 0; row < height; row++) {
        for(int col = 0; col < width; col++) {
            printf("%d ", *(image + row * width + col));
        }
        printf("\n");
    }

    printf("\nFlipped Image:\n");
    flip_horizontal(image, width, height);
    for(int row = 0; row < height; row++) {
        for(int col = 0; col < width; col++) {
            printf("%d ", *(image + row * width + col));
        }
        printf("\n");
    }

    printf("\nBrightened Image:\n");
    adjust_brightness(image, width, height, brightness);
    for(int row = 0; row < height; row++) {
        for(int col = 0; col < width; col++) {
            printf("%d ", *(image + row * width + col));
        }
        printf("\n");
    }

    printf("\nContrasted Image:\n");
    adjust_contrast(image, width, height, contrast);
    for(int row = 0; row < height; row++) {
        for(int col = 0; col < width; col++) {
            printf("%d ", *(image + row * width + col));
        }
        printf("\n");
    }

    return 0;
}