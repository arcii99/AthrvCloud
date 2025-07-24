//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: Linus Torvalds
/* Pixel Art Generator in Linux Torvalds Style */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 200
#define MAX_HEIGHT 200
#define PIXEL_SIZE 10

int main(int argc, char *argv[]) {
    char pixels[MAX_WIDTH][MAX_HEIGHT];
    int width, height;

    // Ask for user input
    printf("Enter width and height (max %dx%d): ", MAX_WIDTH, MAX_HEIGHT);
    scanf("%d %d", &width, &height);

    // Initialize pixel array to empty
    memset(pixels, '.', sizeof pixels);

    // Draw a square in the middle of the pixel array
    for (int i = (width - PIXEL_SIZE) / 2; i < (width + PIXEL_SIZE) / 2; i++) {
        for (int j = (height - PIXEL_SIZE) / 2; j < (height + PIXEL_SIZE) / 2; j++) {
            pixels[i][j] = '#';
        }
    }

    // Print out the pixel array
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            printf("%c ", pixels[i][j]);
        }
        printf("\n");
    }

    return 0;
}