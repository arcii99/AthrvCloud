//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: scalable
#include <stdio.h>

// Define constants for pixel mapping
#define PIXEL_ON '*'
#define PIXEL_OFF '.'

// Define function to generate random binary array
void generateRandomBinaryArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 2; // generates random number 0 or 1
    }
}

// Define function to print pixel array
void printPixelArray(int pixelArray[], int width, int height) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int index = i * width + j;
            if (pixelArray[index] == 1) {
                printf("%c", PIXEL_ON);
            } else {
                printf("%c", PIXEL_OFF);
            }
        }
        printf("\n");
    }
}

int main() {
    // Define size and dimensions for pixel array
    int width = 5;
    int height = 5;

    // Initialize pixel array
    int pixelArray[width * height];

    // Generate random binary array for pixel array
    generateRandomBinaryArray(pixelArray, width * height);

    // Print pixel array
    printPixelArray(pixelArray, width, height);

    return 0;
}