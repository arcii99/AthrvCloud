//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert RGB to grayscale
unsigned char grayscale(unsigned char r, unsigned char g, unsigned char b) {
    return (unsigned char)((0.299 * r) + (0.587 * g) + (0.114 * b));
}

// Function to convert image to ASCII art and print to console
void convertToAscii(FILE *img) {
    char asciiTable[] = {' ', '.', ',', ':', ';', '!', '*', 'o', 'x', '$', '@'};
    int asciiTableSize = sizeof(asciiTable) / sizeof(char);
    int asciiWidth = 120;
    int asciiHeight = 60;
    int scale = 3;
    unsigned char pixels[asciiHeight * asciiWidth];
    unsigned char buf[3];
    int i, j, k, pos, grey;
    fseek(img, 54, SEEK_SET); // Skip BMP header

    // Read image data into pixel array
    for (i = 0; i < asciiHeight; i++)
        for (j = 0; j < asciiWidth; j++) {
            fread(buf, 1, 3, img);
            grey = grayscale(buf[2], buf[1], buf[0]);
            pixels[(i * asciiWidth) + j] = grey;
        }

    // Convert pixel values to ASCII characters and print to console
    for (i = 0; i < asciiHeight; i++) {
        for (j = 0; j < asciiWidth; j++) {
            pos = (i * asciiWidth) + j;
            k = pixels[pos] * (asciiTableSize - 1) / 255;
            for (int p = 0; p < scale; p++)
                for (int q = 0; q < scale; q++)
                    putchar(asciiTable[k]);
        }
        putchar('\n');
    }
}

int main(int argc, char *argv[]) {
    FILE *img;

    if (argc != 2) {
        printf("Usage: %s [filename]\n", argv[0]);
        return 1;
    }

    img = fopen(argv[1], "rb");
    if (!img) {
        printf("Error: Cannot open file '%s'\n", argv[1]);
        return 2;
    }

    convertToAscii(img);
    fclose(img);
    return 0;
}