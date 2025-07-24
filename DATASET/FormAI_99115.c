//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: protected
#include <stdio.h>
#include <stdlib.h>

// Function to flip an image horizontally
void flipHorizontal(int *image, int width, int height) {
    int temp;
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width / 2; j++) {
            temp = *(image + i * width + j);
            *(image + i * width + j) = *(image + i * width + width - j - 1);
            *(image + i * width + width - j - 1) = temp;
        }
    }
}

// Function to change the brightness of an image
void changeBrightness(int *image, int width, int height, int brightness) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int val = *(image + i * width + j);
            val += brightness;
            if (val > 255) val = 255;
            if (val < 0) val = 0;
            *(image + i * width + j) = val;
        }
    }
}

// Function to change the contrast of an image
void changeContrast(int *image, int width, int height, int contrast) {
    double factor = (259.0 * (contrast + 255.0)) / (255.0 * (259.0 - contrast));
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int val = *(image + i * width + j);
            val = factor * (val - 128) + 128;
            if (val > 255) val = 255;
            if (val < 0) val = 0;
            *(image + i * width + j) = val;
        }
    }
}

// Main function to perform image processing tasks
int main() {
    // Sample image data
    int image[4][4] = {{10, 20, 30, 40},
                       {50, 60, 70, 80},
                       {90, 100, 110, 120},
                       {130, 140, 150, 160}};

    // Display the original image
    printf("Original Image:\n");
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            printf("%d ", image[i][j]);
        }
        printf("\n");
    }

    // Flip the image horizontally
    flipHorizontal(&image[0][0], 4, 4);
    printf("\nFlipped Image:\n");

    // Display the flipped image
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            printf("%d ", image[i][j]);
        }
        printf("\n");
    }

    // Increase brightness by 50
    changeBrightness(&image[0][0], 4, 4, 50);
    printf("\nBrightness Increased:\n");

    // Display the image with increased brightness
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            printf("%d ", image[i][j]);
        }
        printf("\n");
    }

    // Decrease brightness by 30
    changeBrightness(&image[0][0], 4, 4, -30);
    printf("\nBrightness Decreased:\n");

    // Display the image with decreased brightness
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            printf("%d ", image[i][j]);
        }
        printf("\n");
    }

    // Increase contrast by 30
    changeContrast(&image[0][0], 4, 4, 30);
    printf("\nContrast Increased:\n");

    // Display the image with increased contrast
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            printf("%d ", image[i][j]);
        }
        printf("\n");
    }

    // Decrease contrast by 50
    changeContrast(&image[0][0], 4, 4, -50);
    printf("\nContrast Decreased:\n");

    // Display the image with decreased contrast
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            printf("%d ", image[i][j]);
        }
        printf("\n");
    }

    return 0;
}