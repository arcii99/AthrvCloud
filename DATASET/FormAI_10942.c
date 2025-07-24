//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: irregular
#include <stdio.h>

int main(void) {

    // Image dimensions
    int height = 256;
    int width = 256;

    // Read input image
    unsigned char image[height][width];
    FILE *in_file = fopen("input_image.raw", "rb");
    fread(image, sizeof(unsigned char), height*width, in_file);
    fclose(in_file);

    // Flip the image horizontally
    for (int row = 0; row < height; row++) {
        for (int col = 0; col < width/2; col++) {
            unsigned char temp   = image[row][col];
            image[row][col]      = image[row][width-col-1];
            image[row][width-col-1] = temp;
        }
    }

    // Increase image brightness
    float brightness_factor = 1.2;
    for (int row = 0; row < height; row++) {
        for (int col = 0; col < width; col++) {
            unsigned char new_pixel = (unsigned char)(image[row][col] * brightness_factor);
            if (new_pixel > 255) {
                new_pixel = 255;
            }
            image[row][col] = new_pixel;
        }
    }

    // Decrease image contrast
    float contrast_factor = 0.8;
    float avg_intensity = 0;
    for (int row = 0; row < height; row++) {
        for (int col = 0; col < width; col++) {
            avg_intensity += image[row][col] / (float)(height * width);
        }
    }
    for (int row = 0; row < height; row++) {
        for (int col = 0; col < width; col++) {
            float pixel_intensity = image[row][col] / 255.0f;
            float new_pixel_intensity = (pixel_intensity - avg_intensity) * contrast_factor + avg_intensity;
            unsigned char new_pixel = (unsigned char)(new_pixel_intensity * 255);
            if (new_pixel > 255) {
                new_pixel = 255;
            } else if (new_pixel < 0) {
                new_pixel = 0;
            }
            image[row][col] = new_pixel;
        }
    }

    // Write output image
    FILE *out_file = fopen("output_image.raw", "wb");
    fwrite(image, sizeof(unsigned char), height*width, out_file);
    fflush(out_file);
    fclose(out_file);

    return 0;
}