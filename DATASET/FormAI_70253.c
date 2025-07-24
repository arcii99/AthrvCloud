//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_WIDTH 100
#define MAX_HEIGHT 100
#define MAX_GRAYSCALE 255

// Input Image Structure
typedef struct Image {
    int width;
    int height;
    int pixels[MAX_HEIGHT][MAX_WIDTH];
} Image;

// Output ASCII Image Structure
typedef struct AsciiImage {
    int width;
    int height;
    char pixels[MAX_HEIGHT][MAX_WIDTH+1];
} AsciiImage;

// Convert input grayscale value to a corresponding character based on intensity
char getIntensityCharacter(int intensity) {
    char chars[] = { ' ', '.', ':', '-', '=', '+', '*', '#', '%', '@' };
    int numChars = 10;
    int index = floor(((float)intensity/MAX_GRAYSCALE) * numChars);
    return chars[index];
}

// Convert input image to an ASCII image
AsciiImage convertToAsciiImage(Image inputImage) {
    AsciiImage outputImage;

    outputImage.width = inputImage.width;
    outputImage.height = inputImage.height;

    // Convert each pixel's grayscale value to a corresponding ASCII character based on intensity
    for(int i=0; i<inputImage.height; i++) {
        for(int j=0; j<inputImage.width; j++) {
            int intensity = inputImage.pixels[i][j];
            outputImage.pixels[i][j] = getIntensityCharacter(intensity);
        }
        outputImage.pixels[i][inputImage.width] = '\n';
    }
    return outputImage;
}

int main() {
    Image inputImage;
    inputImage.width = 20;
    inputImage.height = 10;

    // Generate a random input image with grayscale values ranging from 0 to MAX_GRAYSCALE
    for(int i=0; i<inputImage.height; i++) {
        for(int j=0; j<inputImage.width; j++) {
            inputImage.pixels[i][j] = rand() % (MAX_GRAYSCALE+1);
        }
    }

    // Convert input image to an ASCII image
    AsciiImage outputImage = convertToAsciiImage(inputImage);

    // Display the output ASCII image
    for(int i=0; i<outputImage.height; i++) {
        printf("%s", outputImage.pixels[i]);
    }
    return 0;
}