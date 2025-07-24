//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WIDTH 512
#define HEIGHT 512

unsigned char inputImage[WIDTH][HEIGHT];
unsigned char outputImage[WIDTH][HEIGHT];
unsigned char hist[256] = {0};

void loadImage(const char* filename) {
    FILE* fp;
    if ((fp = fopen(filename, "rb")) == NULL) {
        printf("Error opening input image\n");
        exit(1);
    }
    fread(inputImage, sizeof(unsigned char), WIDTH * HEIGHT, fp);
    fclose(fp);
}

void saveImage(const char* filename) {
    FILE* fp;
    if ((fp = fopen(filename, "wb")) == NULL) {
        printf("Error opening output image\n");
        exit(1);
    }
    fwrite(outputImage, sizeof(unsigned char), WIDTH * HEIGHT, fp);
    fclose(fp);
}

void flipHorizontally() {
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            outputImage[x][y] = inputImage[WIDTH - x - 1][y];    
        }
    }
}

void flipVertically() {
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            outputImage[x][y] = inputImage[x][HEIGHT - y - 1];    
        }
    }
}

void adjustBrightness(int level) {
    int pixel;
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            pixel = inputImage[x][y] + level;
            if (pixel < 0) {
                pixel = 0;
            } else if (pixel > 255) {
                pixel = 255;
            }
            outputImage[x][y] = pixel;
        }
    }
}

void adjustContrast(float strength) {
    float factor = (259.0 * (strength + 255.0)) / (255.0 * (259.0 - strength));
    int pixel;
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            pixel = factor * (inputImage[x][y] - 128) + 128;
            if (pixel < 0) {
                pixel = 0;
            } else if (pixel > 255) {
                pixel = 255;
            }
            outputImage[x][y] = pixel;
        }
    }
}

void computeHistogram() {
    for (int i = 0; i < 256; i++) {
        hist[i] = 0;
    }
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            hist[inputImage[x][y]]++;
        }
    }
}

void printHistogram() {
    printf("Histogram:\n");
    for (int i = 0; i < 256; i++) {
        printf("%d: %d\n", i, hist[i]);
    }
}

int main() {
    // Load input image
    loadImage("input.raw");
    printf("Input image loaded\n");

    // Flip horizontally
    flipHorizontally();
    saveImage("horizontal_flip.raw");
    printf("Horizontal flip done\n");

    // Flip vertically
    flipVertically();
    saveImage("vertical_flip.raw");
    printf("Vertical flip done\n");

    // Adjust brightness
    adjustBrightness(50);
    saveImage("brightness_50.raw");
    printf("Brightness +50 done\n");
    
    // Adjust contrast
    adjustContrast(50.0);
    saveImage("contrast_50.raw");
    printf("Contrast +50 done\n");
    
    // Compute histogram
    computeHistogram();
    printHistogram();
    
    return 0;
}