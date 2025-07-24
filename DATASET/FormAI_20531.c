//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>

#define HEIGHT 100
#define WIDTH 100

// Function to flip the image horizontally
void flipImageHorizontally(int img[][WIDTH]) {
    int temp;
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH / 2; j++) {
            temp = img[i][j];
            img[i][j] = img[i][WIDTH - j - 1];
            img[i][WIDTH - j - 1] = temp;
        }
    }
}

// Function to change the brightness of the image
void changeBrightness(int img[][WIDTH], int brightness) {
    int pixel;
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            pixel = img[i][j] + brightness;
            if (pixel > 255) { // Maximum pixel value is 255
                pixel = 255;
            }
            else if (pixel < 0) { // Minimum pixel value is 0
                pixel = 0;
            }
            img[i][j] = pixel;
        }
    }
}

// Function to change the contrast of the image
void changeContrast(int img[][WIDTH], float contrast) {
    float factor = (259 * (contrast + 255)) / (255 * (259 - contrast));
    int pixel;
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            pixel = factor * (img[i][j] - 128) + 128;
            if (pixel > 255) { // Maximum pixel value is 255
                pixel = 255;
            }
            else if (pixel < 0) { // Minimum pixel value is 0
                pixel = 0;
            }
            img[i][j] = pixel;
        }
    }
}

int main() {
    // Create a random image
    int image[HEIGHT][WIDTH];
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            image[i][j] = rand() % 256; // Random pixel values between 0 and 255
        }
    }

    // Flip the image horizontally
    flipImageHorizontally(image);

    // Change the brightness of the image
    changeBrightness(image, 50);

    // Change the contrast of the image
    changeContrast(image, 50.0);

    // Print the modified image
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            printf("%d ", image[i][j]);
        }
        printf("\n");
    }

    return 0;
}