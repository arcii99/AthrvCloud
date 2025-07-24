//FormAI DATASET v1.0 Category: Image Editor ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdint.h>

#define MAX_PIXEL_VALUE 255

int main()
{
    int width = 512; // Width of the image
    int height = 512; // Height of the image
    
    uint8_t image[height][width]; // 8 bit grayscale image
    
    // Generate a gradient image
    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            image[i][j] = (i + j) % (MAX_PIXEL_VALUE + 1);
        }
    }
    
    // Add noise to the image
    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            uint8_t noise = rand() % 21 - 10; // Random noise between -10 and 10
            int pixel_value = image[i][j] + noise;
            if(pixel_value < 0) {
                pixel_value = 0;
            } else if(pixel_value > MAX_PIXEL_VALUE) {
                pixel_value = MAX_PIXEL_VALUE;
            }
            image[i][j] = pixel_value;
        }
    }
    
    // Apply Gaussian blur
    double kernel[5][5] = {
        {0.003, 0.013, 0.022, 0.013, 0.003},
        {0.013, 0.059, 0.097, 0.059, 0.013},
        {0.022, 0.097, 0.159, 0.097, 0.022},
        {0.013, 0.059, 0.097, 0.059, 0.013},
        {0.003, 0.013, 0.022, 0.013, 0.003}
    };
    
    uint8_t blurred_image[height][width]; // Intermediate blurred image
    
    for(int i = 2; i < height - 2; i++) {
        for(int j = 2; j < width - 2; j++) {
            double sum = 0.0;
            for(int k = -2; k <= 2; k++) {
                for(int l = -2; l <= 2; l++) {
                    sum += kernel[k+2][l+2] * (double)image[i+k][j+l];
                }
            }
            blurred_image[i][j] = (uint8_t)round(sum);
        }
    }
    
    // Invert colors
    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            image[i][j] = MAX_PIXEL_VALUE - blurred_image[i][j];
        }
    }
    
    // Write the image to a file
    FILE *fp = fopen("output.pgm", "wb");
    fprintf(fp, "P5\n%d %d\n%d\n", width, height, MAX_PIXEL_VALUE); // PGM header
    fwrite(image, sizeof(uint8_t), height * width, fp); // PGM pixel data
    fclose(fp);
    
    return 0;
}