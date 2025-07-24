//FormAI DATASET v1.0 Category: Image Editor ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the size of the image
#define WIDTH 10
#define HEIGHT 10

// Define the maximum pixel value
#define MAX_PIXEL_VALUE 255

// Define the image data type
typedef struct {
    int pixels[WIDTH][HEIGHT];
} Image;

// Function to generate a random image
Image generateRandomImage() {
    Image image;

    // Loop through each pixel in the image
    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            // Assign a random pixel value
            image.pixels[i][j] = rand() % (MAX_PIXEL_VALUE + 1);
        }
    }

    return image;
}

// Function to invert the colors of an image
void invertColors(Image *image) {
    // Loop through each pixel in the image
    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            // Invert the pixel value
            image->pixels[i][j] = MAX_PIXEL_VALUE - image->pixels[i][j];
        }
    }
}

// Function to flip an image horizontally
void flipHorizontal(Image *image) {
    // Loop through each row of pixels in the image
    for (int i = 0; i < HEIGHT; i++) {
        // Loop through half of the pixels in the row
        for (int j = 0; j < WIDTH / 2; j++) {
            // Swap the pixels on opposite sides of the row
            int temp = image->pixels[j][i];
            image->pixels[j][i] = image->pixels[WIDTH - 1 - j][i];
            image->pixels[WIDTH - 1 - j][i] = temp;
        }
    }
}

int main() {
    // Generate a random image
    Image image = generateRandomImage();

    // Invert the colors
    invertColors(&image);

    // Flip the image horizontally
    flipHorizontal(&image);

    // Print the final image
    printf("Final Image:\n");
    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            printf("%d ", image.pixels[i][j]);
        }
        printf("\n");
    }

    return 0;
}