//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>

#define WIDTH 512
#define HEIGHT 512

void flipImage(unsigned char image[][WIDTH], unsigned char flippedImage[][WIDTH]) {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            flippedImage[i][j] = image[HEIGHT-i-1][j];
        }
    }
}

void adjustBrightness(unsigned char image[][WIDTH], unsigned char brightenedImage[][WIDTH], int brightness) {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            int pixel = image[i][j] + brightness;
            brightenedImage[i][j] = (pixel < 0) ? 0 : (pixel > 255) ? 255 : pixel;
        }
    }
}

void adjustContrast(unsigned char image[][WIDTH], unsigned char contrastedImage[][WIDTH], float contrast) {
    float factor = (259 * (contrast + 255)) / (255 * (259 - contrast));
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            int pixel = factor * (image[i][j] - 128) + 128;
            contrastedImage[i][j] = (pixel < 0) ? 0 : (pixel > 255) ? 255 : pixel;
        }
    }
}

int main() {
    unsigned char image[HEIGHT][WIDTH];
    unsigned char flippedImage[HEIGHT][WIDTH];
    unsigned char brightenedImage[HEIGHT][WIDTH];
    unsigned char contrastedImage[HEIGHT][WIDTH];
    
    // load image data from file or generate random image data
    // for simplicity, let's just generate random data
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            image[i][j] = rand() % 256;
        }
    }
    
    // flip image
    flipImage(image, flippedImage);
    
    // adjust brightness
    int brightness = 50;
    adjustBrightness(image, brightenedImage, brightness);
    
    // adjust contrast
    float contrast = 0.5;
    adjustContrast(image, contrastedImage, contrast);
    
    // print original image
    printf("Original Image:\n");
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            printf("%3d ", image[i][j]);
        }
        printf("\n");
    }
    
    // print flipped image
    printf("Flipped Image:\n");
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            printf("%3d ", flippedImage[i][j]);
        }
        printf("\n");
    }
    
    // print brightened image
    printf("Brightened Image (Brightness = %d):\n", brightness);
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            printf("%3d ", brightenedImage[i][j]);
        }
        printf("\n");
    }
    
    // print contrasted image
    printf("Contrasted Image (Contrast = %.2f):\n", contrast);
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            printf("%3d ", contrastedImage[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}