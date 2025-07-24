//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WIDTH 80
#define HEIGHT 60
#define CHARACTERS "@#&$%*o!:."

char grayscaleToChar(int value);

int main(int argc, char* argv[])
{
    if (argc != 2) {
        printf("Usage: %s <image-file>\n", argv[0]);
        return 1;
    }

    // Open the image file
    FILE* fp;
    fp = fopen(argv[1], "rb");
    if (fp == NULL) {
        printf("Could not open %s\n", argv[1]);
        return 1;
    }

    // Read the image data
    unsigned char imageData[WIDTH * HEIGHT];
    fread(imageData, sizeof(unsigned char), WIDTH * HEIGHT, fp);
    fclose(fp);

    // Convert the image to ASCII art
    char asciiArt[WIDTH * HEIGHT];
    memset(asciiArt, 0, sizeof(asciiArt));
    for (int i = 0; i < WIDTH * HEIGHT; i++) {
        asciiArt[i] = grayscaleToChar(imageData[i]);
    }

    // Print the ASCII art to the console
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            putchar(asciiArt[y * WIDTH + x]);
        }
        putchar('\n');
    }

    return 0;
}

char grayscaleToChar(int value)
{
    int index = (value * strlen(CHARACTERS)) / 256;
    return CHARACTERS[index];
}