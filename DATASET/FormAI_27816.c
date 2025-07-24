//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: configurable
#include <stdio.h>

// Define constants for maximum image size and pixel intensity
#define MAX_WIDTH 512
#define MAX_HEIGHT 512
#define MAX_INTENSITY 255

// Define a struct to represent an image
typedef struct {
    int width;
    int height;
    int pixels[MAX_WIDTH][MAX_HEIGHT];
} Image;

// Function to flip an image horizontally
void flip_horizontal(Image *image) {
    int i, j;
    int temp;

    for (i = 0; i < image->height; ++i) {
        for (j = 0; j < image->width / 2; ++j) {
            // Swap pixels across the vertical axis
            temp = image->pixels[i][j];
            image->pixels[i][j] = image->pixels[i][image->width - j - 1];
            image->pixels[i][image->width - j - 1] = temp;
        }
    }
}

// Function to adjust the brightness of an image
void brightness(Image *image, int adjust) {
    int i, j;

    for (i = 0; i < image->height; ++i) {
        for (j = 0; j < image->width; ++j) {
            // Apply the brightness adjustment to each pixel
            image->pixels[i][j] += adjust;

            // Clamp pixel intensity to the valid range
            if (image->pixels[i][j] < 0) {
                image->pixels[i][j] = 0;
            } else if (image->pixels[i][j] > MAX_INTENSITY) {
                image->pixels[i][j] = MAX_INTENSITY;
            }
        }
    }
}

// Function to adjust the contrast of an image
void contrast(Image *image, float adjust) {
    int i, j;
    float contrast_factor = (adjust + 1.0) / 2.0;
    int mean_intensity;
    float scale;

    for (i = 0; i < image->height; ++i) {
        for (j = 0; j < image->width; ++j) {
            // Compute the mean intensity of the pixel
            mean_intensity = (image->pixels[i][j] + image->pixels[i][j+1] + image->pixels[i+1][j] + image->pixels[i+1][j+1]) / 4;

            // Scale the pixel intensity using the contrast factor and mean intensity
            scale = (float)(image->pixels[i][j] - mean_intensity) * contrast_factor + mean_intensity;
            image->pixels[i][j] = (int)(scale + 0.5);

            // Clamp pixel intensity to the valid range
            if (image->pixels[i][j] < 0) {
                image->pixels[i][j] = 0;
            } else if (image->pixels[i][j] > MAX_INTENSITY) {
                image->pixels[i][j] = MAX_INTENSITY;
            }
        }
    }
}

int main() {
    int i, j;

    // Create a new image with some initial values
    Image image = {
        .width = 4,
        .height = 4,
        .pixels = {
            { 0,  64, 128, 192},
            { 32, 96, 160, 224},
            { 64, 128, 192, 255},
            { 96, 160, 224, 32}
        }
    };

    // Print the initial image
    printf("Initial Image:\n");
    for (i = 0; i < image.height; ++i) {
        for (j = 0; j < image.width; ++j) {
            printf("%3d ", image.pixels[i][j]);
        }
        printf("\n");
    }

    // Flip the image horizontally
    flip_horizontal(&image);

    // Print the flipped image
    printf("Flipped Image:\n");
    for (i = 0; i < image.height; ++i) {
        for (j = 0; j < image.width; ++j) {
            printf("%3d ", image.pixels[i][j]);
        }
        printf("\n");
    }

    // Adjust the brightness of the image by -30
    brightness(&image, -30);

    // Print the adjusted image
    printf("Brightness Adjusted Image (-30):\n");
    for (i = 0; i < image.height; ++i) {
        for (j = 0; j < image.width; ++j) {
            printf("%3d ", image.pixels[i][j]);
        }
        printf("\n");
    }

    // Adjust the contrast of the image by 0.5
    contrast(&image, 0.5);

    // Print the adjusted image
    printf("Contrast Adjusted Image (0.5):\n");
    for (i = 0; i < image.height; ++i) {
        for (j = 0; j < image.width; ++j) {
            printf("%3d ", image.pixels[i][j]);
        }
        printf("\n");
    }

    return 0;
}