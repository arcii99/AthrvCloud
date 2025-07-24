//FormAI DATASET v1.0 Category: Image Editor ; Style: random
// A Unique C Image Editor Example Program
#include <stdio.h>
#include <stdlib.h>

// Define the size of the image
#define WIDTH 640
#define HEIGHT 480

// Define the maximum pixel value for each color channel
#define MAX_COLOR 255

// Define a struct to represent a pixel
typedef struct {
    unsigned char red;
    unsigned char green;
    unsigned char blue;
} Pixel;

int main() {
    // Allocate memory for the image data
    Pixel* image = (Pixel*)malloc(sizeof(Pixel) * WIDTH * HEIGHT);
    if (image == NULL) {
        fprintf(stderr, "Unable to allocate memory for image.\n");
        exit(1);
    }
    
    // Fill the image with a gradient
    int x, y;
    for (y = 0; y < HEIGHT; y++) {
        for (x = 0; x < WIDTH; x++) {
            float r = (float)x / (float)WIDTH;
            float g = (float)y / (float)HEIGHT;
            float b = (r + g) / 2.0f;
            
            Pixel p;
            p.red = (unsigned char)(r * MAX_COLOR);
            p.green = (unsigned char)(g * MAX_COLOR);
            p.blue = (unsigned char)(b * MAX_COLOR);
            
            image[y * WIDTH + x] = p;
        }
    }
    
    // Apply a sepia filter to the image
    for (y = 0; y < HEIGHT; y++) {
        for (x = 0; x < WIDTH; x++) {
            Pixel p = image[y * WIDTH + x];
            
            // Convert the pixel to grayscale
            unsigned char gray = (unsigned char)(0.2989 * p.red + 0.587 * p.green + 0.114 * p.blue);
            
            // Apply the sepia filter to the grayscale value
            unsigned char r = gray * 1.07;
            unsigned char g = gray * 0.74;
            unsigned char b = gray * 0.43;
            
            // Clamp the color values to the maximum value
            p.red = (r > MAX_COLOR) ? MAX_COLOR : r;
            p.green = (g > MAX_COLOR) ? MAX_COLOR : g;
            p.blue = (b > MAX_COLOR) ? MAX_COLOR : b;
            
            image[y * WIDTH + x] = p;
        }
    }
    
    // Save the image to a file
    FILE* f = fopen("output.ppm", "wb");
    if (f == NULL) {
        fprintf(stderr, "Unable to create file.\n");
        exit(1);
    }
    
    fprintf(f, "P6\n%d %d\n%d\n", WIDTH, HEIGHT, MAX_COLOR);
    fwrite(image, sizeof(Pixel), WIDTH * HEIGHT, f);
    
    fclose(f);
    free(image);
    
    return 0;
}