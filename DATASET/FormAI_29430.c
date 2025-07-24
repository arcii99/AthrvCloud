//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 500
#define MAX_HEIGHT 500
#define MAX_ASCII_COLORS 10
#define ASCII_COLORS " .:-=+*#%@"

int main() {
    int width, height, ascii_colors;
    scanf("%d %d %d", &width, &height, &ascii_colors);

    // Ensure width and height don't exceed maximum values
    if (width > MAX_WIDTH) width = MAX_WIDTH;
    if (height > MAX_HEIGHT) height = MAX_HEIGHT;

    char image[height][width][3];
    // Read in image data
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            scanf("%hhu %hhu %hhu", &image[i][j][0], &image[i][j][1], &image[i][j][2]);
        }
    }

    // Determine scaling factor for color values
    int color_range = 256 / ascii_colors;

    // Convert image to ASCII art
    printf("\n");
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int grayscale = (image[i][j][0] + image[i][j][1] + image[i][j][2]) / 3;
            int ascii_index = grayscale / color_range;
            // Ensure ascii index doesn't exceed maximum value
            if (ascii_index >= ascii_colors) ascii_index = ascii_colors - 1;
            printf("%c", ASCII_COLORS[ascii_index]);
        }
        printf("\n");
    }

    return 0;
}