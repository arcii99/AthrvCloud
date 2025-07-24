//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>

// Function to flip an image horizontally
void flip_horizontal(int *image, int width, int height) {
    int row_len = width * 3;
    int temp[row_len];
    for(int i = 0; i < height; i++) {
        for(int j = 0; j < row_len / 2; j += 3) {
            // Swap each pixel with its respective opposite pixel
            temp[j] = image[i * row_len + row_len - j - 3];
            temp[j+1] = image[i * row_len + row_len - j - 2];
            temp[j+2] = image[i * row_len + row_len - j - 1];
            image[i * row_len + row_len - j - 1] = temp[j];
            image[i * row_len + row_len - j - 2] = temp[j+1];
            image[i * row_len + row_len - j - 3] = temp[j+2];
        }
    }
}

// Function to adjust the brightness/contrast of an image
void adjust_brightness_contrast(int *image, int width, int height, int brightness, int contrast) {
    for(int i = 0; i < width * height * 3; i++) {
        // Adjust the brightness of each pixel
        image[i] += brightness;

        // Adjust the contrast of each pixel
        int pixel = image[i] - 128;
        pixel = pixel * contrast / 128;
        pixel += 128;
        if(pixel < 0) pixel = 0;
        if(pixel > 255) pixel = 255;
        image[i] = pixel;
    }
}

int main() {
    FILE *input = fopen("input.ppm", "r");
    FILE *output = fopen("output.ppm", "w");

    // Read the image header
    char header[3];
    int width, height, max_color;
    fscanf(input, "%s\n%d %d\n%d\n", header, &width, &height, &max_color);

    // Allocate memory for the image array
    int *image = (int*)malloc(width * height * 3 * sizeof(int));

    // Read the image data into the array
    for(int i = 0; i < width * height * 3; i++) {
        fscanf(input, "%d", &image[i]);
    }

    // Flip the image horizontally
    flip_horizontal(image, width, height);

    // Adjust the brightness and contrast of the image
    adjust_brightness_contrast(image, width, height, 50, 128);

    // Write the modified image data to the output file
    fprintf(output, "%s\n%d %d\n%d\n", header, width, height, max_color);
    for(int i = 0; i < width * height * 3; i++) {
        fprintf(output, "%d ", image[i]);
    }

    free(image);
    fclose(input);
    fclose(output);

    return 0;
}