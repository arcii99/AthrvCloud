//FormAI DATASET v1.0 Category: Image Editor ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Define the struct for RGB color values
struct RGB {
    unsigned char R;
    unsigned char G;
    unsigned char B;
};

// Define a struct for the image metadata
struct Image {
    char filetype[3];   // e.g. "PNG", "JPEG", etc.
    int width, height;  // dimensions of the image
    struct RGB* pixels; // 1D array of RGB values
};

// Function prototypes
void readImage(char* filename, struct Image* img);
void writeImage(char* filename, struct Image* img);
void rotateImage(struct Image* img, int angle);
void cropImage(struct Image* img, int x, int y, int width, int height);
void filterImage(struct Image* img, int red, int green, int blue);

// Main function
int main(int argc, char** argv) {

    // Check command-line arguments
    if (argc < 3) {
        printf("Usage: %s <input_file> <output_file>\n", argv[0]);
        return 1;
    }

    // Read in the image file
    struct Image img;
    readImage(argv[1], &img);

    // Apply some image processing effects
    rotateImage(&img, 45);
    cropImage(&img, 100, 100, 200, 200);
    filterImage(&img, 0, 255, 0);

    // Save the modified image to a new file
    writeImage(argv[2], &img);

    // Free the memory used by the pixel array
    free(img.pixels);

    return 0;
}

// Read in an image file
void readImage(char* filename, struct Image* img) {

    // Open the file for reading
    FILE* infile = fopen(filename, "rb");
    if (!infile) {
        printf("Error: could not open file %s\n", filename);
        exit(1);
    }

    // Read in the image metadata
    fscanf(infile, "%2s", img->filetype); // read 2 characters
    fscanf(infile, "%d %d", &img->width, &img->height);

    // Allocate memory for the pixel array
    img->pixels = (struct RGB*)malloc(img->width * img->height * sizeof(struct RGB));

    // Read in the pixel data
    for (int i = 0; i < img->width * img->height; i++) {
        fscanf(infile, "%hhu %hhu %hhu", &img->pixels[i].R, &img->pixels[i].G, &img->pixels[i].B);
    }

    // Close the file
    fclose(infile);
}

// Write an image file
void writeImage(char* filename, struct Image* img) {

    // Open the output file for writing
    FILE* outfile = fopen(filename, "wb");
    if (!outfile) {
        printf("Error: could not open file %s\n", filename);
        exit(1);
    }

    // Write the image metadata to the file
    fprintf(outfile, "%s\n", img->filetype);
    fprintf(outfile, "%d %d\n", img->width, img->height);

    // Write the pixel data to the file
    for (int i = 0; i < img->width * img->height; i++) {
        fprintf(outfile, "%hhu %hhu %hhu ", img->pixels[i].R, img->pixels[i].G, img->pixels[i].B);
    }

    // Close the file
    fclose(outfile);
}

// Rotate an image by a given angle (in degrees)
void rotateImage(struct Image* img, int angle) {

    // Compute the sine and cosine of the angle
    double radians = angle * M_PI / 180.0;
    double cosTheta = cos(radians);
    double sinTheta = sin(radians);

    // Create a new array for the rotated pixels
    struct RGB* rotatedPixels = (struct RGB*)malloc(img->width * img->height * sizeof(struct RGB));

    // Compute the center of the image
    int centerX = img->width / 2;
    int centerY = img->height / 2;

    // Loop over each pixel in the rotated image
    for (int y = 0; y < img->height; y++) {
        for (int x = 0; x < img->width; x++) {

            // Compute the new x and y coordinates
            int xPrime = (x - centerX) * cosTheta - (y - centerY) * sinTheta + centerX;
            int yPrime = (x - centerX) * sinTheta + (y - centerY) * cosTheta + centerY;

            // Check if the pixel is within the bounds of the original image
            if (xPrime >= 0 && xPrime < img->width && yPrime >= 0 && yPrime < img->height) {

                // Copy the pixel value from the original image to the rotated image
                int srcIndex = y * img->width + x;
                int destIndex = yPrime * img->width + xPrime;
                rotatedPixels[destIndex] = img->pixels[srcIndex];
            }
        }
    }

    // Free the memory used by the old pixel array and store the new one
    free(img->pixels);
    img->pixels = rotatedPixels;
}

// Crop an image to a smaller rectangular region
void cropImage(struct Image* img, int x, int y, int width, int height) {

    // Create a new array for the cropped pixels
    struct RGB* croppedPixels = (struct RGB*)malloc(width * height * sizeof(struct RGB));

    // Copy the pixel values from the original image
    for (int j = 0; j < height; j++) {
        for (int i = 0; i < width; i++) {
            int srcIndex = (y + j) * img->width + (x + i);
            int destIndex = j * width + i;
            croppedPixels[destIndex] = img->pixels[srcIndex];
        }
    }

    // Free the memory used by the old pixel array and store the new one
    free(img->pixels);
    img->pixels = croppedPixels;
    img->width = width;
    img->height = height;
}

// Apply a color filter to an image
void filterImage(struct Image* img, int red, int green, int blue) {

    // Compute the RGB color values for the filter
    struct RGB filterColor = { red, green, blue };

    // Loop over each pixel in the image
    for (int i = 0; i < img->width * img->height; i++) {

        // Compute the new RGB value for the pixel
        struct RGB oldColor = img->pixels[i];
        struct RGB newColor = { 
            .R = oldColor.R * filterColor.R / 255,
            .G = oldColor.G * filterColor.G / 255,
            .B = oldColor.B * filterColor.B / 255
        };

        // Store the new RGB value in the pixel array
        img->pixels[i] = newColor;
    }
}