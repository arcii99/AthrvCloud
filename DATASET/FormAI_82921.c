//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: Cyberpunk
#include <stdio.h>

#define WIDTH 256
#define HEIGHT 256
#define MAX_PIXEL_VALUE 255

typedef unsigned char BYTE;

BYTE image[WIDTH][HEIGHT];

/* Function to flip the image horizontally */
void flipHorizontally() {
    for(int i = 0; i < HEIGHT; i++) {
        for(int j = 0; j < WIDTH/2; j++) {
            BYTE temp = image[i][j];
            image[i][j] = image[i][WIDTH-1-j];
            image[i][WIDTH-1-j] = temp;
        }
    }
}

/* Function to adjust the brightness of the image */
void adjustBrightness(int adjustment) {
    for(int i = 0; i < HEIGHT; i++) {
        for(int j = 0; j < WIDTH; j++) {
            if(image[i][j] + adjustment < 0) {
                image[i][j] = 0;
            } else if(image[i][j] + adjustment > MAX_PIXEL_VALUE) {
                image[i][j] = MAX_PIXEL_VALUE;
            } else {
                image[i][j] += adjustment;
            }
        }
    }
}

/* Function to adjust the contrast of the image */
void adjustContrast(float adjustment) {
    float factor = (259.0f * (adjustment + 255.0f)) / (255.0f * (259.0f - adjustment));
    for(int i = 0; i < HEIGHT; i++) {
        for(int j = 0; j < WIDTH; j++) {
            int newValue = factor * (image[i][j] - 128) + 128;
            if(newValue < 0) {
                newValue = 0;
            } else if(newValue > MAX_PIXEL_VALUE) {
                newValue = MAX_PIXEL_VALUE;
            }
            image[i][j] = newValue;
        }
    }
}

int main() {
    // Initialize image
    for(int i = 0; i < HEIGHT; i++) {
        for(int j = 0; j < WIDTH; j++) {
            image[i][j] = i ^ j;
        }
    }
    
    // Flip image horizontally
    flipHorizontally();
    
    // Adjust brightness by -50
    adjustBrightness(-50);
    
    // Adjust contrast by 50%
    adjustContrast(0.5);
    
    // Output modified image
    FILE* fp = fopen("cyberpunk_image.pgm", "wb");
    fprintf(fp, "P5\n%d %d\n%d\n", WIDTH, HEIGHT, MAX_PIXEL_VALUE);
    fwrite(image, sizeof(BYTE), WIDTH * HEIGHT, fp);
    fclose(fp);
    
    return 0;
}