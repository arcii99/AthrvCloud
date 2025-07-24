//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Constants
#define WIDTH 100
#define HEIGHT 50
#define ASCII_SCALE 70.0

// Functions
void convertToASCII(char *filename);

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Usage: %s filename\n", argv[0]);
        return 1;
    }

    convertToASCII(argv[1]);

    return 0;
}

void convertToASCII(char *filename) {
    // Open image file
    FILE *imageFile;
    imageFile = fopen(filename, "rb");
    if (imageFile == NULL) {
        printf("Error opening file.\n");
        return;
    }

    // Allocate memory for pixel data
    unsigned char image[WIDTH*HEIGHT*3];
    fread(image, sizeof(unsigned char), WIDTH*HEIGHT*3, imageFile);

    // Close image file
    fclose(imageFile);

    // Convert image to ASCII art
    float pixelValue;
    char asciiImage[WIDTH*HEIGHT];
    int index;
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            index = i*WIDTH*3 + j*3;
            pixelValue = (image[index] + image[index+1] + image[index+2]) / ASCII_SCALE;

            // Choose ASCII character based on pixel value
            if (pixelValue >= 70) {
                asciiImage[i*WIDTH + j] = ' ';
            } else if (pixelValue >= 60) {
                asciiImage[i*WIDTH + j] = '.';
            } else if (pixelValue >= 50) {
                asciiImage[i*WIDTH + j] = ':';
            } else if (pixelValue >= 40) {
                asciiImage[i*WIDTH + j] = 'o';
            } else if (pixelValue >= 30) {
                asciiImage[i*WIDTH + j] = 'O';
            } else if (pixelValue >= 20) {
                asciiImage[i*WIDTH + j] = '8';
            } else if (pixelValue >= 10) {
                asciiImage[i*WIDTH + j] = '@';
            } else {
                asciiImage[i*WIDTH + j] = '#';
            }
        }
    }

    // Print ASCII art to console
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            printf("%c", asciiImage[i*WIDTH + j]);
        }
        printf("\n");
    }
}