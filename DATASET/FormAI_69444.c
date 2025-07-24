//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>

// Function to flip an image horizontally
void flipHorizontally(int image[][3], int width, int height) {
    int temp;
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width / 2; j++) {
            temp = image[i][j];
            image[i][j] = image[i][width - j - 1];
            image[i][width - j - 1] = temp;
        }
    }
}

// Function to increase brightness of image
void increaseBrightness(int image[][3], int width, int height, int amount) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            for (int k = 0; k < 3; k++) {
                if (image[i][j] + amount > 255) {
                    image[i][j] = 255;
                }
                else {
                    image[i][j] += amount;
                }
            }
        }
    }
}

// Function to decrease brightness of image
void decreaseBrightness(int image[][3], int width, int height, int amount) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            for (int k = 0; k < 3; k++) {
                if (image[i][j] - amount < 0) {
                    image[i][j] = 0;
                }
                else {
                    image[i][j] -= amount;
                }
            }
        }
    }
}

// Function to increase contrast of image
void increaseContrast(int image[][3], int width, int height, int amount) {
    int factor = (259 * (amount + 255)) / (255 * (259 - amount));
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            for (int k = 0; k < 3; k++) {
                image[i][j] = ((factor * (image[i][j] - 128)) + 128);
            }
        }
    }
}

// Function to decrease contrast of image
void decreaseContrast(int image[][3], int width, int height, int amount) {
    int factor = (259 * (amount + 255)) / (255 * (259 - amount));
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            for (int k = 0; k < 3; k++) {
                image[i][j] = ((factor * (image[i][j] - 128)) + 128);
            }
        }
    }
}

int main() {
    // Creating a sample 3x3 image
    int image[3][3] = {{100, 50, 200},
                       {150, 75, 225},
                       {50, 25, 100}};

    // Flipping the image horizontally
    flipHorizontally(image, 3, 3);

    // Increasing the brightness of the image by 50
    increaseBrightness(image, 3, 3, 50);

    // Decreasing the contrast of the image by 50
    decreaseContrast(image, 3, 3, 50);

    printf("Modified Image:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("(%d, %d, %d) ", image[i][j], image[i][j], image[i][j]);
        }
        printf("\n");
    }

    return 0;
}