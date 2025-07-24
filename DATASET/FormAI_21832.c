//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: Cyberpunk
#include <stdio.h>

#define IMAGE_SIZE 32

int pixel_array[32][32];

void fill_neon_green() {
    int r = 0;
    int g = 255;
    int b = 0;
    
    for (int i = 0; i < IMAGE_SIZE; i++) {
        for (int j = 0; j < IMAGE_SIZE; j++) {
            pixel_array[i][j] = (r << 16) | (g << 8) | b;
        }
    }
}

int main() {
    fill_neon_green();
    
    // Save pixel array as image file here
    
    return 0;
}