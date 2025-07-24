//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>

// defining constants for maximum image width and height
#define MAX_WIDTH 1000
#define MAX_HEIGHT 1000

// function prototypes
void flipImage(char inputImage[MAX_HEIGHT][MAX_WIDTH], char outputImage[MAX_HEIGHT][MAX_WIDTH], int width, int height);
void adjustBrightnessAndContrast(char inputImage[MAX_HEIGHT][MAX_WIDTH], char outputImage[MAX_HEIGHT][MAX_WIDTH], int width, int height, int brightness, float contrast);

int main() {
    // variables to store image dimensions and choice of operation
    int choice, width, height;

    // array to hold the input image
    char inputImage[MAX_HEIGHT][MAX_WIDTH];

    // array to hold the output image
    char outputImage[MAX_HEIGHT][MAX_WIDTH];

    printf("Enter image width and height (up to %d x %d): ", MAX_WIDTH, MAX_HEIGHT);
    scanf("%d %d", &width, &height);

    // inputting the image
    printf("Enter the image (as characters A-Z or a-z):\n");
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            scanf(" %c", &inputImage[i][j]);
        }
    }

    // giving user choices to flip or adjust brightness and contrast
    printf("Do you want to:\n");
    printf("1) Flip the image\n");
    printf("2) Adjust brightness and contrast\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            flipImage(inputImage, outputImage, width, height);
            break;
        case 2:
            // variables to store brightness and contrast values
            int brightness;
            float contrast;

            printf("Enter the brightness value (-128 to 127): ");
            scanf("%d", &brightness);
            printf("Enter the contrast value (0 to 4): ");
            scanf("%f", &contrast);

            adjustBrightnessAndContrast(inputImage, outputImage, width, height, brightness, contrast);
            break;
        default:
            printf("Invalid choice\n");
            return 1;
    }

    // printing the output image
    printf("Output image:\n");
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf("%c ", outputImage[i][j]);
        }
        printf("\n");
    }

    return 0;
}

/**
 * Flips the given image vertically.
 */
void flipImage(char inputImage[MAX_HEIGHT][MAX_WIDTH], char outputImage[MAX_HEIGHT][MAX_WIDTH], int width, int height) {
    // flipping the image
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            outputImage[i][j] = inputImage[height-1-i][j];
        }
    }
}

/**
 * Adjusts the brightness and contrast of the given image.
 */
void adjustBrightnessAndContrast(char inputImage[MAX_HEIGHT][MAX_WIDTH], char outputImage[MAX_HEIGHT][MAX_WIDTH], int width, int height, int brightness, float contrast) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            // adjusting brightness
            int pixel = inputImage[i][j] + brightness;

            // adjusting contrast
            pixel = (int) ((pixel - 128) * contrast) + 128;

            // clamping the pixel value between 0 and 255
            if (pixel < 0) {
                pixel = 0;
            }
            if (pixel > 255) {
                pixel = 255;
            }

            outputImage[i][j] = (char) pixel;
        }
    }
}