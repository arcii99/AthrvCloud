//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: curious
#include <stdio.h>
#include <stdlib.h>

#define WIDTH 640
#define HEIGHT 480

// Function to flip horizontally
void flip_horizontally(unsigned char* image) {
    for(int y = 0; y < HEIGHT; y++) {
        for(int x = 0; x < WIDTH/2; x++) {
            unsigned char temp = image[y * WIDTH + x];
            image[y * WIDTH + x] = image[(y + 1) * WIDTH - (x + 1)];
            image[(y + 1) * WIDTH - (x + 1)] = temp;
        }
    }
}

// Function to adjust brightness and contrast
void brightness_contrast(unsigned char* image, float brightness, float contrast) {
    for(int i = 0; i < WIDTH * HEIGHT; i++) {
        float pixel = image[i];
        pixel = (pixel - 128.0) * contrast + 128.0 + brightness;
        if(pixel < 0.0) {
            pixel = 0.0;
        }
        if(pixel > 255.0) {
            pixel = 255.0;
        }
        image[i] = (unsigned char)pixel;
    }
}

int main() {
    // Allocate memory for image
    unsigned char* image = (unsigned char*)malloc(WIDTH * HEIGHT);
    if(image == NULL) {
        printf("Error: Could not allocate memory for image.\n");
        return 1;
    }

    // Initialize image with some data
    for(int y = 0; y < HEIGHT; y++) {
        for(int x = 0; x < WIDTH; x++) {
            image[y * WIDTH + x] = (x + y) % 256;
        }
    }

    // Flip horizontally
    flip_horizontally(image);

    // Adjust brightness and contrast
    brightness_contrast(image, 50.0, 1.5);

    // Print image data
    for(int y = 0; y < HEIGHT; y++) {
        for(int x = 0; x < WIDTH; x++) {
            printf("%d ", image[y * WIDTH + x]);
        }
        printf("\n");
    }

    // Free memory
    free(image);

    return 0;
}