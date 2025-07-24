//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_IMAGE_HEIGHT 1000
#define MAX_IMAGE_WIDTH 1000
#define MAX_PIXEL_VALUE 255

typedef struct {
    int height;
    int width;
    int maxVal;
    int imageData[MAX_IMAGE_HEIGHT][MAX_IMAGE_WIDTH];
} Image;

void flipVertically(Image *image) {
    int tmpImageData[MAX_IMAGE_HEIGHT][MAX_IMAGE_WIDTH];
    for(int i = 0; i < image->height; i++) {
        for(int j = 0; j < image->width; j++) {
            tmpImageData[i][j] = image->imageData[i][j];
        }
    }

    for(int i = 0; i < image->height; i++) {
        for(int j = 0; j < image->width; j++) {
            image->imageData[i][j] = tmpImageData[image->height - 1 - i][j];
        }
    }
}

void flipHorizontally(Image *image) {
    int tmpImageData[MAX_IMAGE_HEIGHT][MAX_IMAGE_WIDTH];
    for(int i = 0; i < image->height; i++) {
        for(int j = 0; j < image->width; j++) {
            tmpImageData[i][j] = image->imageData[i][j];
        }
    }

    for(int i = 0; i < image->height; i++) {
        for(int j = 0; j < image->width; j++) {
            image->imageData[i][j] = tmpImageData[i][image->width - 1 - j];
        }
    }
}

void increaseBrightness(Image *image, int increment) {
    for(int i = 0; i < image->height; i++) {
        for(int j = 0; j < image->width; j++) {
            image->imageData[i][j] += increment;
            if(image->imageData[i][j] > MAX_PIXEL_VALUE) {
                image->imageData[i][j] = MAX_PIXEL_VALUE;
            }
        }
    }
}

void decreaseBrightness(Image *image, int decrement) {
    for(int i = 0; i < image->height; i++) {
        for(int j = 0; j < image->width; j++) {
            image->imageData[i][j] -= decrement;
            if(image->imageData[i][j] < 0) {
                image->imageData[i][j] = 0;
            }
        }
    }
}

void increaseContrast(Image *image, int factor) {
    double contrastFactor = (259.0 * (factor + 255.0)) / (255.0 * (259.0 - factor));

    for(int i = 0; i < image->height; i++) {
        for(int j = 0; j < image->width; j++) {
            int newValue = contrastFactor * (image->imageData[i][j] - 128) + 128;
            if(newValue > MAX_PIXEL_VALUE) {
                newValue = MAX_PIXEL_VALUE;
            }
            if(newValue < 0) {
                newValue = 0;
            }
            image->imageData[i][j] = newValue;
        }
    }
}

void decreaseContrast(Image *image, int factor) {
    double contrastFactor = (259.0 * (255.0 - factor)) / (255.0 * (259.0 - factor + 255.0));

    for(int i = 0; i < image->height; i++) {
        for(int j = 0; j < image->width; j++) {
            int newValue = contrastFactor * (image->imageData[i][j] - 128) + 128;
            if(newValue > MAX_PIXEL_VALUE) {
                newValue = MAX_PIXEL_VALUE;
            }
            if(newValue < 0) {
                newValue = 0;
            }
            image->imageData[i][j] = newValue;
        }
    }
}

void printImage(Image *image) {
    printf("P2\n");
    printf("%d %d\n", image->width, image->height);
    printf("%d\n", image->maxVal);
    for(int i = 0; i < image->height; i++) {
        for(int j = 0; j < image->width; j++) {
            printf("%d ", image->imageData[i][j]);
        }
        printf("\n");
    }
}

int main() {
    // Initialize image
    Image image = {
        .height = 5,
        .width = 5,
        .maxVal = MAX_PIXEL_VALUE,
        .imageData = {
            {255, 0, 255, 0, 255},
            {0, 255, 0, 255, 0},
            {255, 0, 255, 0, 255},
            {0, 255, 0, 255, 0},
            {255, 0, 255, 0, 255}
        }
    };

    // Original Image
    printf("Original Image:\n");
    printImage(&image);

    // Flip vertically
    flipVertically(&image);
    printf("\nImage after flipping vertically:\n");
    printImage(&image);

    // Flip horizontally
    flipHorizontally(&image);
    printf("\nImage after flipping horizontally:\n");
    printImage(&image);

    // Increase brightness
    increaseBrightness(&image, 50);
    printf("\nImage after increasing brightness by 50:\n");
    printImage(&image);

    // Decrease brightness
    decreaseBrightness(&image, 100);
    printf("\nImage after decreasing brightness by 100:\n");
    printImage(&image);

    // Increase contrast
    increaseContrast(&image, 50);
    printf("\nImage after increasing contrast by 50:\n");
    printImage(&image);

    // Decrease contrast
    decreaseContrast(&image, 50);
    printf("\nImage after decreasing contrast by 50:\n");
    printImage(&image);

    return 0;
}