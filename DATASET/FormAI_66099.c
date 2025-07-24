//FormAI DATASET v1.0 Category: Image Editor ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to calculate the magnitude of a pixel
double pixel_magnitude(double r, double g, double b) {
    // Calculate the magnitude using the Euclidean distance formula
    return sqrt(pow(r, 2) + pow(g, 2) + pow(b, 2));
}

// Function to apply a Gaussian blur to an image
void gaussian_blur(unsigned char *image, int width, int height, double sigma) {
    // Create an array to store the blurred image
    unsigned char *blurred_image = malloc(width * height * 3);
    // Create a kernel for the Gaussian blur
    int kernel_size = round(sigma * 6);
    double *kernel = malloc(kernel_size * sizeof(double));
    double sum = 0;
    int i, j;
    for (i = 0; i < kernel_size; i++) {
        kernel[i] = exp(-(pow(i - kernel_size/2, 2)) / (2 * pow(sigma, 2)));
        sum += kernel[i];
    }
    for (i = 0; i < kernel_size; i++) {
        kernel[i] /= sum;
    }
    // Apply the kernel to each pixel in the image
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            double r = 0, g = 0, b = 0, w_sum = 0;
            int k, l;
            for (k = -kernel_size/2; k <= kernel_size/2; k++) {
                for (l = -kernel_size/2; l <= kernel_size/2; l++) {
                    int y = i + k, x = j + l;
                    if (y >= 0 && y < height && x >= 0 && x < width) {
                        double w = kernel[k + kernel_size/2] * kernel[l + kernel_size/2];
                        r += w * image[(y * width + x) * 3];
                        g += w * image[(y * width + x) * 3 + 1];
                        b += w * image[(y * width + x) * 3 + 2];
                        w_sum += w;
                    }
                }
            }
            blurred_image[(i * width + j) * 3] = round(r / w_sum);
            blurred_image[(i * width + j) * 3 + 1] = round(g / w_sum);
            blurred_image[(i * width + j) * 3 + 2] = round(b / w_sum);
        }
    }
    // Copy the blurred image back to the original image array
    for (i = 0; i < width * height * 3; i++) {
        image[i] = blurred_image[i];
    }
    // Free the memory for the kernel and the blurred image
    free(kernel);
    free(blurred_image);
}

int main() {
    // Open the input and output files
    FILE *input_file = fopen("input_image.raw", "rb");
    FILE *output_file = fopen("output_image.raw", "wb");
    // Read the width, height, and color depth from the input file
    int width, height, color_depth;
    fscanf(input_file, "%d %d %d\n", &width, &height, &color_depth);
    // Allocate memory for the image
    unsigned char *image = malloc(width * height * 3);
    // Read the image data from the input file
    fread(image, sizeof(unsigned char), width * height * 3, input_file);
    // Apply a Gaussian blur to the image
    gaussian_blur(image, width, height, 2.0);
    // Write the modified image data to the output file
    fprintf(output_file, "%d %d %d\n", width, height, color_depth);
    fwrite(image, sizeof(unsigned char), width * height * 3, output_file);
    // Free the memory for the image
    free(image);
    // Close the input and output files
    fclose(input_file);
    fclose(output_file);
    return 0;
}