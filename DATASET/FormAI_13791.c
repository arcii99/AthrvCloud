//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define image dimensions
#define HEIGHT 640
#define WIDTH 480

// Define maximum image brightness
#define MAX_BRIGHTNESS 255

// Flip the given image horizontally
void flipImage(char image[][WIDTH]) {
    char temp;
    for(int i=0; i<HEIGHT; i++) {
        for(int j=0; j<WIDTH/2; j++) {
            temp = image[i][j];
            image[i][j] = image[i][WIDTH-j-1];
            image[i][WIDTH-j-1] = temp;
        }
    }
}

// Adjust the brightness of the given image by the specified amount
void adjustBrightness(char image[][WIDTH], int brightnessDelta) {
    for(int i=0; i<HEIGHT; i++) {
        for(int j=0; j<WIDTH; j++) {
            int newBrightness = image[i][j] + brightnessDelta;
            if(newBrightness < 0) {
                newBrightness = 0;
            } else if(newBrightness > MAX_BRIGHTNESS) {
                newBrightness = MAX_BRIGHTNESS;
            }
            image[i][j] = newBrightness;
        }
    }
}

// Adjust the contrast of the given image by the specified amount
void adjustContrast(char image[][WIDTH], int contrastDelta) {
    // Calculate the normalization factor
    float factor = (259 * (contrastDelta + 255)) / (255 * (259 - contrastDelta));
    for(int i=0; i<HEIGHT; i++) {
        for(int j=0; j<WIDTH; j++) {
            int newBrightness = factor * (image[i][j] - 128) + 128;
            if(newBrightness < 0) {
                newBrightness = 0;
            } else if(newBrightness > MAX_BRIGHTNESS) {
                newBrightness = MAX_BRIGHTNESS;
            }
            image[i][j] = newBrightness;
        }
    }
}

int main() {
    // Allocate memory for the image
    char image[HEIGHT][WIDTH];

    // Initialize the image to random values
    for(int i=0; i<HEIGHT; i++) {
        for(int j=0; j<WIDTH; j++) {
            image[i][j] = rand() % (MAX_BRIGHTNESS + 1);
        }
    }

    // Flip the image horizontally
    flipImage(image);

    // Adjust the brightness of the image by -50
    adjustBrightness(image, -50);

    // Adjust the contrast of the image by 50
    adjustContrast(image, 50);

    // Print the final image
    for(int i=0; i<HEIGHT; i++) {
        for(int j=0; j<WIDTH; j++) {
            printf("%d ", image[i][j]);
        }
        printf("\n");
    }

    return 0;
}