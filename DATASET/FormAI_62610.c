//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char ASCII_CHARS[] = {' ', '.', ':', '-', '=', '+', '*', '#', '%', '@'};

void imageToASCII(char *filename, int width, int height) {
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error opening file.");
        exit(1);
    }

    unsigned char image[height][width];

    for (int y=0; y < height; y++) {
        for (int x=0; x < width; x++) {
            image[y][x] = fgetc(fp);
        }
    }

    fclose(fp);

    char ASCII_IMG[height][width];
    int index;

    for (int y=0; y < height; y++) {
        for (int x=0; x < width; x++) {
            index = image[y][x] / 25;
            ASCII_IMG[y][x] = ASCII_CHARS[index];
        }
    }

    for (int y=0; y < height; y++) {
        for (int x=0; x < width; x++) {
            printf("%c", ASCII_IMG[y][x]);
        }
        printf("\n");
    }
}

int main() {
    imageToASCII("image.bmp", 500, 500);
    return 0;
}