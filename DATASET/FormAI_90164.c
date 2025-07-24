//FormAI DATASET v1.0 Category: Image Classification system ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>

// Define the pixel values of the image
#define IMG_SIZE 8
int img[IMG_SIZE][IMG_SIZE] = {
    {255, 255, 0, 0, 0, 0, 255, 255},
    {255, 255, 0, 0, 0, 0, 255, 255},
    {0, 0, 255, 0, 0, 255, 0, 0},
    {0, 0, 255, 0, 0, 255, 0, 0},
    {0, 0, 0, 255, 255, 0, 0, 0},
    {0, 0, 0, 255, 255, 0, 0, 0},
    {255, 0, 0, 0, 0, 0, 0, 255},
    {255, 0, 0, 0, 0, 0, 0, 255}
};

int main() 
{
    int i, j, total_pixels, dark_pixels = 0;
    float dark_pixel_ratio;
    
    // Count the number of dark pixels
    for (i = 0; i < IMG_SIZE; i++) {
        for (j = 0; j < IMG_SIZE; j++) {
            if (img[i][j] <= 127) { // Pixel is considered dark if it is less than or equal to 127
                dark_pixels++;
            }
        }
    }
    
    // Calculate the ratio of dark pixels to total pixels
    total_pixels = IMG_SIZE * IMG_SIZE;
    dark_pixel_ratio = (float) dark_pixels / total_pixels;
    
    // Output the result
    printf("Dark pixel ratio: %.2f%%\n", dark_pixel_ratio * 100);
    
    // Classify the image based on the dark pixel ratio
    if (dark_pixel_ratio < 0.1) {
        printf("This image is mostly bright.\n");
    } else if (dark_pixel_ratio < 0.5) {
        printf("This image is a mix of bright and dark.\n");
    } else {
        printf("This image is mostly dark.\n");
    }
    
    return 0;
}