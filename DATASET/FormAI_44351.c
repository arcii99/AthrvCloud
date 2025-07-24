//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>

#define IMAGE_HEIGHT 10
#define IMAGE_WIDTH 10
#define MAX_PIXEL_VALUE 255

int image[IMAGE_HEIGHT][IMAGE_WIDTH];

void flip_image(int image[IMAGE_HEIGHT][IMAGE_WIDTH]) {
    for (int i = 0; i < IMAGE_HEIGHT / 2; i++) {
        for (int j = 0; j < IMAGE_WIDTH; j++) {
            int temp = image[i][j];
            image[i][j] = image[IMAGE_HEIGHT - i - 1][j];
            image[IMAGE_HEIGHT - i - 1][j] = temp;
        }
    }
}

void adjust_brightness(int image[IMAGE_HEIGHT][IMAGE_WIDTH], int brightness) {
    for (int i = 0; i < IMAGE_HEIGHT; i++) {
        for (int j = 0; j < IMAGE_WIDTH; j++) {
            image[i][j] = image[i][j] + brightness;
            if (image[i][j] > MAX_PIXEL_VALUE) {
                image[i][j] = MAX_PIXEL_VALUE;
            } else if (image[i][j] < 0) {
                image[i][j] = 0;
            }
        }
    }
}

void adjust_contrast(int image[IMAGE_HEIGHT][IMAGE_WIDTH], int contrast) {
    double factor = (259.0 * (contrast + 255.0)) / (255.0 * (259.0 - contrast));
    for (int i = 0; i < IMAGE_HEIGHT; i++) {
        for (int j = 0; j < IMAGE_WIDTH; j++) {
            int pixel_value = image[i][j];
            int adjusted_pixel_value = factor * (pixel_value - 128) + 128;
            if (adjusted_pixel_value > MAX_PIXEL_VALUE) {
                adjusted_pixel_value = MAX_PIXEL_VALUE;
            } else if (adjusted_pixel_value < 0) {
                adjusted_pixel_value = 0;
            }
            image[i][j] = adjusted_pixel_value;
        }
    }
}

int main() {
    // Generate random image
    for (int i = 0; i < IMAGE_HEIGHT; i++) {
        for (int j = 0; j < IMAGE_WIDTH; j++) {
            image[i][j] = rand() % MAX_PIXEL_VALUE;
        }
    }

    // Print original image
    printf("Original Image:\n");
    for (int i = 0; i < IMAGE_HEIGHT; i++) {
        for (int j = 0; j < IMAGE_WIDTH; j++) {
            printf("%d ", image[i][j]);
        }
        printf("\n");
    }

    // Flip image
    flip_image(image);
    printf("\nFlipped Image:\n");
    for (int i = 0; i < IMAGE_HEIGHT; i++) {
        for (int j = 0; j < IMAGE_WIDTH; j++) {
            printf("%d ", image[i][j]);
        }
        printf("\n");
    }

    // Adjust brightness and contrast
    adjust_brightness(image, 20);
    adjust_contrast(image, 50);
    printf("\nAdjusted Image:\n");
    for (int i = 0; i < IMAGE_HEIGHT; i++) {
        for (int j = 0; j < IMAGE_WIDTH; j++) {
            printf("%d ", image[i][j]);
        }
        printf("\n");
    }

    return 0;
}