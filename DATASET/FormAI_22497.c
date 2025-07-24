//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdint.h>

// Define the image size
#define WIDTH 512
#define HEIGHT 512

// Define the maximum pixel value
#define MAX_PIXEL_VALUE 255

// Define the image struct
typedef struct Image {
    uint8_t pixels[HEIGHT][WIDTH];
} Image;

// Function to flip the image horizontally
void flip_horizontally(Image *image) {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH / 2; j++) {
            uint8_t temp = image->pixels[i][j];
            image->pixels[i][j] = image->pixels[i][WIDTH - j - 1];
            image->pixels[i][WIDTH - j - 1] = temp;
        }
    }
}

// Function to adjust the brightness of the image
void adjust_brightness(Image *image, int brightness) {
    // Check the input range
    if (brightness < -255 || brightness > 255) {
        printf("Invalid brightness value\n");
        return;
    }
    // Update the pixel values
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            int new_pixel_value = image->pixels[i][j] + brightness;
            // Clamp the pixel value to the range [0, MAX_PIXEL_VALUE]
            if (new_pixel_value < 0) {
                new_pixel_value = 0;
            } else if (new_pixel_value > MAX_PIXEL_VALUE) {
                new_pixel_value = MAX_PIXEL_VALUE;
            }
            image->pixels[i][j] = new_pixel_value;
        }
    }
}

// Function to adjust the contrast of the image
void adjust_contrast(Image *image, double contrast) {
    // Check the input range
    if (contrast < 0) {
        printf("Invalid contrast value\n");
        return;
    }
    // Update the pixel values
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            int new_pixel_value = round((contrast * (image->pixels[i][j] - MAX_PIXEL_VALUE / 2)) + MAX_PIXEL_VALUE / 2);
            // Clamp the pixel value to the range [0, MAX_PIXEL_VALUE]
            if (new_pixel_value < 0) {
                new_pixel_value = 0;
            } else if (new_pixel_value > MAX_PIXEL_VALUE) {
                new_pixel_value = MAX_PIXEL_VALUE;
            }
            image->pixels[i][j] = new_pixel_value;
        }
    }
}

int main() {
    // Create the image
    Image image;
    // Initialize the image pixels
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            image.pixels[i][j] = i % (MAX_PIXEL_VALUE + 1);
        }
    }
    // Flip the image horizontally
    flip_horizontally(&image);
    // Adjust the brightness by 50
    adjust_brightness(&image, 50);
    // Adjust the contrast by 1.5
    adjust_contrast(&image, 1.5);
    // Print the first 10 rows of the image
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < WIDTH; j++) {
            printf("%3d", image.pixels[i][j]);
        }
        printf("\n");
    }
    return 0;
}