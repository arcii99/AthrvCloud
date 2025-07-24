//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 200
#define MAX_HEIGHT 200

char chars[] = {'@', '%', '#', '*', '+', '=', '-', ':', '.', ' '};
int charCount = 10;
char grayScale[] = " .:-=+*#%@";

// function prototypes
void getImage(char img[MAX_HEIGHT][MAX_WIDTH], char *fileName);
int getPixelBrightness(char r, char g, char b);
char getAsciiChar(int pixelBrightness);
void printAsciiArt(char asciiArt[MAX_HEIGHT][MAX_WIDTH], int height, int width);

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("\nUsage: ./imgToAscii <filename>\n");
        exit(0);
    }

    char img[MAX_HEIGHT][MAX_WIDTH];
    getImage(img, argv[1]);
    int height = strlen(img), width = strlen(img[0]);
    char asciiArt[MAX_HEIGHT][MAX_WIDTH];

    // iterate over each pixel in the image and convert it to ASCII character
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int brightness = getPixelBrightness(img[i][j], img[i][j + 1], img[i][j + 2]);
            asciiArt[i][j] = getAsciiChar(brightness);
            j += 2; // skip the 3 color values for each pixel
        }
    }

    printAsciiArt(asciiArt, height, width);
    return 0;
}

// function to read the image file and store the RGB values for each pixel
void getImage(char img[MAX_HEIGHT][MAX_WIDTH], char *fileName) {
    FILE *file = fopen(fileName, "rb");
    if (!file) {
        printf("Error opening image file.\n");
        exit(0);
    }

    char buffer[3];
    fseek(file, 54, SEEK_SET); // skip the header of the BMP file
    for (int i = 0; i < MAX_HEIGHT; i++) {
        for (int j = 0; j < MAX_WIDTH; j++) {
            fread(buffer, 1, 3, file); // read the RGB values for each pixel
            img[i][j] = buffer[0];
            img[i][j + 1] = buffer[1];
            img[i][j + 2] = buffer[2];
        }
    }
    fclose(file);
}

// function to calculate the brightness of a pixel
int getPixelBrightness(char r, char g, char b) {
    return (r + g + b) / 3; // simple average of R, G, B values
}

// function to map the brightness of a pixel to an ASCII character
char getAsciiChar(int pixelBrightness) {
    int charIndex = (int)(pixelBrightness / (255.0 / (charCount - 1))); // map brightness to a character index
    return chars[charIndex]; // return the corresponding ASCII character
}

// function to print the ASCII art to console
void printAsciiArt(char asciiArt[MAX_HEIGHT][MAX_WIDTH], int height, int width) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf("%c", asciiArt[i][j]);
        }
        printf("\n");
    }
}