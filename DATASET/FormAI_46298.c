//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>

// Function to flip the image horizontally
void flipHorizontal(int *image, int width, int height) {
    int temp;

    for (int row = 0; row < height; row++) {
        for (int col = 0; col < width / 2; col++) {
            temp = *(image + row * width + col);
            *(image + row * width + col) = *(image + row * width + width - col - 1);
            *(image + row * width + width - col - 1) = temp;
        }
    }
}

// Function to adjust the brightness of the image
void adjustBrightness(int *image, int width, int height, int brightness) {
    for (int row = 0; row < height; row++) {
        for (int col = 0; col < width; col++) {
            *(image + row * width + col) += brightness;
            if (*(image + row * width + col) > 255) {
                *(image + row * width + col) = 255;
            }
            else if (*(image + row * width + col) < 0) {
                *(image + row * width + col) = 0;
            }
        }
    }
}

// Function to adjust the contrast of the image
void adjustContrast(int *image, int width, int height, float contrast) {
    float factor = (259.0 * (contrast + 255.0)) / (255.0 * (259.0 - contrast));

    for (int row = 0; row < height; row++) {
        for (int col = 0; col < width; col++) {
            *(image + row * width + col) = factor * (*(image + row * width + col) - 128) + 128;
            if (*(image + row * width + col) > 255) {
                *(image + row * width + col) = 255;
            }
            else if (*(image + row * width + col) < 0) {
                *(image + row * width + col) = 0;
            }
        }
    }
}

int main() {
    int image[3][3] = {{10, 20, 30},
                       {40, 50, 60},
                       {70, 80, 90}};

    printf("Original Image:\n");
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {
            printf("%d ", image[row][col]);
        }
        printf("\n");
    }

    flipHorizontal(&image[0][0], 3, 3);

    printf("Flipped Image:\n");
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {
            printf("%d ", image[row][col]);
        }
        printf("\n");
    }

    adjustBrightness(&image[0][0], 3, 3, 30);

    printf("Brightness Adjusted Image:\n");
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {
            printf("%d ", image[row][col]);
        }
        printf("\n");
    }

    adjustContrast(&image[0][0], 3, 3, 30);

    printf("Contrast Adjusted Image:\n");
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {
            printf("%d ", image[row][col]);
        }
        printf("\n");
    }

    return 0;
}