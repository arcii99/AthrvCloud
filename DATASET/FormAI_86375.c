//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

#define BRIGHTNESS_FACTOR 30 // default brightness factor
#define CONTRAST_FACTOR 0.5 // default contrast factor

typedef struct Image {
    int width; // image width
    int height; // image height
    int bitsPerPixel; // number of bits per pixel
    unsigned char *data; // image data
} Image;

// Function to initialize image structure
void initImage(Image *img, int width, int height, int bpp) {
    img->width = width;
    img->height = height;
    img->bitsPerPixel = bpp;
    img->data = (unsigned char*) malloc(width * height * bpp);
}

// Function to free image data
void destroyImage(Image *img) {
    if (img) {
        free(img->data);
        free(img);
    }
}

// Function to flip image horizontally
void flipHorizontally(Image *img) {
    int rowSize = img->width * img->bitsPerPixel / 8;
    unsigned char *row = (unsigned char*) calloc(rowSize, 1);

    for (int i = 0; i < img->height; i++) {
        unsigned char *start = img->data + i * rowSize;
        unsigned char *end = start + rowSize - 1;

        for (int j = 0; j < rowSize / 2; j++) {
            unsigned char temp = start[j];
            start[j] = end[-j];
            end[-j] = temp;
        }
    }

    free(row);
}

// Function to adjust brightness of image
void adjustBrightness(Image *img, int factor) {
    int size = img->width * img->height * img->bitsPerPixel / 8;

    for (int i = 0; i < size; i++) {
        int newValue = img->data[i] + factor;

        if (newValue > 255) {
            newValue = 255;
        } else if (newValue < 0) {
            newValue = 0;
        }

        img->data[i] = newValue;
    }
}

// Function to adjust contrast of image
void adjustContrast(Image *img, float factor) {
    int size = img->width * img->height * img->bitsPerPixel / 8;
    unsigned char *lut = (unsigned char*) malloc(sizeof(unsigned char) * 256);

    for (int i = 0; i < 256; i++) {
        int newValue = (float) i * factor;

        if (newValue > 255) {
            newValue = 255;
        } else if (newValue < 0) {
            newValue = 0;
        }

        lut[i] = newValue;
    }

    for (int i = 0; i < size; i++) {
        img->data[i] = lut[img->data[i]];
    }

    free(lut);
}

// Function to load image from file
Image *loadImage(char *filename) {
    FILE *file = fopen(filename, "rb");

    if (!file) {
        printf("Error: cannot open file %s\n", filename);
        return NULL;
    }

    unsigned char header[54];

    if (fread(header, sizeof(unsigned char), 54, file) != 54) {
        printf("Error: invalid file format %s\n", filename);
        fclose(file);
        return NULL;
    }

    int width = *(int*)(header + 18);
    int height = *(int*)(header + 22);
    int bpp = *(int*)(header + 28);

    if (bpp != 24) {
        printf("Error: invalid file format %s (bpp=%d)\n", filename, bpp);
        fclose(file);
        return NULL;
    }

    Image *img = (Image*) malloc(sizeof(Image));
    initImage(img, width, height, bpp);

    int rowSize = img->width * img->bitsPerPixel / 8;
    unsigned char *row = (unsigned char*) calloc(rowSize, 1);

    for (int i = 0; i < img->height; i++) {
        if (fread(row, sizeof(unsigned char), rowSize, file) != rowSize) {
            printf("Error: invalid file format %s\n", filename);
            fclose(file);
            destroyImage(img);
            return NULL;
        }

        memcpy(img->data + i * rowSize, row, rowSize);
    }

    fclose(file);
    free(row);

    return img;
}

// Function to save image to file
int saveImage(char *filename, Image *img) {
    FILE *file = fopen(filename, "wb");

    if (!file) {
        printf("Error: cannot open file %s\n", filename);
        return -1;
    }

    unsigned char header[54] = {
        0x42, 0x4d, 0x36, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x36, 0x00, 0x00, 0x00, 0x28, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x36, 0x00,
        0x00, 0x00, 0x12, 0x0b, 0x00, 0x00, 0x12, 0x0b,
        0x00, 0x00, 0x01, 0x00, 0x18, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00
    };

    int rowSize = img->width * img->bitsPerPixel / 8;
    int dataSize = img->height * rowSize;
    int fileSize = dataSize + 54;

    *(int*)(header + 2) = fileSize;
    *(int*)(header + 18) = img->width;
    *(int*)(header + 22) = img->height;
    *(int*)(header + 28) = img->bitsPerPixel;

    fwrite(header, sizeof(unsigned char), 54, file);
    fwrite(img->data, sizeof(unsigned char), dataSize, file);

    fclose(file);

    return 0;
}

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Usage: %s <input_file>\n", argv[0]);
        return -1;
    }

    char *filename = argv[1];
    Image *img = loadImage(filename);

    if (!img) {
        printf("Error: cannot load image\n");
        return -1;
    }

    // flip image horizontally
    flipHorizontally(img);

    // adjust brightness of image
    adjustBrightness(img, BRIGHTNESS_FACTOR);

    // adjust contrast of image
    adjustContrast(img, CONTRAST_FACTOR);

    // save image to file
    char *outputFilename = "output.bmp";

    if (saveImage(outputFilename, img) != 0) {
        printf("Error: cannot save image to file %s\n", outputFilename);
        return -1;
    }

    printf("Image successfully processed and saved to %s\n", outputFilename);

    // free image data
    destroyImage(img);

    return 0;
}