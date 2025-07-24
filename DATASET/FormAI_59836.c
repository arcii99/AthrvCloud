//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: systematic
#include <stdio.h>

// Function declarations
void flipImageHorizontally(unsigned char img[], int width, int height);
void flipImageVertically(unsigned char img[], int width, int height);
void adjustBrightnessContrast(unsigned char img[], int width, int height, int brightness, float contrast);

int main() {
    // Read image data from file
    FILE *file = fopen("image.bin", "rb");
    if(!file) {
        printf("Error: Unable to open file");
        return 1;
    }
    int width = 640;
    int height = 480;
    unsigned char img[width * height];
    fread(img, 1, width * height, file);
    fclose(file);

    // Flip image horizontally
    flipImageHorizontally(img, width, height);

    // Flip image vertically
    flipImageVertically(img, width, height);

    // Adjust brightness and contrast
    int brightness = 50;
    float contrast = 1.5;
    adjustBrightnessContrast(img, width, height, brightness, contrast);

    // Write processed image data to file
    FILE *outFile = fopen("output.bin", "wb");
    if(!outFile) {
        printf("Error: Unable to write to file");
        return 1;
    }
    fwrite(img, 1, width * height, outFile);
    fclose(outFile);

    return 0;
}

/**
 * Flips the image horizontally
 */
void flipImageHorizontally(unsigned char img[], int width, int height) {
    for(int row = 0; row < height; row++) {
        for(int col = 0; col < width/2; col++) {
            int index1 = row * width + col;
            int index2 = row * width + (width - 1 - col);
            unsigned char temp = img[index1];
            img[index1] = img[index2];
            img[index2] = temp;
        }
    }
}

/**
 * Flips the image vertically
 */
void flipImageVertically(unsigned char img[], int width, int height) {
    for(int row = 0; row < height/2; row++) {
        for(int col = 0; col < width; col++) {
            int index1 = row * width + col;
            int index2 = (height - 1 - row) * width + col;
            unsigned char temp = img[index1];
            img[index1] = img[index2];
            img[index2] = temp;
        }
    }
}

/**
 * Adjusts the brightness and contrast of the image
 */
void adjustBrightnessContrast(unsigned char img[], int width, int height, int brightness, float contrast) {
    float factor = (259.0 * (contrast + 255.0)) / (255.0 * (259.0 - contrast));
    for(int i = 0; i < width * height; i++) {
        int val = ((int) img[i]) * factor - 128.0 * factor + brightness;
        img[i] = val < 0 ? 0 : val > 255 ? 255 : (unsigned char) val;
    }
}