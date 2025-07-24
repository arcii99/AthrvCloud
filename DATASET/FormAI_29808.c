//FormAI DATASET v1.0 Category: Image Editor ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>

// Function to flip vertically
void flip_vertical(char* filename, int height, int width) {
    FILE* fp = fopen(filename, "rb+");
    if (fp == NULL) {
        printf("Error: could not open file.\n");
        exit(1);
    }
    char pixel[3];
    for (int i = 0; i < height / 2; i++) {
        for (int j = 0; j < width; j++) {
            fseek(fp, 3 * (i * width + j), SEEK_SET);
            fread(pixel, 3, 1, fp);
            fseek(fp, 3 * ((height - i - 1) * width + j), SEEK_SET);
            fread(&pixel, 3, 1, fp);
            fseek(fp, 3 * (i * width + j), SEEK_SET);
            fwrite(&pixel, 3, 1, fp);
        }
    }
    fclose(fp);
    printf("The image %s has been flipped vertically.\n", filename);
}

int main() {
    char* filename = "image.bmp";
    int height = 480;
    int width = 640;
    flip_vertical(filename, height, width);
    return 0;
}