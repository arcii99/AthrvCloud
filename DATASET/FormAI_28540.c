//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define WIDTH 120
#define HEIGHT 80

void readImage(char *filename, int *width, int *height, char image[HEIGHT][WIDTH]);
void writeAscii(char *filename, int width, int height, char image[HEIGHT][WIDTH]);

int main(int argc, char **argv) {
    char filename[256];
    int width, height;
    char image[HEIGHT][WIDTH];
    double brightness;
    char ascii;

    printf("Enter image filename: ");
    scanf("%255s", filename);

    readImage(filename, &width, &height, image);

    printf("Converting...\n");

    FILE *fp;

    fp = fopen("ascii_image.txt", "w");

    for(int y = 0; y < height; y++) {
        for(int x = 0; x < width; x++) {
            brightness = (double)image[y][x]/255;
            ascii = (char)(brightness*94) + 32;
            fprintf(fp, "%c", ascii);
        }
        fprintf(fp, "\n");
    }

    fclose(fp);

    printf("Done! Output written to ascii_image.txt\n");

    return 0;
}

void readImage(char *filename, int *width, int *height, char image[HEIGHT][WIDTH]) {
    FILE *fp;

    fp = fopen(filename, "rb");

    if(fp == NULL) {
        printf("Error reading file.\n");
        exit(1);
    }

    fread(width, sizeof(int), 1, fp);
    fread(height, sizeof(int), 1, fp);

    for(int y = 0; y < *height; y++) {
        for(int x = 0; x < *width; x++) {
            fread(&image[y][x], sizeof(char), 1, fp);
        }
    }

    fclose(fp);
}