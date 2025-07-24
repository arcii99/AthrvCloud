//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1024

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Usage: %s <image_file>\n", argv[0]);
        return 1;
    }

    FILE *fp = fopen(argv[1], "rb");

    if (fp == NULL) {
        printf("Error reading file: %s\n", argv[1]);
        return 1;
    }

    char *pixels = malloc(MAX_SIZE);
    int width, height;

    fread(&width, sizeof(int), 1, fp);
    fread(&height, sizeof(int), 1, fp);
    fread(pixels, sizeof(char), MAX_SIZE, fp);

    fclose(fp);

    printf("P3\n%d %d\n255\n", width, height);

    for (int i = 0; i < width * height; i++) {
        int pixel = pixels[i] & 0xFF;
        printf("%d %d %d ", pixel, pixel, pixel);
        if ((i + 1) % width == 0) {
            printf("\n");
        }
    }

    free(pixels);

    return 0;
}