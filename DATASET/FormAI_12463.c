//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

//function to flip an image horizontally
void flip_image_horizontal(int* pixels, int width, int height) {
    int i, j;
    int temp;
    for (i = 0; i < height; i++) {
        for (j = 0; j < width / 2; j++) {
            temp = *(pixels + i * width + j);
            *(pixels + i * width + j) = *(pixels + i * width + (width - j - 1));
            *(pixels + i * width + (width - j - 1)) = temp;
        }
    }
}

//function to flip an image vertically
void flip_image_vertical(int* pixels, int width, int height) {
    int i, j;
    int temp;
    for (i = 0; i < height / 2; i++) {
        for (j = 0; j < width; j++) {
            temp = *(pixels + i * width + j);
            *(pixels + i * width + j) = *(pixels + (height - i - 1) * width + j);
            *(pixels + (height - i - 1) * width + j) = temp;
        }
    }
}

//function to adjust brightness of an image
void adjust_brightness(int* pixels, int width, int height, int brightness) {
    int i, j;
    int pixel_value;
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            pixel_value = *(pixels + i * width + j) + brightness;
            if (pixel_value > 255) {
                *(pixels + i * width + j) = 255;
            } else if (pixel_value < 0) {
                *(pixels + i * width + j) = 0;
            } else {
                *(pixels + i * width + j) = pixel_value;
            }
        }
    }
}

//function to adjust contrast of an image
void adjust_contrast(int* pixels, int width, int height, float contrast) {
    int i, j;
    int pixel_value;
    float factor = (259.0 * (contrast + 255.0)) / (255.0 * (259.0 - contrast));
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            pixel_value = factor * (*(pixels + i * width + j) - 128.0) + 128.0;
            if (pixel_value > 255) {
                *(pixels + i * width + j) = 255;
            } else if (pixel_value < 0) {
                *(pixels + i * width + j) = 0;
            } else {
                *(pixels + i * width + j) = pixel_value;
            }
        }
    }
}

int main() {
    int width = 4;
    int height = 3;
    int pixels[width * height];
    int i, j;

    //initialize pixels with values from 0 to 11
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            *(pixels + i * width + j) = i * width + j;
            printf("%d ", *(pixels + i * width + j));
        }
        printf("\n");
    }

    // flip image horizontally
    flip_image_horizontal(pixels, width, height);
    printf("After flipping horizontally:\n");
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            printf("%d ", *(pixels + i * width + j));
        }
        printf("\n");
    }

    // flip image vertically
    flip_image_vertical(pixels, width, height);
    printf("After flipping vertically:\n");
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            printf("%d ", *(pixels + i * width + j));
        }
        printf("\n");
    }

    // adjust brightness of image by 50
    adjust_brightness(pixels, width, height, 50);
    printf("After adjusting brightness:\n");
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            printf("%d ", *(pixels + i * width + j));
        }
        printf("\n");
    }

    // adjust contrast of image by 1.5
    adjust_contrast(pixels, width, height, 1.5);
    printf("After adjusting contrast:\n");
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            printf("%d ", *(pixels + i * width + j));
        }
        printf("\n");
    }

    return 0;
}