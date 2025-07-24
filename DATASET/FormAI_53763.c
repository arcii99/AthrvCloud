//FormAI DATASET v1.0 Category: Image Editor ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_FILENAME_LENGTH 100
#define IMAGE_WIDTH 800
#define IMAGE_HEIGHT 600

// Define the image struct
typedef struct Image {
    char filename[MAX_FILENAME_LENGTH];
    int width;
    int height;
    unsigned char* pixels;
} Image;

// Function to create a new image
Image* createImage(char* filename, int width, int height) {
    Image* img = (Image*) malloc(sizeof(Image));
    if (img == NULL) {
        printf("Error: Failed to allocate memory for new image.\n");
        return NULL;
    }

    strcpy(img->filename, filename);
    img->width = width;
    img->height = height;
    img->pixels = (unsigned char*) calloc(width * height * 3, sizeof(unsigned char));
    if (img->pixels == NULL) {
        printf("Error: Failed to allocate memory for image pixels.\n");
        free(img);
        return NULL;
    }

    return img;
}

// Function to load an existing image from a file
Image* loadImage(char* filename) {
    FILE* f = fopen(filename, "rb");
    if (f == NULL) {
        printf("Error: Failed to open image file \"%s\".\n", filename);
        return NULL;
    }

    unsigned char header[54];
    if (fread(header, sizeof(unsigned char), 54, f) != 54) {
        printf("Error: Failed to read image header.\n");
        fclose(f);
        return NULL;
    }

    // Get image dimensions from header
    int width = *(int*)&header[18];
    int height = *(int*)&header[22];

    // Allocate memory for image
    Image* img = createImage(filename, width, height);
    if (img == NULL) {
        fclose(f);
        return NULL;
    }

    // Read in pixel data
    unsigned char* pixels = img->pixels;
    int numBytes = img->width * img->height * 3;
    if (fread(pixels, sizeof(unsigned char), numBytes, f) != numBytes) {
        printf("Error: Failed to read image pixels.\n");
        free(img->pixels);
        free(img);
        fclose(f);
        return NULL;
    }

    fclose(f);
    return img;
}

// Function to save an image to a file
bool saveImage(Image* img) {
    FILE* f = fopen(img->filename, "wb");
    if (f == NULL) {
        printf("Error: Failed to open file \"%s\" for writing.\n", img->filename);
        return false;
    }

    // Image header
    unsigned char header[54] = {
        'B','M',  // Signature
        0,0,0,0,  // File size
        0,0,0,0,  // Reserved
        54,0,0,0, // Offset to pixel data
        40,0,0,0, // Size of info header
        0,0,0,0,  // Image width
        0,0,0,0,  // Image height
        1,0,      // Number of color planes
        24,0,     // Number of bits per pixel
        0,0,0,0,  // Compression type
        0,0,0,0,  // Size of image data
        0,0,0,0,  // Horizontal resolution
        0,0,0,0,  // Vertical resolution
        0,0,0,0,  // Number of colors in palette
        0,0,0,0   // Number of important colors
    };

    // File size
    int fileSize = 54 + (img->width * img->height * 3);
    header[2] = (unsigned char)(fileSize);
    header[3] = (unsigned char)(fileSize >> 8);
    header[4] = (unsigned char)(fileSize >> 16);
    header[5] = (unsigned char)(fileSize >> 24);

    // Image width
    header[18] = (unsigned char)(img->width);
    header[19] = (unsigned char)(img->width >> 8);
    header[20] = (unsigned char)(img->width >> 16);
    header[21] = (unsigned char)(img->width >> 24);

    // Image height
    header[22] = (unsigned char)(img->height);
    header[23] = (unsigned char)(img->height >> 8);
    header[24] = (unsigned char)(img->height >> 16);
    header[25] = (unsigned char)(img->height >> 24);

    fwrite(header, sizeof(unsigned char), 54, f);
    fwrite(img->pixels, sizeof(unsigned char), img->width * img->height * 3, f);
    fclose(f);

    return true;
}

