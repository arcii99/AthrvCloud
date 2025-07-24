//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: modular
#include <stdio.h>
#include <stdlib.h>

// Function to flip the image horizontally
void horizontal_flip(int *image_data, int width, int height) {
    // Loop through each row of the image
    for (int i = 0; i < height; i++) {
        // Loop through half of the columns of the image
        for (int j = 0; j < width / 2; j++) {
            // Swap the current pixel with its corresponding pixel on the other side of the image
            int temp = *(image_data + i * width + j);
            *(image_data + i * width + j) = *(image_data + i * width + (width - 1 - j));
            *(image_data + i * width + (width - 1 - j)) = temp;
        }
    }
}

// Function to adjust the brightness of the image
void adjust_brightness(int *image_data, int width, int height, int adjustment) {
    // Loop through each pixel in the image
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            // Add the brightness adjustment value to each color channel of the pixel
            *(image_data + i * width + j) += adjustment;
            // Ensure that each color channel stays within the range [0, 255]
            if (*(image_data + i * width + j) < 0) {
                *(image_data + i * width + j) = 0;
            } else if (*(image_data + i * width + j) > 255) {
                *(image_data + i * width + j) = 255;
            }
        }
    }
}

// Function to adjust the contrast of the image
void adjust_contrast(int *image_data, int width, int height, int adjustment) {
    // Calculate the factor by which to multiply each pixel
    float factor = (259.0 * (adjustment + 255.0)) / (255.0 * (259.0 - adjustment));
    // Loop through each pixel in the image
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            // Multiply each color channel of the pixel by the contrast adjustment factor
            *(image_data + i * width + j) = factor * (*(image_data + i * width + j) - 128) + 128;
            // Ensure that each color channel stays within the range [0, 255]
            if (*(image_data + i * width + j) < 0) {
                *(image_data + i * width + j) = 0;
            } else if (*(image_data + i * width + j) > 255) {
                *(image_data + i * width + j) = 255;
            }
        }
    }
}

int main() {
    // Initialize an example image with a 4x4 checkerboard pattern
    int image_data[4][4][3] = {{{255, 255, 255}, {0, 0, 0}, {255, 255, 255}, {0, 0, 0}},
                                {{0, 0, 0}, {255, 255, 255}, {0, 0, 0}, {255, 255, 255}},
                                {{255, 255, 255}, {0, 0, 0}, {255, 255, 255}, {0, 0, 0}},
                                {{0, 0, 0}, {255, 255, 255}, {0, 0, 0}, {255, 255, 255}}};
    int width = 4;
    int height = 4;
    
    // Print the original image
    printf("Original Image:\n");
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf("(%d, %d, %d) ", image_data[i][j][0], image_data[i][j][1], image_data[i][j][2]);
        }
        printf("\n");
    }
    
    // Flip the image horizontally
    horizontal_flip((int *)image_data, width, height);
    
    // Print the horizontally flipped image
    printf("\nHorizontally Flipped Image:\n");
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf("(%d, %d, %d) ", image_data[i][j][0], image_data[i][j][1], image_data[i][j][2]);
        }
        printf("\n");
    }
    
    // Adjust the brightness of the image
    adjust_brightness((int *)image_data, width, height, 50);
    
    // Print the brightness-adjusted image
    printf("\nBrightness-Adjusted Image:\n");
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf("(%d, %d, %d) ", image_data[i][j][0], image_data[i][j][1], image_data[i][j][2]);
        }
        printf("\n");
    }
    
    // Adjust the contrast of the image
    adjust_contrast((int *)image_data, width, height, 50);
    
    // Print the contrast-adjusted image
    printf("\nContrast-Adjusted Image:\n");
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf("(%d, %d, %d) ", image_data[i][j][0], image_data[i][j][1], image_data[i][j][2]);
        }
        printf("\n");
    }
    
    return 0;
}