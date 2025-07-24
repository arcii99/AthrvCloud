//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: real-life
#include <stdio.h>
#include <stdlib.h>

void flipImage(int *image, int width, int height) {
    int i, j;
    for (i = 0; i < height; i++) {
        for (j = 0; j < width / 2; j++) {
            int temp = image[i * width + j];
            image[i * width + j] = image[i * width + (width - j - 1)];
            image[i * width + (width - j - 1)] = temp;
        }
    }
}

void adjustBrightnessContrast(int *image, int width, int height, float brightness, float contrast) {
    int i, j;
    float pixelValue, pixelValueAdjusted;
    float factor = (259 * (contrast + 255)) / (255 * (259 - contrast));
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            pixelValue = (float)image[i * width + j];
            pixelValueAdjusted = factor * (pixelValue - 128) + 128 + brightness;
            image[i * width + j] = (int)pixelValueAdjusted;
        }
    }
}

int main() {
    int width = 4, height = 3;
    int image[] = { 1, 2, 3, 4,
                    5, 6, 7, 8,
                    9, 10, 11, 12 };

    printf("Original Image:\n");
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf("%d ", image[i * width + j]);
        }
        printf("\n");
    }

    // Flip image
    flipImage(image, width, height);
    printf("\nFlipped Image:\n");
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf("%d ", image[i * width + j]);
        }
        printf("\n");
    }

    // Adjust brightness and contrast
    float brightness = 50, contrast = 25;
    adjustBrightnessContrast(image, width, height, brightness, contrast);
    printf("\nAdjusted Brightness and Contrast Image:\n");
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf("%d ", image[i * width + j]);
        }
        printf("\n");
    }

    return 0;
}