// Function to free an image's allocated memory
void freeImage(Image* img) {
    if (img != NULL) {
        if (img->pixels != NULL) {
            free(img->pixels);
        }
        free(img);
    }
}

// Function to copy an image
Image* copyImage(Image* img) {
    Image* copy = createImage(img->filename, img->width, img->height);
    if (copy == NULL) {
        return NULL;
    }
    memcpy(copy->pixels, img->pixels, img->width * img->height * 3 * sizeof(unsigned char));
    return copy;
}

// Function to flip an image horizontally
void flipImageHorizontally(Image* img) {
    int rowSize = img->width * 3;
    unsigned char* row = (unsigned char*) malloc(rowSize * sizeof(unsigned char));
    if (row == NULL) {
        printf("Error: Failed to allocate memory for row buffer.\n");
        return;
    }
    for (int y = 0; y < img->height; y++) {
        int offset = y * rowSize;
        memcpy(row, &(img->pixels[offset]), rowSize);
        for (int x = 0; x < img->width; x++) {
            img->pixels[offset + (x * 3)] = row[(rowSize - 3) - (x * 3)];
            img->pixels[offset + (x * 3) + 1] = row[(rowSize - 3) - (x * 3) + 1];
            img->pixels[offset + (x * 3) + 2] = row[(rowSize - 3) - (x * 3) + 2];
        }
    }
    free(row);
}

// Function to flip an image vertically
void flipImageVertically(Image* img) {
    int rowSize = img->width * 3;
    unsigned char* row1 = (unsigned char*) malloc(rowSize * sizeof(unsigned char));
    if (row1 == NULL) {
        printf("Error: Failed to allocate memory for row1 buffer.\n");
        return;
    }
    unsigned char* row2 = (unsigned char*) malloc(rowSize * sizeof(unsigned char));
    if (row2 == NULL) {
        printf("Error: Failed to allocate memory for row2 buffer.\n");
        free(row1);
        return;
    }
    for (int y = 0; y < img->height / 2; y++) {
        int offset1 = y * rowSize;
        int offset2 = (img->height - 1 - y) * rowSize;
        memcpy(row1, &(img->pixels[offset1]), rowSize);
        memcpy(row2, &(img->pixels[offset2]), rowSize);
        memcpy(&(img->pixels[offset1]), row2, rowSize);
        memcpy(&(img->pixels[offset2]), row1, rowSize);
    }
    free(row1);
    free(row2);
}

// Function to invert the colors of an image
void invertImageColors(Image* img) {
    for (int i = 0; i < img->width * img->height * 3; i++) {
        img->pixels[i] = 255 - img->pixels[i];
    }
}

// Main function
int main() {
    // Create a new image
    Image* img = createImage("test.bmp", IMAGE_WIDTH, IMAGE_HEIGHT);
    if (img == NULL) {
        printf("Error: Failed to create new image.\n");
        return 1;
    }

    // Fill image with random colors
    for (int i = 0; i < IMAGE_WIDTH * IMAGE_HEIGHT * 3; i++) {
        img->pixels[i] = rand() % 256;
    }

    // Save image to file
    if (!saveImage(img)) {
        printf("Error: Failed to save image to file.\n");
        return 1;
    }

    // Load image from file
    Image* loadedImg = loadImage("test.bmp");
    if (loadedImg == NULL) {
        printf("Error: Failed to load image from file.\n");
        freeImage(img);
        return 1;
    }

    // Flip image horizontally
    flipImageHorizontally(loadedImg);

    // Invert image colors
    invertImageColors(loadedImg);

    // Save modified image to file
    if (!saveImage(loadedImg)) {
        printf("Error: Failed to save modified image to file.\n");
        freeImage(img);
        freeImage(loadedImg);
        return 1;
    }

    // Clean up memory
    freeImage(img);
    freeImage(loadedImg);

    return 0;
}