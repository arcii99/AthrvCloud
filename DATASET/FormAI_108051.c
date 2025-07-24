//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: authentic
#include <stdio.h>
#include <stdlib.h>

void flipImage(int image[][4], int rows) {
    int temp[4];
    for (int i = 0; i < rows/2; i++) {
        for (int j = 0; j < 4; j++) {
            temp[j] = image[i][j];
            image[i][j] = image[rows - i - 1][j];
            image[rows - i - 1][j] = temp[j];
        }
    }
}


void adjustBrightness(int image[][4], int rows) {
    int brightness = 20;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < 4; j++) {
            if (image[i][j] + brightness > 255)
                image[i][j] = 255;
            else
                image[i][j] += brightness;
        }
    }
}


void adjustContrast(int image[][4], int rows) {
    float contrast = 1.5;
    float factor = (259 * (contrast + 255)) / (255 * (259 - contrast));
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < 4; j++) {
            image[i][j] = factor * (image[i][j] - 128) + 128;
            if (image[i][j] > 255)
                image[i][j] = 255;
            else if (image[i][j] < 0)
                image[i][j] = 0;
        }
    }
}


int main() {
    int image[4][4] = {{42, 15, 200, 150},
                       {50, 70, 120, 180},
                       {10, 90, 255, 45},
                       {30, 80, 40, 250}};

    printf("Original Image:\n");
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            printf("%d ", image[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    flipImage(image, 4);

    printf("Flipped Image:\n");
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            printf("%d ", image[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    adjustBrightness(image, 4);

    printf("Adjusted Brightness Image:\n");
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            printf("%d ", image[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    adjustContrast(image, 4);

    printf("Adjusted Contrast Image:\n");
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            printf("%d ", image[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    return 0;
}