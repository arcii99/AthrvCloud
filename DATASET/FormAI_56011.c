//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: ephemeral
#include <stdio.h>

// Function that converts a pixel value to an ASCII character
char pixelToChar(int pixelVal) {
    char asciiVal;

    // Map pixel value range to ASCII character
    if (pixelVal >= 0 && pixelVal <= 25) {
        asciiVal = '@';
    } else if (pixelVal >= 26 && pixelVal <= 50) {
        asciiVal = '#';
    } else if (pixelVal >= 51 && pixelVal <= 75) {
        asciiVal = 'X';
    } else if (pixelVal >= 76 && pixelVal <= 100) {
        asciiVal = 'O';
    } else if (pixelVal >= 101 && pixelVal <= 125) {
        asciiVal = '+';
    } else if (pixelVal >= 126 && pixelVal <= 150) {
        asciiVal = '=';
    } else if (pixelVal >= 151 && pixelVal <= 175) {
        asciiVal = '-';
    } else {
        asciiVal = '.';
    }

    return asciiVal;
}

int main() {
    // Sample 3 x 3 pixel image
    int image[3][3] = {
        {255, 153, 0}, // Orange
        {0, 255, 0}, // Green
        {0, 0, 255} // Blue
    };

    // Convert each pixel value to an ASCII character
    char asciiImage[3][3];
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            int pixelVal = image[i][j];
            asciiImage[i][j] = pixelToChar(pixelVal);
        }
    }

    // Print the ASCII art image
    printf("ASCII art image:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%c ", asciiImage[i][j]);
        }
        printf("\n");
    }

    return 0;
}