//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: inquisitive
// Welcome to the C Image to ASCII Art converter program!
// Inquisitive style

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

// Define the ASCII characters to use
const char ASCII_CHARS[]={'@', '#', '%', '.', '+', '*', ':', ',', '^', '-', ';', '=', '!', '~', '\'','"' ,'`', '.', ' '};
const int NUM_ASCII_CHARS = 19; // number of characters in the ASCII_CHARS array

// Define the size of the image and the file locations
const int WIDTH = 75;
const int HEIGHT = 75;
const char* FILE_LOCATION = "example.png";
const char* OUTPUT_LOCATION = "output.txt";

// Function to retrieve the brightness of a pixel
int getBrightness(int r, int g, int b) {
    return (int) round(0.299*r + 0.587*g + 0.114*b); // formula for grayscale conversion
}

// Function to convert a pixel's brightness value to an ASCII character
char brightnessToChar(int brightness) {
    int charindex = (int) round((brightness/255.0) * (NUM_ASCII_CHARS - 1)); // scale brightness to range of ASCII characters
    return ASCII_CHARS[charindex];
}

int main() {
    // Variables for file I/O
    FILE *filePointer;
    char buffer[128];
    int bufferLength = sizeof(buffer);

    // Open the input file
    filePointer = fopen(FILE_LOCATION, "r");
    if (filePointer == NULL) {
        printf("Failed to open input file\n");
        return 1;
    }

    // Read in the file header (not needed for this program)
    fgets(buffer, bufferLength, filePointer);
    fgets(buffer, bufferLength, filePointer);
    fgets(buffer, bufferLength, filePointer);

    // Create a pixel array to store the image
    int pixels[WIDTH*HEIGHT][3];

    // Read in the pixel values of the image
    for (int i = 0; i < WIDTH*HEIGHT; i++) {
        fgets(buffer, bufferLength, filePointer);
        pixels[i][0] = atoi(buffer); // red value
        fgets(buffer, bufferLength, filePointer);
        pixels[i][1] = atoi(buffer); // green value
        fgets(buffer, bufferLength, filePointer);
        pixels[i][2] = atoi(buffer); // blue value
    }

    // Close the input file
    fclose(filePointer);

    // Create the output file and write the ASCII art to it
    filePointer = fopen(OUTPUT_LOCATION, "w");
    if (filePointer == NULL) {
        printf("Failed to open output file\n");
        return 1;
    }

    // Loop through each pixel and write the corresponding ASCII character to the output file
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            int index = (y * WIDTH + x);
            int brightness = getBrightness(pixels[index][0], pixels[index][1], pixels[index][2]);
            char asciiChar = brightnessToChar(brightness);
            fprintf(filePointer, "%c", asciiChar);
        }
        fprintf(filePointer, "\n"); // move to next line in output file
    }

    // Close the output file
    fclose(filePointer);

    printf("Conversion successful! ASCII art saved to %s\n", OUTPUT_LOCATION);

    return 0;
}