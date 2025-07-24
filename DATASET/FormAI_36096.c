//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum width and height of the image
#define MAX_WIDTH 100
#define MAX_HEIGHT 100

// Function declaration
void convertImageToAscii(char* fileName);

int main() {
    // Call the function to convert the image to ASCII art
    convertImageToAscii("image.jpg");
    
    return 0; 
}

// Function definition
void convertImageToAscii(char* fileName) {
    // Open the image file
    FILE* imageFile = fopen(fileName, "rb");
    if (imageFile == NULL) {
        printf("Unable to open image file.\n");
        exit(1);
    }
    
    // Read the width and height of the image
    unsigned int width, height;
    fseek(imageFile, 18, SEEK_SET);
    fread(&width, sizeof(unsigned int), 1, imageFile);
    fread(&height, sizeof(unsigned int), 1, imageFile);
    rewind(imageFile);
    
    // Create a buffer for storing the image data
    unsigned char imageData[MAX_WIDTH][MAX_HEIGHT][3];
    
    // Read the image data
    fseek(imageFile, 54, SEEK_SET);
    unsigned int row, col;
    for (row = 0; row < height; row++) {
        for (col = 0; col < width; col++) {
            fread(&imageData[row][col][2], 1, 1, imageFile);
            fread(&imageData[row][col][1], 1, 1, imageFile);
            fread(&imageData[row][col][0], 1, 1, imageFile);
        }
    }
    
    // Close the image file
    fclose(imageFile);
    
    // Define the ASCII characters that will be used to represent pixels
    char asciiPixels[] = { ' ', '.', ':', '-', '=', '+', '*', '#', '%', '@' };
    int numAsciiPixels = sizeof(asciiPixels) / sizeof(char);
    
    // Convert the image data to ASCII art and print it to the console
    printf("\n\n");
    for (row = 0; row < height; row += 2) {
        for (col = 0; col < width; col++) {
            // Get the average color value of the current pixel and its neighbor below it
            unsigned int pixelValue = (imageData[row][col][0] + imageData[row][col][1] + imageData[row][col][2]
                                       + imageData[row + 1][col][0] + imageData[row + 1][col][1] + imageData[row + 1][col][2]) / 6;
        
            // Map the pixel value to an ASCII character
            int asciiIndex = (int)(pixelValue / 25.5);
            if (asciiIndex >= numAsciiPixels) {
                asciiIndex = numAsciiPixels - 1;
            }
            
            // Print the ASCII character to the console
            printf("%c", asciiPixels[asciiIndex]);
        }
        printf("\n");
    }
    printf("\n\n");
}