//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

// Convert RGB pixel to grayscale
uint8_t RGBtoGray(uint8_t r, uint8_t g, uint8_t b) {
    return ((0.2989 * r) + (0.5870 * g) + (0.1140 * b));
}

// Convert grayscale pixel to ASCII character
char grayscaleToChar(uint8_t grayValue) {
    char asciiChar;
    
    // Choose ASCII character based on grayscale value
    if (grayValue >= 0 && grayValue < 25) {
        asciiChar = '@';
    } else if (grayValue >= 25 && grayValue < 50) {
        asciiChar = '#';
    } else if (grayValue >= 50 && grayValue < 75) {
        asciiChar = '%';
    } else if (grayValue >= 75 && grayValue < 100) {
        asciiChar = '*';
    } else if (grayValue >= 100 && grayValue < 125) {
        asciiChar = '+';
    } else if (grayValue >= 125 && grayValue < 150) {
        asciiChar = '=';
    } else if (grayValue >= 150 && grayValue < 175) {
        asciiChar = '-';
    } else if (grayValue >= 175 && grayValue < 200) {
        asciiChar = ';';
    } else if (grayValue >= 200 && grayValue < 225) {
        asciiChar = ':';
    } else {
        asciiChar = ' ';
    }
    
    return asciiChar;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s [filename]\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    
    FILE *file = fopen(argv[1], "rb");
    
    if (file == NULL) {
        printf("Error: Could not open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }
    
    // Store file header data
    uint8_t header[54];
    fread(header, sizeof(uint8_t), 54, file);
    
    // Parse image properties from header
    int32_t width = *(int32_t*)&header[18];
    int32_t height = *(int32_t*)&header[22];
    int32_t imageDataOffset = *(int32_t*)&header[10];
    
    // Calculate row padding (each row should have number of bytes divisible by 4)
    int32_t rowPadding = (4 - (width * 3) % 4) % 4;
    
    // Allocate memory to store image data
    uint8_t *imageData = (uint8_t*)malloc(sizeof(uint8_t) * (width * height * 3 + rowPadding * height));
    
    // Load image data into memory
    fseek(file, imageDataOffset, SEEK_SET);
    fread(imageData, sizeof(uint8_t), width * height * 3 + rowPadding * height, file);
    
    // Close file
    fclose(file);
    
    // Convert image to ASCII
    for (int32_t y = height - 1; y >= 0; y--) {
        for (int32_t x = 0; x < width; x++) {
            
            // Compute image data index
            int32_t index = (y * width + x) * 3;
            
            // Convert RGB pixel to grayscale
            uint8_t grayValue = RGBtoGray(imageData[index], imageData[index + 1], imageData[index + 2]);
            
            // Convert grayscale pixel to ASCII character
            char asciiChar = grayscaleToChar(grayValue);
            
            // Print ASCII character
            putchar(asciiChar);
        }
        
        // Print row padding
        for (int32_t p = 0; p < rowPadding; p++) {
            putchar(' ');
        }
        
        // Move to next line
        putchar('\n');
    }
    
    // Free memory
    free(imageData);
    
    return 0;
}