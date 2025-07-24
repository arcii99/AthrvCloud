//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the ASCII art characters to be used
char grayscale[] = " .:-=+*#%@";
char medieval[] = " .`,':~=+^*x$#";

// Define the width and height of the output ASCII art
#define WIDTH 50
#define HEIGHT 50

// Define a function to convert color to grayscale
char getGray(int r, int g, int b) {
    return grayscale[(int)(0.21*r + 0.72*g + 0.07*b)/25];
}

// Define a function to convert a pixel to a character
char getChar(int r, int g, int b) {
    return medieval[(int)(0.21*r + 0.72*g + 0.07*b)/25];
}

int main(int argc, char *argv[]) {
    // Check for the correct number of arguments
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    // Open the input file
    FILE *inputFile = fopen(argv[1], "rb");
    if (!inputFile) {
        printf("Error: Could not open input file.\n");
        return 1;
    }

    // Read the header
    char header[54];
    if (fread(header, sizeof(char), 54, inputFile) != 54) {
        printf("Error: Could not read input file.\n");
        fclose(inputFile);
        return 1;
    }

    // Get the width and height from the header
    int width = *(int*)&header[18];
    int height = *(int*)&header[22];

    // Calculate the padding size
    int padding = (4 - (width * 3) % 4) % 4;

    // Check if the image is larger than the output
    if (width > WIDTH || height > HEIGHT) {
        printf("Error: Input image is too large.\n");
        fclose(inputFile);
        return 1;
    }

    // Read the image data
    unsigned char image[height][width][3];
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            fread(image[i][j], sizeof(unsigned char), 3, inputFile);
        }
        fseek(inputFile, padding, SEEK_CUR);
    }

    // Close the input file
    fclose(inputFile);

    // Convert the image to ASCII art
    char output[HEIGHT][WIDTH+1];
    memset(output, 0, sizeof(output));
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            char c = getChar(image[i][j][0], image[i][j][1], image[i][j][2]);
            output[i][j] = c;
        }
        printf("%s\n", output[i]);
    }

    return 0;
}