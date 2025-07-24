//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: modular
#include <stdio.h>
#include <stdlib.h>

// Function to flip an image
void flipImage(int* image, int width, int height) {
    int temp, i, j;
    for (i = 0; i < height; i++) {
        for (j = 0; j < width / 2; j++) {
            temp = *(image + i*width + j);
            *(image + i*width + j) = *(image + i*width + width - j - 1);
            *(image + i*width + width - j - 1) = temp;
        }
    }
}

// Function to adjust the brightness of an image
void adjustBrightness(int* image, int width, int height, int brightness) {
    int i, j;
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            *(image + i*width + j) += brightness;
            if (*(image + i*width + j) > 255) {
                *(image + i*width + j) = 255;
            }
            else if (*(image + i*width + j) < 0) {
                *(image + i*width + j) = 0;
            }
        }
    }
}

// Function to adjust the contrast of an image
void adjustContrast(int* image, int width, int height, float contrast) {
    int i, j;
    float factor = (259.0 * (contrast + 255.0)) / (255.0 * (259.0 - contrast));
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            *(image + i*width + j) = (int)(factor * (*(image + i*width + j) - 128) + 128);
            if (*(image + i*width + j) > 255) {
                *(image + i*width + j) = 255;
            }
            else if (*(image + i*width + j) < 0) {
                *(image + i*width + j) = 0;
            }
        }
    }
}

int main() {
    int width = 4;
    int height = 3;
    int image[12] = { 255, 200, 100, 50,
                      200, 150, 75, 25,
                      100, 75, 50, 0 };
    int i, j;

    // Print the original image
    printf("Original Image:\n");
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            printf("%d ", *(image + i*width + j));
        }
        printf("\n");
    }

    // Flip the image
    flipImage(image, width, height);

    // Print the flipped image
    printf("\nFlipped Image:\n");
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            printf("%d ", *(image + i*width + j));
        }
        printf("\n");
    }

    // Adjust the brightness of the image
    adjustBrightness(image, width, height, 50);

    // Print the brightness adjusted image
    printf("\nBrightness Adjusted Image:\n");
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            printf("%d ", *(image + i*width + j));
        }
        printf("\n");
    }

    // Adjust the contrast of the image
    adjustContrast(image, width, height, 50.0);

    // Print the contrast adjusted image
    printf("\nContrast Adjusted Image:\n");
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            printf("%d ", *(image + i*width + j));
        }
        printf("\n");
    }

    return 0;
}