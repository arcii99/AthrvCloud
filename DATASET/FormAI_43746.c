//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: safe
#include <stdio.h>

#define WIDTH 80
#define HEIGHT 60
#define MAX_RGB 255

char ascii_gray_scale[MAX_RGB + 1] = {' ', '.', '\'', ':', 'o', '&', '8', '#', '@'};

int main() {

    // Initialize file pointer and try to open image file
    FILE *img_fp;
    img_fp = fopen("example_image.ppm", "rb");

    if (img_fp == NULL) {   // if unable to open file
        printf("Unable to open image file.\n");
        return 1;
    }

    // Skip image header data
    char ch = '\n';
    while (ch == '\n') {
        ch = fgetc(img_fp);
    }
    fseek(img_fp, -1, SEEK_CUR);

    // Create buffer to store image pixel data
    int image_data[HEIGHT][WIDTH][3];

    // Read image pixel data into buffer
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            for (int k = 0; k < 3; k++) {   // Read RGB values
                image_data[i][j][k] = fgetc(img_fp);
            }
        }
    }

    // Close image file
    fclose(img_fp);

    // Convert image pixel data to ASCII art
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            int rgb_value = ((image_data[i][j][0] + image_data[i][j][1] + image_data[i][j][2]) / 3);
            printf("%c", ascii_gray_scale[(rgb_value * MAX_RGB) / MAX_RGB]);
        }
        printf("\n");
    }

    return 0;
}