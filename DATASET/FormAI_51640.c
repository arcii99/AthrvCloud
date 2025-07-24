//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to flip an image
void flip_image(int *image, int width, int height) {
    int temp;
    for(int i=0; i<height; i++) {
        for(int j=0; j<width/2; j++) {
            temp = *(image + i*width + j);
            *(image + i*width + j) = *(image + i*width + (width-1-j));
            *(image + i*width + (width-1-j)) = temp;
        }
    }
}

// Function to change the brightness of an image
void change_brightness(int *image, int width, int height, int brightness) {
    for(int i=0; i<height; i++) {
        for(int j=0; j<width; j++) {
            int pixel = *(image + i*width + j);
            pixel += brightness;
            if(pixel < 0) pixel = 0;
            if(pixel > 255) pixel = 255;
            *(image + i*width + j) = pixel;
        }
    }
}

// Function to change the contrast of an image
void change_contrast(int *image, int width, int height, float contrast) {
    float factor = (259 * (contrast + 255)) / (255 * (259 - contrast));
    for(int i=0; i<height; i++) {
        for(int j=0; j<width; j++) {
            int pixel = *(image + i*width + j);
            pixel = factor * (pixel - 128) + 128;
            if(pixel < 0) pixel = 0;
            if(pixel > 255) pixel = 255;
            *(image + i*width + j) = pixel;
        }
    }
}

int main() {

    int width = 4;
    int height = 3;

    int image[] = {  4,  5,  6,  7,
                     8,  9, 10, 11,
                    12, 13, 14, 15 };

    // Print the original image
    printf("Original Image:\n");
    for(int i=0; i<height; i++) {
        for(int j=0; j<width; j++) {
            printf("%3d ", *(image + i*width + j));
        }
        printf("\n");
    }
    printf("\n");

    // Flip the image
    flip_image(image, width, height);

    // Print the flipped image
    printf("Flipped Image:\n");
    for(int i=0; i<height; i++) {
        for(int j=0; j<width; j++) {
            printf("%3d ", *(image + i*width + j));
        }
        printf("\n");
    }
    printf("\n");

    // Change the brightness of the image
    change_brightness(image, width, height, 50);

    // Print the image with changed brightness
    printf("Image with changed brightness:\n");
    for(int i=0; i<height; i++) {
        for(int j=0; j<width; j++) {
            printf("%3d ", *(image + i*width + j));
        }
        printf("\n");
    }
    printf("\n");

    // Change the contrast of the image
    change_contrast(image, width, height, 50.0);

    // Print the image with changed contrast
    printf("Image with changed contrast:\n");
    for(int i=0; i<height; i++) {
        for(int j=0; j<width; j++) {
            printf("%3d ", *(image + i*width + j));
        }
        printf("\n");
    }
    printf("\n");

    return 0;
}