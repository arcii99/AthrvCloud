//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 20
#define HEIGHT 20

int main(void) {
    
    // Seed random number generator
    srand(time(NULL));
    
    // Generate random colors for each pixel
    int pixels[HEIGHT][WIDTH];
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            pixels[i][j] = rand() % 256;
        }
    }
    
    // Print pixel art to console
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (pixels[i][j] < 85) {
                printf("\033[48;2;%d;%d;%dm  ", pixels[i][j], pixels[i][j], pixels[i][j]);
            } else if (pixels[i][j] < 170) {
                printf("\033[48;2;%d;%d;%dm  ", pixels[i][j] - 85, pixels[i][j] - 85, pixels[i][j] - 85);
            } else {
                printf("\033[48;2;%d;%d;%dm  ", pixels[i][j] - 170, pixels[i][j] - 170, pixels[i][j] - 170);
            }
        }
        printf("\n");
    }
    
    return 0;
}