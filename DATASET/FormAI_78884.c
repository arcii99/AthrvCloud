//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: creative
#include <stdio.h>
#include <stdlib.h>

// function to flip the image horizontally
void horizontal_flip(int rows, int cols, int *image) {
    int temp;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols / 2; j++) {
            temp = *(image + i * cols + j);
            *(image + i * cols + j) = *(image + i * cols + cols - j - 1);
            *(image + i * cols + cols - j - 1) = temp;
        }
    }
}

// function to change the brightness of the image
void change_brightness(int rows, int cols, int *image, int brightness) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            int pixel_val = *(image + i * cols + j);
            pixel_val += brightness;
            if (pixel_val < 0) { // minimum pixel value is 0
                pixel_val = 0;
            } else if (pixel_val > 255) { // maximum pixel value is 255
                pixel_val = 255;
            }
            *(image + i * cols + j) = pixel_val;
        }
    }
}

// function to change the contrast of the image
void change_contrast(int rows, int cols, int *image, float contrast) {
    float factor = (259 * (contrast + 255)) / (255 * (259 - contrast));
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            int pixel_val = *(image + i * cols + j);
            pixel_val = (int)(factor * (pixel_val - 128) + 128);
            if (pixel_val < 0) { // minimum pixel value is 0
                pixel_val = 0;
            } else if (pixel_val > 255) { // maximum pixel value is 255
                pixel_val = 255;
            }
            *(image + i * cols + j) = pixel_val;
        }
    }
}

int main() {
    int rows = 3;
    int cols = 4;

    // initialize a sample grayscale image
    int image[3][4] = {
        { 10, 20, 30, 40 },
        { 50, 60, 70, 80 },
        { 90, 100, 110, 120 }
    };
    int *ptr = &image[0][0];

    // display the original image
    printf("Original Image:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", *(ptr + i * cols + j));
        }
        printf("\n");
    }
    printf("\n");

    // flip the image horizontally
    horizontal_flip(rows, cols, ptr);
    printf("Horizontally Flipped Image:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", *(ptr + i * cols + j));
        }
        printf("\n");
    }
    printf("\n");

    // change the brightness of the image
    int brightness = 20;
    change_brightness(rows, cols, ptr, brightness);
    printf("Brightened Image:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", *(ptr + i * cols + j));
        }
        printf("\n");
    }
    printf("\n");

    // change the contrast of the image
    float contrast = 50.0;
    change_contrast(rows, cols, ptr, contrast);
    printf("High Contrast Image:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", *(ptr + i * cols + j));
        }
        printf("\n");
    }

    return 0;
}