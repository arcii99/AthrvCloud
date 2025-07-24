//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Constants
#define MAX_DIM 200
#define ASCII_SCALE 70

// Function prototypes
void printAsciiArt(char asciiImage[MAX_DIM][MAX_DIM], int rows, int cols);
void processImage(char imagePath[]);
char getAsciiChar(int shade);

int main(int argc, char *argv[]) {

    // Check if an image path has been provided
    if (argc < 2) {
        printf("Please provide the path to an image file.\n");
        exit(1);
    }

    // Get the image path from the command-line argument
    char *imagePath = argv[1];

    // Process the image
    processImage(imagePath);

    return 0;
}

// This function processes the image from the given path
void processImage(char imagePath[]) {

    // Open the image file for binary read mode
    FILE *imageFile = fopen(imagePath, "rb");

    // Check if the file exists and can be read
    if (imageFile == NULL) {
        printf("The specified image file cannot be read.\n");
        exit(1);
    }

    // Get the dimensions of the image
    char dimBuffer[10];
    fgets(dimBuffer, 10, imageFile);
    int rows = atoi(strtok(dimBuffer, " "));
    int cols = atoi(strtok(NULL, " "));

    // Check if the image is within the allowed limits
    if (rows > MAX_DIM || cols > MAX_DIM) {
        printf("The image is too large. The maximum allowed dimensions are %dx%d.\n", MAX_DIM, MAX_DIM);
        fclose(imageFile);
        exit(1);
    }

    // Allocate memory for the pixel data
    char pixelData[rows][cols];
    memset(pixelData, 0, sizeof(pixelData));

    // Read the pixel data from the file
    fread(pixelData, 1, rows * cols, imageFile);

    // Close the image file
    fclose(imageFile);

    // Convert the pixel data to ASCII art
    char asciiImage[MAX_DIM][MAX_DIM];
    memset(asciiImage, 0, sizeof(asciiImage));
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            asciiImage[i][j] = getAsciiChar((int)pixelData[i][j] / ASCII_SCALE);
        }
    }

    // Print the ASCII art to standard output
    printAsciiArt(asciiImage, rows, cols);
}

// This function maps a shade value to an ASCII character
char getAsciiChar(int shade) {
    char asciiChar;
    switch (shade) {
    case 0:
        asciiChar = '@';    // Darkest shade
        break;
    case 1:
        asciiChar = '#';
        break;
    case 2:
        asciiChar = '&';
        break;
    case 3:
        asciiChar = '$';
        break;
    case 4:
        asciiChar = '*';
        break;
    case 5:
        asciiChar = 'o';
        break;
    case 6:
        asciiChar = ';';
        break;
    case 7:
        asciiChar = ':';
        break;
    case 8:
        asciiChar = '~';
        break;
    case 9:
        asciiChar = '-';
        break;
    case 10:
        asciiChar = '.';
        break;
    case 11:
        asciiChar = ' ';    // Lightest shade
        break;
    default:
        asciiChar = ' ';
        break;
    }
    return asciiChar;
}

// This function prints the ASCII art to standard output
void printAsciiArt(char asciiImage[MAX_DIM][MAX_DIM], int rows, int cols) {
    printf("\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%c", asciiImage[i][j]);
        }
        printf("\n");
    }
}