//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define PIXEL_COUNT 32  // Constant to define number of pixels per row and column

int main() {
    int pixel_array[PIXEL_COUNT][PIXEL_COUNT];  // 2D array to store each pixel's color
    int color_count = 0;  // Variable to keep count of how many colors have been used
    
    // Seed random number generator
    srand(time(NULL));
    
    // Loop through each pixel
    for (int i = 0; i < PIXEL_COUNT; i++) {
        for (int j = 0; j < PIXEL_COUNT; j++) {
            
            // Choose a random color for this pixel
            int color = rand() % 10 + 1;
            
            // Check if this color has already been used
            int color_exists = 0;
            for (int k = 0; k < color_count; k++) {
                if (pixel_array[i][j] == k) {
                    color_exists = 1;
                    break;
                }
            }
            
            // If the color hasn't been used, add it to the array and increment the color count
            if (!color_exists) {
                pixel_array[i][j] = color_count;
                color_count++;
            }
            // If the color has been used, set the pixel to the same color as another pixel
            else {
                int matching_pixel_found = 0;
                for (int l = i; l >= 0; l--) {
                    for (int m = j; m >= 0; m--) {
                        if (pixel_array[l][m] == pixel_array[i][j]) {
                            pixel_array[i][j] = pixel_array[l][m];
                            matching_pixel_found = 1;
                            break;
                        }
                    }
                    if (matching_pixel_found) {
                        break;
                    }
                }
            }
        }
    }
    
    // Print out the pixel array as ASCII art
    for (int i = 0; i < PIXEL_COUNT; i++) {
        for (int j = 0; j < PIXEL_COUNT; j++) {
            printf("%d ", pixel_array[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}