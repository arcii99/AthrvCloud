//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to resize the image to ASCII art
void resizeImage(int** image, int* width, int* height, int new_width) {
    int new_height = (*height * new_width) / (*width);
    int** new_image = (int**)malloc(new_height * sizeof(int*));
    for (int i = 0; i < new_height; i++) {
        new_image[i] = (int*)malloc(new_width * sizeof(int));
        for (int j = 0; j < new_width; j++) {
            int x = (j * (*width)) / new_width;
            int y = (i * (*height)) / new_height;
            new_image[i][j] = image[y][x];
        }
    }
    for (int i = 0; i < *height; i++) {
        free(image[i]);
    }
    free(image);
    *width = new_width;
    *height = new_height;
    image = new_image;
}

// Function to convert the image to ASCII art
void convertToASCII(int** image, int width, int height, char* ascii_chars, int num_chars) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int value = (image[i][j] * (num_chars - 1)) / 255;
            printf("%c", ascii_chars[value]);
        }
        printf("\n");
    }
}

int main() {
    // Load the image from file
    FILE* file = fopen("image.bmp", "rb");
    if (file == NULL) {
        printf("Error: could not open file\n");
        return 1;
    }

    unsigned char header[54];
    if (fread(header, sizeof(unsigned char), 54, file) != 54) {
        printf("Error: invalid file format\n");
        fclose(file);
        return 1;
    }

    int width = *(int*)&header[18];
    int height = *(int*)&header[22];
    int bits_per_pixel = *(int*)&header[28];
    if (bits_per_pixel != 24) {
        printf("Error: unsupported color format\n");
        fclose(file);
        return 1;
    }

    int padding = (4 - (width * 3) % 4) % 4;
    int** image = (int**)malloc(height * sizeof(int*));
    for (int i = 0; i < height; i++) {
        image[i] = (int*)malloc(width * sizeof(int));
        for (int j = 0; j < width; j++) {
            unsigned char pixel[3];
            if (fread(pixel, sizeof(unsigned char), 3, file) != 3) {
                printf("Error: invalid file format\n");
                fclose(file);
                for (int k = 0; k < i; k++) {
                    free(image[k]);
                }
                free(image);
                return 1;
            }
            image[i][j] = ((30 * pixel[0]) + (59 * pixel[1]) + (11 * pixel[2])) / 100;
        }
        fseek(file, padding, SEEK_CUR);
    }
    fclose(file);

    // Resize the image
    resizeImage(image, &width, &height, 100);

    // Convert the image to ASCII art
    char ascii_chars[] = {' ', '.', ':', '-', '=', '+', '*', '#', '%', '@'};
    convertToASCII(image, width, height, ascii_chars, 10);

    // Free memory
    for (int i = 0; i < height; i++) {
        free(image[i]);
    }
    free(image);

    return 0;
}