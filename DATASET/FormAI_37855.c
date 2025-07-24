//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: lively
#include <stdio.h>

// Function to convert the pixel value to ASCII character
char pixel_to_ascii(int pixel) {
    // ASCII characters used from darkest to lightest
    const char ascii_vals[] = " .:-=+*#%@";
    int intensity_levels = sizeof(ascii_vals) - 1;
    // Scale pixel value to intensity level range.
    int intensity = (int)((float)pixel / 255 * intensity_levels);
    // Return character corresponding to intensity level.
    return ascii_vals[intensity]; 
}

int main() {
    // Load the image from file
    FILE *image_file = fopen("my_image.jpg", "rb");
    if (!image_file) { 
        printf("Error: failed to open file\n");
        return -1;
    }
    // Use image processing library to read JPEG format
    // (not shown here to simplify example)
    int width = 640, height = 480;
    int *pixels = malloc(width * height * sizeof(int));
    // process pixels in image, and store them to *pixels
    // ...
    // Convert image to ASCII art
    printf("\n");
    for (int h = 0; h < height; h++) {
        for (int w = 0; w < width; w++) {
            // Get the pixel value from the array of pixels
            int pixel = pixels[h * width + w];
            // Convert the pixel to an ASCII character
            char ascii = pixel_to_ascii(pixel);
            // Output the ASCII character to the console
            printf("%c", ascii);
        }
        printf("\n");
    }
    // Free memory used by the pixel array
    free(pixels);
    return 0;
}