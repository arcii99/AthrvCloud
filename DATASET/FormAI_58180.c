//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: real-life
#include <stdio.h>
#include <stdint.h>

/* Image dimensions */
#define IMAGE_HEIGHT 480
#define IMAGE_WIDTH 640

/* Pixel storage for image */
uint8_t image[IMAGE_HEIGHT][IMAGE_WIDTH];

/* Function to flip image horizontally */
void flipImageHorizontally(uint8_t img[IMAGE_HEIGHT][IMAGE_WIDTH]) {
    uint8_t temp;
    for(int i=0; i<IMAGE_HEIGHT; i++) {
        for(int j=0; j<IMAGE_WIDTH/2; j++) {
            temp = img[i][j];
            img[i][j] = img[i][IMAGE_WIDTH-1-j];
            img[i][IMAGE_WIDTH-1-j] = temp;
        }
    }
}

/* Function to adjust brightness of image */
void adjustBrightness(uint8_t img[IMAGE_HEIGHT][IMAGE_WIDTH], int brightness) {
    for(int i=0; i<IMAGE_HEIGHT; i++) {
        for(int j=0; j<IMAGE_WIDTH; j++) {
            int newPixelValue = img[i][j] + brightness;
            if(newPixelValue > 255) {
                img[i][j] = 255;
            } else if(newPixelValue < 0) {
                img[i][j] = 0;
            } else {
                img[i][j] = (uint8_t) newPixelValue;
            }
        }
    }
}

/* Function to adjust contrast of image */
void adjustContrast(uint8_t img[IMAGE_HEIGHT][IMAGE_WIDTH], float contrast) {
    float factor = (259 * (contrast + 255)) / (255 * (259 - contrast));
    for(int i=0; i<IMAGE_HEIGHT; i++) {
        for(int j=0; j<IMAGE_WIDTH; j++) {
            int newPixelValue = (factor * (img[i][j] - 128)) + 128;
            if(newPixelValue > 255) {
                img[i][j] = 255;
            } else if(newPixelValue < 0) {
                img[i][j] = 0;
            } else {
                img[i][j] = (uint8_t) newPixelValue;
            }
        }
    }
}

int main() {
    /* Initialize image with random pixel values */
    srand(42);
    for(int i=0; i<IMAGE_HEIGHT; i++) {
        for(int j=0; j<IMAGE_WIDTH; j++) {
            image[i][j] = rand() % 256;
        }
    }
    
    /* Flip image horizontally */
    flipImageHorizontally(image);
    
    /* Adjust brightness by +50 */
    adjustBrightness(image, 50);
    
    /* Adjust contrast by a factor of 1.5 */
    adjustContrast(image, 1.5f);
    
    return 0;
}